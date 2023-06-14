# include "map/map.hpp"
# include <map>

int main()
{
	std::map<int, int> m;
	ft::map<int, int> ft_m;
	m[1] = 1;
	m[2] = 2;
	m[3] = 3;
	ft_m.insert(1,1);
	ft_m.insert(2,2);
	ft_m.insert(3,3);
	ft_m.print_tree();

	std::cout<< "welcome to here\n";
	


}