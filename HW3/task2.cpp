#include <iostream>
#include <string>
#include <algorithm>

void find(int *arr, int elem, int N) { //поиск элемента в массиве типа int
    bool flag = false;
    for (int i = 0; i < N ; i++) {
        if(arr[i] == elem) {
            std::cout << "found";
            flag = true;
        }
    }
    if (flag == 0) {
        std::cout << "not found";
    }
}

void find(char *arr, char elem, int N) { //поиск элемента в массиве типа char
    bool flag = false;
    for (int i = 0; i < N ; i++) {
        if(arr[i] == elem) {
            std::cout << "found";
            flag = true;
        }
    }
    if (flag == 0) {
        std::cout << "not found";
    }
}

void find(float *arr, float elem, int N) { //поиск элемента в массиве типа float
    bool flag = false;
    for (int i = 0; i < N ; i++) {
        if(arr[i] == elem) {
            std::cout << "found";
            flag = true;
        }
    }
    if (flag == 0) {
        std::cout << "not found";
    }
}


int main() {
    std::cout<<"Write type of massiv"<<'\n';
    std::string str1;
    std::cin >> str1;
    std::cout<<"How many element?"<<'\n';
    int N;
    std::cin >> N;
    std::cout<<"Enter the elements one at a time"<<'\n';
    

    if (str1 == "int") {  //создаём и заполняем массив типа int
        int massiv[N];
        for (int i = 0; i < N ; i++) {
            std::cin >> massiv[i];
        }
        std::cout<<"Which element should I find?"<<'\n';
        int y;
        std::cin >> y;

        find(massiv, y, N);
    }
    if (str1 == "char") { //создаём и заполняем массив типа char
        char massiv[N];
        for (int i = 0; i < N ; i++) {
            std::cin >> massiv[i];
        }
        std::cout<<"Which element should I find?"<<'\n';
        char y;
        std::cin >> y;

        find(massiv, y, N);
    }
    if (str1 == "float") { //создаём и заполняем массив типа float
        float massiv[N];
        for (int i = 0; i < N ; i++) {
            std::cin >> massiv[i];
        }
        std::cout<<"Which element should I find?"<<'\n';
        float y;
        std::cin >> y;

        find(massiv, y, N);
    }
}