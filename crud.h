#ifndef __CRUD_H__
#define __CRUD_H__
#include "config.h"


char consultaSimbolo(const unsigned short int id);
ELEMENTO consultaElemento(const unsigned short int id);
unsigned short int atualizaElemento(const ELEMENTO *elementoAtualizado);
unsigned short int apagaElemento(const unsigned short int id);
unsigned short int insereElemento(const ELEMENTO *elemento);
unsigned short int inicializaMapa(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA]);
void negociosMes(unsigned short int vivendasArrendadas[12],unsigned short int  vivendasVendidas[12],unsigned short int apartamentosArrendados[12],unsigned short int apartamentosVendidos[12]);
void distribuicaoTipologia(unsigned short int tipologia[6]);
void distribuicaoCertEnerg(unsigned short int certEnergetico[8]);
void distribuicaoArea(unsigned short int areas[4]);
void distribuicaoPreco(unsigned short int precosVenda[4],unsigned short int precosArrenda[4]);
short int visitas(const unsigned short int id, const unsigned short int mes);
unsigned short int distribuicaoInteresse(const unsigned short int mes, const unsigned short int classe);
unsigned short int insereVisita(const VISITA *visita);




#endif
