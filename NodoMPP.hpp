#pragma once
#include <iostream>
using namespace std;

struct NodoMPP
{
    NodoMPP* next;
    NodoMPP* up;
    int dato,arrow,col;
}*arrow[5],*col[5];

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

    nuevo->arrow=fil;
    nuevo->col=col;
    nuevo->dato=dato;
    
    
}