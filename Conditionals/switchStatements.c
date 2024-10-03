#include <stdio.h>
#include <stdlib.h>

int main () {
    
    char grade;
    printf("Enter your grade: ");
    scanf(" %c", &grade);
    
    switch(grade) {
    case 'A' :
        printf("You did great!\n");
        break;        
    case 'B' :
        printf("You did fine.\n");
        break;
    case 'C' :
        printf("You did ok.\n");
        break;    
    case 'D' :
        printf("You did poorly.\n");
        break;
    case 'F' :
        printf("You did very bad!\n");
        break;
    default: 
        printf("Your grade could not be understood.\n");
    }

    return 0;
}
