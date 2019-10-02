#include<stdio.h> //para uso de funções como printf() e scanf()
#include<stdlib.h> //biblioteca padrão da linguagem C
#include<conio.h> //para uso da função getch()
#include<locale.h> //para uso da função setlocale(LC_ALL,local);
#include<unistd.h> //para uso da função sleep(segundos)
#include<ctype.h> //para uso da função toupper(caractere)
#include<time.h> //para uso das funções rand() e srand()
#define MAX_LENGHT 8 //constante para definir o tamanho da tabela Hash

//tipo de dado para o a tabela hash
typedef struct no{
	int vlr;
	char nome[20];
	int profundidade;
	struct no *maior;
	struct no *menor;	
}bloco;

//cria um vetor de 8 posições do tipo bloco
bloco *tabela_hash[MAX_LENGHT];
int cnt = 0,count;

#include"binary tree.h"//biblioteca com funções de inserção e exibição em árvore binária

//função para criar as raízes das árvores da tabela hash quando necessário
bloco *posicao(int vlr){
	if(tabela_hash[vlr % MAX_LENGHT]->maior == NULL){
		bloco *novo = (bloco*)malloc(sizeof(bloco));
		strcpy(novo->nome,"");
		novo->maior = novo->menor = NULL;
		novo->profundidade = novo->vlr = NULL;
		tabela_hash[vlr % MAX_LENGHT]->maior = novo;
	}
	return(tabela_hash[vlr % MAX_LENGHT]->maior);
}

//função para posicionar alfabeticamente as variáveis
int index(char nome[20]){
	int indice;
	int i = (toupper(nome[0]));//converte o primeiro caractere em maíusculo
		
	if(i>=65 and i<68){
		indice = 0;
	}else if(i>=68 and i<71){
		indice = 1;
	}else if(i>=71 and i<74){
		indice = 2;
	}else if(i>=74 and i<77){
		indice = 3;
	}else if(i>=77 and i<80){
		indice = 4;
	}else if(i>=80 and i<83){
		indice = 5;
	}else if(i>=83 and i<87){
		indice = 6;
	}else if(i>=87 and i<91){
		indice = 7;
	}
	return indice;
}

//função para inserir um vetor do tipo int na tabela hash
void inserir_vetor(int vetor[], int tam){
	char n[] = "";//define o parâmetro "nome" da função inserir como vazio				
	for(int i = 0;i<tam;i++){				
		cnt = 0;
		inserir(posicao(vetor[i]), n, (vetor[i]));////inserir(tabela_hash[int i],String nome, int valor)					
	}
}

