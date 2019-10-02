bloco *novo(char nome[20], int vlr){
	bloco *novo = (bloco *)malloc(sizeof(bloco));
	novo->maior = novo->menor = NULL;
	novo->profundidade = 0;
	novo->vlr = vlr;
	strcpy(novo->nome,nome);
	novo->profundidade = cnt;
	return novo;
}

void inserir(bloco *arvore, char nome[20], char vlr[]){
	
	//verifica se o n� raiz est� vazio
	if(arvore->vlr == NULL){				
		arvore->vlr = atoi(vlr);
		strcpy(arvore->nome,nome);
	}
	//verifica se o valor digitado � menor que o valor do n� atual
	if(atoi(vlr) < arvore->vlr and arvore->menor != NULL){		
		cnt++;
		inserir(arvore->menor,nome,vlr);	
	//verifica se o valor � menor que o valor do n� folha
	}
	if(atoi(vlr) < arvore->vlr and arvore->menor == NULL){		
		cnt++;		
		arvore->menor = novo(nome,atoi(vlr));
	}
	//verifica se o valor digitado � maior que o valor do n� atual
	if(atoi(vlr) > arvore->vlr and arvore->maior != NULL){	
		cnt++;
		inserir(arvore->maior,nome,vlr);
	//verifica se o valor � maior que o valor do n�	folha	
	}
	if(atoi(vlr) > arvore->vlr and arvore->maior == NULL){		
		cnt++;			
		arvore->maior = novo(nome,atoi(vlr));
	}		
}
		

void mostrar(bloco* arvore, int indice){	
		
	if( arvore == NULL or (arvore->maior == NULL and arvore->menor == NULL and arvore->vlr == NULL)){		
		printf("\t\t\t\t\t�rvore vazia\n");
	}else{	
		//verifica se � o �ltimo menor
		if(arvore->menor != NULL){			
			mostrar(arvore->menor,indice);			
		}
		printf("�ndice %i - Nome: %s\t Valor: %i\t profundidade do n� %i\n",indice,arvore->nome,arvore->vlr,arvore->profundidade);
		count ++;
		//verifica se � o �ltimo maior
		if(arvore->maior != NULL){			
			mostrar(arvore->maior,indice);			
		}		
	}
}

void inserir(bloco *arvore, char nome[20], int vlr){
	
	//verifica se o n� raiz est� vazio
	if(strcmp(arvore->nome,"") == 0 and arvore->vlr == NULL ){				
		arvore->vlr = vlr;
		strcpy(arvore->nome,nome);
	}
	
	//verifica se o valor digitado � menor que o valor do n� atual
	if(arvore->nome[0] > nome[0] and arvore->menor != NULL){		
		cnt++;
		inserir(arvore->menor, nome, vlr);
	}else if((arvore->nome[0] == nome[0] or strcmp(arvore->nome,"") == 0) and vlr < arvore->vlr and arvore->menor != NULL){		
		cnt++;
		inserir(arvore->menor, nome, vlr);	
	//verifica se o valor � menor que o valor do n� folha
	}else if(arvore->nome[0] > nome[0] and arvore->menor == NULL){
		cnt++;
		arvore->menor = novo(nome,vlr);
	}else if((arvore->nome[0] == nome[0] or strcmp(arvore->nome,"") == 0) and vlr < arvore->vlr and arvore->menor == NULL){	
		cnt++;				
		arvore->menor = novo(nome,vlr);
	}
	
	//verifica se o valor digitado � maior que o valor do n� atual
	if(arvore->nome[0] < nome[0] and arvore->maior != NULL){		
		cnt++;
		inserir(arvore->maior, nome, vlr);
	}else if((arvore->nome[0] == nome[0] or strcmp(arvore->nome,"") == 0) and vlr > arvore->vlr and arvore->maior != NULL){		
		cnt++;
		inserir(arvore->maior, nome, vlr);
	//verifica se o valor � maior que o valor do n�	folha	
	}else if(arvore->nome[0] > nome[0] and arvore->maior == NULL){
		cnt++;
		arvore->maior = novo(nome,vlr);
	}else if((arvore->nome[0] == nome[0] or strcmp(arvore->nome,"") == 0) and vlr > arvore->vlr and arvore->maior == NULL){
		cnt++;					
		arvore->maior = novo(nome,vlr);
	}
}

void remover(bloco* arvore, int indice){	
		
	if(arvore->maior == NULL and arvore->menor == NULL and arvore->vlr == NULL){		
		printf("\t\t\t\t\t�rvore vazia\n");
	}else{	
		//verifica se o � o �ltimo menor
		if(arvore->menor != NULL){			
			remover(arvore->menor,indice);
			free(arvore);
		}
			
		printf("�ndice %i - removido [Nome: %s\t Valor: %i\t profundidade do n� %i]\n",indice,arvore->nome,arvore->vlr,arvore->profundidade);
				
		//verifica se � o �ltimo maior
		if(arvore->maior != NULL){
			free(arvore);			
			remover(arvore->maior,indice);
		}		
	}
}
