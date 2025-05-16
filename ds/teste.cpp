#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
#define TAM 5


struct Pessoa{
    string nome;
    int idade;
    bool zika; 
    Pessoa* proximo;
};


void inserirInicio(Pessoa** lista, string nome, int idade, bool zika){
    Pessoa* novo = (Pessoa*) malloc(sizeof(Pessoa));
    novo->nome = nome;
    novo->idade = idade;
    novo->zika = zika;
    novo->proximo = *lista;
    *lista = novo;
}

void imprimirLista(Pessoa* lista){
    while(lista!=NULL){
        cout << "Nome: " << lista->nome << " " <<"Idade: " << lista->idade << " "
        << " É zika?: " << boolalpha << lista->zika << endl; 
        lista = lista->proximo;
    }
}


int main(){ 
    Pessoa* lista = NULL;

    inserirInicio(&lista,"csrand",23,true);
    inserirInicio(&lista,"lucas",21,false);
    inserirInicio(&lista,"romario",50,true);
    imprimirLista(lista);

    return 0;
}

