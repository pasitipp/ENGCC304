#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
    int play;
    char input[100];

    srand((unsigned)time(NULL)); 

    while (1) {
        printf("Do you want to play game (1=play,-1=exit) :\n");
        if (scanf("%99s", input) != 1) return 0;

        if (strcmp(input, "1") == 0) {
            play = 1;
        } else if (strcmp(input, "-1") == 0) {
            play = -1;
        } else {
            printf("Please enter only 1 or -1.\n\n");
            continue;
        }

        if (play == -1) {
            printf("See you again.\n");
            break;
        }

        int score = 100;
        int secret = rand() % 100 + 1; 
        int guess;
        int min = 1, max = 100;

        printf("\n(Score=100)\n\n");

        while (1) {
            printf("Guess the winning number (%d-%d) :\n", min, max);

            if (scanf("%d", &guess) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Please enter a valid number.\n");
                continue;
            }

            if (guess == secret) {
                printf("\nThat is correct! The winning number is %d.\n", secret);
                printf("\nScore this game: %d\n\n", score);
                break;
            }

            score -= 10;
            if (score < 0) score = 0;

            if (guess < secret) {
                if (guess + 1 > min) min = guess + 1;
                printf("\nSorry, the winning number is HIGHER than %d. (Score=%d)\n\n", guess, score);
            } else { 
                if (guess - 1 < max) max = guess - 1;
                printf("\nSorry, the winning number is LOWER than %d. (Score=%d)\n\n", guess, score);
            }
        }
    }
    return 0;
}
