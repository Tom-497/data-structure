#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num;
    std::cout << "Enter an integer (enter 0 to exit):" << std::endl;
    while (true) {
        std::cout << "> ";
        std::cin >> num;
        if (num == 0) {
            std::cout << "Exiting." << std::endl;
            break;
        }
        if (isPrime(num))
            std::cout << num << " is prime." << std::endl;
        else
            std::cout << num << " is not prime." << std::endl;
    }
    return 0;
}