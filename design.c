#include "design.h"



unsigned short int menuPrincipal(void){
	unsigned short int escolha, statusEscolha=OK;
	
	
	/*############## CABEÇALHO ##############*/
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "MENU PRINCIPAL",1,"Início");
	
	/*############## OPÇÕES ##############*/
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    1 - Consultar Elemento Urbano");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    2 - Registrar Negócio");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    3 - Gerar Relatório");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    0 - SAIR");
	borda(BORDALARG,'*',RECUOSIMPLES);		
	
	/*############## LEITURA DA ESCOLHA ##############*/	
	do{
		/*TRATAMENTO DE ERRO*/
		if(statusEscolha==FALHA)
			tratarErro("OPÇÃO INVÁLIDA!","Escolha uma opção entre 0 e "SMAXOPCAOPRINCIAL);	
	
		escolha=lerInteiro("\n\t\tEscolha --> ");
		
		if(escolha == MATRICULA1 || escolha == MATRICULA2 || noIntervalo(escolha,MINOPCAOPADRAO,MAXOPCAOPRINCIAL,INTERVALOFECHADO,DENTRODOINTERVALO) ){
			statusEscolha=OK;				
		}else{			
			statusEscolha=FALHA;		
		} 
	}while(statusEscolha==FALHA);	
	
	return escolha;
}

unsigned short int menuAdm(void){
	unsigned short int escolha, statusEscolha=OK;	
	/*############## CABEÇALHO ##############*/
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "MENU ADMINISTRATIVO",2,"Início","Menu Administrativo");
	
	/*############## OPÇÕES ##############*/
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    1 - Criar Elemento Urbano");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    2 - Apagar Elemento Urbano");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    3 - Atualizar Elemento Urbano");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    4 - Testar Sistema");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    0 - VOLTAR");
	borda(BORDALARG,'*',RECUOSIMPLES);	
	
	/*############## LEITURA DA ESCOLHA ##############*/	
	do{
		/*TRATAMENTO DE ERRO*/
		if(statusEscolha==FALHA)
			tratarErro("OPÇÃO INVÁLIDA!","Escolha uma opção entre 0 e "SMAXOPCAOADM);
	
		escolha=lerInteiro("\n\t\tEscolha --> ");
		statusEscolha=noIntervalo(escolha,MINOPCAOPADRAO,MAXOPCAOADM,INTERVALOFECHADO,DENTRODOINTERVALO);		
	}while(statusEscolha==FALHA);	
	
	return escolha;
}
unsigned short int menuNegocio(void){
	unsigned short int escolha, statusEscolha=OK;
	
	/*############## CABEÇALHO ##############*/
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "MENU NEGOCIAL",2,"Início","Menu de Negociações");
	
	/*############## OPÇÕES ##############*/
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    1 - Registrar uma Venda/Arrendamento");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    2 - Cancelar uma Venda/Arrendamento");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    3 - Registrar uma visita(Interessado)");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    0 - VOLTAR");
	borda(BORDALARG,'*',RECUOSIMPLES);	
	
	/*############## LEITURA DA ESCOLHA ##############*/	
	do{
		/*TRATAMENTO DE ERRO*/
		if(statusEscolha==FALHA)
			tratarErro("OPÇÃO INVÁLIDA!","Escolha uma opção entre 0 e "SMAXOPCAONEGOCIO);
	
		escolha=lerInteiro("\n\t\tEscolha --> ");
		statusEscolha=noIntervalo(escolha,MINOPCAOPADRAO,MAXOPCAONEGOCIO,INTERVALOFECHADO,DENTRODOINTERVALO);
		
	}while(statusEscolha==FALHA);	
	
	return escolha;
}

unsigned short int menuRelatorio(void){
	unsigned short int escolha, statusEscolha=OK;
	
	/*############## CABEÇALHO ##############*/
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "RELATÓRIOS",2,"Início","Menu de Relatórios Gerenciais");
	
	/*############## OPÇÕES ##############*/
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    1 - Imóveis VENDIDOS por mês");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    2 - Imóveis ARRENDADOS por mês");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    DISTRIUIÇÃO DOS IMÓVEIS");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    3 - Por FAIXA DE PREÇO");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    4 - Por TIPOLOGIA");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    5 - Por ÁREA (m²)");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    6 - Por CERTIFICADO ENERGÉTICO");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    7 - Por INTERESSE - EM IMÓVEIS A VENDA");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    8 - Por INTERESSE - EM IMÓVEIS À ARRENDAR");
	bordaVertical(BORDALARG,'*',RECUOSIMPLES, ESQUERDA,"    0 - VOLTAR");
	borda(BORDALARG,'*',RECUOSIMPLES);	
	
	/*############## LEITURA DA ESCOLHA ##############*/	
	do{
		/*TRATAMENTO DE ERRO*/
		if(statusEscolha==FALHA)
			tratarErro("OPÇÃO INVÁLIDA!","Escolha uma opção entre 0 e "SMAXOPCAORL);
	
		escolha=lerInteiro("\n\t\tEscolha --> ");
		statusEscolha=noIntervalo(escolha,MINOPCAOPADRAO,MAXOPCAORL,INTERVALOFECHADO,DENTRODOINTERVALO);
		
	}while(statusEscolha==FALHA);	
	
	return escolha;
}

