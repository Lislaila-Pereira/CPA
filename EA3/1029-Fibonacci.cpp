#include <iostream>
 
using namespace std;

int fib(int f, int &f_calls){
    f_calls++;

    if (f <= 1) {
        return f;
    }

    return fib(f - 1, f_calls) + fib(f - 2, f_calls);
}

int main() {
 
    int n = 0, f = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> f;

        int f_calls = 0;
        int resultado = fib(f, f_calls);
        
        cout << "fib(" << f << ") = " << f_calls -1 << " calls = " << resultado << endl;
    }
    return 0;
}