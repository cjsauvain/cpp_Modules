/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:10:05 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/08 17:14:35 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & source)
{
	*this = source;
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & source)
{
	(void)source;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

int	BitcoinExchange::isYearBis(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	BitcoinExchange::checkDayFormat(int d, int m, int y, int lenDay)
{
	if (lenDay > 3 || d < 1)
		return (0);
	else if ((isYearBis(y) && m == 2 && d > 28)  || (!isYearBis(y) && m == 2 && d > 29))
		return (0);
	if (d > 31 && ((m < 8 && m % 2) || (m >= 8 && m % 2 == 0)))
		return (0);
	else if (d > 30 && ((m < 8 && m % 2 == 0) || (m >= 8 && m % 2)))
		return (0);
	return (1);
}

int	BitcoinExchange::checkDateFormat(std::string tmp)
{
	size_t	pos[2];
	int		y;
	int		m;
	int		d;

	//year check
	pos[0] = tmp.find_first_not_of("0123456789");
	if (tmp[pos[0]] != '-' || pos[0] == std::string::npos)
		return (0);
	std::stringstream(tmp.substr(0, pos[0])) >> y;
	if (y < 2009 || y > 2023)
		return (0);

	//month check
	pos[1] = tmp.find_first_not_of("0123456789", pos[0] + 1);
	if (tmp[pos[1]] != '-' || pos[0] == std::string::npos)
		return (0);
	std::stringstream(tmp.substr(pos[0] + 1, pos[1])) >> m;
	if (pos[1] - pos[0] > 3 || m < 1 || m > 12)
		return (0);

	//day check
	pos[0] = tmp.find_first_not_of("0123456789", pos[1] + 1);
	if (pos[0] != std::string::npos)
		return (0);
	std::stringstream(tmp.substr(pos[1] + 1)) >> d;
	if (!checkDayFormat(d, m, y, tmp.length() - pos[1]))
		return (0);
	return (1);
}

int	BitcoinExchange::checkRangeValue(std::string tmp, int file)
{
	std::stringstream	ss(tmp);
	float				f;

	if (file)
	{
		if (!(ss >> f) || f > 1000)
		{
			std::cerr << "Error: too large number => '" << tmp << "'" << std::endl;
			return (0);
		}
		if (f < 0)
		{
			std::cerr << "Error: negative value => '" << tmp << "'" << std::endl;
			return (0);
		}
	}
	else
	{
		if (!(ss >> f))
		{
			std::cerr << "Error database: overflow\n";
			return (0);
		}
	}
	return (1);
}

int	BitcoinExchange::checkValueFormat(std::string tmp, int file)
{
	size_t	pos;

	pos = tmp.find_first_not_of("0123456789");
	if (tmp[pos] == '.' || pos == std::string::npos)
	{
		if (pos != std::string::npos)
			pos = tmp.find_first_not_of("0123456789", pos + 1);
		if (pos == std::string::npos)
		{
			if (file)
			{
				if (!checkRangeValue(tmp, file))
					return (0);
			}
			return (1);
		}
	}
	if (file)
		std::cerr << "Error: invalid value => '" << tmp << "'" << std::endl;
	else
		std::cerr << "Error database: invalid value\n";
	return (0);
}

int	BitcoinExchange::checkFormat(std::string buf, std::string delim, int file)
{
	std::string	tmp;
	size_t		pos;

	pos = buf.find_first_of(delim);
	if (pos == std::string::npos)
	{
		if (file)
			std::cerr << "Error: invalid format => '" << buf << "'" << std::endl;
		else
			std::cerr << "Error database: invalid format\n";
		return (0);
	}
	tmp = buf.substr(0, pos);
	if (!checkDateFormat(tmp))
	{
		if (file)
			std::cerr << "Error: invalid date => '" << tmp << "'" << std::endl;
		else
			std::cerr << "Error database: invalid date\n";
		return (0);
	}
	tmp = buf.substr(pos + delim.length());
	if (!checkValueFormat(tmp, file))
		return (0);
	return (1);
}

std::map<std::string, std::string>	BitcoinExchange::initDataMap(char *data)
{
	std::ifstream						dataStream(data);
	std::map<std::string, std::string>	dataMap;
	std::string							buf;
	std::string							buf2;
	size_t								pos;

	if (!dataStream)
	{
		std::cerr << "Error database: could not open file\n";
		return (std::map<std::string, std::string>());
	}
	getline(dataStream, buf, '\n');
	if (!buf.compare("date,exchange_rate"))
		getline(dataStream, buf, '\n');
	while (!buf.empty())
	{
		if (!checkFormat(buf, ",", 0))
			return (std::map<std::string, std::string>());
		pos = buf.find_first_of(",");
		buf2 = buf.substr(pos + 1);
		buf = buf.substr(0, pos);
		dataMap[buf] = buf2;
		getline(dataStream, buf, '\n');
	}
	return (dataMap);
}

void	BitcoinExchange::displayOperation(std::string mapValueStr, std::string buf)
{
	std::string			value;
	float				bufValue;
	float				mapValue;
	size_t				pos;

	pos = buf.find_first_of(" ");
	std::cout << buf.substr(0, pos) << " => "; 
	pos = buf.find_first_of("0123456789", pos);
	std::cout << buf.substr(pos) << " = "; 
	value = buf.substr(pos);
	std::stringstream(value) >> bufValue;
	std::stringstream(mapValueStr) >> mapValue;
	std::cout << std::fixed << std::setprecision(2) << bufValue * mapValue << std::endl;
}

std::string	BitcoinExchange::checkIfKeyExists(int d, int m, int y, std::map<std::string, std::string> dataMap)
{
	std::string	tmp;
	char		str[11];
	std::tm		date;

	date.tm_mday = d;
	date.tm_mon = m - 1;
	date.tm_year = y - 1900;
	strftime(str, 11, "%F", &date);
	tmp = str;
	if (dataMap.find(tmp) == dataMap.end())
		tmp.clear();
	return (tmp);
}

int	BitcoinExchange::getDay(int m, int y)
{
	if (!isYearBis(y) && m == 2)
		return (29);
	if (m == 2)
		return (28);
	if ((m < 8 && m % 2) || (m >= 8 && m % 2 == 0) || !m)
		return (31);
	return (30);
}

std::string	BitcoinExchange::getMapDate(std::map<std::string, std::string> dataMap, std::tm dateBuf)
{
	std::string	mapDate;
	int			d;
	int			m;
	int			y = 0;

	while (dateBuf.tm_year - y >= 2009)
	{
		m = 0;
		while (dateBuf.tm_mon - m >= 1)
		{
			d = 0;
			while (dateBuf.tm_mday - d >= 1)
			{
				mapDate = checkIfKeyExists(dateBuf.tm_mday - d, dateBuf.tm_mon - m, \
					dateBuf.tm_year - y, dataMap);
				if (!mapDate.empty())
					break;
				d++;
			}
			if (!mapDate.empty())
				break;
			m++;
			if (!(dateBuf.tm_mon - m))
				dateBuf.tm_mday = getDay(dateBuf.tm_mon - m, dateBuf.tm_year - (y + 1));
			else
				dateBuf.tm_mday = getDay(dateBuf.tm_mon - m, dateBuf.tm_year - y);
		}
		if (!mapDate.empty())
			break;
		dateBuf.tm_mon = 12;
		y++;
	}
	return (mapDate);
}

std::string	BitcoinExchange::getMapKey(std::map<std::string, std::string> dataMap, std::string buf)
{
	std::string		mapDate;
	std::tm			dateBuf;
	size_t			pos[2];

	//year
	pos[0] = buf.find_first_of("-");
	std::stringstream(buf.substr(0, pos[0])) >> dateBuf.tm_year;

	//month
	pos[1] = buf.find_first_of("-", pos[0] + 1);
	std::stringstream(buf.substr(pos[0] + 1, pos[1])) >> dateBuf.tm_mon;

	//day
	pos[0] = buf.find_first_of(" ", pos[1] + 1);
	std::stringstream(buf.substr(pos[1] + 1, pos[0])) >> dateBuf.tm_mday;
	
	if (dataMap.find(buf.substr(0, pos[0])) != dataMap.end())
		return (buf.substr(0, pos[0]));
	mapDate = getMapDate(dataMap, dateBuf);
	return (mapDate);
}

void	BitcoinExchange::displayExchange(std::map<std::string, std::string> dataMap, std::string input)
{
	std::ifstream	ss(input.c_str());
	std::string		buf;
	std::string		date;

	if (!ss)
		std::cerr << "Error: could not open " << input << std::endl;
	else
	{
		getline(ss, buf, '\n');
		if (!buf.compare("date | value"))
			getline(ss, buf, '\n');
		while (!buf.empty())
		{
			if (checkFormat(buf, " | ", 1))
			{
				date = getMapKey(dataMap, buf);
				displayOperation(dataMap[date], buf);
			}
			getline(ss, buf, '\n');
		}
	}
}

void	BitcoinExchange::processExchange(char *input, char *data)
{
	std::map<std::string, std::string>	dataMap;

	dataMap = initDataMap(data);
	if (!dataMap.empty())
		displayExchange(dataMap, input);
}
