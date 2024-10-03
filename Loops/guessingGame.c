#include <stdio.h>
#include <stdlib.h>


int main () {
    
    int secretNumber = 7;
    int guess;
    int numGuesses = 0;
    int distanceFromSN;

    do  {
        printf("-------------------------\n");
        printf("Enter an integer guess: ");
        scanf("%d", &guess);
        numGuesses++;
        if(guess < secretNumber) {
            printf("You guessed too low.\n");
        } else if (guess > secretNumber) {
            printf("You guessed too high.\n");
        }
    } while(secretNumber != guess);
    printf("Congratulations! You guessed the secret number %d in %d guesses.\n", secretNumber, numGuesses);

    return 0;
}
