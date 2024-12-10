#include <iostream>
#include <cstdlib>  // Для функции rand() и srand() - это для рандомного числа
#include <ctime>    // Для функции time()- это для рандомного числа
#include <fstream> // Для работы с файлами



template <typename T> T summ(T& fist_elem, T& second_elem) { // Шаблон для сложения (использую для чисел и строк)
    T result = fist_elem + second_elem;
    return result;
}

class Bot {  // Абстрактная фабрика для магических сущностей 
    public:
        int health;
        int shield;
        virtual void info() = 0;
        
};



class Spell { // Абстрактная фабрика для заклинаний 
    public:
        std::string name;
        int health;
        int protection;
        int damage;
        int level;
        virtual void ability(Bot* x, Bot* y) = 0;
        void info()
        {
            std::cout << name;
        }
    friend class Book;
};

class Attack_1_lvl: public Spell {   // заклинание для атаки 1 уровень
    public:
    Attack_1_lvl() {
        name = "Attack_1_lvl";
        level = 1;
        damage = 20;
    }
    void ability(Bot* x, Bot* y) { //сначала снимаем щит, потом здоровье
        if(x -> shield > 0) 
        {
        x -> shield -= damage;
            if(x -> shield <= 0) 
            {
                x -> shield = 0;
            }
        } else {
            x -> health -= damage;
            if(x -> health < 0)
            {
              x -> health = 0;  
            }
        }

    }
};

class Attack_2_lvl: public Spell {   // заклинание для атаки 2 уровень
    public:
    Attack_2_lvl() {
        name = "Attack_2_lvl";
        level = 2;
        damage = 40;
    }
    void ability(Bot* x, Bot* y) { //сначала снимаем щит, потом здоровье
        if(x -> shield > 0) 
        {
        x -> shield -= damage;
            if(x -> shield <= 0) 
            {
                x -> shield = 0;
            }
        } else {
            x -> health -= damage;
            if(x -> health < 0)
            {
              x -> health = 0;  
            }
        }

    }
};
class Attack_3_lvl: public Spell {   // заклинание для атаки 3 уровень
    public:
    Attack_3_lvl() {
        name = "Attack_3_lvl";
        level = 3;
        damage = 60;
    }
    void ability(Bot* x, Bot* y) { //сначала снимаем щит, потом здоровье
        if(x -> shield > 0) 
        {
        x -> shield -= damage;
            if(x -> shield <= 0) 
            {
                x -> shield = 0;
            }
        } else {
            x -> health -= damage;
            if(x -> health < 0)
            {
              x -> health = 0;  
            }
        }

    }
};
class Protect: public Spell {   // заклинание для защиты ... прибавляет себе щит и отбирает у чужого
    public:
    Protect() {
        name = "Protect";
        level = 2;
        protection = 20;
    }
    void ability(Bot* x, Bot* y) {
        x -> shield -= protection;
        y -> shield += protection;
        if(x -> shield <= 0) {
            x -> shield = 0;
        }

        if(y -> shield <= 0) {
            y -> shield = 0;

        }
    }
};

class Unforgivable: public Spell {  // непростительные заклинания 
    public:
    Unforgivable() {
        name = "Unforgivable";
        level = 10;
        damage = 1000;
    }
    std::string curse;
    void ability(Bot* x, Bot* y) {
        x -> health = 0; // точное убийство 
        y -> health = 0;// ну, раз убил этой имбой, изволь умереть сам XD
    }
};

class Orks_attack_lvl_1: public Spell {   // заклинание для атаки 2 уровень
    public:
    Orks_attack_lvl_1() {
        name = "Orks_attack_lvl_1";
        level = 1;
        damage = 20;
    }
    void ability(Bot* x, Bot* y) { //сначала снимаем щит, потом здоровье
        if(x -> shield > 0) 
        {
        x -> shield -= damage;
            if(x -> shield <= 0) 
            {
                x -> shield = 0;
            }
        } else {
            x -> health -= damage;
            if(x -> health < 0)
            {
              x -> health = 0;  
            }
        }

    }
};

class Orks_attack_lvl_2: public Spell {   // заклинание для атаки 2 уровень
    public:
    Orks_attack_lvl_2() {
        name = "Orks_attack_lvl_2";
        level = 2;
        damage = 60;
    }
    void ability(Bot* x, Bot* y) { //сначала снимаем щит, потом здоровье
        if(x -> shield > 0) 
        {
        x -> shield -= damage;
            if(x -> shield <= 0) 
            {
                x -> shield = 0;
            }
        } else {
            x -> health -= damage;
            if(x -> health < 0)
            {
              x -> health = 0;  
            }
        }

    }
};

