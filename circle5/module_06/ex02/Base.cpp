/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:58:25 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/21 16:58:25 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{

}

Base::Base(const Base& s)
{
    *this = s;
}

Base&	Base::operator=(const Base& s)
{
    if (this != &s)
    {

    }
    return (*this);
}

Base*	Base::generate(void)
{
    int roll = std::rand() % 100 + 1;

    if (roll <= 30)
    {
        // 30% chance
        return (new A());
    }
    else if (roll > 30 && roll <= 60)
    {
        return (new B());
    }
    else
    {
        return (new C());
    }
}

void	Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A\n";
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "B\n";
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "C\n";
    }
}

void	Base::identify(Base& p)
{
    try
    {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A\n";
        return ;
    }
    catch(...)
    {
    }
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    }
    catch(...)
    {
    }
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    }
    catch(...)
    {
    }
    
}
