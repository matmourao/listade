#include <iostream>
using namespace std;

void josefo(int[], int, int, int);
int sobrevivente(int, int);

int main()
{
    //Cria o array dos soldados
    int k;
    int iSoldados;
    cin >> iSoldados >> k;

    cout << sobrevivente(iSoldados, k) << endl;

    return 0;
}

void josefo(int iaRoda[], int iTotal, int iIndex, int k)
{
    if(iaRoda[1] != 0)
    {
        //Acha o indice do soldado a ser morto
        iIndex = (iIndex + k-1) % iTotal;

        //Organiza o array
        for(int i=iIndex; i<iTotal-1; i++)
        {
            iaRoda[i] = iaRoda[i+1];
        }
        iaRoda[iTotal - 1] = 0;
        iTotal = iTotal - 1;

        josefo(iaRoda, iTotal, iIndex, k);
    }
}

int sobrevivente(int iSoldados, int k)
{
    int iaRoda[iSoldados];
    for(int i=0; i<iSoldados; i++)
    {
        iaRoda[i] = i+1;
    }
    
    josefo(iaRoda, iSoldados, 0, k);
    return iaRoda[0];
}