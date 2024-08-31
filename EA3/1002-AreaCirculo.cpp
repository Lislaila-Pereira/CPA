#include <iostream>
#include <iomanip>

using namespace std;

double area(double raio){
    const double n = 3.14159;
    return raio * raio * n;
}

int main() {
 
    double raio = 0;
    cin >> raio;
    cout << "A=" << fixed << setprecision(4) << area(raio) << endl;
 
    return 0;
}