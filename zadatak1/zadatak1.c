#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funkcije.h"
#include <string.h>

int main() {

    float *numbers = NULL;
    char method[12];
    int *arrayLen = malloc(sizeof(int));
    int ch;
    float result;
    int len = 0;
    char* input=(char*)malloc(sizeof(char));
    printf("Unos: ");
    while(1) {
        ch = getchar();
        if (len == 0 && !isdigit(ch))
        {
            printf("Neophodan je unos celobrojnog niza");
            return 0;
        }
        else if (isdigit(ch) || isspace(ch))
        {
            input[len]=ch;
            len++;
            input=(char*)realloc(input,sizeof(char)*(len));
        }
        else if (ch == 'a' || ch == 'g' || ch == 'h')
        {
            input[len] = '\0';
            float result;
            char *t = fgets(method, sizeof(method), stdin);
            printf("%c",*t);
            if (strcmp(method,"ritmeticka"))
            {
                *arrayLen = len;
                int *integers = convertToInteger(input, arrayLen);
                len = *arrayLen; 
                result = aritmethic(integers,len);
                for (int i = 0; i < len; i++) {
                    printf("%d ", integers[i]);
                }
            }
            else if(strcmp(method,"eometrijska"))
            {
                printf("momir");
                *arrayLen = len;
                int *integers = convertToInteger(input, arrayLen);
                len = *arrayLen;
                printf("%d",len);
                result = geometric(integers,len);
            }
            else if(strcmp(method,"armonijska"))
            {
                *arrayLen = len;
                int *integers = convertToInteger(input, arrayLen); 
                len = *arrayLen; 
                result = harmonic(integers,len);
            }
            else if( t == NULL ){
                *arrayLen = len;
                int *integers = convertToInteger(input, arrayLen);
                len = *arrayLen; 
                result = calculateResult(integers,len,ch);
            }
            else{
                printf("Nevazeca metoda");
                break;
            }
            printResultToFile(result);
            printf("Rezultat uspesno upisan u Rezultat.txt !");

        }
        else{
            printf("Sta si ti uneo sine moj?!");
            break;
        }
    }
    
    free(arrayLen);
    free(numbers);
    free(input);
    return 0;
}
