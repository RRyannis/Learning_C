#include <stdio.h>
#include <stdlib.h>   //for malloc() and free()

int main(void)
{
    int n = 5;  // how many integers (could be decided at runtime!)

    // Asking the system for enough memory to hold 5 ints.
    // malloc returns a pointer to the start of that memory block.
    int *numbers = malloc(n * sizeof(int));

    //ALWAYS check whether the allocation succeeded.
    //If malloc fails (e.g., out of memory), it returns NULL.
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //Use memory like a regular array.
    for (int i = 0; i < n; i++) {
        numbers[i] = i * 10;
    }

    //Print the values back out.
    for (int i = 0; i < n; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Give the memory back when you're done with it.
    free(numbers);
    numbers = NULL;  // good habit: avoids accidentally reusing a freed pointer

    return 0;
}
// //creating a struct node
// struct node {
//     int value;
//     struct node *next;
// };

// int main (void) {
//     struct node test;
//     test.value = 0;

//     struct node test2;
//     test2.value = 1;

//     test.next = &test2;

//     printf("%d \n", test.value);
//     printf("%d \n", test.next->value);
//     printf("%d \n", test2.value);



// }
//more struct stuff
struct sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
} sigline, *sigline_p;

int main(void) {

    sigline.signum = 5;
    strcpy(sigline.signame, "SIGINT");
    strcpy(sigline.sigdesc, "Interrupt from keyboard");

    sigline_p->signum = 5;
    strcpy(sigline_p->signame, "SIGINT");
    strcpy(sigline_p->sigdesc, "Interrupt from keyboard");
}


// //listing 2-6 and exercise 2-1
// static unsigned int counter = 0;

// void increment(void) {
//     // static unsigned int counter = 0;
//     counter++;
//     //printf("%d ", counter);
// }
// unsigned int retrieve(void) {
//     return counter;
// }
// int main(void) {
//     for (int i = 0; i < 5; i++) {
//     increment();
//     }
//     printf("\ncounter is currently %u\n", retrieve());
//     return 0;
// }
// void swap(int *pa, int *pb) {
//     int temp = *pa;
//     *pa = *pb;
//     *pb = temp;
// }
// int main(void) {
//    int a = 6, b = 9;
//    swap(&a, &b);
//    printf("a = %d, b = %d \n", a, b);
   

//     return 0;
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