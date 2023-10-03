#include <iostream>

//problema 1

void dublare(int v[], int dim, int k) {
    if (dim > 100) {
        std::cout << "dimensiunea vectorului este prea mare";
        exit(1);
    }
    if (k > dim) {
        std::cout << "Nu exista atatea valori in vector";
        exit(1);
    }
    int pozitii[100] = { 0 };
    int min = INT_MAX;
    int pozMin = 0;
    for (int i = 0; i < k; i++) {
        int min = INT_MAX;
        for (int j = 0; j < dim; j++) {
            if (v[j] < min && pozitii[j]==0) {
                min = v[j];
                pozMin = j;
            }
        }
        pozitii[pozMin]++;
        if (pozitii[pozMin] < 2) {
            v[pozMin] *= 2;
        }
    }
}

//problema 2

void inlocuire(int v[], int dim) {
    int max1, max2, max3;
    if (dim < 3) {
        std::cout << "Nu exista 3 valori in vector!";
        exit(1);
    }
    max1 = max2 = max3 = v[0];
    int pozMax1, pozMax2, pozMax3;
    pozMax1 = pozMax2 = pozMax3 = 0;
    for (int i = 1; i < dim; i++) {
        if (v[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = v[i];
            pozMax3 = pozMax2;
            pozMax2 = pozMax1;
            pozMax1 = i;
        }
        else if (v[i] > max2) {
            max3 = max2;
            max2 = v[i];
            pozMax3 = pozMax2;
            pozMax2 = i;
        }
        else if (v[i] > max3) {
            max3 = v[i];
            pozMax3 = i;
        }
    }
    for (int i = 0; i < dim; i++) {
        if (i == pozMax1 || i == pozMax2 || i == pozMax3)
            v[i] = -1;
    }
}

int main()
{
    
    int v[10] = { 5, 3, 8, 8 ,8, 1, 2, 1, 3, 1, };
    dublare(v, 10, 5);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    return 0;
}

