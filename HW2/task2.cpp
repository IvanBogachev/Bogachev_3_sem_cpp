#include <iostream> 
 
int main() { 
    int sum = 0; 
    int x; 
    while (std::cin >> x) { 
        if (x > 0) { 
            sum += x; 
            std::cout << "sum = " << sum << "\n";     
        }  
        else if (x == 0) { 
            break; 
        } 
    } 
 
}