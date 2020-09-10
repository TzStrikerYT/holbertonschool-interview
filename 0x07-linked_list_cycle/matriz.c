#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int filas;
	int columnas;
	int i = 0;
	int j = 0;
	int z = 0;
	int x = 0;
	int n = 1;
	int suma = 0;

	//solicitd de datos
	printf("Ingrese el numero de filas\n");
	scanf("%d", &filas);

	printf("ingrese el numero de columnas\n");
	scanf("%d", &columnas);

	int matrizA[filas][columnas];
	int transA[filas][columnas];
        int matrizB[filas][columnas];
	int resultado[filas][columnas];

	printf("\n\n\nMatrizA\n\n");
	for (i = 0; i < columnas; i++) {
		for (j = 0; j < filas; j++) {
			printf("ingrese el valor %d\n", n);
			scanf("%d", &matrizA[i][j]);
			n++;
		}
	}

	//impresion original
	printf("Matriz A\n\n");
	for (i = 0; i < columnas; i++) {
		printf("\n");
                for (j = 0; j < filas; j++) {
                        printf("%d ", matrizA[i][j]);
                }
        }

	//transposicionacion
        for (i = 0; i < columnas; i++) {
                for (j = 0; j < filas; j++) {
                        transA[i][j] = matrizA[j][i];
		}
	}

        printf("\n\nTransposicion\n\n");
	//impresion transponida
	for (i = 0; i < columnas; i++) {
		printf("\n");
		for (j = 0; j < filas; j++) {
			printf("%d ", transA[i][j]);
		}
	}

	n = 1;
	printf("\n\n\nMatrizB\n\n");
        for (i = 0; i < columnas; i++) {
                for (j = 0; j < filas; j++) {
                        printf("ingrese el valor %d\n", n);
                        scanf("%d", &matrizB[i][j]);
                        n++;
                }
	}

	//impresion original
        printf("Matriz B\n\n");
	for (i = 0; i < columnas; i++) {
		printf("\n");
		for (j = 0; j < filas; j++) {
			printf("%d ", matrizB[i][j]);
		}
	}


	//calculo
	printf("\n\n\nMultiplicacion\n\n");

	for (z = 0; z < columnas; z++) {
		for (i = 0; i < filas; i++) {
			suma = 0;
			for (j = 0; j < columnas; j++) {
				suma += transA[i][j] * matrizB[j][z];
			}
			resultado[i][z] = suma;
		}
	}

	//impresion resultado
	printf("Resultado \n\n");
        for (i = 0; i < columnas; i++) {
		printf("\n");
		for (j = 0; j < filas; j++)
			printf("%d ", resultado[i][j]);
        }
	printf("/n");

}
