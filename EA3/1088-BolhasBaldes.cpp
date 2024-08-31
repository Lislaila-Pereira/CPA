#include <iostream>
using namespace std;

void merge(int l[], int r[], int a[], int n, int m, unsigned int& numeroDeTrocas) {
	int i = 0, j = 0, k = 0;

	while(i < n and j < m){
		if (l[i] < r[j]) {
			a[k] = l[i];
			i++;
		}
		else {
			a[k] = r[j];
			j++;
			numeroDeTrocas = numeroDeTrocas + n - i;
		}
		k++;
	}
	while (i < n) {
		a[k] = l[i];
		k++;
		i++;
	}
	while (j < m) {
		a[k] = r[j];
		k++;
		j++;
	}
}

void mergeSort(int vetor[], int tamanho, unsigned int& numeroDeTrocas) {
	if (tamanho > 1) {
		int meio = tamanho / 2;
		int l[meio];
		int r[tamanho - meio];
		for (int i = 0; i < meio; i++) {
			l[i] = vetor[i];
		}
		for (int i = meio; i < tamanho; i++) {
			r[i - meio] = vetor[i];
		}

		mergeSort(l, meio, numeroDeTrocas);
		mergeSort(r, tamanho - meio, numeroDeTrocas);
		merge(l, r, vetor, meio, tamanho - meio, numeroDeTrocas);
	}
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		int vetor[n];
		for (int i = 0; i < n; i++) {
			cin >> vetor[i];
		}

		unsigned int numeroDeTrocas = 0;
		mergeSort(vetor, n, numeroDeTrocas);
		cout << (((numeroDeTrocas % 2) == 0) ? "Carlos" : "Marcelo") << endl;

		cin >> n;
	}
	return 0;
}