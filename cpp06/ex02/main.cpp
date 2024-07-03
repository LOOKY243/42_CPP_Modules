#include "Base.hpp"

int main()
{
    Base *base1 = new ClassA();
    Base *base2 = new ClassB();
    Base *base3 = new ClassC();
    Base *base = Base::generate();

    base1->identify(base1);
    base1->identify(*base1);
    base2->identify(base2);
    base2->identify(*base2);
    base3->identify(base3);
    base3->identify(*base3);

    std::cout << "\n--------random-----------\n" << std::endl;

    base->identify(base);
    base->identify(*base);
}