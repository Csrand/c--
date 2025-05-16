#include <iostream>
using namespace std;
#define TAM 6

struct arquivo{
    int tamanho;
};

void troca(arquivo  v[], int a, int b){
    int aux;
    aux = v[a].tamanho;
    v[a].tamanho = v[b].tamanho;
    v[b].tamanho = aux; 
}

void selectionSort(arquivo v[]){
    int min;
    for(int i = 0; i< TAM; i++){
        min = i;
        for(int j = i+1; j<TAM; j++){
            if(v[min].tamanho > v[j].tamanho){
                min = j;
            }
        }
        troca(v, i, min);
    } 

}

void imprimirVetor( arquivo v[]){
    for(int i = 0; i < TAM; i++){
        cout << v[i].tamanho << " ";
    }

}

int main(){
    arquivo v[TAM] = {10,9,8,7,6,5};
    
    imprimirVetor(v);
    
    selectionSort(v);
    cout << endl;
    imprimirVetor(v);

    return 0;

}