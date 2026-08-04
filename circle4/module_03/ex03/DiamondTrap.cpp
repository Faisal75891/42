#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap Created\n";

    this->name = name;
    hp = FragTrap::hp;
    ep = ScavTrap::ep;
    ad = FragTrap::ad;
}

DiamondTrap::DiamondTrap(std::string n) : ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n)
{
    std::cout << "DiamondTrap Created\n";

    this->name = n;
    // name = this->name;
    hp = FragTrap::hp;
    ep = ScavTrap::ep;
    ad = FragTrap::ad;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destroyed\n";
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap Name: " << this->name << std::endl
    << "ClapTrap Name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
