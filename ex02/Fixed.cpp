/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:16:33 by ykamboua          #+#    #+#             */
/*   Updated: 2025/05/21 21:41:21 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed():number(0) 
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &obj)
		number = obj.number;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return(this->number);
}

void	Fixed::setRawBits(const int raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}


Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	number = n << fractional_bits;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float constructor called" << std::endl;
	number = roundf(n * ( 1 << fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (number >> fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return (this->number / 256.0f);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    out << obj.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->number > other.number);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->number < other.number);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->number >= other.number); 
}


bool Fixed::operator<=(const Fixed& other) const
{
	return (this->number <= other.number);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->number == other.number);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->number != other.number);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.number == 0)
	{
		std::cerr << "Division by zero!!!" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}



Fixed&	Fixed::operator++()
{
	this->number+= 1;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->number-= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	f;

	f = *this;
	this->number += 1;
	return (f);
}

Fixed	Fixed::operator--(int)
{
	Fixed	f;

	f = *this;
	this->number -= 1;
	return (f);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if(a < b)
		return	(a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a < b)
		return (a);
	else 
		return (b);
}


Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if(a > b)
		return	(a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a > b)
		return (a);
	else 
		return (b);
}
