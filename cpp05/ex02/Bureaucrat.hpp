/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:58:01 by jsauvain          #+#    #+#             */
/*   Updated: 2023/06/02 17:44:34 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & source);
		~Bureaucrat(void);

		Bureaucrat &	operator=(Bureaucrat const & source);

		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(AForm & source) const;
		void			executeForm(AForm const & form);

	private:
		std::string const	_name;
		int					_grade;

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
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & source);

#endif