void lerPosix(unsigned short int *coordenadas, unsigned short int *tamanho, const unsigned short int procedimento){
	unsigned short int i, totalLeitura=2, statusEscolha, limiteSuperior;	
	
	if(procedimento == TAMANHO){
		borda(BORDALARG,'-',RECUOSIMPLES);
		bordaVertical(BORDALARG,'|',RECUOSIMPLES,ESQUERDA,"TAMANHO DO ELEMENTO URBANO");
		borda(BORDALARG,'-',RECUOSIMPLES);
	} else{
		borda(BORDALARG,'-',RECUOSIMPLES);
		bordaVertical(BORDALARG,'|',RECUOSIMPLES,ESQUERDA,"COOREDENADAS DO ELEMENTO URBANO");
		borda(BORDALARG,'-',RECUOSIMPLES);
	}
	
	
	for(i=0;i<totalLeitura;i++){
		statusEscolha=OK;
		limiteSuperior= (i==0)? TMAXLINHA-1 : TMAXCOLUNA-1;
		
		do{			
			/*TRATAMENTO DE ERRO*/
			if(statusEscolha==FALHA)
				if(procedimento == TAMANHO){
					tratarErro("TAMANHO INVÁLIDO!","O tamanho ultrapassa o espaço do mundo.");
				}else{
					if(i==0)					
						tratarErro("LINHA INVÁLIDA!","Informe uma LINHA entre 1 e "STMAXLINHA);
					else
						tratarErro("COLUNA INVÁLIDA!","Informe uma COLUNA entre 1 e "STMAXCOLUNA);
				}	
				
		
			if(i==0)
				if(procedimento == TAMANHO)
					tamanho[i]=lerInteiro("\n\t\tTamanho em LINHAS: ");
				else
					coordenadas[i]=lerInteiro("\n\t\tInforme a LINHA: ");
			else
				if(procedimento == TAMANHO)
					tamanho[i]=lerInteiro("\n\t\tTamanho em COLUNAS: ");
				else
					coordenadas[i]=lerInteiro("\n\t\tInforme a COLUNA: ");
			
			if(procedimento == COORDENADA)
				coordenadas[i]--; /*Decrementa a coordenada informada, para o usuario utilizar de 1 ao max e nao de zero ao max*/
			if(procedimento == TAMANHO)
				if(i==0)
					statusEscolha=validaTamanho(coordenadas[i],tamanho[i],VLINHA);
				else
					statusEscolha=validaTamanho(coordenadas[i],tamanho[i],VCOLUNA);
			else
				statusEscolha=noIntervalo(coordenadas[i],MINOPCAOPADRAO,limiteSuperior,INTERVALOFECHADO,DENTRODOINTERVALO);			
		}while(statusEscolha==FALHA);
	}		
}

void imprimeElemento(const ELEMENTO *elemento){
	char titulo[20];
	putchar('\n');
	/*Define o título da Ficha*/
	if(elemento->categoria == VIVENDA || elemento->categoria == APARTAMENTO)
		strcpy(titulo,"IMÓVEL");
	else
		strcpy(titulo,"PONTO DE INTERESSE");
	/*Imprime o cabeçalho da ficha*/	
	borda(BORDAFICHA,'-',RECUODUPLO);
	bordaVertical(BORDAFICHA,'|',RECUODUPLO,CENTRALIZADO,titulo);
	borda(BORDAFICHA,'-',RECUODUPLO);
	printf("\t\tReferência: %hu",elemento->id);
	printf("\t| Categoria: %s",CATEGORIA[elemento->categoria]);
	
	if(elemento->categoria == VIVENDA || elemento->categoria == APARTAMENTO){
		/*Imprime as características do imóvel*/		
		printf("\n\t\tClasse: ");
		(elemento->imovel.classe == VENDA) ? printf("VENDA") : printf("ARRENDAMENTO");
		
		printf("\t| Status: ");
		if(elemento->imovel.negocio.status == DISPONIVEL){
			printf(GREEN "DISPONÍVEL" RESET);				
		}else{
			if(elemento->imovel.classe == VENDA)
				printf(RED "VENDIDA EM ");
			else
				printf(RED "ARRENDADA EM ");			
			printf("%hu/%hu/%hu" RESET,elemento->imovel.negocio.data.dia, elemento->imovel.negocio.data.mes,elemento->imovel.negocio.data.ano);
		}		
			
		printf("\n\t\tTipologia: T%hu", elemento->imovel.tipologia);
		printf("\t| Área útil: %hum²", elemento->imovel.area);
		printf("\t| Suítes: %hu",elemento->imovel.suites);
		printf("\t| Cert. Energético: %s",CERTENERG[elemento->imovel.certEnerg]);
		
		printf("\n\t\tRegistro Predial: %s",elemento->imovel.regPredial);
		printf("\t\t| Cert. de Habitação: %s",elemento->imovel.certHabit);
					
		printf("\n\t\tValor: EUR %lu,00",elemento->imovel.valor);
		(elemento->imovel.classe == ARRENDA) ? printf("/mês") : putchar(' ');
		
		printf("\t| Interessados: %hu\n",visitas(elemento->id,0));
		
		borda(BORDAFICHA,'-',RECUODUPLO);
		bordaVertical(BORDAFICHA,'|',RECUODUPLO,CENTRALIZADO,"Proprietário");
		borda(BORDAFICHA,'-',RECUODUPLO);
		
		printf("\t\tNome: %s",elemento->imovel.proprietario.nome);
		printf("\t|  NIF: ");		
		imprimeNif(elemento->imovel.proprietario.nif);
		putchar('\n');		
		
	}else{
		/*Imprime as características do Ponto de Interesse*/
						
		printf("\n\t\tDescrição: %s",elemento->pInteresse.descricao);
		
		if(elemento->pInteresse.horario.aplica == APLICAVEL){
			printf("\n\t\tHorário de Funcionamento: ");
			duploZero(elemento->pInteresse.horario.abertura.hora);
			printf("h");
			duploZero(elemento->pInteresse.horario.encerramento.minutos);
			printf(" às ");
			duploZero(elemento->pInteresse.horario.encerramento.hora);
			printf("h");
			duploZero(elemento->pInteresse.horario.abertura.minutos);
			printf(".");
		}	
		putchar('\n');
	}
	borda(BORDAFICHA,'-',RECUODUPLO);
	bordaVertical(BORDAFICHA,'|',RECUODUPLO,CENTRALIZADO,"Endereço");
	borda(BORDAFICHA,'-',RECUODUPLO);
	
	printf("\t\tEndereço: %s - %s\n",elemento->endereco.rua, elemento->endereco.localidade);
	
	borda(BORDAFICHA,'-',RECUODUPLO);
	bordaVertical(BORDAFICHA,'|',RECUODUPLO,CENTRALIZADO,"Observações");
	borda(BORDAFICHA,'-',RECUODUPLO);
	
	printf("\t\t%s\n", elemento->obs);		
	borda(BORDAFICHA,'-',RECUODUPLO);
}

