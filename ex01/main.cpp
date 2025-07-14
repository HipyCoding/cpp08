/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:38:57 by candrese          #+#    #+#             */
/*   Updated: 2025/07/14 00:39:12 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main()
{
	std::cout << "\n----- testing the subject example" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "added numbers: 6, 3, 17, 9, 11" << std::endl;
	
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "whoops: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- what happens with no numbers?" << std::endl;
	Span empty(5);
	
	try
	{
		std::cout << "trying to find span in empty container..." << std::endl;
		empty.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "can't do that: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- testing with lots of numbers" << std::endl;
	Span big(15000);
	
	std::vector<int> numbers;
	for (int i = 0; i < 15000; i++)
		numbers.push_back(i);
	
	try
	{
		std::cout << "adding 15000 numbers at once..." << std::endl;
		big.addNumbers(numbers.begin(), numbers.end());
		std::cout << "done! found shortest span: " << big.shortestSpan() << std::endl;
		std::cout << "and longest span: " << big.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "something went wrong: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- testing duplicate numbers" << std::endl;
	Span duplicates(5);
	duplicates.addNumber(42);
	duplicates.addNumber(42);
	duplicates.addNumber(100);
	
	try
	{
		std::cout << "span with duplicates (42, 42, 100):" << std::endl;
		std::cout << "shortest span: " << duplicates.shortestSpan() << std::endl;
		std::cout << "longest span: " << duplicates.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	
	std::cout << "\ndone testing!" << std::endl;
	return 0;
}


// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }
