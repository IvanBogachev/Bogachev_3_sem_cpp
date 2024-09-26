#include <iostream>

int main() {
    int sum = 0;
    int x;
    std::cin >> x;
    int* numbers = new int[x];
    for (int i = 0; i <= x - 1; ++i) {
        *(numbers + i) = i * i;
    }

    for (int i = 0; i < x; ++i) {
        sum += numbers[i];
        
    }
    std::cout << sum << "\n";
    delete[] numbers;


}