void continuar(const char *mensagem){
	printf("%s",mensagem);
	setbuf(stdin,NULL);
	getchar();
}

void recuo(const unsigned short int recuo){	
	unsigned short int i;
	for(i=0;i<recuo;i++)
		putchar('\t');	
}

void borda(const unsigned short int tamanho, const char simbolo, const unsigned short int margem){
	unsigned short int i;
	recuo(margem);
	for(i=0;i<tamanho;i++)	
		printf("%c",simbolo);
	putchar('\n');
}

void bordaVertical(const short int tamanho, const char simbolo, const unsigned short int margem,const unsigned short int alinhamento, const char *titulo){
	unsigned short int i, espacoLivre, espacoEsquerdo, espacoDireita;
	espacoLivre = tamanho - (strlen(titulo)+2);
	
	recuo(margem);
	putchar(simbolo);	
	switch(alinhamento){		
		case 2: /*A ESQUERDA*/
			putchar(' ');
			printf("%s",titulo);
			for(i=0;i<espacoLivre-1;i++)
				putchar(' ');		
			break;
		
		case 3: /*A DIREITA*/
			for(i=0;i<espacoLivre-1;i++)
				putchar(' ');
			printf("%s",titulo);
			putchar(' ');
			break;
		
		case 1:/*CENTRALIZADO*/
		default:
			espacoDireita = espacoLivre/2;
			espacoEsquerdo = espacoLivre/2;
			if(espacoLivre % 2 == 0)				
				for(i=0;i<espacoEsquerdo;i++)
					putchar(' ');				
			else
				for(i=0;i<espacoEsquerdo+1;i++)
					putchar(' ');
						
			printf("%s",titulo);
			for(i=0;i<espacoDireita;i++)
				putchar(' ');			
	}	
	putchar(simbolo);
	putchar('\n');
}

void cabecalho(const unsigned short int tamanho, const char simbolo, const unsigned short int margem, const char *titulo, const unsigned short int totsubtitulos, ...){
	unsigned short int i;
	char localizacao[150], *temp;
	localizacao[0]='\0';
	va_list subtitulos;	
	printf("\n\n\n");
	borda(tamanho, simbolo, margem);
	bordaVertical(tamanho, simbolo, margem,CENTRALIZADO, "");	
	bordaVertical(tamanho, simbolo, margem, CENTRALIZADO,titulo);
	bordaVertical(tamanho, simbolo, margem,CENTRALIZADO, "");	
	
	if(totsubtitulos > 0){		
		va_start(subtitulos, totsubtitulos);
		temp= va_arg(subtitulos,char *);
		
		strcat(localizacao,temp);
		
		for(i=1;i<totsubtitulos;i++){
			strcat(localizacao," > ");
			temp= va_arg(subtitulos,char *);			
			strcat(localizacao,temp);			
		}	
		va_end(subtitulos);
		borda(tamanho, '-', margem);
		bordaVertical(tamanho, simbolo, margem, ESQUERDA, localizacao);
	}	
	borda(tamanho, simbolo, margem);
	putchar('\n');	
}

