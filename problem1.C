#include <stdio.h>

int main() {
    int score; //scrore variable saved as an int  

    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) { //if score is 0, or 1, exit
            break;
        }

        if (score < 2) {
            printf("Football scores must be 2 or higher.\n"); //score must be 2 or higher to be a valid footbal score
            continue;
        }

        printf("Possible combinations  %d:\n", score);
        for (int td2 = 0; td2 * 8 <= score; td2++) {  // 8 points and a 2 point conversion
            for (int td1 = 0; td1 * 7 <= score; td1++) { //7 points and an extra point
                for (int td = 0; td * 6 <= score; td++) { //a touchdon with no extra point
                    for (int fg = 0; fg * 3 <= score; fg++) { //a field goal
                        for (int safety = 0; safety * 2 <= score; safety++) { //a safety (2 points)
                            if (td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2 == score) { // add the scores and compare with input value
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety); //print the combinations
                            }
                        }
                    }
                }
            }
        }
    }

    printf("End Program\n"); //exit the code
    return 0;
}