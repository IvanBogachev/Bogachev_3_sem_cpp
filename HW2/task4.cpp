#include <iostream>
#include <string>

int main() {
    std::string str1;
    getline(std::cin, str1);

    std::string str2;
    getline(std::cin, str2);
    int l_str2 = str2.size();

    int pos3 = str1.find(str2);
    
    int counter = 0;

    while (pos3 != std::string::npos){
        counter += 1;
        str1.erase(0, pos3 + l_str2);
        pos3 = str1.find(str2);

    }

    std::cout << counter << "\n";
 }