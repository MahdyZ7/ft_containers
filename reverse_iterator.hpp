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

			typedef typename T::value_type tmp_type;
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::random_access_iterator_tag iterator_category;
	
	    reverse_iterator(T p = NULL) : ptr(p){}

		template <typename iter>
		reverse_iterator(const reverse_iterator<iter> & it): ptr(it.base()){};
	    // reverse_iterator(const T & it) : ptr(it.ptr){}
			// reverse_iterator (pointer p, difference_type n) : ptr(p + n){}
			
		reverse_iterator &operator=(const T &other) {ptr = other.ptr; return *this;}
			
	    reverse_iterator & operator++() {
	       --ptr;
	       return *this;
	    }
	
	    reverse_iterator operator++(int) {
	       reverse_iterator copy(*this);
	       operator++();
	       return copy;
	    }
	
	    reverse_iterator & operator--() {
	       ++ptr;
	       return *this;
	    }
	
	    reverse_iterator operator--(int) {
	       reverse_iterator copy(*this);
	       operator--();
	       return copy;
	    }
	
	    bool operator==(const reverse_iterator & rhs) const {
	       return ptr == rhs.ptr;
	    }
	
	    bool operator!=(const reverse_iterator & rhs) const {
			return !(*this == rhs);
	    }
	
	    bool operator<(const reverse_iterator & rhs) const {
	       return ptr > rhs.ptr;
	    }
	
	    bool operator<=(const reverse_iterator & rhs) const {
	       return ptr >= rhs.ptr;
	    }
	
	    bool operator>(const reverse_iterator & rhs) const {
	       return ptr < rhs.ptr;
	    }
	
	    bool operator>=(const reverse_iterator & rhs) const {
	       return ptr <= rhs.ptr;
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
	
	    // value_type *operator->() const {
	    tmp_type *operator->() const {
			// return &(*(operator*()));
			T tmp = ptr;
			--tmp; 
			return ((tmp).operator->());
	    }
	
	    typename T::reference operator[](difference_type k) const {
	    	return *(ptr - k - 1);
	    }

		T base() const{
			return ptr;
		}
	
	   };

	   template <class T>
		reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& it)
		{
			return (reverse_iterator<T>(it + n));
		}

		template <class T>
		reverse_iterator<T> operator-(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& it)
		{
			return (reverse_iterator<T>(it - n));
		}

		template <class T, class T1>
		bool operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<T1>& rhs)
		{
			return (lhs.base() != rhs.base());
		}

		template <class T, class T1>
		bool operator==(const reverse_iterator<T>& lhs, const reverse_iterator<T1>& rhs)
		{
			return (lhs.base() == rhs.base());
		}

		template <class T, class T1>
		bool operator<(const reverse_iterator<T>& lhs, const reverse_iterator<T1>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

		template <class T, class T1>
		bool operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<T1>& rhs)
		{
			return (lhs.base() >= rhs.base());
		}

		template <class T, class T1>
		bool operator>(const reverse_iterator<T>& lhs, const reverse_iterator<T1>& rhs)
		{
			return (lhs.base() < rhs.base());
		}

		template <class T, class T1>
		bool operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<T1>& rhs)
		{
			return (lhs.base() <= rhs.base());
		}		
}
#endif