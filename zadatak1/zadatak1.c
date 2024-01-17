#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funkcije.h"
#include <string.h>

int main() {

    float *numbers = NULL;
    char method[12];
    printf("Unos: ");

    int ch;
    float result;
    int index = 0;
    char avgType;
    int len = 0;
    char* input=(char*)malloc(sizeof(char));
    while(1) {
        ch = getchar();
        if (len == 0 && !isdigit(ch))
        {
            printf("Neophodan je unos celobrojnog niza");
            return 0;
        }
        else if (isdigit(ch) || ch == '10')
        {
            input[len]=ch;
            len++;
            input=(char*)realloc(input,sizeof(char)*(len));
        }
        else if (ch == 'a' || ch == 'g' || ch == 'h')
        {
            input[len] = '\0';
            float result;
            char *t = fgets(method, sizeof(method), stdin); //kako uhvatiti unos duzi od 12
            if (strcmp(method,"ritmeticka") == 0 )
            {
                int *integers = convertToInteger(input, len);
                result = aritmethic(integers,len,ch);
            }
            else if(strcmp(method,"eometrijska")== 0 )
            {
                int *integers = convertToInteger(input, len);
                result = geometric(integers,len,ch);
            }
            else if(strcmp(method,"armonijska") == 0 )
            {
                int *integers = convertToInteger(input, len);
                result = harmonic(integers,len,ch);
            }
            else if( t == NULL ){
                int *integers = convertToInteger(input, len);
                result = calculateResult(integers,len,ch);
            }
            else{
                printf("Nevazeca metoda");
                break;
            }
            printf("%s","MOMIR19");
            printResultToFile(result);
            printf("Rezultat uspesno upisan u Rezultat.txt !");

        }
        else{
            printf("Sta si ti uneo sine moj?!");
            break;
        }
    }

    free(numbers);
    free(input);
    return 0;
}
