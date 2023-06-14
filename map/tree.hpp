/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:27:31 by ayassin           #+#    #+#             */
/*   Updated: 2023/06/14 14:53:54 by ayassin          ###   ########.fr       */
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
	    	Val			content;
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

		template<class Key, class Val,
		class Compare, class Alloc = std::allocator<Val> >
     	class Avl_tree
		{
			typedef typename Alloc::template rebind<tree_node<Val> >::other
	               Node_allocator;
	
	    	protected:
	      		typedef tree_node<Val>*  node_ptr;
	    		typedef const tree_node<Val>* const_node_ptr;
				Node_allocator node_allocator; 
	
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

		  
			
			void insert(const key_type& k, const value_type& v)
			{
				node_ptr tmp = _root;
				node_ptr prev = NULL;
				++_size;
				node_ptr new_node = create_node(v);
				if (_root == NULL)
					_root = new_node;
				else
				{
					while (tmp != NULL)
					{
						prev = tmp;
						if (k == tmp->content.first)
						{
							destroy_node(new_node);
							--_size;
							return ;
						}
						if (Compare(k, tmp->content.first))
							tmp = tmp->left;
						else
							tmp = tmp->right;
					}
				}
				if (Compare(k, prev->content.first))
					prev->left = new_node;
				else
					prev->right = new_node;
				new_node->parent = prev;
			}

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
		   

		   size_type size() const { return _size; }
		   bool empty() const { return _size == 0; }
		   
		   void print_tree()
		   {
			std::cout<< "life is not fair\n";
		   }

		   void printTree(node_ptr root, std::string indent, bool last) {
			if (root != nullptr)
			{
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "     ";
				} else {
					std::cout << "L----";
					indent += "|    ";
				}
				std::cout << root->data << std::endl;
				printTree(root->left, indent, false);
				printTree(root->right, indent, true);
			}
}

				
				
		};

		
		
		
	// };
}
#endif