int criaElemento(const unsigned short int id, const unsigned short int coordenadas[2], const unsigned short int tamanho[2]){
	unsigned short int statusEscolha=OK, escolha, i,j;	
	ELEMENTO elemento;
	
	/*############## CABEÇALHO ##############*/
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "CRIANDO NOVO ELEMENTO URBANO",3,"Início","Menu Administrativo","Criar Elemento Urbano");
			
	borda(BORDALARG,'-',RECUOSIMPLES);
	bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"ESCOLHA DA CATEGORIA");
	borda(BORDALARG,'-',RECUOSIMPLES);
	
	desenhaLegenda(NLEGENDA);
	validaSalvaInteiro(&elemento.categoria,DECREMENTO,"\n\tCategoria: ","CATEGORIA INVÁLIDA!","Escolha uma CATEGORIA entre 1 e 16",MINOPCAOPADRAO,15,INTERVALOFECHADO,DENTRODOINTERVALO);
		
	limpaTela();
	if(elemento.categoria== VIVENDA || elemento.categoria==APARTAMENTO){
		/*é um imóvel*/
		/*############## CABEÇALHO ##############*/
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "CRIANDO UM IMÓVEL",4,"Início","Menu Administrativo","Criar Elemento Urbano", "Criar Imóvel");
	
		validaSalvaInteiro(&elemento.imovel.classe,DECREMENTO,"\n\tInforme a CLASSE do imóvel [1 - ARRENDAMENTO  | 2 - VENDA]: ","CLASSE INVÁLIDA!","Escolha uma CLASSE entre 1 e 2.",MINOPCAOPADRAO,1,INTERVALOFECHADO,DENTRODOINTERVALO);
	
		validaSalvaInteiro(&elemento.imovel.tipologia,SEMDECREMENTO,"\n\tQuartos: ","QUANTIDADE DE QUARTOS INVÁLIDA!","Escolha uma QUANTIDADE entre 0 e "SMAXQUARTOS,MINOPCAOPADRAO,MAXQUARTOS,INTERVALOFECHADO,DENTRODOINTERVALO);
	
		validaSalvaInteiro(&elemento.imovel.suites,SEMDECREMENTO,"\n\tTotal de suítes: ","QUANTIDADE DE SUÍTES INVÁLIDA!","Nº de suítes deve ser inferior a tipologia do imóvel.",MINOPCAOPADRAO,elemento.imovel.tipologia,INTERVALOFECHADO,DENTRODOINTERVALO);
	
		validaSalvaInteiro(&elemento.imovel.area,SEMDECREMENTO,"\n\tÁrea do imóvel: ","ÁREA INVÁLIDA!","Escolha uma ÁREA entre 0 e "SMAXAREA,MINOPCAOPADRAO,MAXAREA,INTERVALOFECHADO,DENTRODOINTERVALO);
		
		do{
			/*TRATAMENTO DE ERRO*/
			if(statusEscolha==FALHA)
				tratarErro("VALOR INVÁLIDO!","O valor deve ser maior que ZERO.");
						
			printf("\n\tValor: ");
			scanf("%lu",&elemento.imovel.valor);
			if(elemento.imovel.valor>0)				
				statusEscolha=OK;						
			else
				statusEscolha=FALHA;
		}while(statusEscolha==FALHA);
		
		printf("\n\tESCOLHA UM CERTIFICADO ENERGÉTICO\n\t");
		for(i=0;i<8;i++){
			printf("%hu - %s\t|",i+1,CERTENERG[i]);
		}
		validaSalvaInteiro(&elemento.imovel.certEnerg,DECREMENTO,"\n\n\tCertificado Energético: ","CERTIFICADO ENERGÉTICO INVÁLIDO!","Escolha um certificado entre 1 e 8.",MINOPCAOPADRAO,7,INTERVALOFECHADO,DENTRODOINTERVALO);
	
		lerTexto("\n\tRegistro Predial: ",elemento.imovel.regPredial,TMAXREGPREDIAL);
		lerTexto("\n\tCertificado de Habitabilidade: ",elemento.imovel.certHabit,TMAXCERTHAB);
		lerTexto("\n\tNome do Proprietário: ",elemento.imovel.proprietario.nome,TMAXNOME);	
		
		do{
			/*TRATAMENTO DE ERRO*/
			if(statusEscolha==FALHA)
				tratarErro("NIF INVÁLIDO!","O NIF deve ter exclusivamente 9 digitos.");
			
			lerTexto("\n\tNIF do Proprietário: ",elemento.imovel.proprietario.nif,TMAXNIF);
				
			statusEscolha = validaNif(elemento.imovel.proprietario.nif);
									
		}while(statusEscolha==FALHA);		
		
		elemento.imovel.negocio.status=DISPONIVEL;		
		elemento.imovel.negocio.data.dia=0;
		elemento.imovel.negocio.data.mes=0;
		elemento.imovel.negocio.data.ano=0;		
	
	}else{
		/*é um ponto de interesse*/
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "CRIANDO UM PONTO DE INTERESSE",4,"Início","Menu Administrativo","Criar Elemento Urbano", "Criar Ponto de Interesse");
	
		lerTexto("\n\tDescrição: ",elemento.pInteresse.descricao,TMAXDESCRICAO);
		
		validaSalvaInteiro(&elemento.pInteresse.horario.aplica,DECREMENTO,"\n\tPossui HORÁRIO de funcionamento [1 - NÃO  | 2 - SIM]: ","OPÇÃO INVÁLIDA!","Escolha uma opção entre 1 ou 2.",MINOPCAOPADRAO,1,INTERVALOFECHADO,DENTRODOINTERVALO);
						
		if(elemento.pInteresse.horario.aplica == APLICAVEL){
			validaSalvaHorario("\n\tHORÁRIO de abertura [HH:MM]: ",&elemento.pInteresse.horario.abertura.hora,&elemento.pInteresse.horario.abertura.minutos);			
			validaSalvaHorario("\n\tHORÁRIO de encerramento [HH:MM]: ",&elemento.pInteresse.horario.encerramento.hora,&elemento.pInteresse.horario.encerramento.minutos);					
		}else{
			elemento.pInteresse.horario.abertura.hora=0;
			elemento.pInteresse.horario.abertura.minutos=0;
			elemento.pInteresse.horario.encerramento.hora=0;
			elemento.pInteresse.horario.encerramento.minutos=0;
		}
	}
	
	lerTexto("\n\tRua c/ nº: ",elemento.endereco.rua,TMAXRUA);
	lerTexto("\n\tLocalidade: ",elemento.endereco.localidade,TMAXRUA);
	lerTexto("\n\tObservações: ",elemento.obs,TMAXOBS);
		
	elemento.id=criaId();
	elemento.inicio.linha=coordenadas[0];
	elemento.inicio.coluna=coordenadas[1];
	elemento.tamanho.linha=tamanho[0];
	elemento.tamanho.coluna=tamanho[1];
	
	insereElemento(&elemento);
	boxSucesso("SUCESSO","Elemento criado com Sucesso.");
}

