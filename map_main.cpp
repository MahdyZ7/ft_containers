# include "map/map.hpp"
# include <map>
# include "map/pair.hpp"


int main()
{
	std::map<int, int> m;
	// ft::map<int, int> ft_m;
	m[1] = 1;
	m[2] = 2;
	m[3] = 3;
	std::pair<const int, int> x(1,1);
	std::pair<const int, int> y(2,2);
	x = y;
	// ft_m.insert(ft::make_pair(x,1));

	// ft_m.insert(ft::make_pair(2,2));
	// ft_m.insert(ft::make_pair(3,3));
	// ft_m.print_tree();

	std::cout<< "welcome to here\n";
	


}