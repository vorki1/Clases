#include <iostream>
using namespace std;

void torreHanoi(int disco, string partida, string aux, string llegada) {

    if (disco == 1) //Caso base
    {
        cout<<"----------------------"<<endl;
        cout << "Se mueve el disco " << disco << " del " << partida << " al " << llegada << endl;
    } 
    else 
    {
        torreHanoi(disco - 1, partida, llegada, aux);
        cout << "Se mueve el disco " << disco << " del " << partida << " al " << llegada << endl;
        cout<<"----------------------"<<endl;
        torreHanoi(disco - 1, aux, partida, llegada);
    }
}

int main()
{
    
    int discos;
    cout<<"Ingresa cantidad discos: ";
    cin>>discos;
    torreHanoi(discos,"partida","aux","llegada");
    cout<<"----------------------"<<endl;
    cout<<" "<<endl;
    cout<<"Apilado en el llegada"<<endl;
    return 0;
}
