#ifndef REVERSE_ITRATORS_HPP
#define REVERSE_ITRATORS_HPP

// #include <iterator>
#include "Iterators.hpp"

namespace ft
{
	template <class T>
	class reverse_iterator{

		private:
	    	T ptr;
	
	   public:

			typedef T value_type; 
			typedef std::ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::random_access_iterator_tag iterator_category;
	
	      reverse_iterator(T p = NULL) : ptr(p){
			  // if (ptr != NULL)
				 //  --ptr;
		  }
	      // reverse_iterator(const T & it) : ptr(it.ptr){}
			// reverse_iterator (pointer p, difference_type n) : ptr(p + n){}
			
			reverse_iterator &operator=(const T &other) {ptr = other.ptr;}
			
	      reverse_iterator & operator++() {
	         --ptr;
	         return *this;
	      }
	
	      reverse_iterator operator++(int) {
	         reverse_iterator copy(*this);
	         operator--();
	         return copy;
	      }
	
	      reverse_iterator & operator--() {
	         ++ptr;
	         return *this;
	      }
	
	      reverse_iterator operator--(int) {
	         reverse_iterator copy(*this);
	         operator++();
	         return copy;
	      }
	
	      bool operator==(const reverse_iterator & rhs) const {
	         return ptr == rhs.ptr;
	      }
	
	      bool operator!=(const reverse_iterator & rhs) const {
			return !(*this == rhs);
	      }
	
	      bool operator<(const reverse_iterator & rhs) const {
	         return ptr < rhs.ptr;
	      }
	
	      bool operator<=(const reverse_iterator & rhs) const {
	         return ptr <= rhs.ptr;
	      }
	
	      bool operator>(const reverse_iterator & rhs) const {
	         return ptr > rhs.ptr;
	      }
	
	      bool operator>=(const reverse_iterator & rhs) const {
	         return ptr >= rhs.ptr;
	      }
	
	      reverse_iterator operator+(const difference_type & rhs) const {
	         return reverse_iterator(ptr - rhs);
	      }
	
	      reverse_iterator operator+=(const difference_type & rhs) {
	         ptr -= rhs;
	         return *this;
	      }
	
	      reverse_iterator operator-(const difference_type & rhs) const {
	         return reverse_iterator(ptr + rhs);
	      }
	
	      reverse_iterator operator-=(const difference_type & rhs) {
	         ptr += rhs;
	         return *this;
	      }
	
	      difference_type operator-(const reverse_iterator & rhs) const{
	         return rhs.ptr - ptr;
	      }

		// difference_type operator-(const iterator& other) const { return ptr - other.ptr; }

	      typename T::reference operator*() const{
	         return (*(ptr - 1));
	      }
	
	      value_type *operator->() const {
	         return ptr;
	      }
	
	      typename T::reference operator[](difference_type k) const {
	         return *(ptr - k);
	      }

			T base(){
				return ptr;
			}
	
	   };
}
#endif