#include <stdio.h>

void descer(int vetor[], int nelem, int i) {
    int fesq = 2 * i + 1;
    if (fesq < nelem) {
        int fdir = fesq + 1;
        int min = fesq;
        if (fdir < nelem) {
            if (vetor[fdir] < vetor[fesq]) {
                min = fdir;
            }
        }
        if (vetor[min] < vetor[i]) {
            int temp = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = temp;
            descer(vetor, nelem, min);
        }
    }
}

void imprimirVetor(int vetor[], int nelem) {
    for (int i = 0; i < nelem; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void heapfy(int vetor[], int nelem) {
    for (int i = (nelem - 1) / 2; i >= 0; i--) {
        descer(vetor, nelem, i);
    }
}

void HeapSort(int vetor[], int nelem) {
    heapfy(vetor, nelem);
    imprimirVetor(vetor, nelem);
    int pos = nelem - 1;
    while (pos > 0) {
        int temp = vetor[0];
        vetor[0] = vetor[pos];
        vetor[pos] = temp;
        descer(vetor, pos, 0);
        pos--;
    }
    imprimirVetor(vetor, nelem);
    for (int i = 0; i < nelem / 2; i++) {
        int temp = vetor[i];
        vetor[i] = vetor[nelem - 1 - i];
        vetor[nelem - 1 - i] = temp;
    }
}

int main() {
    int vetor[] = {12, 3, 45, 7, 20, 11, 9, 23};
    int nelem = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < nelem; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    HeapSort(vetor, nelem);

    imprimirVetor(vetor, nelem);

    return 0;
}
