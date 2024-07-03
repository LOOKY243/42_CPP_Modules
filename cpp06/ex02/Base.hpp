#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    private:
        
    public:
        Base();
        Base(std::string str);
        Base(const Base &other);
        Base &operator=(Base &other);

        virtual ~Base();

        static Base *generate();
        void identify(Base* p);
        void identify(Base& p);
};

class ClassA: public Base {};
class ClassB: public Base {};
class ClassC: public Base {};

#endif