/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:16:00 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/31 15:56:49 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	/**************************/
	/*    Exceptions class    */
	/**************************/
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void) throw();
			GradeTooHighException(std::string phrase) throw();
			~GradeTooHighException(void) throw();

			const char*	what() const throw();

		private:
			std::string const	_phrase;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void) throw();
			GradeTooLowException(std::string phrase) throw();
			~GradeTooLowException(void) throw();

			const char*	what() const throw();

		private:
			std::string const	_phrase;
	};

	/************************/
	/*		AForm class		*/
	/************************/
	public:
		AForm(void);
		AForm(std::string name, int const gradeToSign, int const gradeToExecute);
		AForm(AForm const & source);
		~AForm(void);

		AForm &	operator=(AForm const & source);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int 		getGradeToSign(void) const;
		int 		getGradeToExecute(void) const;
		void		beSigned(Bureaucrat const & John);
		
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream &	operator<<(std::ostream & o, AForm const & source);

#endif
