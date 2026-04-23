#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Automata
#define M 70
#define N 70

// Estrucuturas funcionesz 
int **crearMatriz(int, int);
void inicializar(int **);
void mostrar(int **);
void proceso(int **, int **);
void borrarAutomata(int **matriz);
void copiarAutomata(int **orig, int **dest);
int contarVivos(int **matriz, int i, int j);

int main(){

    srand(time(NULL));
    
    int **matriz = crearMatriz(M,N);
    int **copia = crearMatriz(M,N);
    
    inicializar(matriz);

    while (1)
    {
        mostrar(matriz);
        sleep(1);
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
            printf("%c", (matriz[i][j] ? '#' : '.'));
        }
        
        putchar('\n');
    }
}

void proceso(int **matriz, int **copia){

    // Nace: si tiene tres celulas vivas nace
    // Muere: si tiene menos de dos o mas de tres vivas muere
    // Vive: una celula vive si se mantiene viva dos o mas vecinas alrededor

    // Los cambios se haran sobre la copia
    borrarAutomata(copia);
    
    // Aplicar reglas
     for (int i = 0; i < M; i+=1)
     {
        for (int j = 0; j < N; j++)
        {
            int vivas = contarVivos(matriz, i, j);
        
            if (matriz[i][j])
            {
                copia[i][j] = ((vivas >= 2 && vivas <= 3)) ? 1 : 0;
            } else {
                copia[i][j] = (vivas == 3 ? 1 : 0);   
            }
        }
    }
    copiarAutomata(copia, matriz);
}

void borrarAutomata(int **matriz){
    for (int i = 0; i < M; i+=1)
    {
        for (int j = 0; j < N; j+=1)
        {
            matriz[i][j] = 0;
        }
    }
}

void copiarAutomata(int **orig, int **dest){
    for (int i = 0; i < M; i+=1)
    {
        for (int j = 0; j < N; j+=1)
        {
            dest[i][j] = orig[i][j];
        }
    }    
}

int contarVivos(int **matriz, int i, int j){

    int vivas = 0;
    int izq = (j > 0 ? j-1 : N-1);
    int der = (j + 1) % N;
    int arr = (i > 0 ? i-1 : M-1);
    int abj = (i + 1) % M;

    if(matriz[arr][j]) vivas++;
    if(matriz[arr][der]) vivas++;
    if(matriz[i][der]) vivas++;
    if(matriz[abj][der]) vivas++;
    if(matriz[abj][j]) vivas++;
    if(matriz[abj][izq]) vivas++;
    if(matriz[i][izq]) vivas++;
    if(matriz[arr][izq]) vivas++;

    return vivas;
}
