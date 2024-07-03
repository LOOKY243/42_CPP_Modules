#include "Base.hpp"

Base::Base()
{
}

Base::Base(std::string str)
{
    (void)str;
}

Base::Base(const Base &other)
{
    (void)other;
}

Base &Base::operator=(Base &other)
{
    return other;
}

Base::~Base()
{
}

Base *Base::generate()
{
    std::srand(std::time(0));
    unsigned int randNum = std::rand() % 3;

    switch (randNum)
    {
        case 0:
            return new ClassA();
            break;
        case 1:
            return new ClassB();
            break;
        default:
            return new ClassC;
    }
}

void Base::identify(Base* p)
{
    if (dynamic_cast<ClassA*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<ClassB*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<ClassC*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Couldn't identify" << std::endl;
}

void Base::identify(Base& p)
{
    if (dynamic_cast<ClassA*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<ClassB*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<ClassC*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Couldn't identify" << std::endl;
}