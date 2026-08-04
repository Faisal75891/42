
#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(/* args */);
		virtual	~Brain();
		// Add copy and assignment constructors???
		// NAH
		const	std::string	getIdea(size_t i) const;
		void	setIdea(size_t i, std::string idea);
		void	getIdeas() const;
};

#endif