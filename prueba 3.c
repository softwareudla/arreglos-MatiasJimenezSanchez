#include <stdio.h>

int main(int argc, char *argv[]) {
    float notas[5][3];   
    char materias[3][20];  
    char estudiantes[5][40];  
    int x, y;
    float min, max, prom;
    int aprobados, reprobados;

    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        fgets(materias[i], 20, stdin);
    }

    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        fgets(estudiantes[i], 20, stdin);
    }

    for (x = 0; x < 3; x++) {
        printf("\nIngrese las calificaciones para la materia %s:\n", materias[x]);
        for (y = 0; y < 5; y++) {
            do {
                printf("Estudiante %s: ", estudiantes[y]);  
                scanf("%f", &notas[y][x]);

                if (notas[y][x] < 0 || notas[y][x] > 10) {
                    printf("Error: La calificacion debe estar entre 0 y 10. Intente de nuevo.\n");
                }
            } while (notas[y][x] < 0 || notas[y][x] > 10);
        }
    }

    printf("\nCalificaciones ingresadas:\n");
    for (x = 0; x < 3; x++) {
        printf("Materia: %s\n", materias[x]);
        for (y = 0; y < 5; y++) {
            printf("Estudiante %s: %.2f\n", estudiantes[y], notas[y][x]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\nPromedio General, nota maxima y minima por estudiante (considerando las tres materias):\n");
    for (y = 0; y < 5; y++) {
        prom = 0;
        max = notas[y][0];
        min = notas[y][0];
        printf("\nEstudiante: %s\n", estudiantes[y]);

        for (x = 0; x < 3; x++) {
            prom += notas[y][x];
            if (notas[y][x] > max) max = notas[y][x];
            if (notas[y][x] < min) min = notas[y][x];
        }
        prom /= 3;  

        printf("Promedio General: %.2f, Nota Maxima: %.2f, Nota Minima: %.2f\n", prom, max, min);
    }

    printf("_\n");
    printf("\nPromedio de Clase, nota máxima y mínima, y estudiantes aprobados y reprobados por materia:\n");
    for (x = 0; x < 3; x++) {
        prom = 0;
        min = 10;
        max = 0;
        aprobados = 0;
        reprobados = 0;
        for (y = 0; y < 5; y++) {
            if (notas[y][x] > max) max = notas[y][x];
            if (notas[y][x] < min) min = notas[y][x];
            prom += notas[y][x];

            if (notas[y][x] >= 6) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        prom /= 5;  

        printf("\nMateria: %s - Promedio de Clase: %.2f, Nota Máxima: %.2f, Nota Mínima: %.2f\n", 
               materias[x], prom, max, min);
        printf("Estudiantes aprobados: %d, Estudiantes reprobados: %d\n", aprobados, reprobados);
    }

    return 0;
}