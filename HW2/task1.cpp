#include <iostream> 
 
int main() { 
    int x, y; 
    std::cin >> x; 
    y = 0; 
    for (int i = 2; i <= x/2 + 1; ++i) { 
        if (x % i == 0) { 
            y = i; 
        } 
    } 
    if (y==0) { 
        std::cout << " The number is simple " << "\n" ; 
    } else { 
        std::cout << y << "\n"; 
    } 
}
