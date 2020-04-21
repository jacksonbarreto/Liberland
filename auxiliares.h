#ifndef __AUXILIARES_H__
#define __AUXILIARES_H__
#include "config.h"


unsigned short int anoAtual(void);
void limpaTela(void);
void zeraVetor(unsigned short int *vetor, const unsigned short int tamanho);
unsigned short int noIntervalo(const short int escolha, const short int limiteA, const short int limiteB, const unsigned short int tipoIntervalo, const unsigned short int localnoIntervalo);
unsigned short int validaFormatoData(const char *dataTexto);
unsigned short int validaFormatoHorario(const char *horarioTexto);
void dataTextDataNum(const char *dataTexto, unsigned short int *dia,unsigned short int *mes,unsigned short int *ano);
void horarioTexthorarioNum(const char *horarioTexto, unsigned short int *hora,unsigned short int *minuto);
unsigned short int validaNif(const char *nif);
unsigned short int lerInteiro(const char *pergunta);
void lerTexto(const char *pergunta, char *resposta, const unsigned short int tamanho);
void validaSalvaInteiro(unsigned short int *resposta,const unsigned short int decremento, const char *pergunta, const char *tituloErro, const char *msgErro,const short int limiteA, const short int limiteB, const unsigned short int tipoIntervalo,const unsigned short int localnoIntervalo);
void validaSalvaHorario(const char *pergunta, unsigned short int *hora, unsigned short int *minuto);
void zeraMapa(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA]);
unsigned short int criaId(void);
ELEMENTO elementoNulo(void);
unsigned short int validaTamanho(const unsigned short int coordenada, const unsigned short int tamanho, const unsigned short int procedimento);
unsigned short int validaConstrucao(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA],const unsigned short int *coordenada, const unsigned short int *tamanho);
void demolidor(ELEMENTO *elemento);
void limpaBuf(void);
void duploZero(const unsigned short int numero);
void imprimeNif(const char *nif);
#endif
