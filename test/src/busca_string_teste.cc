#include "busca_string.h"
#include "log_util.h"

#define MAX 6

void asserte(const char *palavra, int retorno_desejado);

const char * const dicionario[MAX] = {"Ana", "Bianca", "Ícaro", "Jorge", "Renato", "Thaís"};

int main(int argc, char **argv) {
	
	setlocale(LC_ALL, "pt_BR.utf8");
	for(int i = 0; i < MAX; i++) {
		asserte(dicionario[i], i);
	}
	asserte("Caio", -1);
	asserte("Ziraldo", -1);
	asserte("Müller", -1);
}

void asserte(const char *palavra, int retorno_desejado) {
	int posicao = busca_string(dicionario, MAX, palavra);
	if (posicao == retorno_desejado) {
		if (retorno_desejado >= 0) {
			SUCESSO("Palavra \"%s\" encontrada na posição %d", palavra, posicao);
		} else {
			SUCESSO("Palavra \"%s\" não encontrada", palavra);
		}
	} else {
		if (retorno_desejado >= 0) {
            if (posicao >= 0) {
			    ERRO("Palavra \"%s\" deveria estar na posição %d, mas foi encontrada na posição %d", palavra, retorno_desejado, posicao);
            } else {
                ERRO("Palavra \"%s\" deveria estar na posição %d, mas não foi encontrada", palavra, retorno_desejado);
            }
		} else {
			ERRO("Palavra \"%s\" não existe no dicionario, mas foi encontrada", palavra);
		}
	}
}
