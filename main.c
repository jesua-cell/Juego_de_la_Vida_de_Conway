#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Automata
#define M 50
#define N 80

// Estrucuturas funcionesz 
int **crearMatriz(int, int);
void inicializar(int **);
void mostrar(int **);
void pausa();
void proceso(int **, int **);

int main(){

    srand(time(NULL));
    
    int **matriz = crearMatriz(M,N);
    int **copia = crearMatriz(M,N);
    
    inicializar(matriz);

    while (1)
    {
        mostrar(matriz);
        pausa();
        proceso(matriz, copia);
    }
    
     
    return 0;
}

int **crearMatriz(int m, int n){

    int **matriz = calloc(m, sizeof(int *));
    
    // Crear las columnas
    for (int i = 0; i < m; i+=1)
    {   
        // Crear las filas
        matriz[i] = calloc(n, sizeof(int));
    }
    
    return matriz;
}

void inicializar(int **matriz){

    // Asignarle un valor a cada casillo TRUE o FALSO
    for (int i = 0; i < M; i+=1)
    {
        for (int j = 0; j < N; j+=1)
        {
            matriz[i][j] = rand()%2; // Dos valores: 0 i 1
        }
    }
}

void mostrar(int **matriz){

    system("clear");

    // Recorrer la matriz y evaluar los valores de los indices de la matriz y mostrar un caracter   
    for (int i = 0; i < M; i+=1)
    {
        for (int j = 0; j < N; j+=1)
        {
            printf("%c", (matriz[i][j] ? '#' : ' '));
        }
        
        putchar('\n');
    }
}

void pausa(){

}

void proceso(int **m, int **n){

}