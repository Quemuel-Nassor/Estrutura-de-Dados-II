#include<stdlib.h>
#include<stdio.h>
#include<string.h>

main(){
	char teste[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	for(int i = 0;i<strlen(teste)-1;i++){
		printf("%C = %i\n",teste[i],teste[i]);
	}printf("%C = %i\n",teste[25],teste[25]);
	return(EXIT_SUCCESS);
}
