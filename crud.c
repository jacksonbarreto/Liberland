#include "crud.h"

char consultaSimbolo(const unsigned short int id){
	ELEMENTO elemento;
	/*Se for um elemento nulo retorna um terreno, para inicializaçao do mundo*/
	if(id == 0)
		return 'T';
		
	elemento=consultaElemento(id);
	
	return SIMBOLO[elemento.categoria];
}

ELEMENTO consultaElemento(const unsigned short int id){
	FILE *BD;
	ELEMENTO elemento;
	
	BD=fopen(ELEMENTOS_BD,"rb");
	
	if(BD != NULL){
		do{
			fread(&elemento,sizeof(ELEMENTO),1,BD);
			if(elemento.id == id){
				fclose(BD);
				return elemento;
			}
		}while(!feof(BD));
		
		fclose(BD);
		return elementoNulo();
	}else{
		/*Redireciona a impressão para o buffer de erro*/
		fprintf(stderr,RED"\n\tErro em 'ConsultaElemento'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}				
}

unsigned short int atualizaElemento(const ELEMENTO *elementoAtualizado){
	FILE *BD;
	ELEMENTO temp;
	
	if(elementoAtualizado->id == 0)
		return FALHA;
	BD=fopen(ELEMENTOS_BD,"r+b");
	
	do{
		fread(&temp,sizeof(ELEMENTO),1,BD);
		if(temp.id == elementoAtualizado->id){
					
			fseek(BD,- (long) sizeof(ELEMENTO), SEEK_CUR);
			if(fwrite(elementoAtualizado,sizeof(ELEMENTO),1,BD) == 1){				
				fclose(BD);
				return OK;
			}else{
				fclose(BD);
				return FALHA;
			}						
		}
	}while(!feof(BD));	
	fclose(BD);
	return FALHA;	
}
unsigned short int apagaElemento(const unsigned short int id){
	FILE *BD;
	ELEMENTO elemento;
	unsigned short int i,j,a,b, tamanho[2], posInicial[2];
	if(id == 0)
		return FALHA;
			
	BD=fopen(ELEMENTOS_BD,"r+b");
		
	do{
		fread(&elemento,sizeof(ELEMENTO),1,BD);
		if(feof(BD))
			break;
		if(elemento.id == id){
			
			tamanho[0]=elemento.tamanho.linha;
			tamanho[1]=elemento.tamanho.coluna;
			posInicial[0]=elemento.inicio.linha;
			posInicial[1]=elemento.inicio.coluna;
			
			demolidor(&elemento);
			fseek(BD,- (long) sizeof(ELEMENTO), SEEK_CUR);			
			if(fwrite(&elemento,sizeof(ELEMENTO),1,BD) == 1){
				fseek(BD,0, SEEK_END);
				/*cria um terreno vazio em cada posição ocupada pelo elemento apagado. */
				for(i=0, a=posInicial[0]; i < tamanho[0] ; a++, i++){
					for(j=0, b=posInicial[1]; j < tamanho[1]; b++, j++){
						if(i==0 && j==0)
							b++;
						elemento.id=criaId();
						elemento.inicio.linha=a;
						elemento.inicio.coluna=b;						
						fwrite(&elemento,sizeof(ELEMENTO),1,BD);						
					}
				}				
				fclose(BD);
				return OK;
			}else{
				fclose(BD);
				return FALHA;
			}						
		}
	}while(!feof(BD));	
	fclose(BD);
	return FALHA;	
}

unsigned short int insereElemento(const ELEMENTO *elemento){ 	
	FILE *BD;
	
	BD=fopen(ELEMENTOS_BD,"ab");
	
	if(fwrite(elemento,sizeof(ELEMENTO),1,BD) == 1){
		fclose(BD);
		return OK;
	}else{
		fclose(BD);
		return FALHA;
	}		
}

unsigned short int inicializaMapa(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA]){
	FILE *BD;
	ELEMENTO elemento;
	unsigned short int i, j, a, b;
	/*Zerando o mapa para usar o 0 como zona null, imprimindo um marcador especial, para fase de construcao do mundo*/
	zeraMapa(mapa);
	
	BD=fopen(ELEMENTOS_BD,"rb");
	
	if(BD != NULL){
		do{
			fread(&elemento,sizeof(ELEMENTO),1,BD);	
			if(feof(BD))
				break;		
			for(i=0, a=elemento.inicio.linha; i < elemento.tamanho.linha ; a++, i++){
				for(j=0, b=elemento.inicio.coluna; j < elemento.tamanho.coluna; b++, j++){
					mapa[a][b]=elemento.id;
				}
			}
		}while(!feof(BD));
		
		fclose(BD);
		return FALHA;		
	}else{
		/*ERRO FATAL*/
		fprintf(stderr,RED"\n\tErro em 'inicializaMapa'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}		
}

void negociosMes(unsigned short int vivendasArrendadas[12],unsigned short int  vivendasVendidas[12],unsigned short int apartamentosArrendados[12],unsigned short int apartamentosVendidos[12]){
	ELEMENTO elemento;
	FILE *BD;

	zeraVetor(vivendasArrendadas,12);
	zeraVetor(vivendasVendidas,12);
	zeraVetor(apartamentosVendidos,12);
	zeraVetor(apartamentosArrendados,12);	
	
	BD=fopen(ELEMENTOS_BD,"rb");
	
	if(BD != NULL){
		do{
			fread(&elemento,sizeof(ELEMENTO),1,BD);
			if(feof(BD))
				break;
				if((elemento.categoria == VIVENDA || elemento.categoria == APARTAMENTO) && elemento.imovel.negocio.status == INDISPONIVEL){
					if(elemento.imovel.classe==VENDA){
						if(elemento.categoria == VIVENDA)
							vivendasVendidas[elemento.imovel.negocio.data.mes-1]++;
						else
							apartamentosVendidos[elemento.imovel.negocio.data.mes-1]++;
					}else{
						if(elemento.categoria == VIVENDA)
							vivendasArrendadas[elemento.imovel.negocio.data.mes-1]++;
						else
							apartamentosArrendados[elemento.imovel.negocio.data.mes-1]++;
					}						
				}			
		}while(!feof(BD));
		fclose(BD);		
	}else{
		/*ERRO FATAL*/
		fprintf(stderr,RED"\n\tErro em 'negociosMes'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}	
}

void distribuicaoTipologia(unsigned short int tipologia[6]) {
	ELEMENTO elemento;
	FILE *BD;
	zeraVetor(tipologia,6);	
	
	BD=fopen(ELEMENTOS_BD,"rb");
	
	if(BD != NULL){
		do{
			fread(&elemento,sizeof(ELEMENTO),1,BD);
			if(feof(BD))
				break;
			if(elemento.categoria == VIVENDA || elemento.categoria == APARTAMENTO){
				if(elemento.imovel.tipologia>=5)
					tipologia[5]++;
				else
					tipologia[elemento.imovel.tipologia]++;
			}
		}while(!feof(BD));		
		fclose(BD);		
	}else{
		fprintf(stderr,RED"\n\tErro em 'distribuicaoTipologia'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}	
}
void distribuicaoCertEnerg(unsigned short int certEnergetico[8]) {
	ELEMENTO elemento;
	FILE *BD;
	zeraVetor(certEnergetico,8);
	BD=fopen(ELEMENTOS_BD,"rb");
	
	if(BD != NULL){
		while(fread(&elemento,sizeof(ELEMENTO),1,BD)){
			if(elemento.categoria == VIVENDA || elemento.categoria == APARTAMENTO){
				certEnergetico[elemento.imovel.certEnerg]++;
			}
		}		
		fclose(BD);	
	}else{
		fprintf(stderr,RED"\n\tErro em 'distribuicaoCertEnerg'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}	
}
void distribuicaoArea(unsigned short int areas[4]) {
	ELEMENTO elemento;
	FILE *BD;
	zeraVetor(areas,4);
	BD=fopen(ELEMENTOS_BD,"rb");
	
	if(BD != NULL){
		do{
			fread(&elemento,sizeof(ELEMENTO),1,BD);
			if(feof(BD))
				break;
			if(elemento.categoria == VIVENDA || elemento.categoria == APARTAMENTO){
				if(elemento.imovel.area < 60){
					areas[0]++;	
				}else if(elemento.imovel.area < 100){
					areas[1]++;	
				}else if(elemento.imovel.area < 150){
					areas[2]++;	
				}else{
					areas[3]++;	
				}				
			}
		}while(!feof(BD));		
		fclose(BD);
	}else{
		fprintf(stderr,RED"\n\tErro em 'distribuicaoArea'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}	
}
void distribuicaoPreco(unsigned short int precosVenda[4],unsigned short int precosArrenda[4]) {
	ELEMENTO elemento;
	FILE *BD;
	zeraVetor(precosVenda,4);
	zeraVetor(precosArrenda,4);
	BD=fopen(ELEMENTOS_BD,"rb");
	
	if(BD != NULL){
		do{
			fread(&elemento,sizeof(ELEMENTO),1,BD);
			if(feof(BD))
				break;
			if(elemento.categoria == VIVENDA || elemento.categoria == APARTAMENTO){
				if(elemento.imovel.classe==VENDA){
				
					if(elemento.imovel.valor <= 80000){
						precosVenda[0]++;	
					}else if(elemento.imovel.valor <= 150000){
						precosVenda[1]++;	
					}else if(elemento.imovel.valor <= 200000){
						precosVenda[2]++;	
					}else{
						precosVenda[3]++;	
					}
				}else{
					if(elemento.imovel.valor <= 350){
						precosArrenda[0]++;	
					}else if(elemento.imovel.valor <= 700){
						precosArrenda[1]++;	
					}else if(elemento.imovel.valor <= 1200){
						precosArrenda[2]++;	
					}else{
						precosArrenda[3]++;	
					}
				}				
			}
		}while(!feof(BD));		
		fclose(BD);
	}else{
		/*ERRO FATAL*/
		fprintf(stderr,RED"\n\tErro em 'distribuicaoPreco'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}
	
	
}
short int visitas(const unsigned short int id, const unsigned short int mes) {
	VISITA visita;
	int contador=0;	
	FILE *BD;
	
	if(noIntervalo(mes,0,12,INTERVALOFECHADO,FORADOINTERVALO))
		return -1;
		
	BD=fopen(VISITAS_BD,"rb");
	
	if(BD != NULL){
		while(fread(&visita,sizeof(VISITA),1,BD)){
			if(visita.id==id)
				switch(mes){
					case VISITASANO:
						if(visita.data.ano==anoAtual())
							contador++;
						break;
					default:		
						/*Retorna as visitas de um mes, no ano atual.*/			
						if(visita.data.mes==mes && visita.data.ano==anoAtual())
							contador++;
				}			
		}	
		fclose(BD);
		return contador;
	}else{
		/*ERRO FATAL*/
		fprintf(stderr,RED"\n\tErro em 'visitas'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}	
}
unsigned short int distribuicaoInteresse(const unsigned short int mes, const unsigned short int classe){
	ELEMENTO elemento;
	int contador=0;
	FILE *BD;
	BD=fopen(ELEMENTOS_BD,"rb");
	
	
	if(BD != NULL){
		while(fread(&elemento,sizeof(ELEMENTO),1,BD)){			
			if((elemento.categoria == VIVENDA || elemento.categoria == APARTAMENTO) && elemento.imovel.classe==classe)
				contador+=visitas(elemento.id,mes);			
		}
		fclose(BD);
		return contador;
	}else{
		/*ERRO FATAL*/
		fprintf(stderr,RED"\n\tErro em 'distribuicaoInteresse'. Falha ao abrir o arquivo: %s ."RESET,ELEMENTOS_BD);
		exit(1);
	}	
}
unsigned short int insereVisita(const VISITA *visita) {
	FILE *BD;
	
	BD=fopen(VISITAS_BD,"ab");
	
	if(fwrite(visita,sizeof(VISITA),1,BD) == 1){
		fclose(BD);
		return OK;
	}else{
		fclose(BD);
		return FALHA;
	}		
}
