#pragma once
#include <iostream>
using namespace std;

struct NodoMPP
{
    NodoMPP* next;
    NodoMPP* up;
    int dato,fila,columna;
}*arrow[5],*acol[5];

void insertar();

int main()
{
    

    return 0;
}


void insertar()
{
    int fil,col,dato;
    NodoMPP* nuevo = new NodoMPP();
    cout<<"Ingrese la fila: ";cin>>fil;
    cout<<"Ingrese la columna: ";cin>>col;
    cout<<"Ingrese el dato: ";cin>>dato;

    nuevo->fila=fil;
    nuevo->columna=col;
    nuevo->dato=dato;


    int i = 1;
    NodoMPP* cabecera = arrow[i];
    NodoMPP* actual = arrow[i]->next;
    NodoMPP* base = arrow[i];
    while(actual!= base)
    {
        cout<<actual->dato<<endl;
        actual=actual->next;
        if(actual==cabecera)
        {
            i++;
            cabecera = arrow[i];
            actual = arrow[i]->next;
        }
    }
}