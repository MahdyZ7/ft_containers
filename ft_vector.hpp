#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>

namespace ft
{
	
	template < class T, class Allocator = std::allocator<T> > 
	class vector
	{
	private:
		
	public:
		// constructors;
		vector();
		vector (const Allocator& alloc);
		vector (typename std::allocator_traits<Allocator>::size_type n, const T& val,
			const Allocator& alloc);
		template <class InputIterator> vector (InputIterator first,
			InputIterator last, const Allocator& alloc);
		vector (const vector& x);
		~vector();
	};

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(void)
	{
		
	}

	template < class T, class Allocator>
	vector<T, Allocator>::vector(void)
	{
		
	}
}

	
	// ft::vector::~vector()
	// {

	// }

#endif