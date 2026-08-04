#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < MAX_MATRIA; i++)
		this->materia[i] = NULL;
	this->idx = 0;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MAX_MATRIA; i++)
	{
		if (this->materia[i] != NULL)
			delete this->materia[i];
	}
}

void        MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;

    for (int i = 0; i < MAX_MATRIA; i++)
    {
        if (this->materia[i] == NULL)
        {
            this->materia[i] = m->clone();
            return ;
        }
    }
}

AMateria    *MateriaSource::createMateria(std::string const & type) const
{
    for (int i = 0; i < MAX_MATRIA; i++)
    {
        if (this->materia[i] && this->materia[i]->getType() == type)
           return(this->materia[i]->clone());
    }
    return (0);
}
