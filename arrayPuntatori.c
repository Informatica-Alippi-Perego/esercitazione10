/*Scrivere una funzione che, presi in ingresso due array di caratteri, crea un terzo array contente un mix dei due array, uno partendo dall’inizio e uno dalla fine. Usare solo i puntatori
*/

#include <stdio.h>
#include <stdlib.h>

char * mixArray(char *a1, int dim1, char *a2, int dim2);

int main(int argc, const char * argv[]) {
    char array1[5] = {'c','f','a','d','r'};
    char array2[8] = {'l','s','w','n','z','h','k','j'};
    
    char *array = NULL;
    
    array = mixArray(array1,5,array2,8);
    
    for (char *cursor = array; cursor<array+5+8; cursor++)
        printf("%c ", *cursor);
    
    free(array);
    return 0;
}

char * mixArray(char *a1, int dim1, char *a2, int dim2){
    char *fin_a1 = a1+dim1;
    char *fin_a2 = a2+dim2;
    
    char *array = (char *)malloc(sizeof(char)*(dim1+dim2));
    char *iniziaArray = array;
    
    while((a1<fin_a1) && (a2<fin_a2)){
        *array = *a1;
        array++;
        a1++;
        *array = *(fin_a2-1);
        array++;
        fin_a2--;
    }
    
    while(a1!=fin_a1){
        *array = *a1;
        array++;
        a1++;
    }
    
    while(fin_a2 != a2){
        *array = *(fin_a2-1);
        array++;
        fin_a2--;
    }
    
    return iniziaArray;
}
