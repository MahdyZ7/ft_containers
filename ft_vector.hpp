#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <vector>
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
		size_t		capacity;
		// allocator_traits<allocator_type>	begin;
		// allocator_traits<allocator_type>	end;
		T*			data;
		T*			p_begin;
		T*			p_end;
		T*			p_end_of_storage;
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

		// capacity
		size_t size() const {return m_size;}
		bool empty() const {return (size() == 0);} //begin() == end()
		size_t max_size() const {return (std::distance(p_begin(), p_end()));} // capacity to be tested
		// void reserve(allocator_type::size_type new_cap);
		
		//modifiers
		void	push_back(const T &val)
		{
			if (capacity == 0)
			{
				//resurve(++capacity);
			}
			else if (m_size == capacity)
			{
				// resurve (capacity * 2)
				// capacity <<= 2;
				// realocate double the capacity
			}
			myallocator.construct(data + m_size, val);
			// data[size++] = val;
		}


		void	resize(size_t n, T val = T())
		{
			while (m_size <  n)
				(void) pop_back();
			while (n < m_size)
				push_back(val);

		}

		void	pop_back()
		{
			myallocator.destroy(data + --m_size);
		}

		void	reserve(size_t n)
		{
			ft::vector<T>	temp(10);
			for (typename T::iterator it = p_begin; it != p_end; ++it)
				temp.push_back(*it);
			std::swap(temp);
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
		capacity = 0;
		m_size = 0;
		
		myallocator.allocate(0);
		// begin = NULL;
		// end = NULL;
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc)
	{
		p_begin = nullptr;
		p_end = nullptr;
		p_end_of_storage = nullptr;
		capacity = 0;
		m_size = 0;
		
		myallocator = alloc;
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
		if (this != &x)
			return this;
		for (typename T::iterator it = x.p_begin; it != p_end; ++it)
			push_back(*it);
		
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{
		for (int i = 0; i < m_size; ++i)
		{
			myallocator.destroy(data + i);
		}
		myallocator.deallocate(data, capacity);
	}

}

	

#endif