#include <stdio.h>
#include <stdlib.h>

int makeTriangle () {
    printf("     /|\n");
    printf("    / |\n");
    printf("   /  |\n");
    printf("  /___|\n");
    return 0;
}

int makeRectangle () {
    printf("  -------\n");
    printf("  |     |\n");
    printf("  |     |\n");
    printf("  |     |\n");
    printf("  -------\n");   
    return 0;
}

int makeRhombus () {
    printf("    /\\   \n");
    printf("   /  \\  \n");
    printf("  /    \\ \n");
    printf("  \\    / \n");
    printf("   \\  /  \n");
    printf("    \\/   \n");
    return 0;
}

int makeHexagon () {
    printf("    ------     \n");
    printf("   /      \\   \n");
    printf("  /        \\   \n");
    printf("  \\        /   \n");
    printf("   \\      /   \n");
    printf("    ------\n");
    return 0;
}

int main () {
    int rtnValue = makeTriangle();
    if(rtnValue == 0) {
        printf("successfully built a triangle\n");
    } 
    rtnValue = makeRectangle();
    if(rtnValue == 0) {
        printf("successfully built a rectangle\n");
    } 
    rtnValue = makeRhombus();
    if(rtnValue == 0) {
        printf("successfully built a rhombus\n");
    }
    rtnValue = makeHexagon();
    if(rtnValue == 0) {
        printf("successfully built a hexagon\n");
    }

    return 0;
}