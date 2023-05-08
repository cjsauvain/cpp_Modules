/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:00:14 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/08 11:29:15 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <iomanip>
#include <stack>

std::stack<int>	calcul(std::stack<int> ints, std::stack<char> ops);
void			displayResult(std::string numbers);

#endif
