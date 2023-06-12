/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:27:31 by ayassin           #+#    #+#             */
/*   Updated: 2023/06/12 18:21:48 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

namespace ft
{
	// template <class Tp, class Compare, class Allocator>
	// class tree
	// {
		template<class Val>
		struct tree_node
		{
			typedef tree_node<Val>*			node_ptr;
			typedef const tree_node<Val>*	const_node_ptr;
			
			node_ptr	parent;
			node_ptr	left;
			node_ptr	right;
	    	Val 		content;
			// Tp			value;

			tree_node(): parent(0), left(0), right(0) {}
			tree_node(const Val& x): parent(0), left(0), right(0), content(x) {}
			tree_node(const Val& x, node_ptr p): parent(p), left(0), right(0), content(x) {}
			tree_node(const Val& x, node_ptr p, node_ptr l, node_ptr r): parent(p), left(l), right(r), content(x) {}
			tree_node(const tree_node& x): parent(x.parent), left(x.left), right(x.right), content(x.content) {}
			~tree_node() {}
			tree_node& operator=(const tree_node& x)
			{
				if (this != &x)
				{
					parent = x.parent;
					left = x.left;
					right = x.right;
					content = x.content;
				}
				return *this;
			}

			// node_ptr create_node(const Val& x)
			// {
			// 	node_ptr tmp = node_allocator.allocate(1);
			// 	construct(&tmp->content, x);
			// 	return tmp;
			// }

			static node_ptr Minimum(node_ptr x)
			{
				while (x->left != 0) x = x->left;
				return x;
			}
	
			static const_node_ptr Minimum(const_node_ptr x)
			{
				while (x->left != 0) x = x->left;
				return x;
			}
	
			static node_ptr Maximum(node_ptr x)
			{
				while (x->right != 0) x = x->right;
				return x;
			}
	
			static const_node_ptr Maximum(const_node_ptr x)
			{
				while (x->right != 0) x = x->right;
				return x;
			}
		};

		 
	    //  struct AVL_tree_node: public tree_node
	    //  {
	    //    typedef AVL_tree_node<Val>* link;
	    //    Val content;
	    //  };

		template<class Key, class Val,
		class Compare, class Alloc = std::allocator<Val> >
     	class Avl_tree
		{
			typedef typename Alloc::template rebind<tree_node<Val> >::other
	               Node_allocator;
	
	    	protected:
	      		typedef tree_node<Val>*  node_ptr;
	    		typedef const tree_node<Val>* const_node_ptr;
	
	     public:
	       typedef Key					key_type;
	       typedef Val					value_type;
	       typedef value_type*			pointer;
	       typedef const value_type*	const_pointer;
	       typedef value_type&			reference;
	       typedef const value_type&	const_reference;
	       typedef size_t 				size_type;
	       typedef ptrdiff_t			difference_type;
	       typedef Alloc 				allocator_type;

		   node_ptr _root;
		   size_type _size;

		   Avl_tree(): _root(0), _size(0) {}
		   ~Avl_tree() { clear(); }
		   Avl_tree(const Avl_tree& x) { *this = x; }

		//    void insert(const value_type& x)
		//    {
		// 		node_ptr parent = _root;
		// 		node_ptr z = create_node(x);
		//    		Avl_tree& operator=(const Avl_tree& x)
				
		//    {
		// 		if (this != &x)
		// 		{
		// 			clear();
		// 			if (x._root != 0)
		// 			{
		// 				_size = x._size;
		// 				_root = copy(x._root, x._root->parent);
		// 				_root->parent = 0;
		// 			}
		// 		}
		// 		return *this;
		//    }

		   void clear()
		   {
				if (_root != 0)
				{
					erase(_root);
					_root = 0;
					_size = 0;
				}
		   }

		   void erase(node_ptr x)
		   {
				if (x != 0)
				{
					erase(x->left);
					erase(x->right);
					destroy_node(x);
				}
		   }

		   void destroy_node(node_ptr x)
		   {
				destroy(&x->content);
				// _node_allocator.deallocate(x, 1);
		   }

		   void destroy(value_type* x)
		   {
				(void) x;
				// _alloc.destroy(x);
		   }
		   
		   

		   size_type size() const { return _size; }
		   bool empty() const { return _size == 0; }

				
				
		};

		
		
		
	// };
}
#endif