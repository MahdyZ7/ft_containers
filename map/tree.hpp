/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:27:31 by ayassin           #+#    #+#             */
/*   Updated: 2023/06/12 09:45:21 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

namespace ft
{
	// template <class Tp, class Compare, class Allocator>
	// class tree
	// {
		struct tree_node
		{
			typedef tree_node* node_ptr;
			typedef const tree_node* const_node_ptr;
			
			node_ptr	parent;
			node_ptr	left;
			node_ptr	right;
			// Tp			value;

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

		 template<class Val>
	     struct AVL_tree_node: public tree_node
	     {
	       typedef AVL_tree_node<Val>* link;
	       Val content;
	     };

		template<class Key, class Val,
		class Compare, class Alloc = std::allocator<Val> >
     	class Avl_tree
		{
			typedef typename Alloc::template rebind<AVL_tree_node<Val> >::other
	               Node_allocator;
	
	    	protected:
	      		typedef tree_node*			node_ptr;
	    		typedef const tree_node*	const_node_ptr;
	    		typedef AVL_tree_node<Val>	Avl_node;
	
	     public:
	       typedef Key					key_type;
	       typedef Val					value_type;
	       typedef value_type*			pointer;
	       typedef const value_type*	const_pointer;
	       typedef value_type&			reference;
	       typedef const value_type&	const_reference;
	       typedef Avl_node*			avl_node_ptr;
	       typedef const Avl_node* 		const_avl_node_ptr;
	       typedef size_t 				size_type;
	       typedef ptrdiff_t			difference_type;
	       typedef Alloc 				allocator_type;
		};

		
		
		
	// };
}
#endif