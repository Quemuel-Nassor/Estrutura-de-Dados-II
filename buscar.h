void buscar(cad* arvore, int vlr){
	
	//verifica se o valor informado foi encontrado na �rvore e se existe o seu valor dobrado tamb�m na �rvore
	if(arvore->vlr == vlr){
		
		printf("A busca encontrou o valor %i\n",arvore->vlr);
		
	}
	
	if(arvore->vlr == (vlr*2)){
		
		printf("A busca encontrou o dobro do valor %i\n",arvore->vlr);
		
	}
	
	//percorre a �rvore pelo lado menor
	if(arvore->menor != NULL){
	
		buscar(arvore->menor,vlr);
	
	}
	
	//percorrendo a �rvore pelo lado maior
	if(arvore->maior != NULL){
	
		buscar(arvore->maior,vlr);
				
	}		
	
}


void buscar_raiz(cad *arvore){
	
	//verifica se a �rvore est� vazia
	if(arvore->maior == NULL and arvore->menor == NULL and arvore->vlr == NULL){
		
		printf("\n\n\n\n\t\t\t\t\t�rvore vazia\n\n\n");
		sleep(1.5);
		
	}else{
		
		//verifica se o n� � folha ou raiz
		if(arvore->maior != NULL or arvore->menor != NULL){
			
			//verifica se o � o �ltimo menor
			if(arvore->menor != NULL){
				
				buscar_raiz(arvore->menor);
				
			}
			
			printf("\nvalor do no: %i\t profundidade do no %i\n",arvore->vlr,arvore->profundidade);
			
			//verifica se � o �ltimo maior
			if(arvore->maior != NULL){
				
				buscar_raiz(arvore->maior);
				
			}
		}
	}
}
