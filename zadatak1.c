#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funkcije.h"

int main() {
    int BUFFER_SIZE = 64;
    int count = 0;
    float *numbers = NULL;

    char *input = malloc(BUFFER_SIZE * sizeof(char));

    printf("Enter input: ");

    int ch;
    int index = 0;
    char avgType;
    do {
        ch = getchar();
        if (index == BUFFER_SIZE - 1) {
            BUFFER_SIZE += 1;
            input = realloc(input, BUFFER_SIZE * sizeof(char));

            if (input == NULL) {
                perror("Error reallocating memory for input");
                exit(EXIT_FAILURE);
            }
        }

        input[index++] = ch;

    } while (ch != 'a' && ch != 'g' && ch != 'h');
    
    avgType = input[index-1];
    input[index-1] = '\0';

    if (isdigit(input[0])) {
        // If the input is a number, convert it to integers
        convertToInteger(input);
    } else if (isalpha(input[0])) {
        // If the input is a character, perform an operation
        float result = calculateResult(numbers, count, avgType);
        printf("Result: %f\n", result);
    } else {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    free(numbers);
    free(input);
    return 0;
}
