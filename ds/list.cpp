#include <iostream>
using namespace std;

struct No{
    int valor;
    No* proximo;
};

void inserirInicio(No** lista, int n){
    No* novoValor = (No*) malloc(sizeof(No));
    novoValor ->valor = n;
    novoValor -> proximo = *lista;
    *lista = novoValor;
}

void imprimirLista(No*lista){
    No* atual = lista;
    while(atual !=NULL){
        cout << atual -> valor << " ";
        atual = atual -> proximo;
    
    }
    cout << endl;
}
void removerInicio(No** lista){
    
    No* temporario = *lista;
    if(temporario != NULL){
        *lista = temporario -> proximo;
        free(temporario);
    }
}
void removerFim(No** lista){
    
    No* atual = *lista;
    while(atual -> proximo != NULL){
        atual = lista -> proximo;
    }
    

    
}

void liberarLista(No* lista) {
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}





void inserirFim(No** lista, int n){
    
    No* novo = (No*) malloc(sizeof(No));
    novo -> valor = n;
    novo -> proximo = NULL;
  
    if (*lista == NULL){
        *lista = novo;
    } else{
        No* atual = *lista;
        while(atual -> proximo != NULL){
            atual = atual -> proximo;
        }
        atual -> proximo = novo;
    }
}
        
int main(){
    No* lista = NULL;
    inserirInicio(&lista,10);
    inserirInicio(&lista,30);
    inserirFim(&lista,100);
    inserirInicio(&lista,30);
    inserirInicio(&lista,30);
    inserirFim(&lista,100);
    inserirInicio(&lista,150);
    imprimirLista(lista);
    removerInicio(&lista);
    imprimirLista(lista);
    return 0;
}    

