/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:38:54 by candrese          #+#    #+#             */
/*   Updated: 2025/07/14 00:36:50 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

Span::Span() : _maxSize(0)
{}

Span::Span(unsigned int N) : _maxSize(N)
{
	_numbers.reserve(N);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is already full");
	
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Need at least 2 numbers to calculate span");

	std::vector<int> sorted_numbers = _numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	int min_span = INT_MAX;
	for (size_t i = 1; i < sorted_numbers.size(); i++)
	{
		int span = sorted_numbers[i] - sorted_numbers[i - 1];
		if (span < min_span)
			min_span = span;
	}
	return min_span;
}


int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("give at least 2 numbers to calculate span");
	std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());

	return *max_it - *min_it;
}

unsigned int Span::size() const
{
	return _numbers.size();
}

unsigned int Span::maxSize() const
{
	return _maxSize;
}
