#include <iostream>
#define N 3 //колличество животных

class Animal {
public:
    virtual void makeSound() = 0; // ЧИСТО виртуальная функция
   

};

class Cat: public Animal {
private:
    std::string name;
    int age;
    std::string breed; // порода
    int health;

public:
    void makeSound() { //определяю ЧИСТО виртуальную функцию
        std::cout << "Meow" << "\n";      
    }

    Cat(std::string name1, int age1, std::string breed1){
            name  = name1;
            age = age1;
            breed = breed1;
            health = 80;
    }
     
    Cat() {
        name = "Cat";
        age = 100;
        breed = "street";
        health = 10;
    }

    void info() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Breed: " << breed << "\n";
        std::cout << "\n";
    }

    void hp()
    {
        std::cout << "Health:" << health << "\n";
    }
    friend class Vet;
};

class Dog: public Animal {
private:
    std::string name;
    int age;
    std::string breed; // порода
    int health;

public:
    void makeSound() { //определяю ЧИСТО виртуальную функцию
        std::cout << "Woof" << "\n";      
    }

    Dog(std::string name1, int age1, std::string breed1){
            name  = name1;
            age = age1;
            breed = breed1;
            health = 90;
    }
     
    Dog() {
        name = "Bobik";
        age = 100;
        breed = "street";
        health = 20;
    }

    void info() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Breed: " << breed << "\n";
        std::cout << "\n";
    }

    void hp()
    {
        std::cout << "Health:" << health << "\n";
    }

    friend class Vet;

};

struct Name_surname {
    std::string name = "N/A";
    std::string surname = "N/A";
};

class Owner{
private:
    struct Name_surname ns;
    int age;
public:
    Cat cat1;
    Cat cat2;
    Dog dog;
    Owner(std::string name1, std::string surname1, int age1, Cat kisa1, Cat kisa2, Dog pesik) 
    {
            ns = Name_surname{name1, surname1};
            age = age1;
            this -> cat1 = kisa1; //ассоциация (агрегация)
            this -> cat2 = kisa2; //ассоциация (агрегация)
            this -> dog = pesik; //ассоциация (агрегация)            
        }

            
    void show_info_Owner_and_animals() 
    {
        std::cout << "Owner name and surname : " << ns.name << " " << ns.surname << '\n';
        std::cout << "Owner age: " << age << "\n";
        std::cout << "Number of animals: " << N << "\n";
        std::cout << "\n";
        std::cout << "First animal: " << "\n";
        cat1.info();
        std::cout << "Second animal: " << "\n";
        cat2.info();
        std::cout << "Third animal: " << "\n";
        dog.info();
    }
    friend class Vet;
};

class Vet {   
private: 
    Name_surname ns;
public:
    Vet(std::string Name, std::string Surname) {
        ns = Name_surname{Name, Surname};
    }

    void healing(Cat* cat) { //функция от указателя на класс Cat
        cat -> health += 15;// cat-указатель, поэтому стрелка (применяю метод не к самому cat, а к тому, на что он указывает)
    }
    void healing(Dog* dog) {
        dog -> health += 10;
    }
    void speaking(Owner owner1) {
        std::cout << "Hi, " << owner1.ns.name << " " << owner1.ns.surname << " I cured your pet!" << "\n";
    }

};

int main() {
    std::cout << "Enter name, surname and age of owner " << "\n";
    std::string name11;
    std::string name22;
    int age;
    std::cin >> name11;
    std::cin >> name22;
    std::cin >> age;
    std::cout << "\n";

    std::cout << "Enter name, age and breed of 1-st animal " << "\n";
    std::string name111;
    int age111;
    std::string breed111;
    std::cin >> name111;
    std::cin >> age111;
    std::cin >> breed111;
    std::cout << "\n";

    std::cout << "Enter name, age and breed of 3-th animal " << "\n";
    std::string name333;
    int age333;
    std::string breed333;
    std::cin >> name333;
    std::cin >> age333;
    std::cin >> breed333;
    std::cout << "\n";

    Cat cat11;
    cat11 = Cat(name111, age111, breed111);
    Cat cat22;
    cat22 = Cat();
    Dog dog0;
    dog0 = Dog(name333, age333, breed333);
    Owner owner1 = Owner(name11, name22, age, cat11, cat22, dog0);
    owner1.show_info_Owner_and_animals();

    Vet vet = Vet("Vova", "Adidas");
    vet.healing(&owner1.cat2); // в скобках ссылка на второго кота хозяина
    vet.speaking(owner1);
    owner1.cat2.hp();

    vet.healing(&owner1.dog);
    owner1.dog.hp();

}    