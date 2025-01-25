#include <stdio.h>
#include <math.h>

// Definición de los colores usando códigos ANSI
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BG_CYAN "\x1b[46m" // Fondo cian
#define WHITE   "\x1b[37m" // Texto blanco

int main() {
    // Carátula
    printf(BG_CYAN WHITE "------------------------------------------------------------\n" RESET);
    printf(BG_CYAN WHITE "|                   Proyecto Integrador                    |\n" RESET);
    printf(BG_CYAN WHITE "|                Matemáticas Discretas                     |\n" RESET);
    printf(BG_CYAN WHITE "|                  Integrantes:                            |\n" RESET);
    printf(BG_CYAN WHITE "|                Juan Garces y Julian Bonilla              |\n" RESET);
    printf(BG_CYAN WHITE "|                   NCR: 5535                              |\n" RESET);
    printf(BG_CYAN WHITE "------------------------------------------------------------\n" RESET);

    printf("\n");
    printf(BG_CYAN WHITE "------------------------------------------------------------\n" RESET);
    printf(BG_CYAN WHITE "|               Universidad de las Américas (UDLA)         |\n" RESET);
    printf(BG_CYAN WHITE "------------------------------------------------------------\n" RESET);

    printf("\n");
    printf(RED "        **       **        \n" RESET);
    printf(RED "      *      *   *      *      \n" RESET);
    printf(RED "    *         * *         *    \n" RESET);
    printf(RED "   *           **           **   \n" RESET);
    printf(RED "  *             *             *  \n" RESET);
    printf(RED "    *                       *    \n" RESET);
    printf(RED "      *                   *       \n" RESET);
    printf(RED "        *               *         \n" RESET);
    printf(RED "          *           *           \n" RESET);
    printf(RED "            *       *             \n" RESET);
    printf(RED "              *   *               \n" RESET);
    printf(RED "                 **                 \n" RESET);

    printf("\n");
    printf(YELLOW "          U   U  DDDDD   L       AAAAA\n");
    printf(YELLOW "          U   U  D    D  L      A     A\n");
    printf(YELLOW "          U   U  D    D  L      AAAAAAA\n");
    printf(YELLOW "          U   U  D    D  L      A     A\n");
    printf(YELLOW "           UUU   DDDDD   LLLLL  A     A\n");
    printf("\n\n" RESET);

    // Variables iniciales
    int variables;
    char nombres[] = {'A', 'B', 'C'}; // Letras para las variables

    // Solicitar el número de variables booleanas
    do {
        printf("Ingrese el número de variables booleanas (2 o 3): ");
        if (scanf("%i", &variables) != 1 || variables < 2 || variables > 3) {
            printf("Error, ingrese un número aceptado de variables (2 o 3).\n");
            while (getchar() != '\n'); // Limpiar el buffer
            variables = 0; // Reiniciar la variable para mantener el ciclo
        }
    } while (variables < 2 || variables > 3);

    int filas = pow(2, variables); // 2^n combinaciones
    int tabla[filas][3];           // Máximo 3 variables
    int salida[filas];

    // Generar la tabla de verdad
    printf("\nTabla de verdad generada:\n");
    for (int i = 0; i < variables; i++) {
        printf("%c ", nombres[i]);
    }
    printf(YELLOW "Salida\n" RESET);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            tabla[i][j] = (i >> (variables - j - 1)) & 1; // Generar valores binarios
            printf("%d ", tabla[i][j]);
        }
        printf("\n");
    }

    // Pedir al usuario las salidas
    printf("\nIngrese los valores de salida (0 o 1) para cada fila:\n");
    for (int i = 0; i < filas; i++) {
        int entrada;
        do {
            printf("Fila %i: ", i + 1);
            if (scanf("%i", &entrada) != 1 || (entrada != 0 && entrada != 1)) {
                printf("Error, ingrese un valor válido (0 o 1).\n");
                while (getchar() != '\n'); // Limpiar el buffer
                entrada = -1; // Reiniciar para mantener el ciclo
            }
        } while (entrada != 0 && entrada != 1);
        salida[i] = entrada;
    }

    // Construir y mostrar la expresión SOP
    printf("\nExpresión SOP:\n");
    int primera = 1; // Indicador para el primer término
    for (int i = 0; i < filas; i++) {
        if (salida[i] == 1) { // Solo filas con salida 1
            if (!primera) {
                printf(" + ");
            }
            printf("(");
            for (int j = 0; j < variables; j++) {
                if (j > 0) {
                    printf(" * ");
                }
                if (tabla[i][j] == 1) {
                    printf("%c", nombres[j]);
                } else {
                    printf("%c'", nombres[j]);
                }
            }
            printf(")");
            primera = 0;
        }
    }
    printf("\n");

    // Mostrar tabla de verdad de cada término
    printf("\nTablas de verdad individuales para cada término de la expresión SOP:\n");

    for (int i = 0; i < filas; i++) {
        if (salida[i] == 1) {
            printf("\nTérmino %d:\n", i + 1);
            for (int j = 0; j < variables; j++) {
                if (tabla[i][j] == 1) {
                    printf("%c", nombres[j]);
                } else {
                    printf("%c'", nombres[j]);
                }
                if (j < variables - 1) {
                    printf(" * ");
                }
            }
            printf("\n");
            printf("Tabla de verdad:\n");
            for (int j = 0; j < filas; j++) {
                int resultado = 1;
                for (int k = 0; k < variables; k++) {
                    if (tabla[i][k] == 1) {
                        resultado &= tabla[j][k];
                    } else {
                        resultado &= !tabla[j][k];
                    }
                }
                for (int k = 0; k < variables; k++) {
                    printf("%d ", tabla[j][k]);
                }
                printf("=> %d\n", resultado);
            }
        }
    }

    // Mostrar tabla de verdad final
    printf("\nTabla final con salidas:\n");
    for (int i = 0; i < variables; i++) {
        printf("%c ", nombres[i]);
    }
    printf(YELLOW "Salida\n" RESET);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < variables; j++) {
            printf("%d ", tabla[i][j]);
        }
        printf(YELLOW "%d\n" RESET, salida[i]);
    }

    return 0;
}
