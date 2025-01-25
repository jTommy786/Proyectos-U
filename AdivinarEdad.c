/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    int Matusalen, intento, num;
    Matusalen=969;
    intento=1;
    char opcion[4];
    
    do{
        intento=1;
    do{
    do{
    printf("\nAdivine la edad de Matusalen (intento: %i): ", intento);
    scanf("%i", &num);
    
    //intentos y verificacion
    if(num<0){
        printf("\nLa edad no puede ser negativa, se conserva su intento.");
    }
    }while(num<0);
    if(num==Matusalen){
        printf("\nHa adivinado la edad correctamente, Matusalen tiene 969 años!");
        break;
    }
    if(num<Matusalen){
        printf("\nLa edad de Matusalen es mayor al numero ingresado.");
    }
    if(num>Matusalen){
        printf("\nLa edad de Matusalen es menor al numero ingresado.");
    }
    
    intento+=1;
    }while(intento<=3);
    
    //volver a intentarlo
   do {
            printf("\n¿Quiere volver a intentarlo? (Si/No): ");
            scanf("%s", opcion);

            if (strcmp(opcion, "Si") != 0 && strcmp(opcion, "No") != 0 &&
                strcmp(opcion, "si") != 0 && strcmp(opcion, "no") != 0) {
                printf("\nLa opción no es válida, inténtelo nuevamente.\n");
            } else {
                break; // Salir del bucle si la opción es válida
            }
        } while (1);

    } while (strcmp(opcion, "Si") == 0 || strcmp(opcion, "si") == 0);

    return 0;
}