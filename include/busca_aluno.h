#ifndef _BUSCA_ALUNO_H_
#define _BUSCA_ALUNO_H_

struct Aluno {
    const char * nome;
    int matricula;
    bool operator> (const int &) const;
    bool operator< (const int &) const;
    bool operator== (const int &) const;
};

/**
 * @param matricula
 *               Matrícula do aluno pesquisado
 * @param vetor
 *               Vetor de alunos ordenado por matrícula no qual a busca será
 *               feita
 * @param tamanho
 *               Tamanho do vetor de busca
 * @return
 *               Nome do aluno ou string vazia caso não haja aluno com a
 *               matrícula pesquisada
 */
const char * busca_aluno(int matricula, Aluno * vetor, int tamanho);

#endif // _BUSCA_ALUNO_H_
