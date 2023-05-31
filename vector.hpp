#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <exception>
#include <iterator>
# include <type_traits>
#include "Iterators.hpp"
#include "reverse_iterator.hpp"
#include "ConstantIterators.hpp"


namespace ft
{
	template < class T, class Allocator = std::allocator<T> > 
	class vector
	{


		public:

		//type defs
		// iterator<T> m_iterator();
		// const_iterator<T> m_const_iterator();
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// typedef implementation-defined						iterator;
		typedef ft::iterator<T>		iterator;
		// typedef ft::iterator<T>		iterator;
		typedef ft::const_iterator<T>		const_iterator;
		// typedef ft::iterator<const T>		const_iterator;

		// typedef std::iterator<const_pointer, vector> const_iterator;
		// typedef implementation-defined						const_iterator;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		size_t		m_size;
		size_t		m_capacity;
		// std::allocator_traits<allocator_type>	m_begin;
		// std::allocator_traits<allocator_type>	m_end;
		T*			m_data;
		T*			m_begin;
		T*			m_end;
		// T*			p_end_of_storage;
		Allocator	myallocator;

	public:

		// //type defs
		// typedef T											value_type;
		// typedef Allocator									allocator_type;
		// typedef typename allocator_type::reference			reference;
		// typedef typename allocator_type::const_reference	const_reference;
		// // typedef implementation-defined						iterator;
		// typedef std::iterator<std::random_access_iterator_tag ,value_type>		iterator;
		// typedef std::iterator<std::random_access_iterator_tag, const value_type> const_iterator;
		// // typedef implementation-defined						const_iterator;
		// typedef typename allocator_type::size_type			size_type;
		// typedef typename allocator_type::difference_type	difference_type;
		// typedef typename allocator_type::pointer			pointer;
		// typedef typename allocator_type::const_pointer		const_pointer;
		// typedef std::reverse_iterator<iterator>				reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;


		// constructors;
		explicit vector (const Allocator& alloc = Allocator());
		explicit vector (size_t n, const T& val = T(), const Allocator& alloc = Allocator());
  template <class InputIterator>
		vector (InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename std::enable_if<std::is_base_of<std::input_iterator_tag,
                                                  typename std::iterator_traits<InputIterator>::iterator_category>::value>::type* = 0);
		vector (const vector& x);
		// template <class InputIterator>
		// vector(InputIterator first,
        //     	typename std::enable_if<is_iterator   <InputIterator>::value &&
		// 		std::is_constructible<
        //                             value_type,
        //                             typename std::iterator_traits<InputIterator>::reference>::value,
        //                          InputIterator>::type last, const Allocator& alloc = Allocator());

		// template<typename InputIterator, typename = typename std::enable_if<is_iterator<InputIterator>::value>::type>
		// std::vector<typename std::iterator_traits<InputIterator>::value_type> make_vector(InputIterator first, InputIterator last) {
		// 	return std::vector<typename std::iterator_traits<InputIterator>::value_type>(first, last);
		// }

		// template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
		// std::vector<T> make_vector(size_t n, const T& val = T()) {
		// 	return std::vector<T>(n, val);
		// }

		// = operator
		vector& operator= (const vector& x)
		{
			if (this != &x)
			{
				clear();
				if (m_capacity < x.m_capacity)
				{
					myallocator.deallocate(m_data, m_capacity);
					m_data = myallocator.allocate(x.m_capacity);
					m_capacity = x.m_capacity;
				}
				for (size_t i = 0; i < x.m_size; ++i)
				{
					myallocator.construct(m_data + i, x[i]);
					++m_size;
				}
			}
			return (*this);
		}

		// Iterators
		iterator begin()
		{
			// return m_data;std::iterator<T, Allocator>(m_data, 0);
			return iterator(m_data);
		}
		const_iterator begin() const
		{
			return const_iterator (m_data); 
		}
		iterator end()
		{
			return iterator(m_data, m_size);
		}
		const_iterator end() const
		{
			return const_iterator(m_data, m_size); 
		}

// Iterators
		reverse_iterator rbegin()
		{
			return reverse_iterator((end()));
		}
		const_iterator rbegin() const
		{
			return const_iterator (end()); 
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_iterator rend() const
		{
			return const_iterator(begin()); 
		}

		// Capacity
		size_t	size() const {return m_size;}
		size_t	max_size() const {return myallocator.max_size();} // to be tested
		size_t	capacity() const {return m_capacity;} // to be tested
		void	resize(size_t n, T val = T())
		{
			while (m_size >  n)
				pop_back();
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
				Allocator temp_allocator = myallocator;
				T* new_data = temp_allocator.allocate(new_cap);
				for (size_t i = 0; i < m_size; ++i)
				{
					temp_allocator.construct(&new_data[i], m_data[i]);
					temp_allocator.destroy(&m_data[i]);
				}
				if (m_data != NULL)
					temp_allocator.deallocate(m_data, m_capacity);
				m_data = new_data;
				m_capacity = new_cap;
			}
		}
		
