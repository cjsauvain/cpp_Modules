/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:25:29 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/08 16:54:01 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>

class BitcoinExchange
{
	public:
		static int									isYearBis(int y);
		static int									checkDayFormat(int d, int m, int y, int lenDay);
		static int									checkDateFormat(std::string tmp);
		static int									checkRangeValue(std::string tmp, int file);
		static int									checkValueFormat(std::string tmp, int file);
		static int									checkFormat(std::string buf, std::string delim, \
														int file);
		static std::map<std::string, std::string>	initDataMap(char *data);
		static void									displayOperation(std::string mapValue, std::string buf);
		static std::string							checkIfKeyExists(int d, int m, int y, \
														std::map<std::string, std::string> dataMap);
		static int									getDay(int m, int y);
		static std::string							getMapDate(std::map<std::string, std::string> dataMap, \
														std::tm dateBuf);
		static std::string							getMapKey(std::map<std::string, std::string> dataMap, \
														std::string buf);
		static void									displayExchange(std::map<std::string, std::string> dataMap, \
														std::string input);
		static void									processExchange(char *input, char *data);


	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & source);
		~BitcoinExchange(void);

		BitcoinExchange &	operator=(BitcoinExchange const & source);
};
