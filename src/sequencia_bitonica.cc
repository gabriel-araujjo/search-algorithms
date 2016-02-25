#include "sequencia_bitonica.h"

bool eh_bitonica(int sequencia[], int tamanho) {
    // Para uma função ser bitônica, são necessários ao menos 3 elementos no
    // sequencia
    if (tamanho < 3) return false;
    
    
    int mudancas = 0;
    for (int i = 1, anterior = sequencia[0]; i < tamanho; anterior = sequencia[i], i++) {
        // As funções bitônicas não tem elementos iguais adjacentes
        if (sequencia[i] == anterior) return false;
        
        if (mudancas == 0) {
            // função deve estar subindo pois ainda não houve nenhuma mudança
            // de direção
            if (sequencia[i] < anterior) {
                // a função já começa decendo, então não é bitônica
                if (i == 1) return false;

                mudancas++;
            }
        } else {
            // função em declínio, uma vez que já houve um pico
            if (sequencia[i] > anterior) {
                // funções bitônicas não admitem mais de uma mudança
                return false;
            }
        }
    }
    // Para ser bitônica deve ocorrer apenas uma mudança
    return mudancas == 1;
}

int obter_pico_abordagem_binaria(int sequencia[], int tamanho) {
    int inicio = 0, fim = tamanho, meio;
    while(inicio < fim) {
        meio = (inicio + fim) / 2;
        if (sequencia[meio - 1] < sequencia[meio]) {
            if (sequencia[meio + 1] < sequencia[meio]) {
                return meio;
            } else {
                inicio = meio + 1;
            }
        } else {
            fim = meio;
        }
    }
    return -1;
}

int obter_pico_abordagem_sequencial(int sequencia[], int tamanho) {
    for (int i = 1; i < tamanho -1; i++) {
        if (sequencia[i - 1] < sequencia[i] && sequencia[i + 1] < sequencia[i]) {
            return i;
        }
    }
    return -1;
}
