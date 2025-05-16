#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node* proximo;
};

void inserirNoInicio(Node* &head, int novoValor){
    Node* novoNo = new Node;
    novoNo -> valor = novoValor;
    novoNo -> proximo = head;
    head = novoNo;
}

int contarOcorrencia(Node* &head, int n){
    contador = 0;
    Node* atual = head;
    while(atual != nullptr){
        if(atual ->valor == n){
            contador ++
        }
        atual = atual -> proximo;

    }
    return contador;
}

void removerNoInicio(Node* &head){
    if(head!=nullptr){
         // verificar se a lista esta vazia
        Node* temporario = head;
        head = head->proximo; // aqui eu queria que o head comecasse a apontar para oonde o proximo esta apontando
        delete temporario;
        cout <<"primeiro no removido\n";
    }
    else {
        cout << "Lista vazia";
    }
}

void imprimirLista(Node* &head){
    Node* atual = head;
    cout << "Lista: ";
    while(atual != nullptr){
        cout << atual -> valor << " ";
        atual = atual -> proximo;
    }
    cout << endl;
}
void liberarLista(Node* &head){
    Node* atual = head;
    Node* proximo;
    while(atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo; 
    }
    head = nullptr;
}


int main(){
    Node* head = nullptr;
    inserirNoInicio(head, 10);
    inserirNoInicio(head, 20);
    inserirNoInicio(head, 30);
    removerNoInicio(head);
    imprimirLista(head);
    return 0;
}
