#include "Fixed.hpp"

int main( void )
{
	Fixed a(10);
	Fixed b(10.5f);
	Fixed const c(5);
	Fixed const d(4.5f);

	if (c > a)
		b = a;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
    std::cout << d << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << "a " << "+ " << "c = " << a + c << std::endl;
	std::cout << "a " << "* " << "c = " << a * c << std::endl;
	std::cout << "a " << "- " << "c = " << a - c << std::endl;
	std::cout << "a " << "/ " << "c = " << a / c << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;


	std::cout << "-----------------------------" << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;
    std::cout << Fixed::max( b, d ) << std::endl;

	return 0;
}

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }