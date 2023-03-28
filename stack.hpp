/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:07:05 by ayassin           #+#    #+#             */
/*   Updated: 2023/03/28 10:04:05 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"
// #include <stack>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack{
		protected:
			Container c;
		public:
			stack() : c() {}
			explicit stack(const Container& ctnr) : c(ctnr) {}
			// explicit stack (const Container& ctnr = Container()) : c(ctnr) {}
			bool empty() const {return c.empty();}
			size_t size() const {return c.size();}
			T& top() {return c.back();}
			void push (const T& val) {c.push_back(val);}
			void pop() {c.pop_back();}
			void swap (stack& l){std::swap(c, l.c);} // to be replaced by ft
	};

	
}

#endif