/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:27:31 by ayassin           #+#    #+#             */
/*   Updated: 2023/06/10 19:50:54 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

namespace ft
{
	template <class Tp, class Compare, class Allocator>
	class tree
	{
		struct tree_node
		{
			typedef tree_node* node_ptr;
			typedef const tree_node* const_node_ptr;
			
			node_ptr	parent;
			node_ptr	left;
			node_ptr	right;
			Tp			value;

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

		
		
		
	};
}
#endif