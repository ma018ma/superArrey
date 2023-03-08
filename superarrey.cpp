#include <iostream>
using namespace std;

// Create
int *aggiungiInFondo(int base[], int dim, int nuovo)
{
    int dim2 = dim + 1;
    int arreyN[dim2];
    for (int i = 0; i < dim2; i++)
    {
        arreyN[i] = base[i];
    }
    arreyN[dim2 - 1] = nuovo;
    for (int i = 0; i < dim2; i++)
    {
        cout << arreyN[i] << endl;
    }
    return arreyN;
}
int *aggiungiInTesta(int base[], int dim, int nuovo)
{
    int dimNuova = dim + 1;
    int arreyD[dimNuova];
    arreyD[0] = nuovo;
    for (int i = 0; i < dim; i++)
    {
        arreyD[i + 1] = base[i];
    }
    for (int i = 0; i < dimNuova; i++)
    {
        cout << arreyD[i] << endl;
    }
    return arreyD;
}
int *aggiungiInPosizione(int base[], int dim, int nuovo, int posizione) // posizione 3 nuovo 5;

{
    int dimTerza = dim + 1;
    int arreyK[dimTerza];
    for (int i = 0; i < posizione; i++)
    {
        arreyK[i] = base[i];
    }
    arreyK[posizione] = nuovo;
    for (int i = posizione + 1; i < dimTerza; i++)
    {
        arreyK[i] = base[i - 1];
    }
    for (int i = 0; i < dimTerza; i++)
    {
        cout << arreyK[i] << endl;
    }

    return arreyK;
}

int trovaPosizione(int base[], int dim, int cerca)
{
    for (int i = 0; i < dim; i++)
    {
        if (cerca == base[i])
        {
            return base[i];
        }
    }
    return -1;
}
int *aggiornaInPosizione(int base[], int dim, int valore, int posizione) // valore 12 posizione 3
{
    int arreyZ[dim];
    for (int i = 0; i < dim; i++)
    {
        arreyZ[i] = base[i];
    }
    arreyZ[posizione] = valore;
    for (int i = 0; i < dim; i++)
    {
        cout << arreyZ[i] << endl;
    }
    return arreyZ;
}
int *rimuovi(int base[], int dim, int elemento) // elemento 3
{
    int dimMin = dim - 1;
    int arreyH[dimMin];
    int j=0;//indice j per tener conto dei giri di i 
    for (int i = 0; base[i]!=elemento; i++)// i di base diverso dall'elemento
    {
        arreyH[i] = base[i]; // copia in arreyH finche non trovi elemento
        j++; // j incrementa per tener conto dei giri di i 
    }
    for(int i = j;i < dim;i++) // j riprende dove lo abbiamo lasciato per copiare in arreyH
    {
        arreyH[i] = base[i+1];
    }
    for(int i = 0 ; i<dimMin;i++)
    {
        cout<< arreyH[i] << endl;
    }
    return arreyH;
}

int main()
{

    int base[] = {15, 16, 17, 18, 19, 20, 21, 22};
    int dim = sizeof(base) / sizeof(base[0]);
    int nuovo = 5;
    int cerca = 23;
    int valore = 12;
    int posizione = 3;
    int elemento = 19;

    int *arreyN = aggiungiInFondo(base, dim, nuovo);
    cout << "-------------" << endl;
    int *arreyD = aggiungiInTesta(base, dim, nuovo);
    cout << "-------------" << endl;
    int *arreyK = aggiungiInPosizione(base, dim, nuovo, posizione);
    cout << "-------------" << endl;
    cout << trovaPosizione(base, dim, cerca) << endl;
    cout << "-------------" << endl;
    int *arreyZ = aggiornaInPosizione(base, dim, valore, posizione);
    cout << "-------------" << endl;
    int *arreyH = rimuovi(base, dim, elemento);
    cout << "-------------" << endl;
}