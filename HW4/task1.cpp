#include <iostream>
#define N 3 // макрос для определения размерности вектора


struct vector { // создаём вектор + функция по умножению вектора на число
    float vect[N];

    void multiply(float k) {
        for(int i = 0; i < N; i++){
            vect[i] *= k;

        }

    }

};

struct vector summ(struct vector v1, struct vector v2) { // функция для суммы векторов
    struct vector v_new{};
    for(int i = 0; i < N; i++) {
        v_new.vect[i] = v1.vect[i] + v2.vect[i];
    }
    return v_new;


};

float scalar(struct vector v1, struct vector v2) { // функция для скалярного умножения векторов
    float ans;
    ans = 0;
    for(int i = 0; i < N; i++) {
        ans += v1.vect[i] * v2.vect[i];
    }
    return ans;

}


int main() {
    struct vector v1 {};
    struct vector v2 {};
    std::cout << "Write the coordinates of vector 1" << '\n';
    for(int i = 0; i < N; i++) {
        float x;
        std::cin >> x;
        v1.vect[i] = x;
    }
    std::cout << "Write the coordinates of vector 2" << '\n';
    for(int j = 0; j < N; j++) {
        float x;
        std::cin >> x;
        v2.vect[j] = x;
    }
    std::cout << "Write the number by which you want to multiply the vector 1" << '\n';
    float k;
    std::cin >> k;
    v1.multiply(k); // вектор v1 домножили на k
    struct vector v3 = summ(v1, v2);
    float sc; 
    sc = scalar(v1, v2); // скалярное произведение v1 и v2
    std::cout << "The scalar of the vectors: " << sc << '\n';
    std::cout << "the first coordinate of the sum of the vectors: " << v3.vect[0] << '\n';

}