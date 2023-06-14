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

		private:
			typedef typename allocator_type::template rebind<tree_node<value_type> >::other
	               Node_allocator;
	      	typedef tree_node<value_type>*  node_ptr;
	    	typedef const tree_node<value_type>* const_node_ptr;
			
			Node_allocator node_allocator;
			node_ptr _root;
		   	size_type _size;
			size_type _hight;
		
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

			node_ptr create_node(const value_type& x)
			{
				node_ptr tmp = node_allocator.allocate(1);
				tmp->content = x;
				return tmp;
			}
			
			void destroy_node(node_ptr x)
			{
				node_allocator.destroy(x);
				node_allocator.deallocate(x, 1);
			}
		// typedef Avl_tree<key_type, value_type, key_compare, Allocator> Avl_type;
		// Avl_type m_tree;

		public:
		
			map(): _root(0), _size(0), _hight(0) {}
			map(const map& other): _root(0), _size(0), _hight(0) {*this = other;}
			// template <class InputIterator>
			// map(InputIterator first, InputIterator last): _root(0), _size(0), _hight(0) {insert(first, last);}
			~map(){}
			// map &operator=(const map& other)
			// {
			// 	if (this != &other)
			// 	{
			// 		clear();
			// 		insert(other.begin(), other.end());
			// 	}
			// 	return *this;
			// }

			// atributes	
			bool empty() const {return _size == 0;}
			size_type size() const {return _size;}
			size_type max_size() const {return node_allocator.max_size();}

			// insert
			// pair<iterator,bool> insert (const value_type& val)
			void insert (const value_type& val)
			{
				node_ptr tmp = _root;
				node_ptr prev = NULL;

				++_size;
				node_ptr new_node = create_node(val);
				if (_root == NULL)
					_root = new_node;
				else
				{
					while (tmp != NULL)
					{
						prev = tmp;
						if (val == tmp->content)
						{
							destroy_node(new_node);
							--_size;
							return ;
						}
						if (val < tmp->content)
							tmp = tmp->left;
						else
							tmp = tmp->right;
					}
				}
				if (val < prev->content)
					prev->left = new_node;
				else
					prev->right = new_node;
				new_node->parent = prev;
			}

			// void insert(const key_type& k, const mapped_type& v)
			// {
			// 	m_tree.insert(k, make_pair<key_type, mapped_type>(k,v));
			// }

			// void print_tree()
			// {
			// 	m_tree.print_tree();
			// }





		
	};
}
#endif