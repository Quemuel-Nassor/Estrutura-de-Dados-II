#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<unistd.h>

int cnt = 0;

//estrutura heterogênea base da árvore
typedef struct dado{		
	struct dado *maior;
	struct dado *menor;
	int vlr;
	int profundidade;		
}cad;

//inclui biblioteca com função de busca para o trabalho
#include "buscar.h"

void inserir(cad *arvore, int vlr){
	
	//verifica se o nó está vazio
	if(arvore->vlr == NULL){				
		arvore->vlr = vlr;
	}

	//verifica se o valor digitado é menor que o valor do nó
	if(vlr < arvore->vlr and arvore->menor != NULL){		
		cnt++;
		inserir(arvore->menor,vlr);	
	//verifica se o valor é menor que o valor do nó		
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
	
	//verifica se o valor digitado é maior que o valor do nó
	if(vlr > arvore->vlr and arvore->maior != NULL){
		cnt++;
		inserir(arvore->maior,vlr);	
	//verifica se o valor é maior que o valor do nó		
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
		printf("\t\t\t\t\tÁrvore vazia\n\n\n");
		sleep(1.5);		
	}else{	
		//verifica se o é o último menor
		if(arvore->menor != NULL){			
			mostrar(arvore->menor);			
		}
			
		printf("valor do no: %i\t profundidade do no %i\n",arvore->vlr,arvore->profundidade);
				
		//verifica se é o último maior
		if(arvore->maior != NULL){			
			mostrar(arvore->maior);			
		}		
	}
}

void remover(cad* arvore, cad *temp, int vlr){

	//percorrendo a árvore pelo lado menor
	if(arvore->menor != NULL and vlr < arvore->menor->vlr){		
		remover(arvore->menor,temp,vlr);	
	}
	
	printf("valor do temp %i valor da arvore %i\n\n",temp->vlr,arvore->vlr);
	temp = arvore;
	
	//verifica se o valor informado foi encontrado pelo lado menor e se o nó não possui filho maior
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
	
	//percorrendo a árvore pelo lado maior	
	if(arvore->maior != NULL and vlr > arvore->maior->vlr){		
		remover(arvore->maior,temp,vlr);		
	}
}


main(){
	
	//habilita a acentuação com base na localidade padrão do sistema
	setlocale(LC_ALL,"");
	
	//declaração de variáveis
	int vlr = 0, sel = 0,vetor[11] = {15,20,12,14,40,13,32,50};

	//declara, aloca memória para o nó raiz, e inicializa os valores
	cad *no = (cad *)malloc(sizeof(cad)), *tmp;
	no->maior = NULL;
	no->menor = NULL;
	no->vlr = NULL;
	no->profundidade = 0;
	
	//loop do menu de entrada de dados
	while(1){
		
		system("cls");
		printf("\n\nSelecione uma opção:\n\n1 - Inserir\n2 - Exibir\n3 - Remover\n4 - Inserir o vetor {15,20,12,14,40,13,32,50}\n5 - Buscar\n6 - Exibir nós raiz\n7 - Sair");
		fflush(stdin);
		sel = getch()-48;
		
		switch(sel){
		
			case 1:{				
				//entrada de dados do usuário e a profundidade da árvore
				system("cls");
				printf("\n\n\n\nInforme um número inteiro maior que zero:\n");
				scanf("%i",&vlr);				
				cnt = 0;
				inserir(no, vlr);
				break;
			}
			
			case 2:{				
				//insere valores na árvore e recebe a nova profundidade da mesma
				system("cls");
				printf("\t\t\t\tProfundidade da árvore: %i\n\n",cnt);
				mostrar(no);
				//verifica se a árvore está vazia para pausar a exbição dos dados
				if(no->maior != NULL or no->menor != NULL or no->vlr != NULL){		
					fflush(stdin);
					getch();					
				}
				break;
			}
			
			case 3:{				
				//remove o valor informado
				system("cls");
				//printf("\t\t\t\n\n\nFunção indisponível");
				//entrada de dados do usuário
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
				//entrada de dados do usuário para busca
				system("cls");
				printf("\t\t\tTrab. Jose Ferreira 01-04-2019\n\nInforme um número inteiro maior que zero:\n");
				scanf("%i",&vlr);
				buscar(no,vlr);
				//pausa a exbição dos dados
				if(no->maior != NULL or no->menor != NULL or no->vlr != NULL){		
					fflush(stdin);
					getch();				
				}
				break;
			}
			
			case 6:{				
				system("cls");
				printf("\t\t\tTrab. Jose Ferreira 01-04-2019\n\n");
				//exibe os nós raiz
				buscar_raiz(no);
				//pausa a exbição dos dados
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
				printf("\n\n\n\t\t\tOpção inválida!");
				sleep(1.9);
				break;
			}
		}	
	}	
	return(0);
}
