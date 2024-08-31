#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void exibir(const vector<string>& nomes) {
    for (const string& nome : nomes) {
        cout << nome << ' ';
    }
    cout << endl << endl;
}

int main() {
    int n;  // número de nomes
    int k;  // número de trocas
    int nroInstancia = 0;

    cin >> n >> k;

    do {
        vector<string> nomes(n);

        for (int i = 0; i < n; i++) {
            cin >> nomes[i];
        }

        int inicio = 0;
        int nroTrocas = k;

        while (nroTrocas != 0 && inicio < n) {
            int posMenor = inicio;

            for (int i = inicio; i <= (inicio + nroTrocas) && i < n; i++) {
                if (nomes[posMenor].compare(nomes[i]) > 0) {
                    posMenor = i;
                }
            }

            while (nroTrocas > 0 && posMenor > inicio) {
                swap(nomes[posMenor], nomes[posMenor - 1]);
                posMenor--;
                nroTrocas--;
            }

            inicio++;
        }

        cout << "Instancia " << ++nroInstancia << endl;
        exibir(nomes);

        cin >> n >> k;

    } while (!(n == 0 && k == 0));

    return 0;
}