#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <exception>
#include <iterator>
# include <type_traits>
#include <map>
#include "map_utils.hpp"

namespace ft
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{

		typedef Key									key_type;
		typedef T									mapped_type;
		typedef std::pair<const Key, T>				value_type;
		typedef Compare								key_compare;	
		typedef Allocator							allocator_type;
		typedef typename Allocator::reference       reference;
    	typedef typename Allocator::const_reference const_reference;
    	typedef typename Allocator::pointer         pointer;
    	typedef typename Allocator::const_pointer   const_pointer;
    	typedef typename Allocator::size_type       size_type;
    	typedef typename Allocator::difference_type difference_type;
		
		// iterator	LegacyBidirectionalIterator to value_type
		// const_iterator	LegacyBidirectionalIterator to const value_type
		// reverse_iterator	std::reverse_iterator<iterator>
		// const_reverse_iterator	std::reverse_iterator<const_iterator>
		class value_compare: public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			protected:
				key_compare comp;

				value_compare(key_compare c): comp(c){}
			public:
				bool operator()(const value_type& x, const value_type& y) const{
					return (comp(x.first, y.first));
				}
		};
		
		struct node
		{
			value_type	value;
			node		*left;
			node		*right;
		};
		
	};
}
#endif