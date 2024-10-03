#include <stdio.h>
#include <stdlib.h>

void sayHi() {
    printf("Hi User\n");
}

void sayHello(char name[]) {
    printf("Hello %s\n", name);
}

int main () {    
    printf("--program--flow--1\n");
    sayHi();
    printf("--program--flow--2\n");
    sayHello("Mike");
    printf("--program--flow--3\n");
    sayHello("Marcus");
    printf("--program--flow--4\n");

    return 0;
}

