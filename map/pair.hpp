#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>
#include <stdexcept>


namespace ft
{
	template <class T1, class T2>
	class pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		public: // should be private
			first_type	first;
			second_type	second;

		public:
		pair(): first(), second(){}
		pair(const first_type& a, const second_type& b): first(a), second(b){}
		template< class U1, class U2 >
		pair( const ft::pair<U1, U2>& p ): first(p.first), second(p.second){}
		
		pair& operator=(const pair<T1, T2>& p){
			if (this != &p)
			{
				first = p.first;
				second = p.second;
				// pair<T1, T2> tmp(p);
				std::cout<< "here\n";
				// std::swap(*this, tmp);
				// std::swap(this->first, tmp.first);
				// std::swap(this->second, tmp.second);
				// first = std::move(p.first);
		    	// second = std::move(p.second);
			}
			return (*this);
		}
		~pair(){}
	};
	
	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return (ft::pair<T1, T2>(t, u));
	}

	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator< ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (rhs.first == lhs.first && lhs.second < rhs.second)); //doubt
	}

	template< class T1, class T2 >
	bool operator<= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator> ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>= ( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (!(lhs < rhs));
	}

}

#endif