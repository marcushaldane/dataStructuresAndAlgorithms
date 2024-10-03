#include <stdio.h>
#include <stdlib.h>

int main () {
    
    FILE * fpointer = fopen("employees.txt", "w");
    fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar, Accountant\n");
    fclose(fpointer);

    fpointer = fopen("employees.txt", "a");
    fprintf(fpointer, "Kelly, Customer Service\n");
    fclose(fpointer);

    char line[255];
    fpointer = fopen("employees.txt", "r");
    for(int i = 0; i < 4; i++) {
        fgets(line, 255, fpointer);
        printf("%s", line);
    }
    fclose(fpointer);
    return 0;
}
