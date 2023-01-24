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
		vector (const Allocator& alloc);
		vector (typename std::allocator_traits<Allocator>::size_type n, const T& val,
			const Allocator& alloc);
		template <class InputIterator> vector (InputIterator first,
			InputIterator last, const Allocator& alloc);
		vector (const vector& x);
		~vector();
	};	
}
	// ft::vector::vector(/* args */)
	// {
	// }
	
	// ft::vector::~vector()
	// {
	// }

#endif