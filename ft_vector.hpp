#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
// #include <algorithm>
// #include <exception>
// #include <iterator>

namespace ft
{
	
	template < class T, class Allocator = std::allocator<T> > 
	class vector
	{
	private:
		size_t	p_size;
		// allocator_traits<allocator_type>	begin;
		// allocator_traits<allocator_type>	end;
		T*									p_begin;
		T*									p_end;
		T*									p_end_of_storage;
		Allocator 							m_alloc;

	public:
		// constructors;
		vector();
		vector (const Allocator& alloc);
		vector (typename std::allocator_traits<Allocator>::size_type n, const T& val,
					const Allocator& alloc);
		template <class InputIterator> vector (InputIterator first,
					InputIterator last, const Allocator& alloc);
		vector (const vector& x);

		// capacity
		size_t size() const {return p_size;}
		bool empty() const {return (size() == 0);} //begin() == end()
		size_t max_size() const {return (std::distance(p_begin(), p_end()));} // to be tested
		// void reserve(allocator_type::size_type new_cap);
		
		//modifiers
		void	push_back(const T &val)
		{
			if (size == size)
			;
		}
		// destructor
		~vector();
	};

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(void)
	{
		p_begin = nullptr;
		p_end = nullptr;
		p_end_of_storage = nullptr;
		// begin = NULL;
		// end = NULL;
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc)
	{
		
	}

	template < class T, class Allocator>
	template <class InputIterator> ft::vector<T, Allocator>::vector(InputIterator first,
			InputIterator last, const Allocator& alloc)
	{
		
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const vector& x)
	{
		
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{

	}

}

	

#endif