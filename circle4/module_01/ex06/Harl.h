
#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	void	complain(string level);
	Harl();
	~Harl();
};

Harl::Harl()
{
}

Harl::~Harl()
{
}


#endif