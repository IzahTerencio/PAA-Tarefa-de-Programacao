#include <iostream>
#include <vector>
#include<clocale>

using namespace std;

// FUNÇÃO RESPONSÁVEL POR FAZER
// O PARTICIONAMENTO DO ARRANJO
int particiona(int a[], int p, int r){
    int element = a[r];
    int indice = (p-1);
    int auxiliar = 0;

    for(int j=p; j<=(r-1); j++){
        if(a[j] <= element){
            indice = (indice + 1);
            auxiliar = 0; //limpando
            auxiliar = a[indice];
            a[indice] = a[j];
            a[j] = auxiliar;
        }
    }

    auxiliar = 0; // limpando
    auxiliar = a[indice+1];
    a[indice+1] = a[r];
    a[r] = auxiliar;

    return(indice+1);
}

// PROCEDIMENTO PRINCIPAL DA ORDENAÇÃO
void quicksort(int a[], int p, int r){
    int q = 0;

    if(p < r){
        q = particiona(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

// PROCEDIMENTO PARA EXIBIR DE MANEIRA
// FORMATADA OS ELEMENTOS DO ARRANJO.
void mostra_vetor(int a[], int tamVet){
    cout << "A = {";
    for(int i=0; i<(tamVet); i++){
        if(i != (tamVet-1)){
            cout << a[i] << ", ";
        }
        else{
            cout << a[i] << "}" << endl;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese"); // para acentuação e caracteres especiais

    int vetor[] = {9 , 10 , -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};

    int tamanho = (sizeof(vetor)/sizeof(int));
    cout << "TAMANHO DO VETOR: " << tamanho << endl;

    cout << "VETOR DE ENTRADA: ";
    mostra_vetor(vetor, tamanho);
    cout << endl;

    quicksort(vetor, 0, (tamanho-1));

    cout << "VETOR DE SAÍDA: ";
    mostra_vetor(vetor, tamanho);
    cout << endl;


    return 0;
}
