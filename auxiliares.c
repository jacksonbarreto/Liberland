#include "auxiliares.h"


unsigned short int anoAtual(void){
	unsigned short int anoAtual;	
	struct tm *tempoAtual;
	
	time_t segundos;
	time(&segundos);
	tempoAtual=localtime(&segundos);
	anoAtual=tempoAtual->tm_year+1900;
	
	return anoAtual;
}
void limpaTela(void){
	system("clear || cls");
}
void zeraVetor(unsigned short int *vetor, const unsigned short int tamanho){
	unsigned short int i;
	for(i=0;i<tamanho;i++)
		vetor[i]=0;
}

unsigned short int noIntervalo(const short int escolha, const short int limiteA, const short int limiteB, const unsigned short int tipoIntervalo, const unsigned short int localnoIntervalo){
	/*Verifica se a escolha encontra-se na faixa de intervalo ou fora dela*/
	switch(tipoIntervalo){
		case INTERVALOFECHADO:
			if(localnoIntervalo == DENTRODOINTERVALO){
				return (escolha >= limiteA && escolha <= limiteB);
			}else if(localnoIntervalo == FORADOINTERVALO){
				return (!(escolha >= limiteA && escolha <= limiteB));
			}else
				return FALHA;
			break;							
		case INTERVALOABERTO:
			if(localnoIntervalo == DENTRODOINTERVALO){
				return (escolha > limiteA && escolha < limiteB);
			}else if(localnoIntervalo == FORADOINTERVALO){
				return (!(escolha > limiteA && escolha < limiteB));
			}else
				return FALHA;
			break;
		default:
			return FALHA;
	}
	return OK;
}

unsigned short int validaFormatoData(const char *dataTexto){
	unsigned short int i, dia, mes, ano;
	
	if(strlen(dataTexto) == 10){ /*String data tem 10 caracteres no formato: dd/mm/aaaa */
		for(i=0;i<10;i++){		
			if(i==2 || i==5){	/*Posição das barras '/' da data*/
				if(dataTexto[i]!='/')
					return FALHA;
			}else
				if(!isdigit(dataTexto[i]))
					return FALHA;
		}
	}else
		return FALHA;
	/*Neste ponto esta garantido que a data encontra-se no formato dd/mm/aaaa*/	
	dia = (((int) dataTexto[0] - 48) * 10) + ((int) dataTexto[1] - 48);
	mes = (((int) dataTexto[3] - 48) * 10) + ((int) dataTexto[4] - 48);
	ano = (((int) dataTexto[6] - 48) * 1000) + ( ((int) dataTexto[7] - 48) * 100) + (((int) dataTexto[8] - 48) * 10) +  ((int) dataTexto[9] - 48);
	
	if(ano != anoAtual()) /*Nesta rotina vamos operar apenas com datas inclusas no ano vigente.*/
		return FALHA;
	if(!noIntervalo(dia,1,31,INTERVALOFECHADO,DENTRODOINTERVALO))
		return FALHA;
	if(!noIntervalo(mes,1,12,INTERVALOFECHADO,DENTRODOINTERVALO))
		return FALHA;
	if(mes == 2 && dia>29)
		return FALHA;
	
	return OK;
}
unsigned short int validaFormatoHorario(const char *horarioTexto){
	unsigned short int i, hora, minuto;
	
	if(strlen(horarioTexto) == 5){ /*String data tem 05 caracteres no formato: hh:mm */
		for(i=0;i<5;i++){		
			if(i==2){	/*Posição do ':' do horário*/
				if(horarioTexto[i]!=':')
					return FALHA;
			}else
				if(!isdigit(horarioTexto[i]))
					return FALHA;
		}
	}else
		return FALHA;
	/*Neste ponto esta garantido que o horário encontra-se no formato hh:mm*/	
	hora = (((int) horarioTexto[0] - 48) * 10) + ((int) horarioTexto[1] - 48);
	minuto = (((int) horarioTexto[3] - 48) * 10) + ((int) horarioTexto[4] - 48);
			
	if(!noIntervalo(hora,0,23,INTERVALOFECHADO,DENTRODOINTERVALO))
		return FALHA;
	if(!noIntervalo(minuto,0,59,INTERVALOFECHADO,DENTRODOINTERVALO))
		return FALHA;
		
	return OK;
}
void horarioTexthorarioNum(const char *horarioTexto, unsigned short int *hora,unsigned short int *minuto){	
		*hora =(((int) horarioTexto[0] - 48) * 10) + ((int) horarioTexto[1] - 48);
		*minuto = (((int) horarioTexto[3] - 48) * 10) + ((int) horarioTexto[4] - 48);		
}

