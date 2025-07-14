/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:20:25 by candrese          #+#    #+#             */
/*   Updated: 2025/07/13 23:00:07 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "\n----- test subject example with MutantStack" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "pushed 5 and 17" << std::endl;
	std::cout << "top element: " << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << "after pop, size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "added more elements: 3, 5, 737, 0" << std::endl;
	std::cout << "final size: " << mstack.size() << std::endl;
	
	std::cout << "\n----- test iterator functionality" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	std::cout << "iterating through MutantStack:" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "\n----- test conversion to std::stack" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "created std::stack from MutantStack" << std::endl;
	std::cout << "std::stack size: " << s.size() << std::endl;
	std::cout << "std::stack top: " << s.top() << std::endl;
	
	std::cout << "\n----- test with std::list (same operations)" << std::endl;
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);
	
	std::cout << "pushed 5 and 17 to list" << std::endl;
	std::cout << "back element: " << lst.back() << std::endl;
	
	lst.pop_back();
	std::cout << "after pop_back, size: " << lst.size() << std::endl;
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::cout << "added more elements: 3, 5, 737, 0" << std::endl;
	std::cout << "final size: " << lst.size() << std::endl;
	
	std::cout << "iterating through list:" << std::endl;
	std::list<int>::iterator lst_it = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();
	
	++lst_it;
	--lst_it;
	while (lst_it != lst_ite)
	{
		std::cout << *lst_it << std::endl;
		++lst_it;
	}
	
	std::cout << "\n----- test reverse iterators" << std::endl;
	std::cout << "MutantStack in reverse order:" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	
	std::cout << "\n----- test with different types" << std::endl;
	MutantStack<std::string> string_stack;
	string_stack.push("first");
	string_stack.push("second");
	string_stack.push("third");
	
	std::cout << "string stack contents:" << std::endl;
	for (MutantStack<std::string>::iterator str_it = string_stack.begin(); 
		 str_it != string_stack.end(); ++str_it)
	{
		std::cout << "\"" << *str_it << "\"" << std::endl;
	}
	
	std::cout << "\n----- test copy constructor and assignment" << std::endl;
	MutantStack<int> copy_stack(mstack);
	std::cout << "copy constructor - size: " << copy_stack.size() << std::endl;
	
	MutantStack<int> assigned_stack;
	assigned_stack = mstack;
	std::cout << "assignment operator - size: " << assigned_stack.size() << std::endl;
	
	std::cout << "checking if copy is independent:" << std::endl;
	mstack.push(999);
	std::cout << "original stack size after adding 999: " << mstack.size() << std::endl;
	std::cout << "copy stack size (should be unchanged): " << copy_stack.size() << std::endl;
	
	std::cout << "\nall tests completed!" << std::endl;
	return 0;
}
