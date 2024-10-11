#include <iostream>
#define N 3 //колличетво книг

struct name_surname { 
    std::string name;
    std::string surname;
};


struct book { //структура книга + функция вывода
    std::string title = "unknown";
    struct name_surname ns {"unknown", "unknown"};
    unsigned year = 0;
    unsigned pages = 0;

    void displayBook() {
        std::cout << "Title : " << title << '\n';
        std::cout << "Autor : " << ns.name << " " << ns.surname << '\n';
        std::cout << "Year : " << year << '\n';
        std::cout << "Pages : " << pages << '\n';
    }
};

struct book create_book(std::string title, std::string name, std::string surname, int year, int pages) { //заполняем инфу о книге
    struct book b1;
    b1.title = title;
    b1.ns.name = name;
    b1.ns.surname = surname;
    b1.year = year;
    b1.pages = pages;
    
    return b1; 
};

int main() {
    struct book library[N]; // массив - библиотека из N книг
    for(int i = 0; i < N; i++) {
        struct book b;
        library[i] = b;
    }

    for(int i = 0; i < N; i++) { // ввод информации о книгах
        std::cout << "Book " << i << ": " << '\n';
        std::cout << '\n';
        std::string t;
        std::string nn;
        std::string sn;
        int y;
        int p;
        std::cout << "enter Title : " << '\n';
        std::cin >> t;
        std::cout << "enter Autor : " << '\n';
        std::cin >> nn >> sn;
        std::cout << "enter Year : " << '\n';
        std::cin >> y;
        std::cout << "enter Pages : " << '\n';
        std::cin >> p;
        struct book bk;
        bk = create_book(t, nn, sn, y, p);
        library[i] = bk;

    }

    std::cout << "Info about library. Total book : " << N+1 << '\n'; //вывод всей информации о библиотеке
    for(int i = 0; i < N; i++) {
        std::cout << "Book : " << i+1 << '\n';
        library[i].displayBook();
        std::cout << '\n';

    }
    

}







