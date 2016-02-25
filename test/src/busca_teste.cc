#include <iostream>
#include "log_util.h"
#include "busca.h"

#define MAX 6

//int ordenado [MAX] = { 3, 6, 7, 19, 21, 56 };
//int aleatorio [MAX] = { 3, 56, 7, 19, 21, 6 };
int ordenado [MAX] = {4, 7, 10, 18, 23, 66};

void suite_teste(int numero, int posicao_desejada);
void asserte_igual(int posicao, int posicao_desejada, int elemento);

int main()
{
    suite_teste(23, 4);
    suite_teste(19, -1);
}

/*
Testa a busca nos vetores pelas funções busca_sequencial_iterativa e
busca_binaria_iterativa
*/
void suite_teste(int numero, int posicao_desejada) {
    
    asserte_igual(busca_sequencial_iterativa(numero, ordenado, MAX), posicao_desejada, numero);
    
    asserte_igual(busca_binaria_iterativa(numero, ordenado, MAX), posicao_desejada, numero);
} 

/*
Imprime o resultado da busca, usando uma formatacao padrao.
*/
void asserte_igual (int posicao, int posicao_desejada, int elemento)
{
    if (posicao == posicao_desejada) {
        if (posicao < 0) {
            SUCESSO("Elemento %d não encontrado no vetor", elemento);
        } else {
            SUCESSO("Elemento %d encontrado na posição %d", elemento, posicao);
        }
    } else {
        if (posicao_desejada >= 0) {
            if (posicao < 0) {
                ERRO("Elemento %d não foi encontrado, mas deveria estar na "
                        "posição %d", elemento, posicao_desejada);
            } else {
                ERRO("Elemento %d foi encontrado na posição %d, mas deveria "
                        "estar na posição %d", elemento, posicao,
                        posicao_desejada);
            }
        } else {
            ERRO("Elemento %d, não está no vetor, mas foi encontrado na "
                        "posição %d", elemento, posicao);
        }
    }

}
