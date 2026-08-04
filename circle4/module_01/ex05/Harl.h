
#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>
using namespace std;

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	Harl(/* args */);
	~Harl();
	void	complain(string level);
};

#endif