/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int contador;
    contador=1;
    float acumuladorDiametro, acumuladorAltura, diametro, altura, promedioDiametro, promedioAltura, mayorDiametro, menorDiametro, mayorAltura, menorAltura; 
    mayorDiametro=0;
    menorDiametro=99999;
    mayorAltura=0;
    menorAltura=99999;
    char opcion;
    
    printf("--Diametros y Alturas de Cipreses.--");
    do{
        do{
            printf("\nIngrese el diametro del cipres #%i en CM:", contador);
            scanf("%f", &diametro);
                if(diametro<1){
                    printf("\n*Ingrese un valor valido.*");
            }
        }while(diametro<1);
        do{
            printf("\nIngrese la altura del cipres #%i en M:", contador);
            scanf("%f", &altura);
                if(altura<1){
                    printf("\n*Ingrese un valor valido.*");
                }
        }while(altura<1);
        
            if(diametro>=mayorDiametro){
            mayorDiametro=diametro;
            }
            if(diametro<=menorDiametro && diametro<mayorDiametro){
                menorDiametro=diametro;
            }
            if(altura>=mayorAltura){
            mayorAltura=altura;
            }
            if(altura<=menorAltura && altura<mayorAltura){
                menorAltura=altura;
            }
                acumuladorDiametro+=diametro;
                promedioDiametro=acumuladorDiametro/contador;
                acumuladorAltura+=altura;
                promedioAltura=acumuladorAltura/contador;
                
        contador++;
        printf("---------------------------------------------------------------");
        printf("\nDesea ingresar el diametro y altura de otro cipres? [S|N]");
        scanf(" %c", &opcion);
    }while(opcion=='S' || opcion=='s');
        printf("---------------------------------------------------------------");
        
        printf("\nEl Diametro Mayor  es: %fcm", mayorDiametro);
        printf("\nEl Diametro Menor  es: %fcm", menorDiametro);
        printf("\n\nLa Altura Mayor es: %fm", mayorAltura);
        printf("\nLa Altura Menor es: %fm", menorAltura);
        printf("\n\nEl promedio del Diametro es: %fcm", promedioDiametro);
        printf("\nEl promedio de la Altura es: %fm", promedioAltura);

    return 0;
}