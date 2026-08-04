#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie() {}
		~Zombie() { cout << name << ": lil bro died :(\n"; }
		void	announce(void)
		{
			std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; 
		}
		std::string	getName( void ) const { return name ;}
		void	setName( const string &n)
		{
			name = n;
		}
};