void tratarErro(const char *titulo, const char *instrucao){	
	char erroTitulo[MAXTITULOERRO]="ERRO: ";
	strcat(erroTitulo,titulo);
	printf("\n");
	printf(RED);
	borda(BORDAERROR,'-',RECUOERRO);
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,"");
	bordaVertical(BORDAERROR,'|',RECUOERRO, CENTRALIZADO,erroTitulo);
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,"");	
	borda(BORDAERROR,'-',RECUOERRO);		
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,instrucao);
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,"");
	borda(BORDAERROR,'-',RECUOERRO);
	printf(RESET);
	continuar("\t\t\t\tPressione qualquer tecla para tentar novamente. . . ");		
	printf("\n");
}
void boxSucesso(const char *titulo, const char *instrucao){		
	printf("\n");
	printf(GREEN);
	borda(BORDAERROR,'-',RECUOERRO);
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,"");
	bordaVertical(BORDAERROR,'|',RECUOERRO, CENTRALIZADO,titulo);
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,"");	
	borda(BORDAERROR,'-',RECUOERRO);		
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,instrucao);
	bordaVertical(BORDAERROR,'|',RECUOERRO, ESQUERDA,"");
	borda(BORDAERROR,'-',RECUOERRO);
	printf(RESET);
	continuar("\t\t\t\tPressione qualquer tecla para continuar. . . ");		
	printf("\n");
}
void desenhaLegenda(unsigned short int i){
	if(i==SLEGENDA){
	
		putchar('\n');
		printf("\n\t\t+ - RUA            H - HABITAÇÃO PERMANENTE     T - TERRENO               $ - MULTIBANCO");
		printf("\n\t\tV - VIVENDA        Ø - PARQUE OU PRAÇA          R - ÁREA RURAL            M - MONUMENTO");
		printf("\n\t\tA - APARTAMENTO    ^ - MONTANHA                 » - RIO                   Q - QUIOSQUE");
		printf("\n\t\tC - COMÉRCIO       P - PRAIA                    G - ÁREA GOVERNAMENTAL    @ - ESPAÇO PÚBLICO");
		putchar('\n');
	}else{
		putchar('\n');
		printf("\n\t\t1 - RUA            5 - HABITAÇÃO PERMANENTE      9 - TERRENO               13 - MULTIBANCO\n");
		printf("\n\t\t2 - VIVENDA        6 - PARQUE OU PRAÇA          10 - ÁREA RURAL            14 - MONUMENTO\n");
		printf("\n\t\t3 - APARTAMENTO    7 - MONTANHA                 11 - RIO                   15 - QUIOSQUE\n");
		printf("\n\t\t4 - COMÉRCIO       8 - PRAIA                    12 - ÁREA GOVERNAMENTAL    16 - ESPAÇO PÚBLICO\n");	
		putchar('\n');
	}
}

void desenhaMapa(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA], const unsigned short int id){
	int i, j;
	
	for(i=0;i<TMAXLINHA;i++){
		printf("\n\t\t");
		if(i==0){
			/*desenha o head*/
			printf(" X|");
			for(j=1;j<=TMAXCOLUNA;j++){
				printf("%2i|",j);
			}
			printf("\n\t\t");
		}
		
		printf("%2i|",i+1); /*desenha o indice lateral*/ 
		/*desenha os elementos do mapa*/
		for(j=0;j<TMAXCOLUNA;j++){
			
			switch(consultaSimbolo(mapa[i][j])){
					case '»':
						printf(BLUE);
						break;
					case '^':
						printf(MARROM);
						break;
					case '+':
						printf(CINZA);
						break;
					case 'Ø':
						printf(VERDEPARQUE);
						break;
					case 'R':
						printf(VERDERURAL);
						break;
					case 'P':
						printf(AREIA);
						break;
					case '$':
						printf(GREEN);
						break;
					case 'A':
						printf(ROXOT);
						break;
					case 'V':
						printf(LARANJAT);
						break;
				}
				if(id != 0){
					if(mapa[i][j] == id)
						printf(AMARELOT);				
				}	
			printf(" %c ", consultaSimbolo(mapa[i][j]));
			printf(RESET);
		}
	}
	if(id == MAPAGENERICO)
		desenhaLegenda(SLEGENDA);
	printf("\n");	
}

unsigned short int lerCoordenadaTamanho(unsigned short int mapa[TMAXLINHA][TMAXCOLUNA], unsigned short int *coordenadas, unsigned short int *tamanho){

	unsigned short int escolha,statusEscolha=OK,status=OK;
	
	do{
		/*TRATAMENTO DE ERRO*/
		if(status==FALHA){ /*Primeiro tente demolir o local desejado.*/
			tratarErro("CONSTRUÇÃO NÃO AUTORIZADA!","Sua construção invade um ELEMENTO EXISTENTE.");			
			borda(BORDALARG,'-',RECUOSIMPLES);
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"O QUE DESEJA FAZER?");
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"");
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"0 - VOLTAR AO MENU PRINCIPAL   |   1 - INSERIR NOVAS COORDENADAS E TAMANHO");
			borda(BORDALARG,'-',RECUOSIMPLES);
			do{
				if(statusEscolha==FALHA)
					tratarErro("OPÇÃO INVÁLIDA!","Escolha uma opção entre 0 e 1.");
					
				escolha=lerInteiro("\n\tEscolha: ");				
				statusEscolha = noIntervalo(escolha,0,1,INTERVALOFECHADO,DENTRODOINTERVALO);
			}while(statusEscolha==FALHA);
			if(escolha==0)
				return FALHA;
		}			
		lerPosix(coordenadas,tamanho,COORDENADA);
		lerPosix(coordenadas,tamanho,TAMANHO);
		status=validaConstrucao(mapa,coordenadas,tamanho);
	}while(status == FALHA);	
	return OK;
}