		// Element access
			// []
		reference operator[] (size_t n) { return m_data[n]; }
			// [] const
	const_reference operator[] (size_t n) const { return m_data[n]; }
		
			// at
		reference at (size_t n)
		{
			if (n >= m_size)
				throw std::out_of_range("vector");
			return (m_data[n]);
		}
			// at const
		const_reference at (size_t n) const
		{
			if (n >= m_size)
				throw std::out_of_range("vector");
			return (m_data[n]);
		}
		
			// front
		reference front() { return m_data[0]; }
			// front const
		const_reference front() const { return m_data[0]; }
			// back
		
		reference back() { return m_data[m_size - 1]; }
			// back const
		const_reference back() const { return m_data[m_size - 1]; }
			// data
		
		reference data() { return m_data; };
			// data const
		const_reference data() const { return m_data;} ;
		
		
		//modifiers

		// template <class InputIterator>
		template <class InputIterator>
		typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type
		assign (InputIterator first, InputIterator last)
		{
			size_t n = last - first;
			if (n <= m_capacity)
			{
				for (size_t i = 0; i < n; ++i)
				{
					if ( i < m_size)
						myallocator.destroy(m_data + i);
					myallocator.construct(m_data + i, *first);
					++first;
				}
				m_size = n;
			}
			else
			{
				Allocator temp_allocator = myallocator;
				T* new_data = temp_allocator.allocate(n);
				for (size_t i = 0; i < n; ++i)
				{
					if (i < m_size)
						myallocator.destroy(m_data + i);
					temp_allocator.construct(new_data + i, *first);
					++first;
				}
				if (m_data != NULL)
					myallocator.deallocate(m_data, m_capacity);
				m_data = new_data;
				m_size = n;
				m_capacity = n;
			}
		}

		void assign (size_t n, const T& val)
		{
			if (n <= m_capacity)
			{
				for (size_t i = 0; i < n; ++i)
				{
					if ( i < m_size)
						myallocator.destroy(m_data + i);
					myallocator.construct(m_data + i, val);
				}
				m_size = n;
			}
			else
			{
				Allocator temp_allocator = myallocator;
				T* new_data = temp_allocator.allocate(n);
				for (size_t i = 0; i < n; ++i)
				{
					if (i < m_size)
						myallocator.destroy(m_data + i);
					temp_allocator.construct(new_data + i, val);
				}
				if (m_data != NULL)
					myallocator.deallocate(m_data, m_capacity);
				m_data = new_data;
				m_size = n;
				m_capacity = n;
			}
		}

		void	push_back(const T &val)
		{
			if (m_capacity == 0)
			{
				reserve(1);
			}
			else if (m_size == m_capacity)
			{
				reserve (m_capacity << 1);
				// m_capacity <<= 1;
				// realocate double the m_capacity
			}
			myallocator.construct(m_data + m_size, val);
			++m_size;
			// 
		}



		void	pop_back()
		{
			myallocator.destroy(m_data + --m_size);
		}

		iterator insert (iterator position, const value_type& val)
		{
			T temp_add = val, temp_destroy;
			typename iterator::difference_type n = std::distance(begin(), position);

			if (position >= end())
			{
				push_back(val);
				return (--end());
			}
			temp_add = *position;
			myallocator.destroy(&(*position));
			myallocator.construct(&(*position), val);
			for (iterator it = position + 1; it < end(); ++it)
			{
				temp_destroy = *it;
				myallocator.destroy(&*it);
				myallocator.construct(&*it, temp_add);
				temp_add = temp_destroy;
			}
			push_back(temp_add);
			return begin() + n;
		}

		iterator insert (iterator position, size_type n, const value_type& val)
		{
			typename iterator::difference_type diff = std::distance(begin(), position);
			if (n == 0)
				return position; // check for position > end()
			if ( m_size + n > m_capacity)
			{
				Allocator temp_allocator = myallocator;
				size_t new_capacity =  m_capacity * 2 > m_size + n ? m_capacity * 2 : m_size + n;
				T* new_data;
				new_data = temp_allocator.allocate(new_capacity);
				for (typename iterator::difference_type i = 0; i < diff; ++i)
				{
					temp_allocator.construct(&new_data[i], m_data[i]);
					temp_allocator.destroy(&m_data[i]);
				}
				for (size_t i = 0; i < n; ++i)
					temp_allocator.construct(&new_data[diff + i], val);
				for (size_t i = diff; i < m_size; ++i)
				{
					temp_allocator.construct(&new_data[i + n], m_data[i]);
					temp_allocator.destroy(&m_data[i]);
				}
				if (m_data != NULL)
					temp_allocator.deallocate(m_data, m_capacity);
				m_data = new_data;
				m_capacity = new_capacity;
				m_size = m_size + n;
				return (begin() + diff);
			}
			if (position >= end())
			{
				for (size_t i = 0; i < n; ++i)
					push_back(val);
				return (--end());
			}
			for (iterator it = --end(); it >= position; --it)
			{
				myallocator.construct(&(*(it + n)), *it);
				myallocator.destroy(&(*it));
			}
			for (size_t i = 0; i < n; ++i)
				myallocator.construct(&(*(position + i)), val);
			m_size += n;
			return (begin() + diff);
		}

