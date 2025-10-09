#include <iostream>
using namespace std;

struct vectorIPK {
    int *data;
    int capacity;
    int length;
};

void initIPK (vectorIPK &vec) {
    vec.capacity = 2;
    vec.length = 0;
    vec.data = new int[vec.capacity];
}

void resize (vectorIPK &vec, int newCap) {
    int *newVector = new int[newCap];
    for (int i = 0; i < vec.length; i++)
    {
        newVector[i] = vec.data[i];
    }
    delete[] vec.data;
    vec.data = newVector;
    vec.capacity = newCap;
}

void pushIPK (vectorIPK &vec, int value) {
    if (vec.capacity = vec.length)
    {
        resize(vec, vec.capacity++);
    }
    vec.data[vec.length] = value;
    vec.length++;
}

void setIPK (vectorIPK &vec, int index, int value) {
    if (index >= 0 && index < vec.length)
    {
        vec.data[index] = value;
    }   
}

void deleteTop (vectorIPK &vec) {
    if (vec.length > 0)
    {
        vec.length--;
    }
}

void display (vectorIPK &vec) {
    for (int i = 0; i < vec.length; i++)
    {
        cout << vec.data[i] << "\n";
    }
}

int main () {
    vectorIPK vectorIPKTeknik;
    initIPK(vectorIPKTeknik);

    pushIPK(vectorIPKTeknik, 3.45);

    display(vectorIPKTeknik);
}