#include <iostream>

template <typename T> T summ(T& fist_elem, T& second_elem) { // Шаблон для сложения (использую для чисел и строк)
    T result = fist_elem + second_elem;
    return result;
}

class Bot {  // Абстрактная фабрика для магических сущностей 
    public:
        int health;
        int shield;
        int mentality;
        virtual void info() = 0;
        
};



class Spell { // Абстрактная фабрика для заклинаний 
    public:
        std::string name;
        int health;
        int protection;
        int damage;
        int mental;
        int level = 2;
        virtual void ability(Bot*) = 0;
        void info()
        {
            std::cout << name;
        }
    friend class Book;
};

class Attack: public Spell {   // заклинание для атаки
    public:
    Attack() {
        name = "Attack";
        damage = 10;
    }
    void ability(Bot* x) {
        x -> health -= damage;
    }
};

class Protect: public Spell {   // заклинание для защиты
    public:
    Protect() {
        name = "Protect";
        protection = 10;
    }
    void ability(Bot* x) {
        x -> shield += protection;
    }
};

class Household: public Spell {    // заклинание для бытовых нужд (ментальное здоровье)   
    public:
    Household() {
        name = "Household";
        mental = 5;
    }
    void ability(Bot* x) {
        x -> mentality += mental;
    }
};

class Unforgivable: public Spell {  // непростительные заклинания (за такое должны банить(будет в проекте))
    public:
    Unforgivable() {
        name = "Unforgivable";
        damage = 1000;
    }
    std::string curse;
    void ability(Bot* x) {
        x -> health -= damage; 
    }
};

class UpSpell: public Spell {   
    Spell* one;
    Spell* two;
    public:
    UpSpell(Spell* frst, Spell* sknd) {   
        one = frst;
        two = sknd;
        name = summ(one -> name, two -> name);
        damage = summ(one -> damage, two -> damage);
    }
    void ability(Bot* x) {
            one -> ability(x);
            two -> ability(x);
        }
};


class Magic_Book {   
    public:
    std::string name;
    int pages;
    Spell** m_spells; 
    int array_length;
    Magic_Book(std::string n, Spell** sp, int s) {
        name = n;
        m_spells = sp;
        array_length = s;

    }
    void info() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Mike Tyson spells: \n";
        for(int i = 0; i < array_length; i++) {
            m_spells[i] -> info();
            std::cout << "\n";
        }

    }

    void upgrade(Spell* one, Spell* two) {
        m_spells[array_length] = new UpSpell(one, two);
        array_length += 1;
    }

};
class Wizard: public Bot {   
    public:
    std::string name;
    int level;  
    Wizard(std::string n, int l, int h, int p, int mh) {
        name = n;
        level = l;
        health = h;
        shield = p;
        mentality = mh;
    }
    void info() {       
            std::cout<< "Name: " << name << '\n';
            std::cout<< "Health: " << health << '\n';
            std::cout<< "Shield: " << shield << '\n';
            std::cout<< "Mentality: " << mentality << '\n';

    }
    void use(Magic_Book* book, int num, Bot* t) {
        if(book -> m_spells[num] -> level <= level) { // проверка на уровень
        book -> m_spells[num] -> ability(t);
        }
        else {
            throw(1); // второе исключение
        }
    }
};




main() {
    Wizard wiz = Wizard("Mike Tyson", 3, 99, 50, 35); // Создал "колдуна"
    Wizard test_object = Wizard("Punching bag", 0, 100, 100, 100); // Создал объект для опытов

    std::cout << "How many spells of the great and mighty Mike Tyson do you know? \n";    
    int number_of_spells;
    std::cin >> number_of_spells;
    Spell** list_of_spells {new Spell*[number_of_spells]};
    std::cout << "Write the capital letters of the spells:";
    std::string n;

    try {    // первое исключение     
    for(int i = 0; i < number_of_spells; i++) {
        std::cin>>n;
        if(n == "A") {
            list_of_spells[i] = new Attack();
        }
        else if(n == "P") {
            list_of_spells[i] = new Protect();
        }
        else if(n == "H") {
            list_of_spells[i] = new Household();
        }
        else if(n == "U") {
            list_of_spells[i] = new Unforgivable();
        }
        else
        {
            throw(1); 
        }
    }
    }
    
    catch(...) {
        std::cout << "Incorrect input!!!\n";
    }

    
    std::cout << "\n";
    Magic_Book book = Magic_Book("Volume 1", list_of_spells, number_of_spells);
    book.info();
    std::cout << "\n";
    std::cout << "Create new spell from two\n";
    int num_1;
    int num_2;
    std::cin >> num_1;
    std::cin >> num_2;
    book.upgrade(book.m_spells[num_1 - 1], book.m_spells[num_2 - 1]);
    book.info();

    std::cout << "How many attacks do you want to make???";
    int n_att;
    std::cin >> n_att;
    for(int i = 0; i < n_att; i++) {
        std::cout << "Write the number of the spell you want to try out\n";
        int num;
        std::cin >> num;
        std::cout << "the first move for the punching bag\n";
        try { //второе иключение   
        wiz.use(&book, num - 1, &test_object);
        test_object.use(&book, num - 1, &wiz);
        }
        catch(const int&) {
        std::cout << "Ooooops, the punching bag has a small level, it cannot fight back! \n";
        }
    }

    std::cout << "\n";
           
    test_object.info();
}