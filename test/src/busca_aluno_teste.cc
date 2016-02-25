#include <string.h>
#include "busca_aluno.h"
#include "log_util.h"

#define MAX 6

void asserte(int matricula, const char * retorno_desejado);

Aluno turma[MAX] = {
    {"Ana", 23},
    {"Bianca", 54},
    {"Ícaro", 66},
    {"Jorge", 84},
    {"Renato", 91},
    {"Thaís", 2000}
};

int main(int argc, char **argv) {
	setlocale(LC_ALL, "pt_BR.utf8");
    for(int i = 0; i < MAX; i++) {
		asserte(turma[i].matricula, turma[i].nome);
	}
	asserte(20, "");
	asserte(50, "");
	asserte(2011, "");
}

void asserte(int matricula, const char * retorno_desejado) {
	const char * nome = busca_aluno(matricula, turma, MAX);
	if (strcmp(retorno_desejado, nome) == 0) {
		if (strcmp(nome, "") != 0) {
			SUCESSO("Aluno \"%s\" encontrado", nome);
		} else {
			SUCESSO("Aluno não encontrada");
		}
	} else {
        if (strcmp(retorno_desejado, "") != 0) {
            if (strcmp(nome, "") != 0) {
			    ERRO("Aluno \"%s\" encontrado, quando deveria ser encontrado aluno \"%s\"", nome, retorno_desejado);
		    } else {
			    ERRO("Aluno \"%s\" deveria ter sido encontrado, mas não foi", retorno_desejado);
		    }
        } else {
            ERRO("Aluno \"%s\" foi encontrado, mas não pertence a turma", nome);
        }
	}
}
