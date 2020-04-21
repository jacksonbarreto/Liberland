#include "tester.h"
void tester(void){
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "TESTE DO SISTEMA",3,"Início","Menu Administrativo","Teste do Sistema");
	
	
	start_tester("validaFormatoData",tester_validaFormatoData());
    start_tester("noIntervalo", tester_noIntervalo());
    start_tester("validaNif",tester_validaNif());
    start_tester("criaId",tester_criaId());
	start_tester("validaFormatoHorario",tester_validaFormatoHorario());
	start_tester("horarioTexthorarioNum",tester_horarioTexthorarioNum());
	start_tester("dataTextDataNum",tester_dataTextDataNum());
}

unsigned short int tester_validaFormatoData(void){
	
	//Casos validos - Atenção a Exclamação ( ! ) 
	if(! validaFormatoData("01/01/2020"))
		return FALHA;
	if(! validaFormatoData("31/01/2020"))
		return FALHA;
	if(! validaFormatoData("23/12/2020"))
		return FALHA;
	if(! validaFormatoData("01/01/2020"))
		return FALHA;
	if(! validaFormatoData("29/02/2020"))
		return FALHA;
	//Casos Invalidos - Atenção para NÃO ter Exclamação ( ! )	
	if( validaFormatoData("30/02/2020"))
		return FALHA;
	if( validaFormatoData("30-11/2020"))
		return FALHA;
	if( validaFormatoData("30/09-2020"))
		return FALHA;
	if( validaFormatoData("27/04/2019"))
		return FALHA;
	if( validaFormatoData("030/02/2020"))
		return FALHA;
	if( validaFormatoData("10/02/202a"))
		return FALHA;
	if( validaFormatoData("30-02-2020"))
		return FALHA;
	if( validaFormatoData("17/13/2020"))
		return FALHA;
	if( validaFormatoData("07/7/2020"))
		return FALHA;
	if( validaFormatoData("28/03/2021"))
		return FALHA;
		
	return OK;
}

unsigned short int tester_noIntervalo(void){
	
	//Casos validos - Atenção a Exclamação ( ! )  - Atenção a Exclamação ( ! ) 
	if(! noIntervalo(4,1,15,INTERVALOFECHADO,DENTRODOINTERVALO) )
		return FALHA;
	if(! noIntervalo(1,1,19,INTERVALOFECHADO,DENTRODOINTERVALO) )
		return FALHA;
	if(! noIntervalo(22,1,22,INTERVALOFECHADO,DENTRODOINTERVALO) )
		return FALHA;
	if(! noIntervalo(-18,-18,22,INTERVALOFECHADO,DENTRODOINTERVALO) )
		return FALHA;
	if(! noIntervalo(-6,-7,6,INTERVALOFECHADO,DENTRODOINTERVALO) )
		return FALHA;
	if(! noIntervalo(2,1,32,INTERVALOABERTO,DENTRODOINTERVALO) )
		return FALHA;
	if(! noIntervalo(14,1,15,INTERVALOABERTO,DENTRODOINTERVALO) )
		return FALHA;
	if(! noIntervalo(6,1,15,INTERVALOABERTO,DENTRODOINTERVALO) )
		return FALHA;	
	if(! noIntervalo(59,0,58,INTERVALOFECHADO,FORADOINTERVALO) )
		return FALHA;
	if(! noIntervalo(74,5,74,INTERVALOABERTO,FORADOINTERVALO) )
		return FALHA;
	if(! noIntervalo(43,43,233,INTERVALOABERTO,FORADOINTERVALO) )
		return FALHA;
	if(! noIntervalo(1500,MINOPCAOPADRAO,MAXAREA,INTERVALOFECHADO,DENTRODOINTERVALO) )
		return FALHA;
		
	//Casos Invalidos - Atenção para NÃO ter Exclamação ( ! )	
	if( noIntervalo(0,0,15,INTERVALOABERTO,DENTRODOINTERVALO)  )
		return FALHA;
	if( noIntervalo(25,1,25,INTERVALOABERTO,DENTRODOINTERVALO)  )
		return FALHA;
	if( noIntervalo(2,3,55,INTERVALOFECHADO,DENTRODOINTERVALO)  )
		return FALHA;
	if( noIntervalo(-24,-23,89,INTERVALOFECHADO,DENTRODOINTERVALO)  )
		return FALHA;
	if( noIntervalo(26,8,25,INTERVALOFECHADO,DENTRODOINTERVALO)  )
		return FALHA;
	if( noIntervalo(73,5,74,INTERVALOABERTO,FORADOINTERVALO) )
		return FALHA;
	if( noIntervalo(43,43,233,INTERVALOFECHADO,FORADOINTERVALO) )
		return FALHA;
	if( noIntervalo(-5,-5,12,INTERVALOFECHADO,FORADOINTERVALO) )
		return FALHA;
	
	return OK;	
}

