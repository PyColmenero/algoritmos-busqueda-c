#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define false 0
#define true 1

int KMPSearch (char *, char *) ;
void computeLPSArray (char *, int, int *) ;

int main (){
    char *texto = "abracadabra";
    char *patron;
    printf ("\nIntroduce la palabra a buscar: ") ;
    scanf ("%s", patron) ;
    int amount = KMPSearch (patron, texto) ;
    printf("\nSe encontro %d veces.\n", amount);
    return 0;

}

int KMPSearch (char *patron, char *texto){

    int m = strlen (patron);
    int N = strlen (texto) ;

    int encontrado = false;
    int amount = 0;

    int *matriz = (int *) malloc (sizeof (int) *m) ;
    int j = 0;


    computeLPSArray (patron, m, matriz) ;

    int i = 0; // Indice de texto[]
    while (i < N){
        if (patron [j] == texto[i])
        {
            i++;
            j++;
        }
        if(j == m){
            encontrado = true;
            printf ("La palabra se ha encontrado en %d \n", i-j) ;
            amount++;
            j = matriz [j-1] ;
        }
        else if (i < N && patron[j] != texto[i]){
            if(j != 0){
                j = matriz[j-1];
            } else {
                i++;
            }
        }

    }

    if (! encontrado){
        printf ("La palabra NO se ha encontrado\n") ;
    }

    free (matriz) ;

    return amount;
}


void computeLPSArray (char *patron, int m, int *matriz){
    int len = 0;
    int i;
    matriz [0] = 0; // matriz [0] siempre vale 0
    i = 1;


    while (i < m)
    if (patron [i] == patron[len]){
        len++;
        matriz[i] = len;
        i++;
    } else {
         if(len!=0){
            len = matriz[len-1];
         } else {
            matriz[i] = 0;
            i++;
         }
    }
}
