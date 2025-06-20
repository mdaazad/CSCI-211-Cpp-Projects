// Md Azad
// CSCI 211 Lab
// Numerical Integration Using Function Pointers and the Midpoint Riemann Sum Method

#include <iostream>
#include <cmath>  // For using mathematical functions like sqrt()
using namespace std;

// Define a function pointer type (alias) for functions that take a double and return a double
typedef double (*FUNC)(double);

/**
 * Function: integrate
 * -------------------
 * Numerically integrates a given function `f` over the interval [a, b]
 * using the Midpoint Riemann Sum method and a fixed step size (dx = 0.0001).
 *
 * Parameters:
 *  - f: a pointer to a function matching FUNC type (e.g., line, square, etc.)
 *  - a: lower bound of integration
 *  - b: upper bound of integration
 *
 * Returns:
 *  - Approximate value of the definite integral of f(x) from a to b
 */
double integrate(FUNC f, double a, double b) {
    double sum = 0.0;
    double dx = 0.0001;  // Step size — smaller step improves accuracy but increases runtime

    // Loop over the interval using midpoint sampling
    for (double x = a + dx / 2; x < b; x += dx) {
        sum += f(x) * dx;  // Approximate the area of each small rectangle and accumulate
    }

    return sum;
}

// Below are sample mathematical functions to be used with the integration function

// Linear function: f(x) = x
double line(double x) {
    return x;
}

// Quadratic function: f(x) = x^2
double square(double x) {
    return x * x;
}

// Cubic function: f(x) = x^3
double cube(double x) {
    return x * x * x;
}

// Square root function: f(x) = √x
double root(double x) {
    return sqrt(x);  // Uses standard library function sqrt() from <cmath>
}

/**
 * Function: main
 * --------------
 * Demonstrates numerical integration on different mathematical functions
 * over the interval [5, 9], and prints the results to the console.
 */
int main() {
    // Each call integrates a specific function over the interval [5, 9]
    cout << "The integration of f(x) = x between 5 and 9 is: "        << integrate(line, 5, 9) << endl;
    cout << "The integration of f(x) = x^2 between 5 and 9 is: "      << integrate(square, 5, 9) << endl;
    cout << "The integration of f(x) = x^3 between 5 and 9 is: "      << integrate(cube, 5, 9) << endl;
    cout << "The integration of f(x) = sqrt(x) between 5 and 9 is: "  << integrate(root, 5, 9) << endl;

    return 0; // Successful execution
}