void registraNegocio(const unsigned short int id, const unsigned short int operacao){
	ELEMENTO elemento=consultaElemento(id);
	unsigned short int status=OK;
	char data[TMAXDATA+1];
	
	limpaTela();
	/*############## CABEÇALHO ##############*/
	if(operacao == CANCELARNEGOCIO)
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "CANCELAR NEGÓCIO",2,"Início","Cancelar uma VENDA ou ARRENDAMENTO");
	else
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "REGISTRAR NEGÓCIO",2,"Início","Registrar uma VENDA ou ARRENDAMENTO");
	if(operacao != CANCELARNEGOCIO){
		do{
			/*TRATAMENTO DE ERRO*/
			if(status==FALHA)
				tratarErro("DATA INVÁLIDA!","Formato válido: dd/mm/aaaa. Com ano atual.");
				
			if(elemento.imovel.classe==VENDA)	
				lerTexto("\n\tData da venda  [dd/mm/aaaa]: ",data,11);
			else
				lerTexto("\n\tData do arrendamento  [dd/mm/aaaa]: ",data,11);
				status=validaFormatoData(data);			
		}while(status==FALHA);
		dataTextDataNum(data,&elemento.imovel.negocio.data.dia,&elemento.imovel.negocio.data.mes,&elemento.imovel.negocio.data.ano);
		elemento.imovel.negocio.status=INDISPONIVEL;
		atualizaElemento(&elemento);
		boxSucesso("SUCESSO","Negócio registrado com sucesso");
	}else{
		elemento.imovel.negocio.status=DISPONIVEL;
		if(atualizaElemento(&elemento))	
			boxSucesso("SUCESSO","Cancelamento realizado com sucesso");
			
	}	
}

