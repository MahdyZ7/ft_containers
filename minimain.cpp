 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:08:16 by ayassin           #+#    #+#             */
/*   Updated: 2023/06/01 20:05:50 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// constructing stacks
#include "vector.hpp"
#include <deque>    // std::deque
#include <iostream> // std::cout
#include <stack>    // std::stack
#include <vector>   // std::vector

// vector main
void print_test(bool x, std::string str) {
  if (x == false)
    throw std::runtime_error("\033[0;31m" + str + " does not match" +
                             "\033[0m");
  // std::cout << "\033[0;32m" << str << ": completed" << "\033[0m" <<
  // std::endl;
}
void stdprint(int id,  std::vector<int>* container)
{
    std::cout << id << ". ";
    for (std::vector<int>::iterator it = container->begin(); it != container->end(); ++it)
        std::cout << *it << ' ';
    std::cout << "capacity: " << container->capacity() << '\n';
}
void ftprint(int id, ft::vector<int>* container)
{
    std::cout << id << ". ";
    for (ft::vector<int>::iterator it = container->begin(); it != container->end(); ++it)
        std::cout << *it << ' ';
    std::cout << "capacity: " << container->capacity() << '\n';
}


int main() {


  try {
	
	{
		std::cout << "helllo\n";
		std::vector<int> c1;
		c1.push_back(10);
		c1.push_back(20);
		c1.push_back(30);
		ft::vector<int> c2;
		c2.push_back(10);
		c2.push_back(20);
		c2.push_back(30);
		// stdprint(1, &c1);
	
		
		{

		ft::vector<int>::reverse_iterator ite_rb = c2.rbegin();
		std::vector<int>::reverse_iterator site_rb = c1.rbegin();
		ft::vector<int>::reverse_iterator ite_rend = c2.rend();
		std::vector<int>::reverse_iterator site_rend = c1.rend();
		
		std::cout << "REVERSE\n";
		std::cout << "base :" << *(ite_rend.base()) << *(site_rend.base()) << std::endl ;
		std::cout << "std: " << (site_rend < site_rb) << std::endl;
		std::cout << "ft: " << (ite_rend < ite_rb) << std::endl;
		std::cout << "base std: " << (site_rend.base() < site_rb.base()) << std::endl;
		std::cout << "base ft: " << (ite_rend.base()  < ite_rb.base() ) << std::endl;
		}

		{
			ft::vector<int>::const_reverse_iterator ite_rb = c2.rbegin();
			std::vector<int>::const_reverse_iterator site_rb = c1.rbegin();
			ft::vector<int>::const_reverse_iterator ite_rend = c2.rend();
			std::vector<int>::const_reverse_iterator site_rend = c1.rend();
			
			std::cout << "CONST REVERSE\n";
			std::cout << "base :" << *(ite_rend.base()) << *(site_rend.base()) << std::endl ;
			std::cout << "std: " << (site_rend < site_rb) << std::endl;
			std::cout << "ft: " << (ite_rend < ite_rb) << std::endl;
			std::cout << "base std: " << (site_rend.base() < site_rb.base()) << std::endl;
			std::cout << "base ft: " << (ite_rend.base()  < ite_rb.base() ) << std::endl;
		}

		{
			ft::vector<int>::const_reverse_iterator cite_rb = c2.rbegin();
			std::vector<int>::const_reverse_iterator csite_rb = c1.rbegin();
			ft::vector<int>::const_reverse_iterator cite_rend = c2.rend();
			std::vector<int>::const_reverse_iterator csite_rend = c1.rend();
			ft::vector<int>::const_reverse_iterator ite_rb = c2.rbegin();
			std::vector<int>::const_reverse_iterator site_rb = c1.rbegin();
			ft::vector<int>::const_reverse_iterator ite_rend = c2.rend();
			std::vector<int>::const_reverse_iterator site_rend = c1.rend();
			
			std::cout << "CONST REVERSE\n";
			std::cout << "base :" << *(ite_rend.base()) << *(site_rend.base()) << std::endl ;
			std::cout << "std: " << (site_rb <= csite_rend) << std::endl;
			std::cout << "ft: " << (ite_rb <= cite_rend) << std::endl;
			std::cout << "base std: " << (site_rend.base() <= csite_rb.base()) << std::endl;
			std::cout << "base ft: " << (ite_rend.base()  <= cite_rb.base() ) << std::endl;
		}




	// 		ft::vector<TESTED_TYPE> vct;
	// ft::vector<TESTED_TYPE>::iterator it = vct.begin();
	// ft::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

	// ft::vector<TESTED_TYPE>::reverse_iterator rit(it);

	// ft::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
	// ft::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
	// ft::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);


		
		return 0;
	}
  } catch (std::runtime_error &e) {
    std::cout << "Error: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}