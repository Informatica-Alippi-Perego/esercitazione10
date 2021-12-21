/*
Creare una matrice NxM di interi (con N e M definiti dall’utente). Impostare la matrice con tutti gli elementi a ‘0’. Definire un puntatore ad interi che punti all’elemento (0, 0) della matrice. Scrivere un algoritmo che sposti il puntatore di i caselle in basso e di j caselle a destra (dove i e j sono numeri casuali compresi rispettivamente tra 0 e N e tra 0 e M). Ripetere l’operazione di spostamento del puntatore un numero di volte definito dall’utente e incrementare di 1 ogni ele- mento della matrice che viene puntato dal puntatore. Stampare le coordinate di tutti i movimenti del puntatore e la matrice ottenuta alla fine degli spostamenti del puntatore.

Sia A una matrice 5x4 allocata dinamicamente.
Se si vuole accedere all’elemento A[3][2] è possibile utilizzare l’aritmetica dei puntatori nel seguente modo:
*(*(A+3)+2)
(A+3) è il quarto puntatore dell’array che rappresenta le righe
*(A+3) è l’indirizzo del primo elemento della quarta riga *(A+3)+2 è l’indirizzo del terzo elemento della quarta riga *(*(A+3)+2) è il contenuto della cella p
*/

#include <stdio.h>
#include <stdlib.h>

int ** creaMat(int n, int m);
void coordinate(int **matrix, int *x, int *y, int i, int j, int maxX, int maxY);
void svuotaMatrice(int **matrice, int maxX, int maxY);
void stampa(int **matrice, int maxX, int maxY);

int main(){
    int **matrice;
    int x,y;
    int n,m;

    printf("Inserisci dimensione N: ");
    scanf("%d",&n);
    printf("Inserisci dimensione M: ");
    scanf("%d",&m);
    matrice = creaMat(n, m);
    
    svuotaMatrice(matrice, n, m);
    
    stampa(matrice, n, m);
    
    x=0;
    y=0;
    coordinate(matrice, &x, &y, 2, 2, n, m);
    stampa(matrice, n, m);
    coordinate(matrice, &x, &y, 3, 1, n, m);
    stampa(matrice, n, m);
    coordinate(matrice, &x, &y, 0, 1, n, m);
    stampa(matrice, n, m);
    coordinate(matrice, &x, &y, 1, -2, n, m);
    stampa(matrice, n, m);
    return 0;
}

int ** creaMat(int r, int c){
    int** m;
    int i;
    
    m = (int**)malloc(r*sizeof(int*));
    for (i=0; i<r; i++)
        m[i] = (int*)malloc(c*sizeof(int));
    
    return m;
}

void coordinate(int **matrix, int *x, int *y, int i, int j, int maxX, int maxY){
    *x = *x + i;
    if (*x>=maxX)
        *x = maxX-1;
    
    *y = *y + j;
    if (*y>=maxY)
        *y = maxY-1;
    
    *(*(matrix+(*x))+(*y))+=1;
}

void svuotaMatrice(int **matrice, int maxX, int maxY){
    int x,y;
    
    for (x=0; x<maxX; x++){
        for (y=0; y<maxY; y++){
            matrice[x][y] = 0;
        }
    }
}

void stampa(int **matrice, int maxX, int maxY){
    int x,y;
    printf("\n");
    for (x=0; x<maxX; x++){
        for (y=0; y<maxY; y++){
            printf("%d ", matrice[x][y]);
        }
        printf("\n");
    }
}
 
