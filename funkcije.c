#include "funkcije.h"

float calculateResult(float *numbers, int count, char operation) {
    float result = 0;

    switch (operation) {
    case 'a':
        for (int i = 0; i < count; ++i) {
            result += numbers[i];
        }
        result /= count;
        break;
    case 'g':
        result = 1.0;  // Initialize result for multiplication
        for (int i = 0; i < count; ++i) {
            result *= numbers[i];
        }
        result = pow(result, 1.0 / count);
        break;
    case 'h':
        for (int i = 0; i < count; ++i) {
            result += 1.0 / numbers[i];
        }
        result = count / result;
        break;
    default:
        printf("Invalid operation\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

void convertToInteger(char *line) {
    int num, i = 0, len;
    while (sscanf(line, "%d%n", &num, &len) == 1) {
        printf("Number %d is %d\n", i, num);
        line += len;
        i++;
    }
}