#include "busca.h"
#include "busca_aluno.h"

bool Aluno::operator> (const int &i) const { return matricula > i; }
bool Aluno::operator< (const int &i) const { return matricula < i; }
bool Aluno::operator== (const int &i) const {return matricula == i; }

const char * busca_aluno(int matricula, Aluno * vetor, int tamanho) {
    int posicao = busca_binaria_iterativa(matricula, vetor, tamanho);
    return posicao >= 0 ? (const char *) vetor[posicao].nome : "";
}
