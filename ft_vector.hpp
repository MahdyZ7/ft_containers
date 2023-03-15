#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <exception>
// #include <iterator>

namespace ft
{
	
	template < class T, class Allocator = std::allocator<T> > 
	class vector
	{
	private:
		size_t		m_size;
		size_t		m_capacity;
		// allocator_traits<allocator_type>	begin;
		// allocator_traits<allocator_type>	end;
		T*			data;
		T*			p_begin;
		// T*			p_end;
		// T*			p_end_of_storage;
		Allocator	myallocator;

	public:

		//type defs
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		// typedef implementation-defined						iterator;
		// typedef implementation-defined						const_iterator;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// typedef std::reverse_iterator<iterator>				reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;


		// constructors;
		vector();
		vector (const Allocator& alloc);
		vector (typename std::allocator_traits<Allocator>::size_type n, const T& val,
					const Allocator& alloc);
		template <class InputIterator> vector (InputIterator first,
					InputIterator last, const Allocator& alloc);
		vector (const vector& x);

		// Capacity
		size_t	size() const {return m_size;}
		size_t	max_size() const {return myallocator.max_size();} // to be tested
		size_t	capacity() const {return m_capacity;} // to be tested
		void	resize(size_t n, T val = T())
		{
			while (m_size <  n)
				pop_back();
			int x = 0;
			if (n > m_capacity)
				reserve(n);
			while (n > m_size)
				push_back(val);
		}
		bool	empty() const {return (m_size == 0);}
		void	reserve(size_t new_cap)
		{
			if (new_cap > m_capacity) 
			{
				Allocator temp_allocator;
				T* new_data = temp_allocator.allocate(new_cap);
				for (size_t i = 0; i < m_size; ++i)
				{
					temp_allocator.construct(&new_data[i], data[i]);
					temp_allocator.destroy(&data[i]);
				}
				if (data != nullptr)
					temp_allocator.deallocate(data, m_capacity);
				data = new_data;
				m_capacity = new_cap;
			}
		}
		
		// Element access
		typename allocator_type::reference operator[] (size_t n) { return data[n]; }
		const typename allocator_type::reference operator[] (size_t n) { return data[n]; }
		//modifiers
		void	push_back(const T &val)
		{
			if (m_capacity == 0)
			{
				//resurve(++m_capacity);
			}
			else if (m_size == m_capacity)
			{
				// resurve (m_capacity * 2)
				// m_capacity <<= 2;
				// realocate double the m_capacity
			}
			myallocator.construct(data + m_size, val);
			// data[size++] = val;
		}



		void	pop_back()
		{
			myallocator.destroy(data + --m_size);
		}

		// destructor
		~vector();
	};

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(void)
	{
		p_begin = nullptr;
		// p_end = nullptr;
		// p_end_of_storage = nullptr;
		m_capacity = 0;
		m_size = 0;
		
		myallocator.allocate(0);
		// begin = NULL;
		// end = NULL;
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc)
	{
		p_begin = nullptr;
		// p_end = nullptr;
		// p_end_of_storage = nullptr;
		m_capacity = 0;
		m_size = 0;
		
		myallocator.allocate(alloc);
	}

	template < class T, class Allocator>
	template <class InputIterator> ft::vector<T, Allocator>::vector(InputIterator first,
			InputIterator last, const Allocator& alloc)
	{
		myallocator.allocate(alloc.size());
		for (typename T::iterator it = first; it != last; ++it)
			push_back(*it);
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const vector& x)
	{
		if (this == &x)
			return ;
		reserve(x.size());
		// T*	end_temp = ;
		// for (typename T::iterator it = x.p_begin; it != p_end; ++it)
		// 	push_back(*it);
		
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{
		for (int i = 0; i < m_size; ++i)
		{
			myallocator.destroy(data + i);
		}
		myallocator.deallocate(data, m_capacity);
	}

}

	

#endif