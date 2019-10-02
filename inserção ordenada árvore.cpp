#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<unistd.h>

int cnt = 0;

//estrutura heterog�nea base da �rvore
typedef struct dado{		
	struct dado *maior;
	struct dado *menor;
	int vlr;
	int profundidade;		
}cad;

//inclui biblioteca com fun��o de busca para o trabalho
#include "buscar.h"

void inserir(cad *arvore, int vlr){
	
	//verifica se o n� est� vazio
	if(arvore->vlr == NULL){				
		arvore->vlr = vlr;
	}

	//verifica se o valor digitado � menor que o valor do n�
	if(vlr < arvore->vlr and arvore->menor != NULL){		
		cnt++;
		inserir(arvore->menor,vlr);	
	//verifica se o valor � menor que o valor do n�		
	}else if(vlr < arvore->vlr and arvore->menor == NULL){					
		cad *novo = (cad *)malloc(sizeof(cad));
		novo->maior = NULL;
		novo->menor = NULL;
		novo->profundidade = 0;
		novo->vlr = vlr;
		arvore->menor = novo;
		cnt++;
		novo->profundidade = cnt;		
	}
	
	//verifica se o valor digitado � maior que o valor do n�
	if(vlr > arvore->vlr and arvore->maior != NULL){
		cnt++;
		inserir(arvore->maior,vlr);	
	//verifica se o valor � maior que o valor do n�		
	}else if(vlr > arvore->vlr and arvore->maior == NULL){						
		cad *novo = (cad *)malloc(sizeof(cad));
		novo->maior = NULL;
		novo->menor = NULL;
		novo->profundidade = 0;
		novo->vlr = vlr;
		arvore->maior = novo;
		cnt++;
		novo->profundidade = cnt;		
	}		
}
		

void mostrar(cad* arvore){	
		
	if(arvore->maior == NULL and arvore->menor == NULL and arvore->vlr == NULL){		
		printf("\t\t\t\t\t�rvore vazia\n\n\n");
		sleep(1.5);		
	}else{	
		//verifica se o � o �ltimo menor
		if(arvore->menor != NULL){			
			mostrar(arvore->menor);			
		}
			
		printf("valor do no: %i\t profundidade do no %i\n",arvore->vlr,arvore->profundidade);
				
		//verifica se � o �ltimo maior
		if(arvore->maior != NULL){			
			mostrar(arvore->maior);			
		}		
	}
}

void remover(cad* arvore, cad *temp, int vlr){

	//percorrendo a �rvore pelo lado menor
	if(arvore->menor != NULL and vlr < arvore->menor->vlr){		
		remover(arvore->menor,temp,vlr);	
	}
	
	printf("valor do temp %i valor da arvore %i\n\n",temp->vlr,arvore->vlr);
	temp = arvore;
	
	//verifica se o valor informado foi encontrado pelo lado menor e se o n� n�o possui filho maior
	if(arvore->vlr == vlr){
		printf("arvore->vlr == vlr %i\n ",arvore->vlr);
		
		if(arvore->maior == NULL and arvore->menor == NULL){
			printf("arvore->maior == NULL and arvore->menor == NULL\n");
			if(temp->maior == arvore){
				printf("temp->maior == arvore %i\n",arvore->vlr);
				temp->maior = NULL;
			}else if(temp->menor == arvore){
				printf("temp->menor == arvore %i\n",arvore->vlr);
				temp->menor = NULL;
			}			
		}else if(arvore->maior != NULL and arvore->menor != NULL){
			printf("arvore->maior != NULL and arvore->menor != NULL");
			if(temp->maior == arvore){
				printf("temp->maior == arvore %i\n",arvore->vlr);
				temp->maior = arvore->maior;
			}else if(temp->menor == arvore){
				printf("temp->menor == arvore %i\n",arvore->vlr);
				temp->menor = arvore->maior;
			}					
		}
		
		if(arvore->maior == NULL){
			printf("arvore->maior == NULL\n");
			if(temp->maior == arvore){
				printf("temp->maior == arvore %i\n",arvore->menor->vlr);
				temp->maior = arvore->menor;
			}else if(temp->menor == arvore){
				printf("temp->menor == arvore %i\n",arvore->menor->vlr);
				temp->menor = arvore->menor;
			}			
		}else if(arvore->menor == NULL){
			printf("arvore->menor == NULL\n");
			if(temp->maior == arvore){
				printf("temp->maior == arvore %i\n",arvore->maior->vlr);
				temp->maior = arvore->maior;
			}else if(temp->menor == arvore){
				printf("temp->menor == arvore %i\n",arvore->maior->vlr);
				temp->menor = arvore->maior;
			}		
		}
	}
	
	//percorrendo a �rvore pelo lado maior	
	if(arvore->maior != NULL and vlr > arvore->maior->vlr){		
		remover(arvore->maior,temp,vlr);		
	}
}