void dataTextDataNum(const char *dataTexto, unsigned short int *dia,unsigned short int *mes,unsigned short int *ano){	
		*dia = (((int) dataTexto[0] - 48) * 10) + ((int) dataTexto[1] - 48);
		*mes = (((int) dataTexto[3] - 48) * 10) + ((int) dataTexto[4] - 48);
		*ano = (((int) dataTexto[6] - 48) * 1000) + ( ((int) dataTexto[7] - 48) * 100) + (((int) dataTexto[8] - 48) * 10) +  ((int) dataTexto[9] - 48);	
}


unsigned short int validaNif(const char *nif){
	unsigned short int i,j;
	char temp[TMAXNIF+1];
	
	if(strlen(nif)==TMAXNIF){
		for(i=0;i<TMAXNIF;i++){
			if(!isdigit(nif[i]))
	 			return FALHA;	 		
		}
		/*Testa se é um nif com todos os números iguais, ex: 999999999 */
		for(i=0;i<=9;i++){ 
			for(j=0;j<TMAXNIF;j++) 
	 			temp[j]= (char) i+48;
	 		temp[j]='\0';
	 		if(strcmp(temp,nif)==0)
	 			return FALHA;
		}			 
	}else
	 	return FALHA;
	return OK; 
}

unsigned short int lerInteiro(const char *pergunta){
	unsigned short int inteiro;
	printf("%s",pergunta);
	scanf("%hu",&inteiro);
	limpaBuf();
	return inteiro;
}

void lerTexto(const char *pergunta, char *resposta, const unsigned short int tamanho){
	char formato[12]="%",temp[12];
	
	sprintf(temp,"%hu[^\n]s",tamanho);
	strcat(formato,temp);	
	printf("%s",pergunta);
	scanf(formato,resposta);
	limpaBuf();
}
void validaSalvaInteiro(unsigned short int *resposta,const unsigned short int decremento, const char *pergunta, const char *tituloErro, const char *msgErro,const short int limiteA, const short int limiteB, const unsigned short int tipoIntervalo,const unsigned short int localnoIntervalo){
	unsigned short int respostaStatus=OK, respostaTemp;
	
	do{		
		if(respostaStatus==FALHA)
			tratarErro(tituloErro,msgErro);
		
		respostaTemp=lerInteiro(pergunta);
		if(decremento==DECREMENTO)	
			respostaTemp--;
		respostaStatus = noIntervalo(respostaTemp,limiteA,limiteB,tipoIntervalo,localnoIntervalo);					
	}while(respostaStatus==FALHA);
		
	*resposta=respostaTemp;
}
void validaSalvaHorario(const char *pergunta, unsigned short int *hora, unsigned short int *minuto){
	unsigned short int leituraStatus=OK;
	char horario[6];
	
	do{
		//TRATAMENTO DE ERRO AQUI
		if(leituraStatus==FALHA)
			tratarErro("HORÁRIO INVÁLIDO!","Formato: HH:MM com H: 0 a 23 e M: 0 a 59.");
		
		lerTexto(pergunta,horario,5);		
		leituraStatus = validaFormatoHorario(horario);	
	}while(leituraStatus==FALHA);
	
	horarioTexthorarioNum(horario,hora,minuto);	
}
void zeraMapa(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA]){
	unsigned short int i, j;
	
	for(i=0;i<TMAXLINHA;i++)
		for(j=0;j<TMAXCOLUNA;j++)
			mapa[i][j]=NULO;	
}