class Orks_attack_lvl_3: public Spell {   // заклинание для атаки 2 уровень
    public:
    Orks_attack_lvl_3() {
        name = "Orks_attack_lvl_3";
        level = 3;
        damage = 80;
    }
    void ability(Bot* x, Bot* y) { //сначала снимаем щит, потом здоровье
        if(x -> shield > 0) 
        {
        x -> shield -= damage;
            if(x -> shield <= 0) 
            {
                x -> shield = 0;
            }
        } else {
            x -> health -= damage;
            if(x -> health < 0)
            {
              x -> health = 0;  
            }
        }

    }
};


class Magic_Book {   // Почему тут нет в наследниках (сверху) спеллов?
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

};




class Wizard: public Bot {   
    public:
    std::string name;
    int level;  
    Wizard(std::string n, int l, int h, int p) {
        name = n;
        level = l;
        health = h;
        shield = p;
    }
    void info() {       
            std::cout<< "Name: " << name << '\n';
            std::cout<< "Health: " << health << '\n';
            std::cout<< "Shield: " << shield << '\n';

    }
    
};




class Squad {   
    public:
    std::string name;
    int fighters;
    Wizard** m_bots;
    int array_length;
    Squad(std::string n, Wizard** bt, int s) {
        name = n;
        m_bots = bt;
        array_length = s;

    }
    
    void info() {
        std::cout << "Squad name: " << name << "\n";
        for(int i = 0; i < array_length; i++) {
            m_bots[i] -> info();
            std::cout << "\n";            
        }
        

    }

    void use_mag(Magic_Book* book_mag, Magic_Book* book_ork, int num, Squad* squad_mag, Squad* squad_ork, int n_att, int n_def) {
        if((book_mag -> m_spells[num] -> level) <= (squad_mag -> m_bots[n_att] -> level) ) { // проверка на уровень
        book_mag -> m_spells[num] -> ability(squad_ork -> m_bots[n_def], squad_mag -> m_bots[n_att]);
        }
        else {
            throw(1); // второе исключение
        }
    }

    void use_ork(Magic_Book* book_mag, Magic_Book* book_ork, int num, Squad* squad_mag, Squad* squad_ork, int n_att, int n_def) {
        if((book_ork -> m_spells[num] -> level) <= (squad_ork -> m_bots[n_att] -> level) ) { // проверка на уровень
        book_ork -> m_spells[num] -> ability(squad_mag -> m_bots[n_def], squad_ork -> m_bots[n_att]);
        }
        else {
            throw(1); // второе исключение
        }
    }
    void duel(Magic_Book* book_mag, Magic_Book* book_ork, Squad* squad_mag, Squad* squad_ork, int n_att_1, int n_att_2) {
        int mark;
        int flag = 0;
        while(squad_ork -> m_bots[n_att_2] -> health > 0 and squad_mag -> m_bots[n_att_1] -> health > 0) {
        int randomNumber;
        if (flag < 1) {
            // Инициализация генератора случайных чисел    с помощью рандомного числа определю кто ходит первым
            std::srand(static_cast<unsigned int>(std::time(0)));
            // Генерация случайного числа 0 или 1
            randomNumber = std::rand() % 2;} 
        // если вначале выпал 0, то ходин первый, иначе второй
        if((randomNumber % 2) == 0){ // ход мага
            std::cout << " Magician's Move, write down which spell you want to use \n";
            int n_spell;
            std::cin >> n_spell;
            try {
            use_mag(book_mag, book_ork, n_spell, squad_mag, squad_ork, n_att_1, n_att_2);
            }
            catch(const int&) {
            std::cout << "!!!   The first magician has a low level, the attack did not pass   !!!! \n";
        }
        }
        else { //ход орка
            std::cout << "Orc's Move, write down which spell you want to use \n";
            int n_spell;
            std::cin >> n_spell;
            try {
            use_ork(book_mag, book_ork, n_spell, squad_mag, squad_ork, n_att_2, n_att_1);
            }
            catch(const int&) {
            std::cout << "!!!   The ork has a low level, the attack did not pass   !!!! \n";
            }
        }
        squad_mag -> m_bots[n_att_1] -> info();
        squad_ork -> m_bots[n_att_2] -> info();

        randomNumber += 1;
        flag += 1;
        }
    

        if(squad_mag -> m_bots[n_att_1] -> health >0) {
        std:: cout << "The mag win!!!! \n";
        }
        else {
        std:: cout << "The ork win!!!! \n";

        }
        
    }

};


