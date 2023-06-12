#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <exception>
// #include <iterator>
# include <type_traits>
#include <map>
#include "map_utils.hpp"
#include "pair.hpp"
#include "tree.hpp"

namespace ft
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<pair<const Key, T> >
	> class map
	{

		typedef Key									key_type;
		typedef T									mapped_type;
		typedef ft::pair<const Key, T>				value_type;
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
		class value_compare
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
		
		private:

		typedef Avl_tree<key_type, value_type, key_compare, Allocator> Avl_type;
		Avl_type m_tree;

		public:
		
			map()
			{
				
			}

			// map(const Compare& comp, const Allocator& alloc = Allocator()): 
			// {

			// }

			// template <class InputIterator>
			// map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
			// {

			// }

			// map( const map& other )
			// {

			// }

			~map(){}




		
	};
}
#endif