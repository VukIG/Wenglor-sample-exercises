#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

float calculateResult(int *numbers, int count, char operation);
int* convertToInteger(char *line, int *len);
void printResultToFile(float result);
float aritmethic(int *numbers, int count);
float geometric( int *numbers, int count);
float harmonic(int *numbers, int count);