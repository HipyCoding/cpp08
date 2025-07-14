/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:56:32 by candrese          #+#    #+#             */
/*   Updated: 2025/07/13 23:29:01 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::cout << "\n----- test with vector container" << std::endl;
	std::vector<int> numbers;
	numbers.push_back(42);
	numbers.push_back(17);
	numbers.push_back(3);
	numbers.push_back(99);
	numbers.push_back(21);
	
	std::cout << "vector contains: 42, 17, 3, 99, 21" << std::endl;
	
	try
	{
		std::cout << "searching for value 17..." << std::endl;
		std::vector<int>::iterator found = easyfind(numbers, 17);
		std::cout << "found: " << *found << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "searching for value 88 (not in container)..." << std::endl;
		easyfind(numbers, 88);
		std::cout << "found 88!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- test with list container" << std::endl;
	std::list<int> favorites;
	favorites.push_back(7);
	favorites.push_back(13);
	favorites.push_back(42);
	
	std::cout << "list contains: 7, 13, 42" << std::endl;
	
	try
	{
		std::cout << "searching for 13..." << std::endl;
		std::list<int>::iterator lucky = easyfind(favorites, 13);
		std::cout << "found: " << *lucky << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- test with deque container" << std::endl;
	std::deque<int> scores;
	scores.push_back(100);
	scores.push_back(85);
	scores.push_back(92);
	
	std::cout << "deque contains: 100, 85, 92" << std::endl;
	
	try
	{
		std::cout << "searching for score 85..." << std::endl;
		std::deque<int>::iterator score = easyfind(scores, 85);
		std::cout << "found: " << *score << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n----- test with empty container" << std::endl;
	std::vector<int> empty;
	std::cout << "empty vector size: " << empty.size() << std::endl;
	
	try
	{
		std::cout << "trying to find value 1 in empty container..." << std::endl;
		easyfind(empty, 1);
		std::cout << "this shouldn't print!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- test first and last elements" << std::endl;

	try
	{
		std::cout << "searching for first element (42)..." << std::endl;
		std::vector<int>::iterator first = easyfind(numbers, 42);
		std::cout << "found: " << *first << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "searching for last element (21)..." << std::endl;
		std::vector<int>::iterator last = easyfind(numbers, 21);
		std::cout << "found: " << *last << "\n" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
