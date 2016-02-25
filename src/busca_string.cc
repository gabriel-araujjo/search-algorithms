#include <locale.h>
#include <string.h>

#include "busca_string.h"

int busca_string(const char * const * dicionario, int tamanho, const char *palavra) {
	int inicio = 0, fim = tamanho-1, meio, comparacao;
	while(inicio <= fim) {
		meio = (inicio+fim)/2;

		comparacao = strcoll(palavra, dicionario[meio]);		

		// Continua a busca na parte esquerda
		if( comparacao < 0 ){
			fim = meio -1;
		}

		// Continua a busca na parte direita
		else if( comparacao > 0 ){
			inicio = meio + 1;
		}
		else {
			return meio; // SUCESSO
		}
	}
	return -1; // INSUCESSO
}