unsigned short int criaId(void){
	static unsigned short int inicializado=NAO;
	unsigned short int i, id, inicio = 1, fim = USHRT_MAX;
	ELEMENTO elemento;
	
    if(inicializado==NAO){
        srand((unsigned int) time(NULL));
        inicializado = SIM;
    }
    fim = (fim-inicio)+1;
	do{
		id = inicio + rand() % fim;		
		elemento=consultaElemento(id);
	}while(elemento.id != NULO);
	
	return id;
}

ELEMENTO elementoNulo(void){
	ELEMENTO elemento;
	
	demolidor(&elemento);	
	elemento.id=NULO;	
	strcpy(elemento.pInteresse.descricao,"ELEMENTO NULO");	
	return elemento;
}

unsigned short int validaTamanho(const unsigned short int coordenada, const unsigned short int tamanho, const unsigned short int procedimento){
	unsigned short int tamanhoTotal = (coordenada + tamanho)-1;
	
		if(procedimento == VLINHA)
			return (tamanhoTotal <= TMAXLINHA);
		else
			return (tamanhoTotal <= TMAXCOLUNA);
}

unsigned short int validaConstrucao(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA],const unsigned short int *coordenada, const unsigned short int *tamanho){
	/*Verifica se a tentativa de construção é valida, sendo permitido a construção apenas em elemento nulou ou terreno de tamnho 1x1*/
	ELEMENTO elemento;
	unsigned short int a,b, i,j;	
	
	for(i=0, a=coordenada[0]; i < tamanho[0] ; a++, i++){
		for(j=0, b=coordenada[1]; j < tamanho[1]; b++, j++){			
				elemento=consultaElemento(mapa[a][b]);
				if(! (elemento.id== NULO || (elemento.categoria==TERRENO && (elemento.tamanho.linha==1 && elemento.tamanho.coluna==1))) )
					return FALHA;			
		}
	}	
	return OK;
}

void demolidor(ELEMENTO *elemento){
	/*Info do Elemento*/
	elemento->categoria=TERRENO;
	strcpy(elemento->obs,"");
	elemento->tamanho.linha=1;
	elemento->tamanho.coluna=1; 
	strcpy(elemento->endereco.rua,"");
	strcpy(elemento->endereco.localidade,"");
	/*Info do Imóvel*/
	elemento->imovel.classe= VENDA;
	elemento->imovel.tipologia=0;
	elemento->imovel.area = 0;
	elemento->imovel.suites= 0;
	elemento->imovel.certEnerg = 0;
	strcpy(elemento->imovel.regPredial,"");
	strcpy(elemento->imovel.certHabit,"");
	elemento->imovel.valor= 0;
	/*Info do Proprietario*/
	strcpy(elemento->imovel.proprietario.nome,"República Livre de Liberland");
	strcpy(elemento->imovel.proprietario.nif,"000000000");
	/*Info do Negócio*/	
	elemento->imovel.negocio.status=DISPONIVEL; 	
	elemento->imovel.negocio.data.dia=0;
	elemento->imovel.negocio.data.mes=0;
	elemento->imovel.negocio.data.ano=0;
	/*Info do Ponto de Interesse*/	
	strcpy(elemento->pInteresse.descricao,"TERRENO PARA CONSTRUÇÃO");
	elemento->pInteresse.horario.aplica=NAOAPLICAVEL; 
	elemento->pInteresse.horario.abertura.hora=0;
	elemento->pInteresse.horario.abertura.minutos=0;
	elemento->pInteresse.horario.encerramento.hora=0;
	elemento->pInteresse.horario.encerramento.minutos=0;	
}
void limpaBuf(void){
	/*Esvazia o buffer do teclado consumindo todos os caracteres que lá estão*/
	char c;
	while((c=getchar()) != '\n' && c != EOF);
}
void duploZero(const unsigned short int numero){
	/*Faz a impresão de números menores que 10 no formato de dois digitos.*/
	if(numero>=0 && numero<10)
		printf("0%hu",numero);
	else
		printf("%hu",numero);
}
void imprimeNif(const char *nif){
	/*Faz a impressão formatada do nif, no formato xxx.xxx.xxx*/
	unsigned short int i;
	
	for(i=0;nif[i]!='\0';i++){
		if(i!=0 && (i%3 ==0))
			putchar('.');
		printf("%c",nif[i]);
	}
}
