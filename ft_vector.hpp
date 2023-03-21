#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>
#include <vector>
// #include <algorithm>
#include <exception>
#include <iterator>

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
		T*			m_data;
		// T*			p_begin;
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
		explicit vector (const Allocator& alloc = Allocator());
		explicit vector (size_t n, const T& val = T(), const Allocator& alloc = Allocator());
		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last, const Allocator& alloc = Allocator());
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
				if (m_capacity != 0)
					myallocator.deallocate(m_data, m_capacity);
				m_data = myallocator.allocate(x.capacity);
				for (size_t i; i < x.size; ++i)
					myallocator.construct(m_data + i, x[i]);
			}
			return (this);
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

		// template <class InputIterator>  void assign (InputIterator first, InputIterator last); // to be done later

		void assign (size_t n, const T& val)
		{
			Allocator temp_allocator = myallocator;
			T* new_data = temp_allocator.allocate(n);
			size_t i = 0;
			for (; i < n; ++i)
			{
				myallocator.destroy(m_data + i);
				temp_allocator.construct(new_data + i, val);
			}
			for (; i < m_size; ++i)
				temp_allocator.construct(new_data + i, m_data[i]);
			if (m_data != NULL)
				temp_allocator.deallocate(m_data, m_capacity);
			m_data = new_data;
			m_size = n;
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
		}



		void	pop_back()
		{
			myallocator.destroy(m_data + --m_size);
		}

		void	clear()
		{
			while (m_size)
				myallocator.destroy( m_data + --m_size );
		}

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
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::vector (size_t n, const T& val, const Allocator& alloc)
	{
		m_size = 0;
		m_capacity = n; // to be checked
		myallocator = alloc;
		m_data = myallocator.allocate(m_capacity); // to be checked
		while (m_size < m_capacity)
		{
			myallocator.construct(m_data + m_size, val);
			++m_size;
		}
	}


	// template < class T, class Allocator>
	// template <class InputIterator>
	// 	vector(InputIterator first,
    //         	typename std::enable_if<is_iterator  <InputIterator>::value &&
	// 			std::is_constructible<
    //                                 value_type,
    //                                 typename std::iterator_traits<InputIterator>::reference>::value,
    //                              InputIterator>::type last, const Allocator& alloc = Allocator())
	// template < class T, class Allocator>
	// template <class InputIterator>
	// ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator& alloc)
	// {
	// 	m_capacity = std::distance(first, last); // to be checked
	// 	myallocator = alloc;
	// 	m_data = myallocator.allocate(m_capacity); // to be checked
	// 	for (typename T::iterator it = first; it != last; ++it)
	// 	{
	// 		myallocator.construct(m_data + m_size, *it);
	// 		++m_size;
	// 	}
	// }

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
	}

	template < class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			myallocator.destroy(m_data + i);
		}
		if (m_capacity)
			myallocator.deallocate(m_data, m_capacity);
	}

}

	
//  template <typename U = T>
    // typename std::enable_if<std::is_same<U, T>::value && std::is_same<U&, decltype(*data_)>::value, U&>::type
//     front() {
//         return data_[0];
//     }

    // template <typename U = T>
    // typename std::enable_if<std::is_same<U, T>::value && std::is_same<const U&, decltype(*data_)>::value, const U&>::type
//     front() const {
//         return data_[0];
//     }
#endif