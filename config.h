#ifndef __CONFIG_H__
#define __CONFIG_H__

/* BIBLIOTECAS PADRÃO */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>


/* DEFINIÇÃO DE TAMANHO */
#define TMAXLINHA 40
#define TMAXCOLUNA 30
#define TMAXRUA 40
#define MAXCAMPOTEXTO 100
#define TMAXLOCALIDADE 20
#define TMAXDESCRICAO 25
#define TMAXDATA 10
#define TMAXNOME 40
#define TMAXOBS 100
#define TMAXNIF 9
#define TMAXREGPREDIAL 11
#define TMAXCERTHAB 11

#define STMAXLINHA "40."
#define STMAXCOLUNA "30."
#define MAXOPCAOPRINCIAL 3
#define MAXOPCAOADM 4
#define MAXOPCAORL 8
#define MAXOPCAONEGOCIO 3
#define MINOPCAOPADRAO 0
#define SMAXOPCAONEGOCIO "3."
#define SMAXOPCAORL "7."
#define SMAXOPCAOADM "3."
#define SMAXOPCAOPRINCIAL "3."
#define MAXQUARTOS 20
#define SMAXQUARTOS "20."
#define MAXAREA SHRT_MAX
#define SMAXAREA "32.767."


/* DEFINIÇÃO DE CORES */
	/*Apenas Texto*/
#define RED "\033[1;91m"
#define GREEN "\033[1;92m"
#define RESET "\033[0;0m"
#define BOLD "\x1B[1m"
#define AMARELOT "\x1B[38;2;255;255;0m"
#define ROXOT "\x1B[38;2;255;0;255m"
#define LARANJAT "\x1B[38;2;255;140;0m"
	/*Apenas Fundo*/
#define AMARELO "\x1B[48;2;255;255;0m"
#define BLUE "\x1B[48;2;0;0;205m"
#define MARROM "\x1B[48;2;139;69;19m"
#define CINZA "\x1B[48;2;128;128;128m"
#define AREIA "\x1B[48;2;255;228;181m"
#define VERDEPARQUE "\x1B[48;2;60;179;113m"
#define VERDERURAL "\x1B[48;2;0;128;0m"


/* DEFINIÇÃO DE TELAS */
#define BUFERTELA 120
#define BORDALARG 107
#define BORDAERROR 60
#define MAXTITULOERRO 55
#define BORDAFICHA 80
#define RECUOSIMPLES 1
#define RECUODUPLO 2
#define RECUOERRO 4
#define CENTRALIZADO 1
#define ESQUERDA 2
#define DIREITA 3

/* DEFINIÇÃO DAS CATEGORIAS DA LEGENDA */
#define RUA 0
#define VIVENDA 1
#define APARTAMENTO 2
#define COMERCIO 3
#define HABITACAO 4
#define PARQUE 5
#define MONTANHA 6
#define PRAIA 7
#define TERRENO 8
#define RURAL 9
#define RIO 10
#define GOVERNAMENTAL 11
#define MULTIBANCO 12
#define MONUMENTO 13
#define QUIOSQUE 14
#define PUBLICO 15


/* MACROS DE CONTROLE */
#define DISPONIVEL 1
#define INDISPONIVEL 0
#define VENDA 1
#define ARRENDA 0
#define APLICAVEL 1
#define NAOAPLICAVEL 0
#define OK 1
#define FALHA 0
#define SIM 1
#define NAO 0
#define DECREMENTO 1
#define SEMDECREMENTO 0
#define MATRICULA1 24031
#define MATRICULA2 24544
#define COORDENADA 1
#define TAMANHO 0
#define VLINHA 0
#define VCOLUNA 1
#define NULO 0
#define MAPAGENERICO 0
#define VISITASANO 0
#define INTERVALOABERTO 0
#define INTERVALOFECHADO 1
#define DENTRODOINTERVALO 1
#define FORADOINTERVALO 0
#define CANCELARNEGOCIO 0
#define REGISTRARNEGOCIO 1
#define SLEGENDA 1
#define NLEGENDA 0

#endif

/* ################## GERENCIAMENTO DE DEPENDENCIAS ################## */

/* DEPENDÊNCIAS EM CRUD.H */
#ifdef __CRUD_H__
	#include "auxiliares.h"
	#include <errno.h>
#endif

/* DEPENDÊNCIAS EM DESIGN.H */
#ifdef __DESIGN_H__
	#include <stdarg.h>	
	#include "auxiliares.h"
	#include "crud.h"
#endif

/* DEPENDÊNCIAS EM TESTER.H */
#ifdef __TESTER_H__
	#include "auxiliares.h"
	#include "design.h"
#endif

/* DEPENDÊNCIAS EM AUXILIARES.H */
#ifdef __AUXILIARES_H__
	#include "crud.h"
	#include "design.h"
	#include <time.h>
	#include <limits.h>
#endif


/* DEPENDÊNCIAS EM MAIN */
#ifdef __PRINCIPAL__	
	#include "auxiliares.h"
	#include "tester.h"
	#include "design.h"
#endif

/* COMPARTILHA STRUCT.H COM TODOS EXCETO STRUCT */
#ifndef __STRUCTS_H__
#include "structs.h"
#endif

/*VARIÁVEIS GLOBAIS*/
#ifndef __PRINCIPAL__
extern const  char CERTENERG[8][3];
extern const  char SIMBOLO[];
extern const char CATEGORIA[][21];
extern char ELEMENTOS_BD[20];
extern char MESES[12][10];
extern char VISITAS_BD[20];
#endif

