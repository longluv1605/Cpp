// sqrt.cpp: self implementation of sqrt
#include <iostream>
#include <cassert>

// compute the positive square root of a
// input: a double a
// outout: a positive double as square root
double mySqrt(double a, double eps=1e-6);

int main()
{
    double b = 100000;
    std::cout << mySqrt(b) << std::endl;
    std::cout << "address(b) = " << (&b) << std::endl;
    return 0;
}

double mySqrt(double a, double eps)
{
    std::cout << "address(a) = " << (&a) << std::endl;

    assert(a >= 0);
    if (a == 0) return 0;
    double x = 1;
    while (true) {
        double new_x = 0.5*(x + a/x);
        std::cout << new_x << std::endl;
        if (x-new_x < eps && new_x-x < eps) break;
        x = new_x;
    }
    return x;
}