#ifndef  __TESTER_H__
#define __TESTER_H__

#include "config.h"




//funcoes testers
unsigned short int tester_validaFormatoData(void);
unsigned short int tester_noIntervalo(void);
unsigned short int tester_validaNif(void);
unsigned short int tester_criaId(void);
unsigned short int tester_validaFormatoHorario(void);
unsigned short int tester_horarioTexthorarioNum(void);
unsigned short int tester_dataTextDataNum(void);


//Funções de gerenciamento de Tester
void start_tester(char *name, unsigned short int result);
void tester(void);
#endif
