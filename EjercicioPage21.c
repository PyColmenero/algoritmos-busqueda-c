#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define false 0
#define true 1
#define NO_OF_CHARS 256

int max (int, int) ;
void badCharHeuristic (char*, int, int[]) ;
void bm (char*, char* ) ;


int main ( ){
    char *texto = "abracadabra";
    char *patron;
    system("color 0B");
    printf ("\nIntroduce la palabra a buscar: ") ;
    scanf ("%s", patron) ;
    bm (texto, patron) ;
    return 0;

}


int max (int a, int b){
    return (a > b)? a: b;
}

void badCharHeuristic ( char *str, int size, int badchar [NO_OF_CHARS] ){

    int i;

    for (i = 0; i < NO_OF_CHARS; i++){
        badchar [i] = -1;
    }

    for (i = 0; i < size; i++){
        badchar [ (int) str[i]] = i;
    }

}

void bm ( char *texto, char *patron){

    int m = strlen (patron);
    int n = strlen (texto) ;
    int amount = 0;
    int badchar [NO_OF_CHARS] ;
    badCharHeuristic (patron, m, badchar) ;

    int s = 0; // s es el salto del patron con respecto al texto
    while (s <= (n - m) ){
        int j = m-1;

        while (j >= 0 && patron [j] == texto [s+j]){
            j--;
        }
        if (j < 0){
            amount++;
            printf ("La palabra se ha encontrado en %d \n", s);

            s += (s+m < n) ? m-badchar [texto [s+m] ] : 1;
        } else {
            s += max (1, j - badchar [texto [s+j]] );
        }
    }



    if(amount == 0){
        printf ("\nLa palabra NO se ha encontrado\n") ;
    } else {
        printf ("\nLa palabra se ha encontrado %d veces.\n", amount) ;
    }


}

