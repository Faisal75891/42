
#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MAX_MATRIA 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *materia[MAX_MATRIA];
        int         idx;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource& operator=(const MateriaSource& src);
        ~MateriaSource();
        void        learnMateria(AMateria*);
        AMateria    *createMateria(std::string const & type) const;
};
