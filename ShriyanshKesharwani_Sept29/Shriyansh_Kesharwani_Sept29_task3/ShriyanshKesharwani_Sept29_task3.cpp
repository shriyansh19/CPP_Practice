#include <iostream>

// (a) Function header for exchange
void exchange(double* x, double* y);

// (c) Function header for evaluate
int evaluate(int x, int (*poly)(int));

// A simple polynomial function for testing evaluate
int square(int n) {
    return n * n;
}

int main() {
    // --- Testing exchange ---
    double a = 5.5, b = 9.9;
    std::cout << "Before exchange: a = " << a << ", b = " << b << std::endl;
    exchange(&a, &b);
    std::cout << "After exchange:  a = " << a << ", b = " << b << std::endl;

    // --- Testing evaluate ---
    int num = 4;
    int result = evaluate(num, square);
    std::cout << "evaluate(" << num << ", square) = " << result << std::endl;

    // --- Initializing vowel array ---
    char vowel[6] = "AEIOU";   // Explicit size
    char vowel2[] = "AEIOU";   // Compiler decides size

    std::cout << "vowel = " << vowel << std::endl;
    std::cout << "vowel2 = " << vowel2 << std::endl;

    return 0;
}

// (b) Function definition for exchange
void exchange(double* x, double* y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

// (d) Function definition for evaluate
int evaluate(int x, int (*poly)(int)) {
    return poly(x);
}

