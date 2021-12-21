#include <stdio.h>
#include <string.h>

typedef struct autore{
    char nome[20];
    char cognome[20];
    int anno_di_nasita;
} autore;

typedef struct libro{
    char titolo[20];
    int anno;
    char tipologia[20];
    char editore[20];
    char lingua[3];
    autore autori[5];
    int numAutori;
} libro;

int inserisciLibro(libro biblioteca[], int len);
void stampaLibri(libro biblioteca[], int len);

libro cercaPerTitolo(libro biblioteca[], int len, char titolo[]){
    int i;
    for (i=0; i<len; i++)
    {
        if (strcmp(titolo,biblioteca[i].titolo)==0)
            stampaLibri(&biblioteca[i], 1);
    }
    return biblioteca[i];
}

void cercaAutore(libro biblioteca[], int len, char autore[]){
    int i,j;
    for (i=0; i<len; i++)
    {
        for(j=0; j<biblioteca[i].numAutori; j++)
        if (strcmp(autore,biblioteca[i].autori[j].nome)==0)
            stampaLibri(&biblioteca[i], 1);
    }
    
    
}


int main(){
    
}
