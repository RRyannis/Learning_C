//εοππεπ ερώτηση 154, ομάδα Α
// #include <iostream>

// int main(void) {
//     std::cout<<"Hello World!"<<std::endl;
//     std::cout<<"C++ is an object oriented language!"<<std::endl;
//     return 0;
// }

//εοππεπ ερώτηση 162, ομάδα Α

// #include <iostream>

// using namespace std;

// int factorial(int n) {
//     if (n == 0) {
//         return 1;
//     } else {
//         return n*factorial(n-1);
//     }
// }

// int main(void) {
//     int number;
//     cout<<"Enter a number:";
//     cin>>number;
//     if (number < 0) {
//         cout<<"Has to be a positive integer."<<endl;
//     } else {
//         cout<<"The factorial of "<<number<<" is "<<factorial(number)<<endl;
//     }
//     return 0;
// }

//εοππεπ ερώτηση 163, ομάδα Α
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string sentence = "C++ is an object oriented programming language and is a superset of C.";
    string wordToFind = "is";
    int position = 1;
    int count = 0;

    size_t found = sentence.find(wordToFind);
    while (found != string::npos) {
        count++;
        position = found;
        found = sentence.find(wordToFind, found + 1);
    }

    if (count > 0) {
        cout<<"The word "<< wordToFind << " has been found "<< count << " times."<<endl;
        cout<<"Its last position is "<< position << endl;
    } else {
        cout<<"The word "<< wordToFind<<" wasn't found"<<endl; 
    }
    return 0;
}