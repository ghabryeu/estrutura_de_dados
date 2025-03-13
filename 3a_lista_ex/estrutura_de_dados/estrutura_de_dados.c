#include <stdio.h>

int buscaBinaria(int arr[], int n, int valor) {
	
	int esq = 0;
	int dir = n - 1;

	while (esq <= dir) {
		int meio = (esq + dir) / 2;

		if (arr[meio] == valor) {
			return meio;
		}
		else if (arr[meio] > valor) {
			dir = meio - 1;
		}
		else {
			esq = meio + 1;
		}
	}
	return -1;
}

int potencia(int a, int b) {
	if (b == 0) {
		return 1;
	}

	return a * potencia(a , b - 1);
}

int main(void) {

	int arr[] = { 2, 3, 4, 5, 6, 7 };
	int n = 6;
	int valor = 10;

	//int resultado = buscaBinaria(arr, n, valor);
	//printf("%d", resultado);

	int result = potencia(3, 2);
	printf("%d", result);

	return 0;
}