void imprimeRLvendidosMes(const unsigned short int classe){
	
	unsigned short int i, vivendasArrendadas[12]={0}, vivendasVendidas[12]={0},apartamentosArrendados[12]={0}, apartamentosVendidos[12]={0};
	/*############## CABEÇALHO ##############*/
	if(classe==VENDA)
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "VENDA DE IMÓVEIS POR MESES",3,"Início","Relatório Gerencial","Imóveis Vendidos por Mês");
	else
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "ARRENDAMENTO DE IMÓVEIS POR MESES",3,"Início","Relatório Gerencial","Imóveis Arrendados por Mês");
		
	negociosMes(vivendasArrendadas,vivendasVendidas,apartamentosArrendados,apartamentosVendidos);
	printf(BOLD"\n\tMÊS\t\t   | Vivendas |\t\t| Apartamentos |\t\t| TOTAL |"RESET);
	
	for(i=0;i<12;i++){
		if(classe==VENDA)
			if(noIntervalo(i,2,7,INTERVALOFECHADO,DENTRODOINTERVALO))
				printf("\n\t%s:\t\t\t%hu\t\t\t%hu\t\t\t    %hu",MESES[i],vivendasVendidas[i],apartamentosVendidos[i],vivendasVendidas[i]+apartamentosVendidos[i]); 
			else
				printf("\n\t%s:\t\t%hu\t\t\t%hu\t\t\t    %hu",MESES[i],vivendasVendidas[i],apartamentosVendidos[i],vivendasVendidas[i]+apartamentosVendidos[i]); 
		else
			if(noIntervalo(i,2,7,INTERVALOFECHADO,DENTRODOINTERVALO))
				printf("\n\t%s:\t\t\t%hu\t\t\t%hu\t\t\t    %hu",MESES[i],vivendasArrendadas[i],apartamentosArrendados[i],vivendasArrendadas[i]+apartamentosArrendados[i]); 
			else
				printf("\n\t%s:\t\t%hu\t\t\t%hu\t\t\t    %hu",MESES[i],vivendasArrendadas[i],apartamentosArrendados[i],vivendasArrendadas[i]+apartamentosArrendados[i]); 
	}
	printf("\n\n");
}
void imprimeDistPreco(void){
	unsigned short int precosVenda[4], precosArrenda[4];
	distribuicaoPreco(precosVenda,precosArrenda);
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "DISTRIBUIÇÃO DE IMÓVEIS - POR PREÇO",4,"Início","Relatório Gerencial","Distribuição de Imóveis","Por faixa de preço");
	
	borda(BORDALARG,'-',RECUOSIMPLES);
	bordaVertical(BORDALARG,'|',RECUOSIMPLES, ESQUERDA,"DISPONÍVEIS PARA ARRENDAMENTO");
	borda(BORDALARG,'-',RECUOSIMPLES);
	
	printf("\n\tAté 350,00: %hu",precosArrenda[0]);
	printf("\n\tEntre 351,00 e 700,00:  %hu",precosArrenda[1]);
	printf("\n\tEntre 701,00 e 1200,00:  %hu",precosArrenda[2]);
	printf("\n\tAcima de 1200,00:  %hu",precosArrenda[3]);
	printf("\n\n");
	borda(BORDALARG,'-',RECUOSIMPLES);
	bordaVertical(BORDALARG,'|',RECUOSIMPLES, ESQUERDA,"DISPONÍVEIS PARA VENDA");
	borda(BORDALARG,'-',RECUOSIMPLES);
	
	printf("\n\tAté 80.000,00:  %hu",precosVenda[0]);
	printf("\n\tEntre 80.001,00 e 150.000,00:   %hu",precosVenda[1]);
	printf("\n\tEntre 150.001,00 e 200.000,00:  %hu",precosVenda[2]);
	printf("\n\tAcima de 200.001,00:   %hu",precosVenda[3]);
	printf("\n\n");
}
void imprimeDistTipologia(void){
	unsigned short int i, tipologia[6];
	distribuicaoTipologia(tipologia);
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "DISTRIBUIÇÃO DE IMÓVEIS - POR TIPOLOGIA",4,"Início","Relatório Gerencial","Distribuição de Imóveis","Por Tipologia");
	
	for(i=0;i<6;i++){
		if(i!=5)
			printf("\n\tT%hu: %hu",i,tipologia[i]);
		else
			printf("\n\tT5 ou +: %hu",tipologia[i]);
	}
	printf("\n\n");
}
void imprimeDistArea(void){
	unsigned short int areas[4]={0};
	distribuicaoArea(areas);
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "DISTRIBUIÇÃO DE IMÓVEIS - POR ÁREA",4,"Início","Relatório Gerencial","Distribuição de Imóveis","Por Área");
	printf("\n\tAté 60m²:       %hu",areas[0]);
	printf("\n\tDe 60 a 100m²:  %hu",areas[1]);
	printf("\n\tDe 100 a 150m²: %hu",areas[2]);
	printf("\n\tAcima de 150m²: %hu",areas[3]);
	printf("\n\n");
}
void imprimeDistEnerg(void){
	unsigned short int certEnergetico[8];
	distribuicaoCertEnerg(certEnergetico);
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "DISTRIBUIÇÃO DE IMÓVEIS - POR CLASSIFICAÇÃO ENERGÉTICA",4,"Início","Relatório Gerencial","Distribuição de Imóveis","Por Certificado Energético");
	
	printf("\n\tA+: %hu\t\tA:  %hu",certEnergetico[0],certEnergetico[1]);
	printf("\n\tB:  %hu\t\tB-: %hu",certEnergetico[2],certEnergetico[3]);
	printf("\n\tC:  %hu\t\tD:  %hu",certEnergetico[4],certEnergetico[5]);
	printf("\n\tE:  %hu\t\tF:  %hu",certEnergetico[6],certEnergetico[7]);
	printf("\n\n");
}
void imprimeRLinteresse(const unsigned short int classe){
	unsigned short int i;
	if(classe== VENDA)
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "DISTRIBUIÇÃO DE INTERESSADOS - PARA IMÓVEIS A VENDA",4,"Início","Relatório Gerencial","Distribuição de Imóveis","Por Interessados");
	else
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "DISTRIBUIÇÃO DE INTERESSADOS - PARA IMÓVEIS À ARRENDAR",4,"Início","Relatório Gerencial","Distribuição de Imóveis","Por Interessados");
	
	for(i=0;i<12;i++){
		if(noIntervalo(i,2,7,INTERVALOFECHADO,DENTRODOINTERVALO))
			printf("\n\t%s:\t\t%hu",MESES[i],distribuicaoInteresse(i+1,classe));
		else
			printf("\n\t%s:\t%hu",MESES[i],distribuicaoInteresse(i+1,classe));
	}
	printf("\n\n");
}	
void cadastraVisita(unsigned short int id){
	VISITA visita;
	unsigned short int status=OK;
	char data[TMAXDATA+1];
	
	limpaTela();
	cabecalho(BORDALARG,'*',RECUOSIMPLES, "REGISTRO DE INTERESSADO",3,"Início","Registrar um Negócio","Registrar uma Visita");
	do{
		/*TRATAMENTO DE ERRO*/
		if(status==FALHA)
			tratarErro("DATA INVÁLIDA!","Formato válido: dd/mm/aaaa. Com ano atual.");
			
		lerTexto("\n\tData da Visita [dd/mm/aaaa]: ",data,11);
		status=validaFormatoData(data);			
	}while(status==FALHA);
	dataTextDataNum(data,&visita.data.dia,&visita.data.mes,&visita.data.ano);
	visita.id=id;
	insereVisita(&visita);
	boxSucesso("SUCESSO","Visita registrada com Sucesso.");
	printf("\n\n");
}
void telaAtualizaElemento(const unsigned int id){
	ELEMENTO elemento=consultaElemento(id);
	unsigned short int i, statusEscolha, opcao, limiteB;
	
	do{
		limpaTela();
		cabecalho(BORDALARG,'*',RECUOSIMPLES, "EDITAR ELEMENTO URBANO",3,"Início","Menu administrativo","Edição de elemento urbano");
		imprimeElemento(&elemento);
		putchar('\n');
		
		borda(BORDALARG,'-',RECUOSIMPLES);
		bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"ESCOLHA O ITEM QUE DESEJA ALTERAR");
		borda(BORDALARG,'-',RECUOSIMPLES);
		if(elemento.categoria== VIVENDA || elemento.categoria==APARTAMENTO){
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO," 1 - Classe       |    2 - Tipologia     |    3 - Área        |   4 - Suites");
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO," 5 - Cert. Energ. |    6 - Reg. Predial  |    7 - Cert. Habit.|   8 - Valor");
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"9 - Nome         |   10 - NIF           |   11 - Endereço    |  12 - Obs.");
			borda(BORDALARG,'-',RECUOSIMPLES);
			printf(BOLD);
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"13 - SALVAR   |   0 - DESCARTAR");
			printf(RESET);
			borda(BORDALARG,'-',RECUOSIMPLES);
			limiteB=13;
		}else{
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"1 - Descrição    |    2 - Horário    |    3 - Endereço  |    4 - Obs.");
			borda(BORDALARG,'-',RECUOSIMPLES);
			printf(BOLD);
			bordaVertical(BORDALARG,'|',RECUOSIMPLES,CENTRALIZADO,"5 - SALVAR    |    0 - DESCARTAR");
			printf(RESET);
			borda(BORDALARG,'-',RECUOSIMPLES);
			limiteB=5;
		}
		
		validaSalvaInteiro(&opcao,SEMDECREMENTO,"\n\tEscolha --> ","OPÇÃO INVÁLIDA!","Escolha uma opção do menu.",MINOPCAOPADRAO,limiteB,INTERVALOFECHADO,DENTRODOINTERVALO);
		if(limiteB==5)
			opcao+=14;
		
		switch(opcao){
			case 1:
				validaSalvaInteiro(&elemento.imovel.classe,DECREMENTO,"\n\tInforme a CLASSE do imóvel [1 - ARRENDAMENTO  | 2 - VENDA]: ","CLASSE INVÁLIDA!","Escolha uma CLASSE entre 1 e 2.",MINOPCAOPADRAO,1,INTERVALOFECHADO,DENTRODOINTERVALO);
				break;
			case 2:
				validaSalvaInteiro(&elemento.imovel.tipologia,SEMDECREMENTO,"\n\tQuartos: ","QUANTIDADE DE QUARTOS INVÁLIDA!","Escolha uma QUANTIDADE entre 0 e "SMAXQUARTOS,MINOPCAOPADRAO,MAXQUARTOS,INTERVALOFECHADO,DENTRODOINTERVALO);
				break;
			case 3:
				validaSalvaInteiro(&elemento.imovel.area,SEMDECREMENTO,"\n\tÁrea do imóvel: ","ÁREA INVÁLIDA!","Escolha uma ÁREA entre 0 e "SMAXAREA,MINOPCAOPADRAO,MAXAREA,INTERVALOFECHADO,DENTRODOINTERVALO);
				break;
			case 4:
				validaSalvaInteiro(&elemento.imovel.suites,SEMDECREMENTO,"\n\tTotal de suítes: ","QUANTIDADE DE SUÍTES INVÁLIDA!","Nº de suítes deve ser inferior a tipologia do imóvel.",MINOPCAOPADRAO,elemento.imovel.tipologia,INTERVALOFECHADO,DENTRODOINTERVALO);
				break;
			case 5:
				printf("\n\tESCOLHA UM CERTIFICADO ENERGÉTICO\n\t");
				for(i=0;i<8;i++)
					printf("%hu - %s\t|",i+1,CERTENERG[i]);			
				validaSalvaInteiro(&elemento.imovel.certEnerg,DECREMENTO,"\n\n\tCertificado Energético: ","CERTIFICADO ENERGÉTICO INVÁLIDO!","Escolha um certificado entre 1 e 8.",MINOPCAOPADRAO,7,INTERVALOFECHADO,DENTRODOINTERVALO);
				break;
			case 6:
				lerTexto("\n\tRegistro Predial: ",elemento.imovel.regPredial,TMAXREGPREDIAL);
				break;
			case 7:
				lerTexto("\n\tCertificado de Habitabilidade: ",elemento.imovel.certHabit,TMAXCERTHAB);
				break;
			case 8:
				do{
					/*TRATAMENTO DE ERRO*/
					if(statusEscolha==FALHA)
						tratarErro("VALOR INVÁLIDO!","O valor deve ser maior que ZERO.");
								
					printf("\n\tValor: ");
					scanf("%lu",&elemento.imovel.valor);
					if(elemento.imovel.valor>0)				
						statusEscolha=OK;						
					else
						statusEscolha=FALHA;
				}while(statusEscolha==FALHA);
				break;
			case 9:
				lerTexto("\n\tNome do Proprietário: ",elemento.imovel.proprietario.nome,TMAXNOME);
				break;
			case 10:
				do{
					/*TRATAMENTO DE ERRO*/
					if(statusEscolha==FALHA)
						tratarErro("NIF INVÁLIDO!","O NIF deve ter exclusivamente 9 digitos.");
					
					lerTexto("\n\tNIF do Proprietário: ",elemento.imovel.proprietario.nif,TMAXNIF);
						
					statusEscolha = validaNif(elemento.imovel.proprietario.nif);
											
				}while(statusEscolha==FALHA);
				break;
			case 17:
			case 11:
				lerTexto("\n\tRua c/ nº: ",elemento.endereco.rua,TMAXRUA);
				lerTexto("\n\tLocalidade: ",elemento.endereco.localidade,TMAXRUA);
				break;
			case 18:
			case 12:
				lerTexto("\n\tObservações: ",elemento.obs,TMAXOBS);
				break;
			case 19:
			case 13:
				atualizaElemento(&elemento);
				opcao=13;
				break;
			case 15:
				lerTexto("\n\tDescrição: ",elemento.pInteresse.descricao,TMAXDESCRICAO);
				break;
			case 16:
				validaSalvaInteiro(&elemento.pInteresse.horario.aplica,DECREMENTO,"\n\tPossui HORÁRIO de funcionamento [1 - NÃO  | 2 - SIM]: ","OPÇÃO INVÁLIDA!","Escolha uma opção entre 1 ou 2.",MINOPCAOPADRAO,1,INTERVALOFECHADO,DENTRODOINTERVALO);
							
				if(elemento.pInteresse.horario.aplica == APLICAVEL){
					validaSalvaHorario("\n\tHORÁRIO de abertura [HH:MM]: ",&elemento.pInteresse.horario.abertura.hora,&elemento.pInteresse.horario.abertura.minutos);			
					validaSalvaHorario("\n\tHORÁRIO de encerramento [HH:MM]: ",&elemento.pInteresse.horario.encerramento.hora,&elemento.pInteresse.horario.encerramento.minutos);					
				}else{
					elemento.pInteresse.horario.abertura.hora=0;
					elemento.pInteresse.horario.abertura.minutos=0;
					elemento.pInteresse.horario.encerramento.hora=0;
					elemento.pInteresse.horario.encerramento.minutos=0;
				}
				break;
			case 14:
				opcao=0;			
		}
	}while(!(opcao == 0 || opcao == 13));
			
	if(opcao == 13)
		boxSucesso("SUCESSO","Elemento alterado com Sucesso.");	
}
