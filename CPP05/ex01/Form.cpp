/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:29:23 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/31 15:56:03 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/****************************************/
/*			Form implementation			*/
/****************************************/

Form::Form(void) : _name("defaultName"), _signed(0), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, int const gradeToSign, int const gradeToExecute) :
	_name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1)
		throw GradeTooHighException("Grade to sign's value is too high to initialize");
	if (_gradeToExecute < 1)
		throw GradeTooHighException("Grade to execute's value is too high to initialize");
	if (_gradeToSign > 150)
		throw GradeTooLowException("Grade to sign's value is too low to initialize");
	if (_gradeToExecute > 150)
		throw GradeTooLowException("Grade to execute's value is too low to initialize");
}

Form::Form(Form const & source) :
	_name(source._name), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{
	*this = source;
}

Form::~Form(void)
{
}

Form &	Form::operator=(Form const & source)
{
	if (this != &source)
		_signed = source._signed;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat const & John)
{
	if (John.getGrade() >= _gradeToSign)
		throw GradeTooLowException(John.getName() + " couldn't sign because his grade is too low");
	_signed = 1;
}

/*************************************************/
/*				GradeTooHighExeption			 */
/*************************************************/

Form::GradeTooHighException::GradeTooHighException(void) throw() :
	_phrase("Form GradeTooHighException")
{
}

Form::GradeTooHighException::GradeTooHighException(std::string phrase) throw() :
	_phrase("GradeTooHighException : " + phrase)
{
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return (_phrase.c_str());
}

/*************************************************/
/*				GradeTooLowExeption				 */
/*************************************************/

Form::GradeTooLowException::GradeTooLowException(void) throw() :
	_phrase("Form GradeTooLowException")
{
}

Form::GradeTooLowException::GradeTooLowException(std::string phrase) throw() :
	_phrase("GradeTooLowException : " + phrase)
{
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return (_phrase.c_str());
}

/*************************************************/
/*				Operator overload <<			 */
/*************************************************/

std::ostream &	operator<<(std::ostream & o, Form const & source)
{
	std::string	signStatus = "unsigned";

	if (source.getSigned())
		signStatus = "signed";
	o << "Form " << source.getName() << ", grade to sign is " << source.getGradeToSign() \
		<< ", grade to execute is " << source.getGradeToExecute() << ", " << signStatus << std::endl;
	return (o);
}
