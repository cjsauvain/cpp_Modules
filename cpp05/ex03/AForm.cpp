/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:29:23 by jsauvain          #+#    #+#             */
/*   Updated: 2023/06/02 17:56:42 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>

/****************************************/
/*			AForm implementation		*/
/****************************************/

AForm::AForm(void) : _name("StandardForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, int const gradeToSign, int const gradeToExecute) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1)
		throw GradeTooHighException("Grade to sign's value is too high to initialize, it should be 1 max");
	if (_gradeToExecute < 1)
		throw GradeTooHighException("Grade to execute's value is too high to initialize, it should be 1 max");
	if (_gradeToSign > 150)
		throw GradeTooLowException("Grade to sign's value is too low to initialize, it should be 150 min");
	if (_gradeToExecute > 150)
		throw GradeTooLowException("Grade to execute's value is too low to initialize, it should be 150 min");
}

AForm::AForm(AForm const & source) :
	_name(source._name), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{
	*this = source;
}

AForm::~AForm(void)
{
}

AForm &	AForm::operator=(AForm const & source)
{
	if (this != &source)
		_signed = source._signed;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat const & John)
{
	if (_signed == true)
		throw FormException(John.getName() + " couldn't sign because it was already signed");
	if (John.getGrade() > _gradeToSign)
	{
		std::string	err;

		err = John.getName() + " doesn't have the required grade to sign " + _name + " Form";
		throw GradeTooLowException(err);
	}
	_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw FormException("hasn't been signed yet");
	if (executor.getGrade() > _gradeToExecute)
	{
		std::string	err;

		err = executor.getName() + " doesn't have the required grade to execute " + _name + " Form";
		throw GradeTooLowException(err);
	}
	executeFormAction();
}

/*************************************************/
/*				GradeTooHighExeption			 */
/*************************************************/

AForm::GradeTooHighException::GradeTooHighException(void) throw() :
	_phrase("AForm GradeTooHighException")
{
}

AForm::GradeTooHighException::GradeTooHighException(std::string phrase) throw() :
	_phrase("GradeTooHighException : " + phrase)
{
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw()
{
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return (_phrase.c_str());
}

/*************************************************/
/*				GradeTooLowExeption				 */
/*************************************************/

AForm::GradeTooLowException::GradeTooLowException(void) throw() :
	_phrase("AForm GradeTooLowException")
{
}

AForm::GradeTooLowException::GradeTooLowException(std::string phrase) throw() :
	_phrase("GradeTooLowException : " + phrase)
{
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return (_phrase.c_str());
}

/*************************************************/
/*				FormExeption					 */
/*************************************************/

AForm::FormException::FormException(void) throw() :
	_phrase("FormException")
{
}

AForm::FormException::FormException(std::string phrase) throw() :
	_phrase("FormException : " + phrase)
{
}

AForm::FormException::~FormException(void) throw()
{
}

const char*	AForm::FormException::what(void) const throw()
{
	return (_phrase.c_str());
}

/*************************************************/
/*				Operator overload <<			 */
/*************************************************/

std::ostream &	operator<<(std::ostream & o, AForm const & source)
{
	std::string	signStatus = "unsigned";

	if (source.getSigned() == true)
		signStatus = "signed";
	o << source.getName() << ", grade to sign is " << source.getGradeToSign() \
		<< ", grade to execute is " << source.getGradeToExecute() << ", " << signStatus << std::endl;
	return (o);
}
