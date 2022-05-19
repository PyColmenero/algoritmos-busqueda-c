#include <stdio.h>
#define tam 10
#define false 0
#define true 1

int main (){

    int tabla [tam] ;
    int i, elemento, amount = 0;
    for (i=0; i<tam; i++){
        printf ("Dame el elemento de la posicion %d:", i) ;
        scanf ("%d", &tabla[i] ) ;
    }

    printf ("\nDame el elemento a buscar: ") ;
    scanf ("%d", &elemento) ;
    i = 0;

    while ( i<tam ){
        if (tabla[i] == elemento){
            printf("\nEncontrado en la posicion %d", i);
            amount++;
        }
        i++;
    }

    if (amount != 0)
    {

        printf ("\nEl elemento a buscar se ha encontrado %d veces\n", amount);
    }

    else{
        printf ("\nEl elemento a buscar NO se ha encontrado\n") ;
    }


    return 0;
}
