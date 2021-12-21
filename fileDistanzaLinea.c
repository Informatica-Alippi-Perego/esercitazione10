/* Dato un file contenente dei punti su di un piano, calcolare la lunghezza della linea spezzata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcolaDistanza(char nomeFile[]);

int main(){
    printf("La linea spezzata è lunga %.2f\n", calcolaDistanza("linee.txt"));
    return 0;
}

float calcolaDistanza(char nomeFile[]){
    FILE *f;
    float distanza = 0;
    int x,y;
    int xOld, yOld;
    int first = 1;
    
    f = fopen(nomeFile,"r");
    if (f == NULL)
        return -1;
    
    fscanf(f,"%d",&x);
    while(!feof(f)){
        if (first)
        {
            fscanf(f,"%d",&y);
            first = 0;
        }
        else{
            xOld = x;
            yOld = y;
            fscanf(f,"%d %d",&x, &y);
            distanza = distanza + sqrt(pow(xOld-x,2)+pow(yOld-y,2));
        }
    }
    return distanza;
}
