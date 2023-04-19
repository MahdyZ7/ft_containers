/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:32:24 by ayassin           #+#    #+#             */
/*   Updated: 2023/03/28 13:35:47 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTITRATORS_HPP
#define CONSTANTITRATORS_HPP

// #include <const_iterator>
#include "vector.hpp"
namespace ft
{
	
	template
<class T>
	class const_iterator {
	
	   public:
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::random_access_iterator_tag iterator_category;
	private:
	    	pointer ptr;
	
	   public:
	
	      const_iterator(pointer p = NULL) : ptr(p){}
	      const_iterator(const const_iterator & it) : ptr(it.ptr){}
			const_iterator (pointer p, difference_type n) : ptr(p + n){}
			
			const_iterator &operator=(const const_iterator &other) {ptr = other.ptr;}
			
	      const_iterator & operator++() {
	         ++ptr;
	         return *this;
	      }
	
	      const_iterator operator++(int) {
	         const_iterator copy(*this);
	         operator++();
	         return copy;
	      }
	
	      const_iterator & operator--() {
	         --ptr;
	         return *this;
	      }
	
	      const_iterator operator--(int) {
	         const_iterator copy(*this);
	         operator--();
	         return copy;
	      }
	
	      bool operator==(const const_iterator & rhs) const {
	         return ptr == rhs.ptr;
	      }
	
	      bool operator!=(const const_iterator & rhs) const {
	         return !(*this == rhs);
	      }
	
	      bool operator<(const const_iterator & rhs) const {
	         return ptr < rhs.ptr;
	      }
	
	      bool operator<=(const const_iterator & rhs) const {
	         return ptr <= rhs.ptr;
	      }
	
	      bool operator>(const const_iterator & rhs) const {
	         return ptr > rhs.ptr;
	      }
	
	      bool operator>=(const const_iterator & rhs) const {
	         return ptr >= rhs.ptr;
	      }
	
	      const_iterator operator+(const difference_type & rhs) const {
	         return const_iterator(ptr + rhs);
	      }
	
	      const_iterator operator+=(const difference_type & rhs) {
	         ptr += rhs;
	         return *this;
	      }
	
	      const_iterator operator-(const difference_type & rhs) const {
	         return const_iterator(ptr - rhs);
	      }
	
	      const_iterator operator-=(const difference_type & rhs) {
	         ptr -= rhs;
	         return *this;
	      }
	
	      difference_type operator-(const const_iterator & rhs) const{
	         return ptr - rhs.ptr;
	      }

		// difference_type operator-(const const_iterator& other) const { return ptr - other.ptr; }

	      reference operator*() const{
	         return (*ptr);
	      }
	
	      value_type *operator->() const {
	         return ptr;
	      }
	
	      reference operator[](difference_type k) const {
	         return *(ptr + k);
	      }
	
	   };
	
	   // const_iterator begin() const {
	   //    return const_iterator(this, 0);
	   // }
	
	   // const_iterator end() const {
	   //    return const_iterator(this, count);
	   // }
	
}
#endif