#include "log_util.h"
#include "sequencia_bitonica.h"

#define MAX 9

void asserte_eh_bitonica(int vetor[], int tamanho, bool bitonicidade_desejada);
void asserte_pico(int vetor[], int tamanho, int pico_desejado, int (*) (int *, int));

int sequencias [57] = {
    1,2,3,4,3,2,1, // Bitonico
    1,2,3,4,5,6,7, // Não bitônico
    7,8,6,5,4,3,2, // Bitônico
    1,2, // Não bitônico
    2,1, // Não bitônico
    4,3,2,1,2,3,4, // Não bitônico (pela definição da questão)
    4,5,6,7,8,9,10,11,12,13,-1, // Bitônico
    1,1,1,1,1,1,1, // Não bitônico
    1,2,3,4,4,5,4 // Não bitônico
};

int tamanhos[MAX] = {
    7,
    7,
    7,
    2,
    2,
    7,
    11,
    7,
    7
};

bool bitonicidades_desejadas[MAX] = {
    true,
    false,
    true,
    false,
    false,
    false,
    true,
    false,
    false
};

int main (int argc, char **argv) {
    for(int i = 0, cursor = 0; i < MAX; cursor += tamanhos[i], i++) {
		asserte_eh_bitonica(sequencias + cursor, tamanhos[i], bitonicidades_desejadas[i]);
	}

    asserte_pico(sequencias, 7, 3, obter_pico_abordagem_binaria);
    asserte_pico(sequencias + 14, 7, 1, obter_pico_abordagem_binaria);
    asserte_pico(sequencias + 32, 11, 9, obter_pico_abordagem_binaria);

    asserte_pico(sequencias, 7, 3, obter_pico_abordagem_sequencial);
    asserte_pico(sequencias + 14, 7, 1, obter_pico_abordagem_sequencial);
    asserte_pico(sequencias + 32, 11, 9, obter_pico_abordagem_sequencial);
}

void asserte_eh_bitonica(int vetor[], int tamanho, bool bitonicidade_desejada) {
    bool bitonicidade = eh_bitonica(vetor, tamanho);

    if (bitonicidade == bitonicidade_desejada) {
        if (bitonicidade) {
            SUCESSO("Vetor é bitônico");
        } else {
            SUCESSO("Vetor não é bitônico");
        }
    } else {
        if (bitonicidade_desejada) {
            ERRO("Vetor não é bitônico quando deveria ser");
        } else {
            ERRO("Vetor é bitônico quando deveria não ser");
        }
    }
}

void asserte_pico(int vetor[], int tamanho, int pico_desejado,
        int (* abordagem) (int *, int)) {
    int pico = abordagem(vetor, tamanho);
    if (pico == pico_desejado) {
        SUCESSO("Pico %d encontrado!", pico);
    } else {
        ERRO("Deveria ter encontrado o pico %d, mas encontrou %d", pico_desejado, pico);
    }
}