		// iterator std::enable_if<!std::is_integral<InputIterator>::value, iterator>::type 
		template <class InputIterator>
		typename std::enable_if<!std::is_integral<InputIterator>::value, iterator>::type
		insert (iterator position, InputIterator first, InputIterator last)
		{
			if (first == last)
				return position;
			typename iterator::difference_type diff = std::distance(begin(), position);
			size_t n = last - first; //std::distance(first, last);
			if ( m_size + n > m_capacity)
			{
				Allocator temp_allocator = myallocator;
				size_t new_capacity =  m_capacity * 2 > m_size + n ?  m_capacity * 2 : m_size + n;
				T* new_data;
				new_data = temp_allocator.allocate(new_capacity);
				for (typename iterator::difference_type i = 0; i < diff; ++i)
				{
					temp_allocator.construct(&new_data[i], m_data[i]);
					temp_allocator.destroy(&m_data[i]);
				}
				for (size_t i = 0; i < n; ++i)
				{
					temp_allocator.construct(&new_data[diff + i], *first);
					++first;
				}
				for (size_t i = diff; i < m_size; ++i)
				{
					temp_allocator.construct(&new_data[i + n], m_data[i]);
					temp_allocator.destroy(&m_data[i]);
				}
				if (m_data != NULL)
					temp_allocator.deallocate(m_data, m_capacity);
				m_data = new_data;
				m_capacity = new_capacity;
				m_size = m_size + n;
				return (begin() + diff);
			}
			if (position >= end())
			{
				for (size_t i = 0; i < n; ++i)
				{
					push_back(*first);
					++first;
				}
				return (--end());
			}
			for (iterator it = --end(); it >= position; --it)
			{
				myallocator.construct(&(*(it + n)), *it);
				myallocator.destroy(&(*it));
			}
			for (size_t i = 0; i < n; ++i)
			{
				myallocator.construct(&(*(position + i)), *first);
				++first;
			}
			m_size += n;
			return (begin() + diff);
		}
		
		void	clear()
		{
			while (m_size)
				myallocator.destroy( m_data + --m_size );
			
		}

		// swap
		// void	swap(vector& other)
		// {
		// 	vector temp = *this;
		// 	*this = other;
		// 	other = temp;
		// }
		// destructor
		~vector();
	};

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc)
	{
		// p_begin = nullptr;
		// p_end = nullptr;
		// p_end_of_storage = nullptr;
		m_capacity = 0;
		m_size = 0;
		myallocator = alloc;
		m_data = myallocator.allocate(0);
		m_begin = m_data;
		m_end = m_data + m_size + 1;
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector (size_t n, const T& val, const Allocator& alloc)
	{
		m_size = 0;
		m_capacity = n; // to be checked
		myallocator = alloc;
		// if (m_capacity)
		m_data = myallocator.allocate(m_capacity); // to be checked
		while (m_size < m_capacity)
		{
			myallocator.construct(m_data + m_size, val);
			++m_size;
		}
		m_begin = m_data;
		m_end = m_data + m_size + 1;
	}


	template < class T, class Allocator>
	template <class InputIterator>
	ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator& alloc, typename std::enable_if<std::is_base_of<std::input_iterator_tag,
                                                  typename std::iterator_traits<InputIterator>::iterator_category>::value>::type*)
	{
		m_capacity = last - first; // to be checked
		myallocator = alloc;
		m_size = 0;
		m_data = myallocator.allocate(m_capacity); // to be checked
		for (iterator it = first; it != last; ++it)
		{
			myallocator.construct(m_data + m_size, *it);
			++m_size;
		}
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector(const vector& x)
	{
		if (this == &x)
			return ;
		m_size = 0;
		m_capacity = x.m_size;
		m_data = myallocator.allocate(m_capacity);
		while (m_size < x.m_size)
		{
			myallocator.construct(m_data + m_size, x.m_data[m_size]);
			++m_size;
		}
		m_begin = m_data;
		m_end = m_data + m_size + 1;
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{
		for (size_t i = 0; i < m_size; ++i)
			myallocator.destroy(m_data + i);
		myallocator.deallocate(m_data, m_capacity);
	}

}

#endif