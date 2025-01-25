/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // Para validar si el monto es decimal

// Estructura para usuarios
typedef struct {
    char username[50];
    char password[50];
} User;

// Precios de los boletos
#define VIP 1000
#define PREFERENTE 700
#define GENERAL 500

// Funciones
int login(User users[], int userCount);
void registrarUsuario(User users[], int *userCount);
void mostrarMenu();
void gestionarVenta();
void calcularCambio(int cambio);

int main() {
    // Usuarios registrados
    User users[100];
    int userCount = 0;

    printf("Bienvenido al sistema de gestion de boletos del teatro.\n\n");

    int opcion;
    do {
        printf("--- Menu de Inicio ---\n");
        printf("1. Registrar usuario\n");
        printf("2. Iniciar sesion\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarUsuario(users, &userCount);
                break;
            case 2:
                if (login(users, userCount)) {
                    int subOpcion;
                    do {
                        mostrarMenu();
                        printf("\nSeleccione una opcion: ");
                        scanf("%d", &subOpcion);

                        switch (subOpcion) {
                            case 1:
                                gestionarVenta();
                                break;
                            case 2:
                                printf("Saliendo del sistema.\n");
                                break;
                            default:
                                printf("Opcion no valida. Intente nuevamente.\n");
                        }
                    } while (subOpcion != 2);
                } else {
                    printf("Inicio de sesion fallido.\n");
                }
                break;
            case 3:
                printf("Gracias por usar el sistema.\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

    return 0;
}

void registrarUsuario(User users[], int *userCount) {
    char username[50], password[50];

    printf("\n--- Registro de Usuario ---\n");
    printf("Ingrese un nombre de usuario: ");
    scanf("%s", username);
    printf("Ingrese una contrasena: ");
    scanf("%s", password);

    strcpy(users[*userCount].username, username);
    strcpy(users[*userCount].password, password);
    (*userCount)++;

    printf("Usuario registrado con exito.\n\n");
}

int login(User users[], int userCount) {
    char inputUsername[50], inputPassword[50];

    printf("\n--- Inicio de Sesion ---\n");
    printf("Usuario: ");
    scanf("%s", inputUsername);
    printf("Contrasena: ");
    scanf("%s", inputPassword);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, inputUsername) == 0 && strcmp(users[i].password, inputPassword) == 0) {
            printf("Inicio de sesion exitoso.\n\n");
            return 1;
        }
    }

    printf("Usuario o contrasena incorrectos.\n\n");
    return 0;
}

void mostrarMenu() {
    printf("\n--- Menu Principal ---\n");
    printf("1. Gestionar venta de boletos\n");
    printf("2. Salir\n");
}

void gestionarVenta() {
    int tipoBoleto, cantidad, total = 0, cambio;
    double pago;

    printf("\n--- Venta de boletos ---\n");

    do {
        printf("Seleccione el tipo de boleto:\n");
        printf("1. VIP ($%d)\n", VIP);
        printf("2. Preferente ($%d)\n", PREFERENTE);
        printf("3. General ($%d)\n", GENERAL);
        printf("Opcion: ");
        scanf("%d", &tipoBoleto);

        if (tipoBoleto < 1 || tipoBoleto > 3) {
            printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (tipoBoleto < 1 || tipoBoleto > 3);

    do {
        printf("Ingrese la cantidad de boletos: ");
        scanf("%d", &cantidad);

        if (cantidad <= 0) {
            printf("La cantidad debe ser un numero positivo. Intente nuevamente.\n");
        }
    } while (cantidad <= 0);

    switch (tipoBoleto) {
        case 1:
            total += VIP;
            break;
        case 2:
            total += PREFERENTE;
            break;
        case 3:
            total += GENERAL;
            break;
    }

    total *= cantidad;
    printf("El costo total es: $%d\n", total);

    do {
        printf("Ingrese el monto pagado: ");
        scanf("%lf", &pago);

        double parteEntera;
        if (modf(pago, &parteEntera) != 0.0) {
            printf("El valor a pagar es en pesos, por favor no ingrese el monto en decimales.\n");
            continue;
        }

        if ((int)pago < total) {
            printf("El monto pagado es insuficiente. Intente nuevamente.\n");
        } else {
            cambio = (int)pago - total;
            printf("Cambio a devolver: $%d\n", cambio);
            printf("Desglose del cambio:\n");
            calcularCambio(cambio);
            break;
        }
    } while (1);
}

void calcularCambio(int cambio) {
    int billetes100 = cambio / 100;
    cambio %= 100;
    int billetes50 = cambio / 50;
    cambio %= 50;
    int monedas10 = cambio / 10;
    cambio %= 10;
    int monedas5 = cambio / 5;
    cambio %= 5;
    int monedas2 = cambio / 2;
    cambio %= 2;
    int monedas1 = cambio;

    if (billetes100 > 0) printf("%d billete(s) de $100\n", billetes100);
    if (billetes50 > 0) printf("%d billete(s) de $50\n", billetes50);
    if (monedas10 > 0) printf("%d moneda(s) de $10\n", monedas10);
    if (monedas5 > 0) printf("%d moneda(s) de $5\n", monedas5);
    if (monedas2 > 0) printf("%d moneda(s) de $2\n", monedas2);
    if (monedas1 > 0) printf("%d moneda(s) de $1\n", monedas1);
}

