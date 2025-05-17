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

int contarPessoas(Pessoa* lista, int* totalPessoas){
    *totalPessoas = 0;
    if(lista == NULL){
        cout << "Nenhuma Pessoa Cadastrada\n";
        return 0;
    }
    
    while (lista!=NULL){
        (*totalPessoas)++;
        lista = lista->proximo;
    }
    return *totalPessoas;
}

void imprimirLista(Pessoa* lista){
    while(lista!=NULL){
        cout << "Nome: " << lista->nome << " " <<"Idade: " << lista->idade << " "
        << " É zika?: " << boolalpha << lista->zika << endl; 
        lista = lista->proximo;
    }
}

void imprimirListaRecursiva(Pessoa* lista, int* totalPessoas){
    if(*totalPessoas > 0 && lista != NULL){
        cout << "Nome: " << lista->nome << " " <<"Idade: " << lista->idade << " "
        << " É zika?: " << boolalpha << lista->zika << endl;
        (*totalPessoas)--;
        imprimirListaRecursiva(lista->proximo, totalPessoas);
    }
    
}


int main(){ 
    Pessoa* lista = NULL;
    
    inserirInicio(&lista,"csrand",23,true);
    inserirInicio(&lista,"lucas",21,false);
    inserirInicio(&lista,"romario",50,true);
    imprimirLista(lista);
    int totalPessoas = contarPessoas(lista, &totalPessoas);
    cout << "O Total de Pessoas Cadastradas é: "<< totalPessoas << endl;
    cout << endl;
    imprimirListaRecursiva(lista, &totalPessoas);

    return 0;
}

