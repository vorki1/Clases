#pragma once
#include <iostream>
using namespace std;

class Camion
{
    private:
        int peso;
        string id;
    public:
        Camion(int,string);
        int getPeso();
};
Camion::Camion(int peso,string id)
{
    this->peso=peso;
    this->id=id;
}
int Camion::getPeso()
{
    return peso;
}