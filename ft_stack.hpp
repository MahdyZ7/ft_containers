/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:07:05 by ayassin           #+#    #+#             */
/*   Updated: 2023/03/10 18:16:54 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

#include <vector>
#include <stack>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack{
		protected:
			Container c;
		public:
			stack() : c() {}
			explicit stack(const Container& ctnr) : c(ctnr) {}
		
	};

	
}

#endif