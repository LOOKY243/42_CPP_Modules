#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"

class Character: public ICharacter
{
	struct List {
		AMateria *value;
		List *next;

		List(AMateria *_value)
		{
			value = _value;
			next = NULL;
		}
	};

    private:
        std::string _name;
        AMateria    *_mats[4];
        List *remove;
    public:
        Character();
        Character(std::string _name);
        Character(const Character &other);
        Character &operator=(const Character &other);

        ~Character();

        virtual std::string const &getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int index);
        virtual void use(int idx, ICharacter& target);

};


#endif