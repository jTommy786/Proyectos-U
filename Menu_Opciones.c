/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int opcion;
    float numero, mayor, cantidad, acum, promedio;
    mayor=0;
    acum=0;
    cantidad=0;
    promedio=0;
    
    do{
    printf("\n---------------------------");
    printf("\nMenu.");
     printf("\n1. Numeros a ingresar.");
      printf("\n2. Promedio de numeros.");
       printf("\n3. Mayor de los numeros.");
        printf("\n4. Salir.");
        printf("\nOpcion: ");
        scanf("%i", &opcion);
        
        if(opcion>4){
            printf("\nLa opcion es diferente a las opciones.");
        }
        
        if(opcion==1){
            mayor=0;
            acum=0;
            cantidad=0;
            promedio=0;
            numero=0;
            printf("\nIngrese la cantidad de numeros a ingresar: ");
            scanf("%f", &cantidad);
            for(int i=1; i<=cantidad; i++){
                printf("\n%i Ingrese el numero: ", i);
                scanf("%f", &numero);
                acum=acum+numero;
                promedio=acum/cantidad;
                if(numero>mayor){
                    mayor=numero;
                }
            }
        }
        if(opcion==2){
            
            if(promedio==0){
                printf("\nEl promedio es 0");
            }else{
                printf("\nEl promedio de %f/%f es: %f", acum, cantidad, promedio);
            }
        }
        if(opcion==3){
            if(cantidad==0){
            printf("\nIngrese valores");
            }else{
                 printf("\nEl numero mayor es: %f", mayor);
            }
        }
        if(opcion==4){
            break;
        }
        
    }while(opcion!=4);
    

    return 0;
}
