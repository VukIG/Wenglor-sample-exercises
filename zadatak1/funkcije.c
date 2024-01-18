#include "funkcije.h"

float aritmethic( int *numbers, int count, char operation)
{
   float result = 0.0;
   for (int i = 0; i < count; ++i) {
       result += numbers[i];
   }
   return result / count;
}


float geometric( int *numbers, int count, char operation)
{
    float result = 1.0;
    for (int i = 0; i < count; ++i) {
        result *= numbers[i];
    }
    return pow(result, 1.0 / count);
}

float harmonic( int *numbers, int count, char operation)
{
    float result = 0.0;
    for (int i = 0; i < count; ++i) {
        result += 1.0 / numbers[i];
    }
    return count / result;
}

float calculateResult(int *numbers, int count, char operation) {
    switch (operation) {
    case 'a':
        return aritmethic(numbers, count, operation);
        break;
    case 'g':
        return geometric(numbers, count, operation);
        break;
    case 'h':
        return harmonic(numbers, count, operation);
        break;
    default:
        printf("Invalid operation\n");
        exit(EXIT_FAILURE);
    }
}

int* convertToInteger(char *line, int *len) {
    int *numbers = malloc(sizeof(int) * (*len));
    int numbersSize = 0;
    char *ptr = strtok(line, " ");

    while (ptr != NULL) {
        numbers[numbersSize++] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }
    *len = numbersSize;
   return numbers;
}


void printResultToFile(float result) {
    
    FILE *file = fopen("Rezultat.txt", "w");
    if (file == NULL) {
        perror("Problem pri otvaranju fajla");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%f\n", result);
    fclose(file);
}