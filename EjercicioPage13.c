#include <stdio.h>
#include <string.h>
#define false 0
#define true 1

int brute_force (char [255], char [10]) ;
int main ()
{
    char texto[255] = "Una naranja nada desnatada.";
    char patron [10];
    printf ("\nIntroduce la palabra a buscar: ") ;
    scanf ("%s", patron) ;

    printf("Buscando '%s' en '%s'\n\n",  patron, texto);
    int amount = brute_force(texto, patron);
    if (amount != 0){
        printf ("\nLa palabra se ha encontrado %d veces.\n", amount) ;
    }
    else{
        printf ("\nLa palabra NO se ha encontrado.\n") ;
    }

    return 0;
}


int brute_force (char texto [255], char patron [10])
{
    int n = strlen (texto) ;
    int m = strlen (patron);
    int amount = 0;

    int i, j;
    int match;
    for (i=0; i<n; i++){
        match = 0;
        for (j=0; j<m; j++){

            if (texto [i]==patron[ j ]){
                match++;
                i++;
            }else{
                j = m;
            }
            if (match==m){
                printf("Encontrado en el caracter %d\n", i-m+1);
                match=0;
                amount++;
            }
        }
    }


    return (amount) ;

}
