#include <iostream>
#define DYNAMIC_MEMORY 1
#define size 5

void filling(int *x) {
    for(int i = 0; i < size; ++i) {
        x[i] = i;
        std::cout << x[i] << '\n';
    }
}

int main() {

#if DYNAMIC_MEMORY == 0
    int* massiv_d = new int[size];
    int* m_d = massiv_d;
    filling(m_d);
    std::cout << "dynamic array" << '\n';

    delete[] massiv_d;
#else
    int massiv_s[size];
    int* m_s = massiv_s;
    filling(m_s);
    std::cout << "static array" << '\n';
#endif //DYNAMIC_MEMORY

}