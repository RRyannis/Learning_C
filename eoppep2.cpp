//εοππεπ ερώτηση 154, ομάδα Α
// #include <iostream>

// int main(void) {
//     std::cout<<"Hello World!"<<std::endl;
//     std::cout<<"C++ is an object oriented language!"<<std::endl;
//     return 0;
// }

//εοππεπ ερώτηση 162, ομάδα Α

#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

int main(void) {
    int number;
    cout<<"Enter a number:";
    cin>>number;
    if (number < 0) {
        cout<<"Has to be a positive integer."<<endl;
    } else {
        cout<<"The factorial of "<<number<<" is "<<factorial(number)<<endl;
    }
    return 0;
}