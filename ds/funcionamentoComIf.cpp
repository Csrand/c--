#include <iostream>
#include <cstdlib>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

void inserirInicio(No** lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *lista;
    *lista = novo;
}

void imprimirLista(No* lista) {
    while (lista != NULL) {
        cout << lista->valor << " ";
        lista = lista->proximo;
    }
    cout << endl;
}

void removerInicio(No** lista) {
    No* temporario = *lista;
    if (temporario != NULL) {
        *lista = temporario->proximo;
        cout << "Removendo: " << temporario->valor << endl;
        free(temporario);
    } else {
        cout << "Lista já está vazia!" << endl;
    }
}

int main() {
    No* lista = NULL;

    inserirInicio(&lista, 30);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 10);

    imprimirLista(lista);

    removerInicio(&lista); // Remove 10
    removerInicio(&lista); // Remove 20
    removerInicio(&lista); // Remove 30
    removerInicio(&lista); // Tenta remover de lista vazia (com if)

    return 0;
}
