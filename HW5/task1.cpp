#include <iostream>
class Student {
    const std::string f_name = "Jason";
    const std::string s_name = "Statham";
    std::string group {};
    int age {};
    int hp {};
    int money {};
    int time_student {}; //время бодорствования
    int time {}; // едениц времени до сдачи сессии
    int progress {};

public:
    void print() {
        std::cout << "Name : " << f_name << "\tSurname : " << s_name << "\n";
        std::cout << "group : " << group << "\n" << "age : " << age << "\n";
        std::cout << "HP : " << hp << "\n" << "money : " << money << "\n";
        std::cout << "Time_student : " << time_student << "\n" << "time : " << time << "\n";
        std::cout << "Your progress : " << progress << "\n"; 
    }

    void info() {
        std::cout << "HP : " << hp << "\n" << "money : " << money << "\n";
        std::cout << "Time_student : " << time_student << "\n" << "time : " << time << "\n";
        std::cout << "Your progress : " << progress << "\n";
    }

    Student(std::string p_group , int p_age , int p_hp , int p_money , int p_time_student , int p_time, int p_progress) {
        group = p_group;
        age = p_age;
        hp = p_hp;
        money = p_money;
        time_student = p_time_student;
        time = p_time;
        progress = p_progress;
    }

    int show_hp() {
        return hp;
    }
    int show_money() {
        return money;
    }
    int show_time_student() {
        return time_student;
    }
    int show_time() {
        return time;
    }
    int show_progress() {
        return progress;
    }

    void eat() {
        if(hp > 99) {
            std::cout << "You're not hungry!" << "\n";
        }
        else if(money >= 200) {
            hp += 30;
            money -= 250;
            time_student += 1;
            time -= 1;
            if(hp > 100) {
                hp = 100;
            }
        }
        else {
            std::cout << "Not enough money ;(" << "\n";
        }
        
        
    }

    void botay(int t) {  // 1 время затраченное на бот даёт 3 прогресса, тратит 1 время, 5hp  
        if(time_student < 24) {
            progress += 3*t;
            time_student += t;
            time -= t;
            hp -= 5*t;
        }
        else if(time_student >= 24) {
            progress += 3*t;
            time_student += t;
            time -= t;
            hp -= 15*t;

        }
        }

    void work(int t) { // 1 время затраченное на работу даёт 150 денег, тратит 1 время, 5hp
        if(time_student < 24) {
            money += 150*t;
            time_student += t;
            time -= t;
            hp -= 5*t;
        }
        else if(time_student >= 24) {
            money += 150*t;
            time_student += t;
            time -= t;
            hp -= 15*t;

        }
        }

    void sleep(int t) { // 1 время затраченное на сон убирает 3 времени студента, если время сна >= 6, то время студента обнуляется + за сон дается хр
        if(t < 6) {
            time_student -= 3*t;
            time -= t;
            hp += 5*t;
            if(hp > 100) {
                hp = 100;
            }
        }
        else if(t > 5) {
            time_student = 0;
            time -= t;
            hp += 5*t;
            if(hp > 100) {
                hp = 100;
            }

        }
        }

    void relax(int t) { // отдых)
        if(money <= 100*t) {
            std::cout << "Not enough money ;(" << "\n";
        }
        else if(time_student> 23) {
            hp += 3*t;
            money -= 100*t;
            time_student += t;
            time -= t;
            if(hp > 100) {
                hp = 100;
            }
        }
        else {
            hp += 10*t;
            money -= 100*t;
            time_student += t;
            time -= t;
            if(hp > 100) {
                hp = 100;
            }
        }
        }    

};



int main() {
    std::cout << "Hey, hey, are you awake?" << "\n";
    std::cout << "Welcome to MIPT, the best university in the country!!!" << "\n";
    std::cout << "Your main goal is to close the session in time." << "\n";
    std::cout << "Here is the information about you:" << "\n" << "\n";
    Student man("B04-304", 19,100,1000,0,100,0);
    man.print();
    std::cout << "\n" << "Get 100 progress until the time runs out!" << "\n";
    std::cout << "Do not forget to sleep, eat and rest, otherwise you will die :)" << "\n" << "\n";
    std::cout << "Commands: info; eat; botay; work; sleep; relax" << "\n";

    int hp1 = man.show_hp();
    int money1 = man.show_money();
    int time_student1 = man.show_time_student();
    int time1 = man.show_time();
    int progress1  = man.show_progress();

    while(time1 > 0) {
        std::string action;
        std::cout << "Action: " << "\n";
        std::cin >> action;
        if(action == "eat") {
            man.eat();
        }
        else if(action == "info") {
            man.info();
        }

        else {
            std::cout << "Enter time: " << "\n";
            int t;
            std::cin >> t;
            if(action == "botay") {
                man.botay(t);
            }
            else if(action == "work") {
                man.work(t);
            }
            else if(action == "sleep") {
                man.sleep(t);
            }
            else if(action == "relax") {
                man.relax(t);
            }
            else {
                std::cout << "Incorrect input, try again!!!" << "\n";
            }
        }

    hp1 = man.show_hp();
    money1 = man.show_money();
    time_student1 = man.show_time_student();
    time1 = man.show_time();
    progress1  = man.show_progress();
    if(hp1 < 1) {
        std::cout << "You dead!!!" << "\n";
        break;
    }    
    
    }

    if(progress1 > 99 && hp1 > 0) {
        std::cout << "Congratulations, you passed the session!!!" << "\n";
    }
    else if(hp1 > 0) {
        std::cout << "YOU DIDN'T PASS THE SESSION!!!" << "\n";

    }
}

