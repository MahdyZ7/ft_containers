/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:08:16 by ayassin           #+#    #+#             */
/*   Updated: 2023/03/28 14:51:08 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// constructing stacks
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "vector.hpp"
// #include "stack.hpp"


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
void 	print_test(bool x, std::string str)
{
	if (x == false)
		throw std::runtime_error("\033[0;31m" + str + " does not match" + "\033[0m");
	// std::cout << "\033[0;32m" << str << ": completed" << "\033[0m" << std::endl;
}

template <class T>
void	cmp_vectors(std::vector<T> *s, ft::vector<T> *f, std::string test)
{
	print_test(s->size() == f->size(), test + "size");
	print_test(s->capacity() == f->capacity(), test + "capacity");
	print_test(s->max_size() == f->max_size(), test + "max_size");
	print_test(s->empty() == f->empty(), test + "empty");
	for (size_t i = 0; i < f->size(); ++i)
	{
		print_test((*s)[i] == (*f)[i], test + " [] operator");
		print_test(s->at(i) == f->at(i), test + " at()");
	}
	if (s->size() == 0)
		return ;
	print_test(s->back() == f->back(), test + "back");
	print_test(s->front() == f->front(), test + "front");
	// print_test((s->begin()) == (f->begin()), test + "begin");
	// std::cout << s->begin();// << "  " << f->begin() << std::endl;
}

template <class T>
void	repetative_talk(std::vector<T> *s, ft::vector<T> *f, std::string test0)
{
	std::string test1 = "";
	cmp_vectors(s, f, test0+test1);

	test1 = "Clear empty Vector ";
	s->clear(); f->clear();
	cmp_vectors(s, f, test0+test1);

	test1 = "push_back(11) ";
	s->push_back(11); f->push_back(11);
	cmp_vectors(s, f, test0+test1);

	test1 = "push_back alot ";
	for (int i = 0; i < 100; ++i)
	{
		s->push_back(i); f->push_back(i);
		cmp_vectors(s, f, test0+test1);
	}

	test1 = "pop_back() ";
	s->pop_back(); f->pop_back();
	cmp_vectors(s, f, test0+test1);
	
	test1 = "Reserve 10 ";
	s->reserve(10); f->reserve(10);
	cmp_vectors(s, f, test0+test1);

	test1 = "Reserve 300 ";
	s->reserve(300); f->reserve(300);
	cmp_vectors(s, f, test0+test1);

	test1 = "Reserve 11 ";
	s->reserve(11); f->reserve(11);
	cmp_vectors(s, f, test0+test1);

	test1 = "Clear full Vector ";
	s->clear(); f->clear();
	cmp_vectors(s, f, test0+test1);

	test1 = "Reserve 100 ";
	s->reserve(100); f->reserve(100);
	cmp_vectors(s, f, test0+test1);

	test1 = "assign 30 11 ";
	s->assign(300,11); f->assign(300, 11);
	cmp_vectors(s, f, test0+test1);

	test1 = "assinment  ";
	{
		ft::vector<int>		tempft(40,10);
		std::vector<int>	tempstd(40,10);
		*s = tempstd; *f = tempft;
		cmp_vectors(s, f, test0+test1);
	}

	test1 = "assinment 2 ";
	{
		ft::vector<int>		tempft(400,1110);
		std::vector<int>	tempstd(400,1110);
		*s = tempstd; *f = tempft;
		cmp_vectors(s, f, test0+test1);
	}
	
	// test1 = "swap ";
	// {
	// 	ft::vector<int>		tempft(40,10);
	// 	std::vector<int>	tempstd(40,10);
	// 	s->swap(tempstd); f->swap(tempft);
	// 	cmp_vectors(s, f, test0+test1);
	// 	test1 = "second swap";
	// 	s->swap(tempstd); f->swap(tempft);
	// 	cmp_vectors(s, f, test0+test1);
	// }
}

int	main()
{

	// {
	// 	std::vector<int> stda;
	// 	ft::vector<int> fta;

	// 	stda.reserve(300); fta.reserve(300);

	// 	stda.assign(30, 1); fta.assign(30,1);
	// 	{ft::vector<int>		tempft(40,10);
	// 	std::vector<int>	tempstd(40,10);
	// 	// stda.swap(tempstd); fta.swap(tempft);
	// 	stda = tempstd; fta = tempft;
	// 	std::cout << stda.capacity() << " vs " << fta.capacity() << std::endl;
	// 	}{
	// 	ft::vector<int>		tempft(401,10);
	// 	std::vector<int>	tempstd(401,10);
	// 	// stda.swap(tempstd); fta.swap(tempft);
	// 	stda = tempstd; fta = tempft;
	// 	std::cout << stda.capacity() << " vs " << fta.capacity() << std::endl;
	// 	}
	// 	return 0; 
	// }
	
	try 
	{
		std::string test0 = "Deafult constructor: ";
		std::vector<int> stda;
		ft::vector<int> fta;
		
		repetative_talk(&stda, &fta, test0);


		stda.push_back(50); fta.push_back(50);
		stda.push_back(50); fta.push_back(50);
		stda.push_back(50); fta.push_back(50);
		test0 = "Copy constructor: ";
		std::vector<int> stda_copy(stda);
		ft::vector<int> fta_copy(fta);

		
		repetative_talk(&stda_copy, &fta_copy, test0);

		test0 = "Assinment operatopr: ";
		std::vector<int> stda_ass = stda;
		ft::vector<int> fta_ass = fta;
		repetative_talk(&stda_ass, &fta_ass, test0);

		test0 = "size constructor (0, default values): ";
		std::vector<int> stda_size(0);
		ft::vector<int> fta_size(0);
		
		repetative_talk(&stda_size, &fta_size, test0);
		
		test0 = "size constructor (70, default values): ";
		std::vector<int> stda_size1(70);
		ft::vector<int> fta_size1(70);
		
		repetative_talk(&stda_size1, &fta_size1, test0);
		
		test0 = "size constructor (70, 90): ";
		std::vector<int> stda_size2(70, 90);
		ft::vector<int> fta_size2(70, 90);
		
		repetative_talk(&stda_size2, &fta_size2, test0);
		std::cout << "done\n";
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	// std::string test0 = "Deafult constructor";
	// std::string test0 = "";
	// std::vector<int> stda;
	// std::vector<int> fta;
	
	// std::cout << a.capacity() << std::endl;
	// std::vector<int> b(10);
	// b.reserve(13);
	// std::cout << b.capacity() << std::endl;
	// b.resize(51, 10);
	// std::cout << b.capacity() << std::endl;
	// //  a.pop_back();
	// b.reserve(111);
	// std::cout << "the numbers inside are: ";
	// for (size_t i = 0; i < b.size(); ++i )
	// 	std::cout << b[i] << " ";
	// std::cout << std::endl;
	// std::cout << "the capacity inside is ";
	// for (size_t i = 0; i < 100; ++i)
	// {
	// 	b.push_back(i);
	// 	std::cout << b.capacity() << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "the number inside is: ";
	// for (size_t i = 0; i < b.size(); ++i )
	// 	std::cout << b[i] << " ";
	// std::cout << std::endl;
	// try{
	// 	b.at(1000);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what();
	// }
}