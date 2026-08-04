
#pragma once

#include "IMateriaSource.hpp"
#include "Materia.hpp"

#define MAX_MATRIA 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *materia[MAX_MATRIA];
        int         idx;
    public:
        MateriaSource();
        ~MateriaSource();
        void        learnMateria(AMateria*);
        AMateria    *createMateria(std::string const & type) const;
};
