#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char major[50];
    int age;
    double gpa;
};

void printStudentInfo(struct Student student) {
    printf("Hello %s", student.name);
    printf("Your age is %d\n", student.age);
    printf("Your major is %s", student.major);
    printf("Your gpa is %lf\n", student.gpa);
    
}

int main () {
    
    struct Student student1;

    char name[50];
    printf("enter your name: ");
    fflush(stdin); //fgets() may break after using scanf() above because of how both functions use '\n' chars
    fgets(name, 50, stdin);
    strcpy(student1.name, name);

    int age;
    printf("enter your age: ");
    scanf("%d", &age);
    student1.age = age;
    
    char major[50];
    printf("enter your major: ");
    fflush(stdin); //fgets() may break after using scanf() above because of how both functions use '\n' chars
    fgets(major, 50, stdin);
    strcpy(student1.major, major);

    float gpa;
    printf("enter your gpa: ");
    scanf("%f", &gpa);
    student1.gpa = gpa;

    printStudentInfo(student1);
    return 0;
}
