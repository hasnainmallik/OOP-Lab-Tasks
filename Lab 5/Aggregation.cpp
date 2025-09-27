#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
};

class Student {
    string name;
    Calculator* calc; 
public:
    Student(string n, Calculator* c) {
        name = n;
        calc = c;
    }

    void solveAddition(int a, int b) {
        cout << name << " used calculator: "
             << a << " + " << b << " = " << calc->add(a, b) << endl;
    }

    void solveMultiplication(int a, int b) {
        cout << name << " used calculator: "
             << a << " * " << b << " = " << calc->multiply(a, b) << endl;
    }
};


int main() {
    
    Calculator sharedCalculator;

    
    Student s1("Ahmad", &sharedCalculator);
    Student s2("Sai", &sharedCalculator);

    s1.solveAddition(5, 3);
    s2.solveMultiplication(4, 6);

    return 0;
}

