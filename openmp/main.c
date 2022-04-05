//Libreria necesaria para realizar tareas de paralelizaci�n
#include <omp.h>
//Librerias generales para imprimir informaci�n en consolo
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    //Declaraci�n de matrices de 32x32 bidimensionales
	int A[32][32];
	int B[32][32];
	int C[32][32];
	//Ciclo for para asignar valores a las matrices A y B
	//Que serviran para realizar la suma de estar dos
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 32; ++j) {
            //Por cada posicion, se le asignara el valor de 2 a la matriz A y 3 a la B
			A[i][j] = 2;
			B[i][j] = 3;
		}
	}
//Declaraci�n de funci�n de paralelismo de librerio OpenMP
#pragma omp parallel
	{
	    //Hilo actual: Se obtiene utilizando la funci�n asignada a la variable id
		int id = omp_get_thread_num();
		//nt es la variable que asigna la cantidad de hilos
		int nt = omp_get_num_threads();
		//Tama�o de nuestras matrices sobre la cantidad de hilos
		//El n�mero de hilos del equipo es de 8
		//Por lo tanto 32/8 = 4
		int size = (int) 32 / nt;
		//Inicializaci�n q sera requerido en nuestro ciclo
		//Id de nuestro primero hilo = 0
		//Size de nuestra matriz = 4
		//Primero valor sera 0 * 4 = 0
		int ini = id * size;
		//Tama�o de valores que agarrar� el hilo
		//Ini = 0 + size = 4 - 1 == 3
		//Nuestro fin sera 3 en el primer valor
		int fin = ini + size - 1;
		//En nuestro for se agarraran los valores que obtuvimos
		//En el primer ciclo, cada hilo agarrara 4 filas
		//Obteniendo as� los resultados y haciendo m�s rapido la ejecuci�n
		//Nuestra soluci�n
		for (int i = ini; i < fin; ++i) {
			for (int j = 0; j < 32; ++j) {
                //Aqui solo se suma los valores asignados en nuestras ciclos anteriores
				C[i][j] = A[i][j] + B[i][j];
			}
		}
	}

	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 32; ++j) {
            //Impresi�n de valores
			printf("C[%d][%d] = %d \n", i, j, C[i][j]);
		}
	}
	return 0;
}