unsigned short int tester_validaNif(void){
	unsigned short int i,j;
	char temp[TMAXNIF+1];
	//Casos validos - Atenção a Exclamação ( ! ) 
	if (! validaNif("289120950") )
		return FALHA;
	if (! validaNif("007123954") )
		return FALHA;
	if (! validaNif("000000001") )
		return 1;//FALHA;
	//Casos Invalidos - Atenção para NÃO ter Exclamação ( ! )
	if(validaNif("2891299509233"))
		return FALHA;
	if(validaNif("dO2934865"))
		return FALHA;
	if(validaNif("983 458 984"))
		return FALHA;
	if(validaNif("983.458.984"))
		return FALHA;
	for(i=0;i<=9;i++)	{		
		for(j=0;j<TMAXNIF;j++)
			temp[j]=(char)i+48;
		temp[j]='\0';
		if(validaNif(temp))
			return FALHA;
	}
	
	return OK;
}

unsigned short int tester_criaId(void){
	unsigned short int i,id;
		
		for(i=0;i<100;i++){
			id=criaId();
			if(!(id>0 && id<USHRT_MAX))
				return FALHA;
		}
		return OK;	
}
unsigned short int tester_validaFormatoHorario(void){
	
	//Casos validos - Atenção a Exclamação ( ! ) 
	if(! validaFormatoHorario("23:30"))
		return FALHA;
	if(! validaFormatoHorario("00:30"))
		return FALHA;
	//Casos Invalidos - Atenção para NÃO ter Exclamação ( ! )	
	if( validaFormatoHorario("25:30") )
		return FALHA;
	if( validaFormatoHorario("12:60") )
		return FALHA;
	if( validaFormatoHorario("2:40") )
		return FALHA;
	if( validaFormatoHorario("09-45") )
		return FALHA;
	return OK;	
}
unsigned short int tester_horarioTexthorarioNum(void){
	unsigned short int hora,minuto;
	
	//Casos validos - Atenção a Exclamação ( ! )
	horarioTexthorarioNum("23:30",&hora,&minuto) ;
	if(! (hora==23 && minuto==30))
		return FALHA;
		
	horarioTexthorarioNum("00:30",&hora,&minuto) ;
	if(! (hora==0 && minuto==30))
		return FALHA;
	
	horarioTexthorarioNum("25:45",&hora,&minuto) ;
	if(! (hora==25 && minuto==45))
		return FALHA;
		
		
	return OK;	
}

unsigned short int tester_dataTextDataNum(void){
	unsigned short int dia, mes, ano;
	
	
	//Casos validos - Atenção a Exclamação ( ! ) 
	dataTextDataNum("20/10/1985",&dia,&mes,&ano);
	if(! (dia==20 && mes==10 && ano==1985) )
		return FALHA;
	dataTextDataNum("02/01/2020",&dia,&mes,&ano);
	if(! (dia==2 && mes==1 && ano==2020) )
		return FALHA;
	dataTextDataNum("31/15/9999",&dia,&mes,&ano);
	if(! (dia==31 && mes==15 && ano==9999) )
		return FALHA;
	
	return OK;	
}
/* MODELO DE FUNÇAO DE TESTE
---------------------------------------------

unsigned short int tester_ nome(void){
	
	//Casos validos - Atenção a Exclamação ( ! ) 
	if(! )
		return FALHA;
	//Casos Invalidos - Atenção para NÃO ter Exclamação ( ! )	
	if( )
		return FALHA;
	
	return OK;	
}

---------------------------------------------
*/

/* GERENCIAMENTO DE TESTE */

void start_tester(char *name, unsigned short int result){
		
	/*#### CABEÇALHO ####*/
	printf("\t\t######################");
    printf("  Teste da função ''%s''  ", name);
    printf("######################");
    printf("\n\n");
	
	
	/*#### RESULTADO ####*/
	
	printf("\t\t- %s foi ", name);
	if(result)
		printf(GREEN " APROVADO " RESET);
	else
		printf(RED " REPROVADO " RESET);
	
	printf("no teste.");
	
	/*#### RODAPÉ ####*/
	printf("\n\t\t-------------------------------------------------\n\n");
}





