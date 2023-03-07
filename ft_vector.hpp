#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
// #include <algorithm>
// #include <exception>
// #include <iterator>

namespace ft
{
	
	template < class T, class Allocator = std::allocator<T> > 
	class vector
	{
	private:
		allocator_type::size_type	size;
		allocator_traits<allocator_type>	begin;
		allocator_traits<allocator_type>	end;
		
	public:
		// constructors;
		vector();
		vector (const Allocator& alloc);
		vector (typename std::allocator_traits<Allocator>::size_type n, const T& val,
					const Allocator& alloc);
		template <class InputIterator> vector (InputIterator first,
					InputIterator last, const Allocator& alloc);
		vector (const vector& x);

		// capacity
		allocator_type::size_type size() const {return size;}
		bool empty() const {return (size == 0);} //begin() == end()
		allocator_type::size_type max_size() const {return (std::distance(begin(), end()));} // to be tested
		// void reserve(allocator_type::size_type new_cap);
		
		// destructor
		~vector();
	};

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(void)
	{
		begin = NULL;	
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc)
	{
		
	}

	template < class T, class Allocator>
	template <class InputIterator> ft::vector<T, Allocator>::vector(InputIterator first,
			InputIterator last, const Allocator& alloc)
	{
		
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const vector& x)
	{
		
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{

	}

}

	

#endif