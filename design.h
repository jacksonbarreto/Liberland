#ifndef __DESIGN_H__
#define __DESIGN_H__

#include "config.h"

unsigned short int  menuPrincipal(void);
unsigned short int  menuAdm(void);
unsigned short int menuNegocio(void);
unsigned short int menuRelatorio(void);
void lerPosix(unsigned short int *coordenadas, unsigned short int *tamanho, const unsigned short int procedimento);
void imprimeElemento(const ELEMENTO *elemento);
void continuar(const char *mensagem);
void recuo(const unsigned short int recuo);
void borda(const unsigned short int tamanho, const char simbolo, const unsigned short int margem);
void bordaVertical(const short int tamanho, const char simbolo, const unsigned short int margem,const unsigned short int alinhamento, const char *titulo);
void cabecalho(const unsigned short int tamanho, const char simbolo, const unsigned short int margem, const char *titulo, const unsigned short int totsubtitulos, ...);
int criaElemento(const unsigned short int id, const unsigned short int coordenadas[2], const unsigned short int tamanho[2]);
void tratarErro(const char *titulo, const char *instrucao);
void boxSucesso(const char *titulo, const char *instrucao);
void desenhaLegenda(unsigned short int i);
void desenhaMapa(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA], const unsigned short int id);
unsigned short int lerCoordenadaTamanho(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA], unsigned short int *coordenadas, unsigned short int *tamanho);
void registraNegocio(const unsigned short int id, const unsigned short int operacao);
void imprimeRLvendidosMes(const unsigned short int classe);
void imprimeDistPreco(void);
void imprimeDistTipologia(void);
void imprimeDistArea(void);
void imprimeDistEnerg(void);
void imprimeRLinteresse(const unsigned short int classe);
void cadastraVisita(unsigned short int id);
void telaAtualizaElemento(const unsigned int id);






#endif