main(){
	//habilita a acentuação com base na localidade padrão do sistema
	setlocale(LC_ALL,"");
	
	char nome[20], vlr[15];
	
	//inicialização da tabela hash
	for(int i=0;i<MAX_LENGHT;i++){
		tabela_hash[i] = (bloco*)malloc(sizeof(bloco));
		strcpy(tabela_hash[i]->nome,"");
		tabela_hash[i]->maior = tabela_hash[i]->menor = NULL;
		tabela_hash[i]->profundidade = tabela_hash[i]->vlr = NULL;		
	}
	//loop do menu principal
	while(1){
		system("cls");
		printf("\t\t\t Tabela Hash com árvore\nSelecione uma opção:\n\n1 - Inserir\n2 - Exibir\n3 - Inserir vetores pré definidos\n4 - Sair\n\n*Obs: a estrutura da árvore binária não permite inserção de valores repetidos!");
		setbuf(stdin,NULL);//define o conteúdo do buffer do teclado como NULL		
		switch(getch()-48){
			case 1:{
				system("cls");				
				//entrada de dados do usuário
				printf("\nInforme um nome:\n");
				fgets(nome,20,stdin);
				nome[strlen(nome)-1]= '\0';//substitui o caractere '\n' no fim da string por '\0'
				printf("\nInforme um número inteiro maior que zero:\n");
				setbuf(stdin,NULL);
				fgets(vlr,15,stdin);
				vlr[strlen(vlr)-1]= '\0';//substitui o caractere '\n' no fim da string por '\0'
				cnt = 0;
				//função com polimorfismo
				//insere comparando prioritariamente caracteres e em caso de ambiguidade números
				inserir(posicao(index(nome)), nome, atoi(vlr));//inserir(tabela_hash[int i],String nome, int valor)
				//insere comparando apenas números
				//inserir(posicao(atoi(vlr)), nome, vlr);//inserir(tabela_hash[int i],String nome, char valor)
				break;
			}
			case 2:{				
				system("cls");
				printf("\t\t\t\tTabela Hash de %i índices\n\n",MAX_LENGHT);
				count = 0;
				for(int i = 0;i<MAX_LENGHT;i++){
					mostrar(tabela_hash[i]->maior,i);//chamada da função para mostrar os itens na tabela Hash
					printf("-----------------------------------------------------------------------------------------\n");
				}
				//pausa a exibição das informações se a tabela não estiver vazia
				if(count > 0){
					setbuf(stdin,NULL);//define o conteúdo do buffer do teclado como NULL
					getch();					
				}else{
					sleep(1.7);//exibe a tabela vazia por 1.7 segundos
				}
				break;
			}
			case 3:{
				//submenu de inicialização
				system("cls");
				printf("\t\tSelecione uma opção de inicialização: \n\n1 - {15,20,12,14,40,13,32,50}\n2 - {18,4,8,1,3,7,12,15,11,6,5,2,13,10,9,17}\n3 - {8,4,13,1,3,7,12,15,11,6,5,2,18,10,9,17}\n4 - {7,5,93,77,3,39,14,775,12,1,73,377,2,95,53}\n5 - {7,9,78,18,1,797,98,3,79,21,97,2,25,49,897}\n6 - {8,1,11,2,81,111,16,5,811,20,3,10,102,81,21}\n7 - Vetor randômico(0 a 1000)\n");
				setbuf(stdin,NULL);//define o conteúdo do buffer do teclado como NULL				
				switch(getch()-48){	
					case 1:{
						int vetor[] = {15,20,12,14,40,13,32,50};
						inserir_vetor(vetor,sizeof(vetor)/sizeof(int));//chamada da função para inserir o vetor gerado
						system("cls");
						printf("Vetor inserido: {15,20,12,14,40,13,32,50}\n\n\n");						
						break;
					}
					case 2:{
						int vetor[] = {18,4,8,1,3,7,12,15,11,6,5,2,13,10,9,17};
						inserir_vetor(vetor,sizeof(vetor)/sizeof(int));//chamada da função para inserir o vetor gerado
						system("cls");
						printf("Vetor inserido: {18,4,8,1,3,7,12,15,11,6,5,2,13,10,9,17}\n\n\n");
						break;
					}
					case 3:{
						int vetor[] = {8,4,13,1,3,7,12,15,11,6,5,2,18,10,9,17};
						inserir_vetor(vetor,sizeof(vetor)/sizeof(int));//chamada da função para inserir o vetor gerado
						system("cls");
						printf("Vetor inserido: {8,4,13,1,3,7,12,15,11,6,5,2,18,10,9,17}\n\n\n");
						break;
					}
					case 4:{
						int vetor[] = {7,5,93,77,3,39,14,775,12,1,73,377,2,95,53};
						inserir_vetor(vetor,sizeof(vetor)/sizeof(int));//chamada da função para inserir o vetor gerado
						system("cls");
						printf("Vetor inserido: {7,5,93,77,3,39,14,775,12,1,73,377,2,95,53}\n\n\n");
						break;
					}
					case 5:{
						int vetor[] = {7,9,78,18,1,797,98,3,79,21,97,2,25,49,897};
						inserir_vetor(vetor,sizeof(vetor)/sizeof(int));//chamada da função para inserir o vetor gerado
						system("cls");
						printf("Vetor inserido: {7,9,78,18,1,797,98,3,79,21,97,2,25,49,897}\n\n\n");
						break;
					}
					case 6:{
						int vetor[] = {8,1,11,2,81,111,16,5,811,20,3,10,102,81,21};
						inserir_vetor(vetor,sizeof(vetor)/sizeof(int));//chamada da função para inserir o vetor gerado
						system("cls");
						printf("Vetor inserido: {8,1,11,2,81,111,16,5,811,20,3,10,102,81,21}\n\n\n");
						break;
					}
					case 7:{
						system("cls");
						printf("Informe o tamanho desejado para o vetor randômico: ");
						char tam[] = {""};//vetor de string vazio
						fgets(tam,50,stdin);
						int vetor[atoi(tam)];
						
						//gera uma semente aleatória para rand()
						srand(time(NULL));//passa como parâmetro o tempo em segundos desde 1970 até o horário do sistema
						printf("\nVetor inserido: {");
						
						//gera um vetor aleatório
						for(int i=0;i<atoi(tam);i++){
							vetor[i] = rand()%1000;//gera um valor aleatório entre 0 e 1000
							printf("%i",vetor[i]);
							if(i<atoi(tam)-1){//separador de valores da exibição do vetor de inteiros
								printf(",");
							}
						}
						//insere o vetor aleatório
						inserir_vetor(vetor,sizeof(vetor)/sizeof(int));//chamada da função para inserir o vetor gerado
						printf("}\n\n\n");
						break;
					}
				}				
				//mostra a tabela hash após a inserção dos vetores pré-inicializados
				for(int i = 0;i<MAX_LENGHT;i++){
							mostrar(tabela_hash[i]->maior,i);
							printf("-----------------------------------------------------------------------------------------\n");
							count++;
				}
				setbuf(stdin,NULL);//define o conteúdo do buffer do teclado como NULL
				getch();
				break;
			}
			case 4:{				
				system("cls");
				return(EXIT_SUCCESS);
				break;
			}
			default:{//opção default do menu principal				
				system("cls");
				printf("\n\n\n\t\t\tOpção inválida!");				
				sleep(1.9);
				break;
			}
		}	
	}	
	return(EXIT_SUCCESS);//EXIT_SUCCESS é uma constante com valor 0 definida na biblioteca stdlib.h
}
