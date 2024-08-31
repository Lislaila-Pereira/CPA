/* Lislaila Tarsila Pereira - 202020550
EA5 - Ferramenta Irritante de Pintura */
#include <iostream>
#include <vector>

using namespace std;

void printPinturaDepois(vector<vector<int>>& pinturaAtual, int n, int m){
    cout << "pintura depois da troca:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << pinturaAtual[i][j] << " ";
        }
            cout << endl;
    }
}

int resolverPintura(int n, int m, int r, int c, vector<string>& pinturaDesejada) {
    vector<vector<int>> pinturaAtual(n, vector<int>(m, 0));
    int operacoes = 0;

    for (int i = 0; i <= n - r; ++i) {
        for (int j = 0; j <= m - c; ++j) {
            if (pinturaAtual[i][j] != (pinturaDesejada[i][j] - '0')) {
                operacoes++;
                // cout << "a pintura desejada na posicao i= " << i <<" , j= "<< j << " ,e:" <<pinturaDesejada[i][j] << endl;
                // cout << "a pintura atual na posicao i= " << i <<" , j= "<< j << " ,e:" <<pinturaAtual[i][j] << endl;
                // cout << "precisa trocar." << endl;
                // Inverte a submatriz de tamanho r x c começando em (i, j)
                for (int x = 0; x < r; ++x) {
                    for (int y = 0; y < c; ++y) {
                        pinturaAtual[i + x][j + y] = 1 - pinturaAtual[i + x][j + y];
                    }
                }
                // printPinturaDepois(pinturaAtual, n, m);
                // cout << "numero total de trocas:" << operacoes << endl;
                
            }
        }
    }

    // Verifica se a matriz atual é igual à matriz desejada
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pinturaAtual[i][j] != (pinturaDesejada[i][j] - '0')) {
                return -1;
            }
        }
    }

    return operacoes;
}

int main() {
    while (true) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;

        if (n == 0 && m == 0 && r == 0 && c == 0)
            break;

        vector<string> pinturaDesejada(n);
        for (int i = 0; i < n; ++i) {
            cin >> pinturaDesejada[i];
        }

        int resultado = resolverPintura(n, m, r, c, pinturaDesejada);
        cout << resultado << endl;
    }

    return 0;
}