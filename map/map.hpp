#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <exception>
#include <iterator>
# include <type_traits>

namespace ft
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T>>
	> class map
	{

		typedef Key						key_type;
		typedef T						mapped_type;
		typedef std::pair<const Key, T>	value_type;
		typedef typename size_t			size_type;
		typedef typenamestd::ptrdiff_t 	difference_type;
		typedef Compare					key_compare	
		typedef Allocator				allocator_type	
		typedef	typename value_type&	reference	
		typedef	typename const value_type&	const_reference	
		typedef Allocator::pointer			pointer	 
		typedef	Allocator::const_pointer	const_pointer	 
		
		// iterator	LegacyBidirectionalIterator to value_type
		// const_iterator	LegacyBidirectionalIterator to const value_type
		// reverse_iterator	std::reverse_iterator<iterator>
		// const_reverse_iterator	std::reverse_iterator<const_iterator>
		
		struct node
		{
			value_type	*value;
			node		*left;
			node		*right;
		};
		
	}
}
#endif