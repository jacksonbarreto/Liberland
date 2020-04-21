#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "config.h"

typedef struct _hora{
	unsigned short int hora;
	unsigned short int minutos;
}HORA;
typedef struct _horario{
	unsigned short int aplica;
	HORA abertura;
	HORA encerramento;
}HORARIO;
typedef struct _posyx{
	unsigned short int linha;
	unsigned short int coluna;
}POSYX;
typedef struct _data{
	unsigned short int dia;
	unsigned short int mes;
	unsigned short int ano;
}DATA;
typedef struct _proprietario{
	char nome[TMAXNOME+1];
	char nif[TMAXNIF+1];
}PROPRIETARIO;
typedef struct _endereco{
	char rua[TMAXRUA+1];
	char localidade[TMAXLOCALIDADE+1];
}ENDERECO;
typedef struct _negocio{
	unsigned short int status;
	DATA data;	
}NEGOCIO;
typedef struct _pinteresse{
	char descricao[TMAXDESCRICAO+1];
	HORARIO horario;
}PINTERESSE;
typedef struct _imovel{
	unsigned short int classe;
	unsigned short int tipologia;
	unsigned short int area;
	unsigned short int suites;
	unsigned short int certEnerg;
	char regPredial[TMAXREGPREDIAL+1];
	char certHabit[TMAXCERTHAB+1];
	unsigned long int valor;
	PROPRIETARIO proprietario;
	
	NEGOCIO negocio;
}IMOVEL;
typedef struct _elemento{
	unsigned short int id;
	unsigned short int categoria; 
	char obs[TMAXOBS+1];	
	POSYX inicio;
	POSYX tamanho;
	IMOVEL imovel;
	PINTERESSE pInteresse;
	ENDERECO endereco;
}ELEMENTO;
typedef struct _visita{
	unsigned short int id;
	DATA data;
}VISITA;
#endif
