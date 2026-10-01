// //bitwise exercise, equivalent of 6 *  13
// #include <stdio.h>

// int main(void) {
//   int num1 = 6;
//   int num2 = 13;
//   int shift = 0;

//   while (num2 > 1) {
//     num2 = num2 / 2;
//     shift++;
//   }

//   printf("%d << %d is %d \n", num1, shift, num1 << shift);
// }
#include <stdio.h>
#include <string.h>


struct Point {
    int x;
    int y;
};

void printPoint(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}


struct Rectangle {
    struct Point topLeft;
    struct Point bottomRight;
};

int rectangleArea(struct Rectangle r) {
    int width = r.bottomRight.x - r.topLeft.x;
    int height = r.bottomRight.y - r.topLeft.y;
    return width * height;
}


typedef struct {
    char name[50];
    int age;
} Person;


void haveBirthday(Person *p) {
    p->age++;   
}

int main(void) {
    struct Point p1 = {3, 4};
    printPoint(p1);

    p1.x = 10;
    printPoint(p1);

    struct Rectangle rect = {{0, 0}, {5, 3}};
    printf("Area: %d\n", rectangleArea(rect));

    Person alice;
    strcpy(alice.name, "Alice");
    alice.age = 29;
    printf("%s is %d\n", alice.name, alice.age);

    haveBirthday(&alice);
    printf("%s is now %d\n", alice.name, alice.age);

    Person people[2] = {
        {"Bob", 40},
        {"Carol", 35}
    };
    for (int i = 0; i < 2; i++)
        printf("%s: %d\n", people[i].name, people[i].age);

    return 0;
}