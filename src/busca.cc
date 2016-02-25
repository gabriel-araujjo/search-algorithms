#include <iostream>
#include "busca.h"

int busca_sequencial_iterativa (int k, int colecao[], int tamanho)
{
    int posicao = 0;
    do {
        if( k == colecao[posicao] ){
            return posicao; // SUCESSO
        }
        posicao = posicao + 1;
    } while(posicao < tamanho);
    return -1; // INSUCESSO
};

int busca_sequencial_recursiva (int k, int colecao[], int tamanho, int posicao)
{
    if (posicao == tamanho)
    {
        return -1; // INSUCESSO
    };
    if( k == colecao[posicao] )
    {
            return posicao; // SUCESSO
    }
    else
    {
        return busca_sequencial_recursiva(k, colecao, tamanho, posicao+1);
    }
};

int busca_sequencial_ordenado (int k, int colecao[], int tamanho)
{
    int posicao = 0;
    do {
        if( k == colecao[posicao] ){
            return posicao; // SUCESSO
        }
        else if( k < colecao[posicao] ){
            return -1; // INSUCESSO
        }
        posicao = posicao + 1;
    } while(posicao < tamanho);
    return -1; // INSUCESSO
}

int busca_binaria_recursiva (int k, int colecao[], int inicio, int fim) {
    if( inicio > fim ){
        return -1; // INSUCESSO
    }
    int meio = (inicio+fim)/2;
    if( k < colecao[meio] ){
        // Continua a busca na parte esquerda
        return busca_binaria_recursiva (k, colecao, inicio, meio-1);
    }
    else if( k > colecao[meio] ){
        // Continua a busca na parte direita
        return busca_binaria_recursiva (k, colecao, meio+1, fim);
    }
    else{
        return meio; // SUCESSO
    }
}
