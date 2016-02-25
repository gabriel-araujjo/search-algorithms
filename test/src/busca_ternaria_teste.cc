#include "log_util.h"
#include "busca_ternaria.h"

#define MAX 7

void asserte(int elemento, int posicao_desejada);

int ordenado [MAX] = {4, 7, 10, 18, 23, 66, 77};

int main (int argc, char **argv) {
    for(int i = 0; i < MAX; i++) {
		asserte(ordenado[i], i);
	}
    asserte(50, -1);
    asserte(51, -1);
    asserte(-30, -1);
}

void asserte(int elemento, int posicao_desejada) {
    int posicao = busca_ternaria(ordenado, 0, MAX, elemento);

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
