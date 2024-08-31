#include <iostream>
#include <vector>

using namespace std;

// Função para combinar duas sublistas ordenadas
void combinar(vector<int>& esquerda, vector<int>& direita, vector<int>& resultado) {
    int idxEsquerda = 0, idxDireita = 0, idxResultado = 0;
    int tamanhoEsquerda = esquerda.size(), tamanhoDireita = direita.size();

    while (idxEsquerda < tamanhoEsquerda && idxDireita < tamanhoDireita) {
        if (esquerda[idxEsquerda] < direita[idxDireita]) {
            resultado[idxResultado] = esquerda[idxEsquerda];
            idxEsquerda++;
        } else {
            resultado[idxResultado] = direita[idxDireita];
            idxDireita++;
        }
        idxResultado++;
    }
    
    while (idxEsquerda < tamanhoEsquerda) {
        resultado[idxResultado] = esquerda[idxEsquerda];
        idxResultado++;
        idxEsquerda++;
    }
    
    while (idxDireita < tamanhoDireita) {
        resultado[idxResultado] = direita[idxDireita];
        idxResultado++;
        idxDireita++;
    }
}

// Função de ordenação por merge sort
void ordenarMerge(vector<int>& vetor) {
    if (vetor.size() > 1) {
        int meio = vetor.size() / 2;
        vector<int> parteEsquerda(vetor.begin(), vetor.begin() + meio);
        vector<int> parteDireita(vetor.begin() + meio, vetor.end());

        ordenarMerge(parteEsquerda);
        ordenarMerge(parteDireita);
        combinar(parteEsquerda, parteDireita, vetor);
    }
}

int main() {
    int quantidade;                           
    while (cin >> quantidade) {
        int k;                                
        cin >> k;

        vector<int> posicoes(quantidade);
        posicoes[0] = 0;

        vector<int> distancias(quantidade);
        distancias[0] = 0;

        for (int i = 1; i < quantidade; i++) {
            cin >> posicoes[i];
            distancias[i] = posicoes[i] - posicoes[i - 1];
        }
        
        ordenarMerge(distancias);

        int somaSubgrupos = 0;
        for (int i = 0; i < quantidade - k + 1; i++) {
            somaSubgrupos += distancias[i];
        }
        cout << somaSubgrupos << endl;
    }
}
