/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:08:16 by ayassin           #+#    #+#             */
/*   Updated: 2023/03/29 12:03:16 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// constructing stacks
#include "vector.hpp"
#include <deque>    // std::deque
#include <iostream> // std::cout
#include <stack>    // std::stack
#include <vector>   // std::vector
// #include "stack.hpp"

// stack main
// int main ()
// {
// 	{
// 		std::deque<int> myVector (3,100);          // deque with 3
// elements 		std::vector<int> myvector (2,200);        // vector with
// 2 elements

// 		std::stack<int> first;                    // empty stack
// 		std::stack<int> second (myVector);         // stack initialized
// to copy of deque

// 		std::stack<int,std::vector<int> > third;  // empty stack using
// vector 		std::stack<int,std::vector<int> > fourth (myvector);

// 		std::cout << "size of first: " << first.size() << '\n';
// 		std::cout << "size of second: " << second.size() << '\n';
// 		std::cout << "size of third: " << third.size() << '\n';
// 		std::cout << "size of fourth: " << fourth.size() << '\n';
// 	}
// 	{
// 		// std::vector<int> myVector (3,100);          // deque with 3
// elements 		std::vector<int> myvector (2,200);        // vector with
// 2 elements

// 		ft::stack<int> first;                    // empty stack
// 		// ft::stack<int> second (myVector);         // stack
// initialized to copy of deque

// 		ft::stack<int,std::vector<int> > third;  // empty stack using
// vector 		ft::stack<int,std::vector<int> > fourth (myvector);

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
void print_test(bool x, std::string str) {
  if (x == false)
    throw std::runtime_error("\033[0;31m" + str + " does not match" +
                             "\033[0m");
  // std::cout << "\033[0;32m" << str << ": completed" << "\033[0m" <<
  // std::endl;
}

template <class T>
void cmp_vectors(std::vector<T> *s, ft::vector<T> *f, std::string test) {
  // std::cout << test << std::endl;
  // std::cout << "size std: " << s->size() << " ft: " << f->size() <<
  // std::endl;
  print_test(s->size() == f->size(), test + "size");
  // std::cout << "capacity std: " << s->capacity() << " ft: " << f->capacity()
  // << std::endl;
  print_test(s->capacity() == f->capacity(), test + "capacity");
  // std::cout << "max_size std: " << s->max_size() << " ft: " << f->max_size()
  // << std::endl;
  print_test(s->max_size() == f->max_size(), test + "max_size");
  print_test(s->empty() == f->empty(), test + "empty");
  for (size_t i = 0; i < f->size(); ++i) {
    // if ((*s)[i] != (*f)[i])
    {
      // std::cout << "Element at [" << i << "] -> std: " <<
      // (*s)[i] << 	" ft: " << (*f)[i] << std::endl;
    }
    print_test((*s)[i] == (*f)[i], test + " [] operator");
    print_test(s->at(i) == f->at(i), test + " at()");
  }
  if (s->size() == 0)
    return;
  // std::cout << "back std: " << s->back() << " ft: " << f->back() <<
  // std::endl;
  print_test(s->back() == f->back(), test + "back");
  // std::cout << "front std: " << s->front() << " ft: " << f->front() <<
  // std::endl;
  print_test(s->front() == f->front(), test + "front");
  print_test(*(s->begin()) == *(f->begin()), test + "begin");
  print_test(*(s->rbegin()) == *(f->rbegin()), test + "rbegin");
  // std::cout << test << " rend std: " << *(s->rend()) << " ft: " <<
  // *(f->rend()) << std::endl; std::cout << test << " rend-1 std: " <<
  // (*(s->rend() - 1)) << " ft: " << *(f->rend() - 1) << std::endl;
  print_test(*(s->end() - 1) == *(f->end() - 1), test + "end");
  print_test(*(s->rend()) == *(f->rend()), test + "rend");
  std::vector<int>::reverse_iterator sit = s->rbegin();
  // std::vector<int>::const_iterator c_sit = s->begin();
  ft::vector<int>::reverse_iterator fit = f->rbegin();
  // ft::vector<int>::const_iterator c_fit = f->begin();
  print_test(*sit == *(fit), test + "begin 2");
  // std::cout << test << " base std: " << (*sit.base()) << " ft: " << (*fit.base()) << std::endl;
  // std::cout << test << " base std: " << (*(sit.base() - 2)) << " ft: " << (*(fit.base() - 2)) << std::endl;
  print_test(*(sit.base() - 1) == *(fit.base() - 1), test + "base");
  print_test(*(sit.base() - 2) == *(fit.base() - 2), test + "base");

  // print_test(*c_sit == *(c_fit), test + "begin const");
  // std::cout << *(s->begin()) << "  " << *(f->begin()) << std::endl;
	// std::cout << "\033[0;32m" << test << ":	✅" << std::endl;
}

template <class T>
void repetative_talk(std::vector<T> *s, ft::vector<T> *f, std::string test0) {
  std::string test1 = "";
  cmp_vectors(s, f, test0 + test1);

  test1 = "Clear empty Vector ";
  s->clear();
  f->clear();
  cmp_vectors(s, f, test0 + test1);

  test1 = "push_back(11) ";
  s->push_back(11);
  f->push_back(11);
  cmp_vectors(s, f, test0 + test1);

	test1 = "insert";
	s->insert(s->begin(), 12);
	f->insert(f->begin(), 12);
	cmp_vectors(s, f, test0 + test1);

	test1 = "insert(end)";
	s->insert(s->end(), 13);
	f->insert(f->end(), 13);
	cmp_vectors(s, f, test0 + test1);
	
  test1 = "push_back alot ";
  for (int i = 0; i < 100; ++i) {
    s->push_back(i);
    f->push_back(i);
    cmp_vectors(s, f, test0 + test1);
  }

  test1 = "pop_back() ";
  s->pop_back();
  f->pop_back();
  cmp_vectors(s, f, test0 + test1);

  test1 = "Reserve 10 ";
  s->reserve(10);
  f->reserve(10);
  cmp_vectors(s, f, test0 + test1);

  test1 = "Reserve 300 ";
  s->reserve(300);
  f->reserve(300);
  cmp_vectors(s, f, test0 + test1);

  test1 = "Reserve 11 ";
  s->reserve(11);
  f->reserve(11);
  cmp_vectors(s, f, test0 + test1);

  test1 = "assign 0 ";
  s->assign(0, 0);
  f->assign(0, 0);
  cmp_vectors(s, f, test0 + test1);

  test1 = "assign 10 -10";
  s->assign(10, -10);
  f->assign(10, -10);
  cmp_vectors(s, f, test0 + test1);

  test1 = "assign itt";
  const std::string extra(6, 'b');
  s->assign(extra.begin(), extra.end());
  f->assign(extra.begin(), extra.end());
  cmp_vectors(s, f, test0 + test1);

  test1 = "assign itt";
  const std::string extra1(1000, 'c');
  s->assign(extra1.begin(), extra1.end());
  f->assign(extra1.begin(), extra1.end());
  cmp_vectors(s, f, test0 + test1);

  test1 = "assign itt";
  const std::string extra2(1, 'd');
  s->assign(extra2.begin(), extra2.end());
  f->assign(extra2.begin(), extra2.end());
  cmp_vectors(s, f, test0 + test1);

  test1 = "Clear full Vector ";
  s->clear();
  f->clear();
  cmp_vectors(s, f, test0 + test1);

  test1 = "Reserve 100 ";
  s->reserve(100);
  f->reserve(100);
  cmp_vectors(s, f, test0 + test1);

  test1 = "assign 300 11 ";
  s->assign(300, 11);
  f->assign(300, 11);
  cmp_vectors(s, f, test0 + test1);

  test1 = "assinment  ";
  {
    ft::vector<int> tempft(40, 10);
    std::vector<int> tempstd(40, 10);
    *s = tempstd;
    *f = tempft;
    cmp_vectors(s, f, test0 + test1);
  }

  test1 = "assinment 2 ";
  {
    ft::vector<int> tempft(400, 1110);
    std::vector<int> tempstd(400, 1110);
    *s = tempstd;
    *f = tempft;
    *s = tempstd;
    *f = tempft;
    cmp_vectors(s, f, test0 + test1);
  }

  test1 = "push_back alot 1";
  for (int i = 1; i < 2333; ++i) {
    s->push_back(i);
    f->push_back(i);
    cmp_vectors(s, f, test0 + test1);
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

int main() {

  // {
  // 	std::vector<int> vec(30, 10);
  //     std::vector<int>::const_iterator it;
  //     std::cout << "Printing vector using a constant iterator" << std::endl;
  //     for(it = vec.begin(); it != vec.end(); ++it) {
  //         std::cout << *it << "\n";
  //     }
  //     return 0;
  // }

  try {
    std::string test0 = "Deafult constructor: ";
    std::vector<int> stda;
    ft::vector<int> fta;

    repetative_talk(&stda, &fta, test0);

    stda.push_back(50);
    fta.push_back(50);
    stda.push_back(50);
    fta.push_back(50);
    stda.push_back(50);
    fta.push_back(50);
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

	test0 = "iteraotr constructor";
	  std::vector<int> stda_temp;
	  ft::vector<int> fta_temp;
	  for (int i = 0; i < 100; ++i) {
		  stda_temp.push_back(i);
		  fta_temp.push_back(i);
	  }
	  std::vector<int>::iterator it = stda_temp.begin();
	  ft::vector<int>::iterator it2 = fta_temp.begin();
	  it += 5;
	  it2 += 5;
	  std::vector<int> std_itr(it, it + 13);
	  ft::vector<int> fta_itr(it2, it2 + 13);
	  repetative_talk(&std_itr, &fta_itr, test0);

	  // test0 = "invalid constructor";
	  // std::vector<int> std_itr1(it, it+1000);
	  // ft::vector<int> fta_itr1(it2, it2+1000);
	  // repetative_talk(&std_itr1, &fta_itr1, test0);
	  
    std::cout << "done\n";
  } catch (std::runtime_error &e) {
    std::cout << "Error: " << e.what() << std::endl;
  } catch (std::exception &e) {
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