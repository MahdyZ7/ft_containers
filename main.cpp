/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:08:16 by ayassin           #+#    #+#             */
/*   Updated: 2023/03/14 10:14:07 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// constructing stacks
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "ft_vector.hpp"
// #include "ft_stack.hpp"


// stack main
// int main ()
// {
// 	{
// 		std::deque<int> myVector (3,100);          // deque with 3 elements
// 		std::vector<int> myvector (2,200);        // vector with 2 elements

// 		std::stack<int> first;                    // empty stack
// 		std::stack<int> second (myVector);         // stack initialized to copy of deque

// 		std::stack<int,std::vector<int> > third;  // empty stack using vector
// 		std::stack<int,std::vector<int> > fourth (myvector);

// 		std::cout << "size of first: " << first.size() << '\n';
// 		std::cout << "size of second: " << second.size() << '\n';
// 		std::cout << "size of third: " << third.size() << '\n';
// 		std::cout << "size of fourth: " << fourth.size() << '\n';
// 	}
// 	{
// 		// std::vector<int> myVector (3,100);          // deque with 3 elements
// 		std::vector<int> myvector (2,200);        // vector with 2 elements

// 		ft::stack<int> first;                    // empty stack
// 		// ft::stack<int> second (myVector);         // stack initialized to copy of deque

// 		ft::stack<int,std::vector<int> > third;  // empty stack using vector
// 		ft::stack<int,std::vector<int> > fourth (myvector);

// 		std::cout << "size of first: " << first.size() << '\n';
// 		// std::cout << "size of second: " << second.size() << '\n';
// 		first.push(6);
// 		first.push(12);
// 		std::cout<< "The top element is " << first.top() << std::endl;
// 		std::cout << "size of first: " << first.size() << '\n';
// 		first.pop();
// 		std::cout << "size of first: " << first.size() << '\n';
// 		std::cout << "size of third: " << third.size() << '\n';
// 		std::cout << "size of fourth: " << fourth.size() << '\n';
// 	}
//   return 0;
// }

// vector main
int	main()
{
	std::vector<int> a;
	std::cout << a.capacity() << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		a.push_back(i);
		std::cout << a.capacity() << std::endl;
	}
}