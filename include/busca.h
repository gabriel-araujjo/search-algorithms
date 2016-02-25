#ifndef _BUSCA_H_
#define _BUSCA_H_

int busca_sequencial_iterativa (int k, int colecao[], int tamanho);
int busca_sequencial_recursiva (int k, int colecao[], int tamanho, int posicao);
int busca_sequencial_ordenado (int k, int colecao[], int tamanho);
template<typename T> int busca_binaria_iterativa (int key, T colecao[], int tamanho);
int busca_binaria_recursiva (int k, int colecao[], int inicio, int fim);

// implementacao do template da busca binaria iterativa
template<typename T> int busca_binaria_iterativa (int key, T colecao[], int tamanho){
    int inicio = 0, fim = tamanho-1, meio;
    while(inicio <= fim){
        meio = (inicio+fim)/2;
        // Continua a busca na parte esquerda
        if( colecao[meio] > key ){
            fim = meio -1;
        }
        // Continua a busca na parte direita
        else if( colecao[meio] < key ){
            inicio = meio + 1;
        }
        else {
            return meio; // SUCESSO
        }
    }
    return -1; // INSUCESSO
}

#endif // _BUSCA_H_
