/*Examen progreso 3
Construya un programa que lea los datos de un archivo plano que contiene los datos de un conjunto de estudiantes, ordenados en función de su código, 
y genere un nuevo archivo ordenado de mayor a menor e incluya el cálculo de la nota promedio.
Utilice los conceptos de: Funciones, Punteros, Estructuras, Archivos.
Hecho por Brandon Arellano
Programacion 1
Universidad de las Americas
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nombre[50];
    char carrera[50];
    float nota1,nota2,nota3;
    float promedio;
    } Estudiante;

void ordenarEstudiantes(Estudiante *estudiantes, int numEstudiantes);
float calcularPromedio(Estudiante *estudiantes, int numEstudiantes);
void archivoOrdenado(Estudiante *estudiantes, int numEstudiantes);


int main(){

    int numEstudiantes;
    Estudiante *estudiantes;

    // Abrir archivo de entrada
    FILE *archivoEntrada = fopen("alumnos.txt", "r");
    if (archivoEntrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    fscanf(archivoEntrada, "%d", &numEstudiantes);

    estudiantes  = (Estudiante*) malloc (numEstudiantes * sizeof(Estudiante));
    if (estudiantes == NULL) {
        printf("Error de memoria.\n");
        return 1;
    }

    for (int i = 0; i < numEstudiantes; i++) {
        fscanf(archivoEntrada, "%d;%[^;];%[^;];%f;%f;%f\n", &(estudiantes[i].codigo), estudiantes[i].nombre, estudiantes[i].carrera, &(estudiantes[i].nota1), &(estudiantes[i].nota2), &(estudiantes[i].nota3));
        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3) / 3;
    }

    fclose(archivoEntrada);


    return 0;
}

void ordenarEstudiantes(Estudiante *estudiantes, int numEstudiantes) {
    for (int i = 0; i < numEstudiantes - 1; i++) {
        for (int j = 0; j < numEstudiantes - i - 1; j++) {
            if (estudiantes[j].codigo > estudiantes[j + 1].codigo) {
                
                Estudiante temp = estudiantes[j];
                
                estudiantes[j] = estudiantes[j + 1];
                
                estudiantes[j + 1] = temp;
            }
        }
    }
}

float calcularPromedio(Estudiante *estudiantes, int numEstudiantes){
    float suma = 0; 
    for (int i =0; i < numEstudiantes; i--){
        suma += estudiantes[i].promedio;
    }

    return suma / numEstudiantes;

}

void archivoOrdenado(Estudiante *estudiantes, int numEstudiantes){
    FILE *archivoReordenado  = fopen("alumnos.txt", "w+") ; 
    if (archivoReordenado == NULL) {
        printf("Error no se pudo abrir el archivo.\n");
        return 1;
    }

    fprintf(archivoOrdenado, "%d\n", numEstudiantes);

    for (int i=0; i<numEstudiantes; i++){
        fprintf(archivoReordenado;"%d;%s;%s;%f;%f;%f;%f", estudiantes[i].codigo, estudiantes[i].nombre, estudiantes[i].nota1,estudiantes[i].nota2,estudiantes[i].nota3,estudiantes[i].promedio);
    }

    fclose(archivoReordenado);

}