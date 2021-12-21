/*
 Scrivere una funzione che presa in ingresso una matrice, estrae la diagonale usando solamente i puntatori.
*/

#include <stdio.h>
#include <stdlib.h>

int * trovaDiagonale(int matrice[][5], int l);

int main(){
    int matrix[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int *diag = NULL;
    
    int i,j;
    //STAMPO
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf("%d ",*(*(matrix+i)+j));
        }
        printf("\n");
    }
    
    diag = trovaDiagonale(matrix, 5);
    
    //STAMPO diag
    printf("\n\nDiagonale: ");
    for (i=0; i<5; i++)
        printf("%d ",diag[i]);
    return 0;
}

int * trovaDiagonale(int matrice[][5], int l){
    int *diag;
    int *move;
    
    int i;
    
    diag = (int*)malloc(sizeof(int)*l);
    move = diag;
    
    for (i=0; i<l; i++)
    {
        *move = *(*(matrice+i)+i);
        move++;
    }
    return diag;
}
