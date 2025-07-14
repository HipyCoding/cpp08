/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:38:51 by candrese          #+#    #+#             */
/*   Updated: 2025/07/11 22:55:54 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end);

	unsigned int size() const;
	unsigned int maxSize() const;
};


template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{

	unsigned int count = std::distance(begin, end);

	if (_numbers.size() + count > _maxSize)
		throw std::runtime_error("Not enough space to add all numbers");

	_numbers.insert(_numbers.end(), begin, end);
}

#endif
