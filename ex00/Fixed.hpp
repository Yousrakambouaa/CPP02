/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:52:16 by ykamboua          #+#    #+#             */
/*   Updated: 2025/05/26 15:48:49 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					number;
		static const int	fractional_bits;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