main() {
    std::string line;
    int dannye[5];
 
    std::ifstream in("Homework/HW8_project/dannye.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        
        for(int i = 0; i < 6; i++){
            std::getline(in, line);
            dannye[i] = stoi(line);
        }
    }

    in.close(); 
    // Создаю армию визардов
    std::cout << "How many wizards do you want to create? \n";    
    int number_of_bots = dannye[0];
    //std::cin >> number_of_bots; // если бы вводил ручками
    std::cout << dannye[0] << "\n";
    

    Wizard** list_of_bots {new Wizard*[number_of_bots]}; //массив магов      
    for(int i = 0; i < number_of_bots; i++) {
        int n_level = dannye[i+1];
        std::cout << "Enter the level of the " << i+1 <<" magician \n";
        //std::cin >> n_level;
        std::cout << dannye[i+1] << "\n";

        std::string numberStr = std::to_string(i+1);
        std::string name = "wizard " + numberStr;
        list_of_bots[i] = new Wizard(name, n_level, 50*n_level, 25*n_level);
    }

    Squad squad = Squad("Army 1",list_of_bots, number_of_bots);
    squad.info();
    
    std::cout << "\n";

    Spell** list_of_spells {new Spell*[5]};
    list_of_spells[0] = new Attack_1_lvl();
    list_of_spells[1] = new Attack_2_lvl();
    list_of_spells[2] = new Attack_3_lvl();
    list_of_spells[3] = new Protect();
    list_of_spells[4] = new Unforgivable();

    Magic_Book book = Magic_Book("Volume 1", list_of_spells, 5);
    book.info();


    // Создаю армию орков


    std::cout << "How many orks do you want to create? \n";    
    int number_of_bots_orks = dannye[3];
    //std::cin >> number_of_bots_orks;
    std::cout << dannye[3] << "\n";

    Wizard** list_of_bots_orks {new Wizard*[number_of_bots_orks]}; //массив орков     
    for(int i = 0; i < number_of_bots_orks; i++) {
        int n_level = dannye[4+i];
        std::string name;
        std::cout << "Enter the level of the " << i+1 <<" Orks (1,2 or 3) \n";
        //std::cin >> n_level;
        std::cout << dannye[4+1] << "\n";
        if(n_level == 1){
            name = "Small boy";    
        }
        else if(n_level == 2){
            name = "Middle boy";    
        }
        else {
            name = "Big boy";
            n_level = 3;

        }
        
        list_of_bots_orks[i] = new Wizard(name, n_level, 150*n_level, 100*n_level);
    }

    Squad squad_orks = Squad("Army 2", list_of_bots_orks, number_of_bots_orks);
    squad_orks.info();

    std::cout << "\n";

    Spell** list_of_spells_orks {new Spell*[3]};
    list_of_spells_orks[0] = new Orks_attack_lvl_1();
    list_of_spells_orks[1] = new Orks_attack_lvl_2();
    list_of_spells_orks[2] = new Orks_attack_lvl_3();


    Magic_Book book_orks = Magic_Book("Volume 2", list_of_spells_orks, 3);
    book_orks.info();
    //И настанет час войны между магами и орками за право знанять аудиторию в ГК.....
    int mag_summ_hp;
    int ork_summ_hp;
    do {
    mag_summ_hp = 0;
    ork_summ_hp = 0;    
    std::cout << "mag fighter's number \n";
    int n_att_1;
    std::cin >> n_att_1;
    if(list_of_bots[n_att_1] -> health <= 0) {
        std::cout << "Sorry, this magician is dead, choose another one \n";
        std::cin >> n_att_1;        
    }
        
    std::cout << "ork fighter's number \n";
    int n_att_2;
    std::cin >> n_att_2;
    if(list_of_bots_orks[n_att_2] -> health <= 0) {
        std::cout << "Sorry, this ork is dead, choose another one \n";
        std::cin >> n_att_2;        
    }

    squad.duel(&book, &book_orks, &squad, &squad_orks, n_att_1, n_att_2);

    for(int i = 0; i < number_of_bots; i++) {
        mag_summ_hp += list_of_bots[i] -> health;
    }
    std::cout << "summ mag hp :" << mag_summ_hp << "\n";

    for(int i = 0; i < number_of_bots_orks; i++) {
        ork_summ_hp += list_of_bots_orks[i] -> health;
    }
    std::cout << "summ ork hp :" << ork_summ_hp << "\n";
    }

    while(mag_summ_hp > 0 and ork_summ_hp > 0);
    squad.info();
    squad_orks.info();
    if(mag_summ_hp > 0){
        std::cout << "The army of magicians has won!!! \n";
        int alive;
        for(int i = 0; i < number_of_bots; i++) {
            if(list_of_bots[i] -> health > 0){
                alive += 1;
            }
        }
    }

     else {
        std::cout << "The army of orcs has won!!! \n";
        int alive_52;
        for(int i = 0; i < number_of_bots; i++) {
            if(list_of_bots[i] -> health > 0){
                alive_52 += 1;
            }
        }

    }    
}