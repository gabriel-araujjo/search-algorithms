#include "busca_ternaria.h"

int busca_ternaria (int * vetor, int inicio, int fim, int chave) {
    int um_terco, dois_tercos;
    while(inicio < fim) {
        um_terco = (2 * inicio + fim) / 3;
        if (chave == vetor[um_terco])
            return um_terco;
        else if (chave < vetor[um_terco]) {
            // chave no primeiro terço
            fim = um_terco;
            continue;
        }
        dois_tercos = (2 * fim + inicio ) / 3;
        if (chave == vetor[dois_tercos])
            return dois_tercos;
        else if (chave < vetor[dois_tercos]) {
            // chave no segundo terço
            inicio = um_terco + 1;
            fim = dois_tercos;
            continue;
        }
        // chave no terceiro terço
        inicio = dois_tercos + 1;
    }
    return -1;
}
