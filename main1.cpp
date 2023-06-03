/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:18:30 by ayassin           #+#    #+#             */
/*   Updated: 2023/06/03 12:18:27 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main() {
	ft::vector<int> v1(10);

	for (size_t i = 0; i < 9; i++)
	{
		v1[i] = i;
	}
	
	ft::vector<int>::iterator it = v1.begin();
	ft::vector<int>::iterator it2 = v1.end();
	
	it++;
	it = 1 + it;
	
}