main(){
	
	//habilita a acentua��o com base na localidade padr�o do sistema
	setlocale(LC_ALL,"");
	
	//declara��o de vari�veis
	int vlr = 0, sel = 0,vetor[11] = {15,20,12,14,40,13,32,50};

	//declara, aloca mem�ria para o n� raiz, e inicializa os valores
	cad *no = (cad *)malloc(sizeof(cad)), *tmp;
	no->maior = NULL;
	no->menor = NULL;
	no->vlr = NULL;
	no->profundidade = 0;
	
	//loop do menu de entrada de dados
	while(1){
		
		system("cls");
		printf("\n\nSelecione uma op��o:\n\n1 - Inserir\n2 - Exibir\n3 - Remover\n4 - Inserir o vetor {15,20,12,14,40,13,32,50}\n5 - Buscar\n6 - Exibir n�s raiz\n7 - Sair");
		fflush(stdin);
		sel = getch()-48;
		
		switch(sel){
		
			case 1:{				
				//entrada de dados do usu�rio e a profundidade da �rvore
				system("cls");
				printf("\n\n\n\nInforme um n�mero inteiro maior que zero:\n");
				scanf("%i",&vlr);				
				cnt = 0;
				inserir(no, vlr);
				break;
			}
			
			case 2:{				
				//insere valores na �rvore e recebe a nova profundidade da mesma
				system("cls");
				printf("\t\t\t\tProfundidade da �rvore: %i\n\n",cnt);
				mostrar(no);
				//verifica se a �rvore est� vazia para pausar a exbi��o dos dados
				if(no->maior != NULL or no->menor != NULL or no->vlr != NULL){		
					fflush(stdin);
					getch();					
				}
				break;
			}
			
			case 3:{				
				//remove o valor informado
				system("cls");
				//printf("\t\t\t\n\n\nFun��o indispon�vel");
				//entrada de dados do usu�rio
				printf("\n\n\n\nInforme o valor a ser removido:\n");
				scanf("%i",&vlr);
				tmp=no;
				remover(no,tmp,vlr);
				fflush(stdin);
				getch();				
				break;
			}
			
			case 4:{				
				//insere um vetor com 10 valores de forma automatizada
				system("cls");				
				for(int i = 0;i<8;i ++){				
					cnt = 0;
					inserir(no, vetor[i]);					
				}
				break;
			}
			
			case 5:{				
				//entrada de dados do usu�rio para busca
				system("cls");
				printf("\t\t\tTrab. Jose Ferreira 01-04-2019\n\nInforme um n�mero inteiro maior que zero:\n");
				scanf("%i",&vlr);
				buscar(no,vlr);
				//pausa a exbi��o dos dados
				if(no->maior != NULL or no->menor != NULL or no->vlr != NULL){		
					fflush(stdin);
					getch();				
				}
				break;
			}
			
			case 6:{				
				system("cls");
				printf("\t\t\tTrab. Jose Ferreira 01-04-2019\n\n");
				//exibe os n�s raiz
				buscar_raiz(no);
				//pausa a exbi��o dos dados
				if(no->maior != NULL or no->menor != NULL or no->vlr != NULL){		
					fflush(stdin);
					getch();				
				}
				break;
			}
			
			case 7:{				
				system("cls");
				return(EXIT_SUCCESS);
				break;
			}
			
			default:{				
				system("cls");
				printf("\n\n\n\t\t\tOp��o inv�lida!");
				sleep(1.9);
				break;
			}
		}	
	}	
	return(0);
}
