#include <iostream>
using namespace std;

void torreHanoi(int n, string inicio, string aux, string destino) {

    if (n == 1) {//Caso base (1 disco pasa directo)
        cout << "Mueve el disco " << n << " del " << inicio << " al " << destino << endl;
    } else {//Caso general (origen->Auxiliar; Auxiliar->Destino)
        torreHanoi(n - 1, inicio, destino, aux); //Movimiento al destino
        cout << "Mueve el disco " << n << " del " << inicio << " al " << destino << endl;
        cout<<"----------------------"<<endl;
        torreHanoi(n - 1, aux, inicio, destino); //Movimiento del aux al destino
    }
}

int main()
{
    
    int elementos,movimiento;
    cout<<"Ingresa cantidad discos: ";
    cin>>elementos;
    torreHanoi(elementos,"partida","aux","llegada");
    cout<<"Apilado en el destino"<<endl;
    return 0;
}