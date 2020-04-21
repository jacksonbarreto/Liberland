/*@@@@ DIRETIVAS DE INCLUSÃO					 @@@@*/
#ifndef __PRINCIPAL__
#define __PRINCIPAL__
#endif
#include "config.h"

/*@@@@ VARIÁVEIS GLOBAIS						 @@@@*/

const  char CERTENERG[8][3]={"A+","A","B","B-","C","D","E","F"};
const  char SIMBOLO[]={'+','V','A','C','H','Ø','^','P','T','R','»','G','$','M','Q','@'};
const char CATEGORIA[][21]={"RUA","VIVENDA","APARTAMENTO","COMÉRCIO","HABITAÇÃO PERMANENTE","PARQUE OU PRAÇA","MONTANHA","PRAIA","TERRENO","ÁREA RURAL","RIO","ÁREA GOVERNAMENTAL","MULTIBANCO","MONUMENTO","QUIOSQUE","ESPAÇO PÚBLICO"};
char ELEMENTOS_BD[20]="elementos.dat";
char VISITAS_BD[20]={"visitas.dat"};
char MESES[12][10]={"JANEIRO","FEVEREIRO","MARÇO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"};

int main(int argc, char *argv[]) {	
	ELEMENTO elemento;
	unsigned short int mapa[TMAXLINHA][TMAXCOLUNA];
	unsigned short int coordenadas[2], tamanho[2];
	unsigned short int opcao, opcaoSecundaria;
	
	setlocale(LC_ALL, "");
	system("color");
	do{
		limpaTela();
		inicializaMapa(mapa);		
				
		opcao=menuPrincipal();
		switch(opcao){
			case 1:
				limpaTela();
				desenhaMapa(mapa,MAPAGENERICO);				
				lerPosix(coordenadas,tamanho,COORDENADA);
				elemento=consultaElemento(mapa[coordenadas[0]][coordenadas[1]]);
				limpaTela();
				cabecalho(BORDALARG,'*',RECUOSIMPLES, "CONSULTA ELEMENTO URBANO",2,"Início","Consulta elemento Urbano");
				desenhaMapa(mapa,mapa[coordenadas[0]][coordenadas[1]]);
				imprimeElemento(&elemento);
				continuar("\n\tPressione qualquer tecla para voltar ao MENU PRINCIPAL. . .");				
				break;
			case 2:
				limpaTela();
				opcaoSecundaria=menuNegocio();
				switch(opcaoSecundaria){
					case 1: /*registra um negócio*/
						limpaTela();
						desenhaMapa(mapa,MAPAGENERICO);
						lerPosix(coordenadas,tamanho,COORDENADA);					 
						desenhaMapa(mapa,mapa[coordenadas[0]][coordenadas[1]]);						
						registraNegocio(mapa[coordenadas[0]][coordenadas[1]],REGISTRARNEGOCIO);					
						break;
					case 2: /*cancela um negócio*/
						limpaTela();
						desenhaMapa(mapa,MAPAGENERICO);
						lerPosix(coordenadas,tamanho,COORDENADA);					 
						desenhaMapa(mapa,mapa[coordenadas[0]][coordenadas[1]]);	
						registraNegocio(mapa[coordenadas[0]][coordenadas[1]],CANCELARNEGOCIO);					
						break;
					case 3: /*registra uma visita*/
						limpaTela();
						desenhaMapa(mapa,MAPAGENERICO);
						lerPosix(coordenadas,tamanho,COORDENADA);					 
						desenhaMapa(mapa,mapa[coordenadas[0]][coordenadas[1]]);	
						cadastraVisita(mapa[coordenadas[0]][coordenadas[1]]);							
						break;
				}
			 	break;
			case 3:				
				limpaTela();
				opcaoSecundaria=menuRelatorio();
				switch(opcaoSecundaria){
					case 1:
						limpaTela();
						imprimeRLvendidosMes(VENDA);						
						break;
					case 2:
						limpaTela();
						imprimeRLvendidosMes(ARRENDA);						
						break;
					case 3:
						limpaTela();
						imprimeDistPreco();						
						break;
					case 4:
						limpaTela();
						imprimeDistTipologia();						
						break;
					case 5:
						limpaTela();
						imprimeDistArea();						
						break;
					case 6:
						limpaTela();
						imprimeDistEnerg();						
						break;
					case 7:
						limpaTela();
						imprimeRLinteresse(VENDA);						
						break;
					case 8:
						limpaTela();
						imprimeRLinteresse(ARRENDA);						
						break;										
				}
				continuar("\n\tPressione qualquer tecla para voltar ao MENU PRINCIPAL. . .");
				break;	
			
			case 24031:
			case 24544:
				limpaTela();
				opcaoSecundaria=menuAdm();
				switch(opcaoSecundaria){
					case 1: /*Insere um novo elemento*/
						limpaTela();
						desenhaMapa(mapa,MAPAGENERICO);
						if(lerCoordenadaTamanho(mapa,coordenadas,tamanho)==FALHA)
							break;
						limpaTela();
						criaElemento(mapa[coordenadas[0]][coordenadas[1]],coordenadas,tamanho);						
						break;
					case 2: /*Apaga um elemento*/
						limpaTela();
						desenhaMapa(mapa,MAPAGENERICO);
						lerPosix(coordenadas,tamanho,COORDENADA);
						if(apagaElemento(mapa[coordenadas[0]][coordenadas[1]]))
							boxSucesso("SUCESSO","Elemento eliminado com Sucesso.");
						else
							tratarErro("EXCLUSÃO FALHOU","Não foi possível eliminar o EL.");						
						break;
					case 3: /*Atualiza um elemento*/
						limpaTela();
						desenhaMapa(mapa,MAPAGENERICO);
						lerPosix(coordenadas,tamanho,COORDENADA);
						telaAtualizaElemento(mapa[coordenadas[0]][coordenadas[1]]);						
						break;
					case 4:/*Testa o sistema*/
						limpaTela();
						tester();
						continuar("\n\tPressione qualquer tecla para voltar ao MENU PRINCIPAL. . .");
						break;
				}								
				break;
		}
		
	}while(opcao!=0);
	
	return 0;
}
