#include <stdio.h>
//chat gpt was used in order to help with temperature conversions
int main() {
    int temp; //temperature variable saved as an int
    char fromScale, toScale; //analyze letters to determine the scale of the temperature

    while (1) {
        printf("Enter the temperature value: ");
        scanf("%d", &temp);

        printf("Enter the input scale (C for Celsius, F for Fahrenheit, K for Kelvin): ");
        scanf(" %c", &fromScale);

        printf("Enter the target scale (C for Celsius, F for Fahrenheit, K for Kelvin): ");
        scanf(" %c", &toScale);

        double tempC, convertedTemp;

        // Convert input temperature to Celsius
        if (fromScale == 'F') {
            tempC = (temp - 32) * 5.0 / 9.0;
        } else if (fromScale == 'K') { //convert from Kelvin to Celcius
            tempC = temp - 273.15;
        } else {
            tempC = temp; // Already in Celsius
        }

        // Convert Celsius to target scale
        if (toScale == 'F') {
            convertedTemp = (tempC * 9.0 / 5.0) + 32;
        } else if (toScale == 'K') {
            convertedTemp = tempC + 273.15; //convert to Kelvin
        } else {
            convertedTemp = tempC; // Return in Celsius
        }

        printf("Converted Temperature: %.2lf %c\n", convertedTemp, toScale); //print the converted temperature

        if (tempC < 0) {
            printf("Its freezing, Wear a big jacket, gloves, and a beanie.\n");
        } else if (tempC >= 0 && tempC < 10) {
            printf("Its cold, wear a nice jacket\n");
        } else if (tempC >= 10 && tempC < 25) {
            printf("the weather is nice and comfortable, spend some time outside\n");
        } else if (tempC >= 25 && tempC < 35) {
            printf("Its hot, drink water, dont wear long sleeves, jackets, or clothes that will make you overheat\n");
        } else {
            printf("Its very hot! stay indoors with the AC and drink water\n");
        }
    }

    printf("End Program\n");
    return 0;
}