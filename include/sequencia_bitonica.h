#ifndef _SEQUENCIA_BITONICA_H_
#define _SEQUENCIA_BITONICA_H_

/**
 * Testa se {@code vetor} é uma sequencia bitônica ou não
 * @param sequencia
 *          Sequencia a ser testada
 * @param tamanho
 *          Tamanho da sequencia a ser testada
 * @return
 *          true caso a função seja bitônica
 */
bool eh_bitonica(int sequencia[], int tamanho);

/**
 * Retorna o índice do elemento Ai, isto é, o índice do elemento em que a 
 * sequência crescente tem fim e a sequência decrescente tem início
 * 
 * Abordagem inspirada na busca binária
 * @param sequencia
 *          Sequencia bitonica (mínimo 3 elementos)
 * @param tamanho
 *          Tamanho da sequencia bitonica
 * @return
 *          O  índice do elemento Ai (pico)
 */
int obter_pico_abordagem_binaria(int sequencia[], int tamanho);

/**
 * Retorna o índice do elemento Ai, isto é, o índice do elemento em que a 
 * sequência crescente tem fim e a sequência decrescente tem início
 * 
 * Abordagem inspirada na busca sequencial
 * @param sequencia
 *          Sequencia bitonica (mínimo 3 elementos)
 * @param tamanho
 *          Tamanho da sequencia bitonica
 * @return
 *          O  índice do elemento Ai (pico)
 */
int obter_pico_abordagem_sequencial(int sequencia[], int tamanho);

#endif // _SEQUENCIA_BITONICA_H_
