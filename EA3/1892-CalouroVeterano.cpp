#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<string>& arr, int inicio, int meio, int fim) {
    vector<string> esquerda(arr.begin() + inicio, arr.begin() + meio + 1);
    vector<string> direita(arr.begin() + meio + 1, arr.begin() + fim + 1);

    long long inversoes = 0;

    int i = 0, j = 0, k = inicio;
    while (i < esquerda.size() && j < direita.size()) {
        if (esquerda[i] > direita[j]) {
            arr[k++] = direita[j++];
            inversoes += meio - inicio + 1 - i; // contagem de inversões
        } else {
            arr[k++] = esquerda[i++];
        }
    }

    while (i < esquerda.size()) {
        arr[k++] = esquerda[i++];
    }

    while (j < direita.size()) {
        arr[k++] = direita[j++];
    }

    return inversoes;
}

// Função que ordena o vetor e conta as inversões usando o Merge Sort
long long mergeSort(vector<string>& arr, int inicio, int fim) {
    long long inversoes = 0;

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        inversoes += mergeSort(arr, inicio, meio);
        inversoes += mergeSort(arr, meio + 1, fim);
        inversoes += merge(arr, inicio, meio, fim);
    }

    return inversoes;
}

int main() {
    int numero_alunos;
    while (cin >> numero_alunos) {
        if (numero_alunos == 0)
            break;

        vector<string> classificacoes(numero_alunos);
        for (int i = 0; i < numero_alunos; i++) {
            cin >> classificacoes[i];
        }

        long long inversoes = mergeSort(classificacoes, 0, numero_alunos - 1);
        cout << inversoes << endl;
    }

    return 0;
}