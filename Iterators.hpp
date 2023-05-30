/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:32:24 by ayassin           #+#    #+#             */
/*   Updated: 2023/05/30 12:40:23 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITRATORS_HPP
#define ITRATORS_HPP

#include <iterator>

namespace ft
{
	template <class T>
	class iterator {
	
	   public:
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::random_access_iterator_tag iterator_category;
	private:
	    	pointer ptr;
	
	   public:
	
	      iterator(pointer p = NULL) : ptr(p){}
	      iterator(const iterator & it) : ptr(it.ptr){}
			iterator (pointer p, difference_type n) : ptr(p + n){}
			
			iterator &operator=(const iterator &other) {ptr = other.ptr; return *this;}
			
	      iterator & operator++() {
	         ++ptr;
	         return *this;
	      }
	
	      iterator operator++(int) {
	         iterator copy(*this);
	         operator++();
	         return copy;
	      }
	
	      iterator & operator--() {
	         --ptr;
	         return *this;
	      }
	
	      iterator operator--(int) {
	         iterator copy(*this);
	         operator--();
	         return copy;
	      }
	
	      bool operator==(const iterator & rhs) const {
	         return ptr == rhs.ptr;
	      }
	
	      bool operator!=(const iterator & rhs) const {
	         return !(*this == rhs);
	      }
	
	      bool operator<(const iterator & rhs) const {
	         return ptr < rhs.ptr;
	      }
	
	      bool operator<=(const iterator & rhs) const {
	         return ptr <= rhs.ptr;
	      }
	
	      bool operator>(const iterator & rhs) const {
	         return ptr > rhs.ptr;
	      }
	
	      bool operator>=(const iterator & rhs) const {
	         return ptr >= rhs.ptr;
	      }
	
	      iterator operator+(const difference_type & rhs) const {
	         return iterator(ptr + rhs);
	      }
	
	      iterator operator+=(const difference_type & rhs) {
	         ptr += rhs;
	         return *this;
	      }
	
	      iterator operator-(const difference_type & rhs) const {
	         return iterator(ptr - rhs);
	      }
	
	      iterator operator-=(const difference_type & rhs) {
	         ptr -= rhs;
	         return *this;
	      }
	
	      difference_type operator-(const iterator & rhs) const{
	         return ptr - rhs.ptr;
	      }

		// difference_type operator-(const iterator& other) const { return ptr - other.ptr; }

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
	
	   // iterator begin() const {
	   //    return iterator(this, 0);
	   // }
	
	   // iterator end() const {
	   //    return iterator(this, count);
	   // }
	
}
#endif