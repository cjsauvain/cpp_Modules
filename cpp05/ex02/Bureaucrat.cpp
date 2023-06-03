/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:34:33 by jsauvain          #+#    #+#             */
/*   Updated: 2023/06/02 17:49:16 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/************************************************/
/*			Bureaucrat implementation			*/
/************************************************/

Bureaucrat::Bureaucrat(void) : _name("defaultName"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException("Bureaucrat's grade is too high to initialize");
	if (grade > 150)
		throw GradeTooLowException("Bureaucrat's grade is too low to initialize");
}

Bureaucrat::Bureaucrat(Bureaucrat const & source) : _name(source._name)
{
	*this = source;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & source)
{
	if (this != &source)
		_grade = source._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException("Cannot upgrade " + _name + "'s grade");
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException("Cannot downgrade " + _name + "'s grade");
	_grade++;
}

void	Bureaucrat::signForm(AForm & source) const
{
	source.beSigned(*this);
	std::cout << _name << " signed form " << source.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
	std::cout << _name << " executed " << form.getName() << " Form\n";
}

/*************************************************/
/*				GradeTooHighExeption			 */
/*************************************************/

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw() :
	_phrase("Bureaucrat GradeTooHighException")
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string phrase) throw() :
	_phrase("GradeTooHighException : " + phrase)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (_phrase.c_str());
}

/*************************************************/
/*				GradeTooLowExeption				 */
/*************************************************/

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw() :
	_phrase("Bureaucrat GradeTooLowException")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string phrase) throw() :
	_phrase("GradeTooLowException : " + phrase)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (_phrase.c_str());
}

/*************************************************/
/*				Operator overload <<			 */
/*************************************************/

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & source)
{
	o << source.getName() << ", bureaucrat grade " << source.getGrade() << "." << std::endl;
	return (o);
}
