#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < MAX_MATRIA; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    for (int i = 0; i < MAX_MATRIA; i++)
    {
        if (src.materia[i])
		    this->materia[i] = src.materia[i]->clone();
        else
            this->materia[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
    if (this != &src)
    {
        for (int i = 0; i < MAX_MATRIA; i++)
        {
            delete this->materia[i];
            this->materia[i] = NULL;
            if (src.materia[i])
		        this->materia[i] = src.materia[i]->clone();
            else
                this->materia[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MAX_MATRIA; i++)
    {
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
            this->materia[i] = m;
            return ;
        }
    }
    delete m;
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
