#include <stdio.h>
#define tam 10
#define false 0
#define true 1

int main (){

    int tabla [tam] ;
    int i, encontrado, elemento, amount = 0;
    int inferior, superior, central;
    for (i=0; i<tam; i++){
        printf ("Dame el elemento de la posicion %d: ", i) ;
        scanf ("%d", &tabla[i]) ;
    }


    printf ("\nDame el elemento a buscar:") ;
    scanf ("%d", &elemento) ;
    encontrado = false;
    inferior = 0;
    superior = tam-1;

    while (inferior<=superior){
        central = (inferior + superior) / 2;
        if (tabla[central] == elemento){
            encontrado = central;
            printf("Encontrado en la posicion %d\n", central);
            amount++;
            // probar parriba
            int central1 = central;
            while(true){
                central1++;
                if(tabla[central1] == elemento){
                    printf("Encontrado en la posicion %d\n", central1);
                    amount++;
                } else{
                    break;
                }
            }
            int central2 = central;
            //probar pabajo
            while(true){
                central2--;
                if(tabla[central2] == elemento){
                    printf("Encontrado en la posicion %d\n", central2);
                    amount++;
                } else {
                    break;
                }
            }

            inferior = superior+1; // Para salir del bucle
        }else{
            if (elemento<tabla [central] ){
                superior = central - 1;
            }else{
                inferior = central + 1;
            }
        }
    }

    if(encontrado){
        printf("\nEncontrado %d veces.\n", amount);
    } else{
        printf("\nNo encontrado.\n");
    }


    return 0;
}

//           |
// 0 1 2 3 3 3 3 4 5 6
// 0 1 2 3 4 5 6 7 8 9


