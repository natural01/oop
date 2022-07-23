#include <iostream>
#include "Rational.cpp"

int main()
{
    CRational p;
    std::cin >> p;
    std::cout << p;
    system("pause");
    CRational n(3, 2);
    n+=p;
    if (2 != n)
    {
        system("pause");
    }
    std::cout << n;
    system("pause");
    p += 5;
    std::cout << p;
    system("pause");
    std::cin >> p;
    p += n;
    std::cout << p;
    system("pause");
    return 0;
}