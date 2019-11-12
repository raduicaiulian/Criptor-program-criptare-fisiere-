#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *f=fopen("fisier.txt","r+b");
	if(f== NULL){
		printf("eroare la deschiderea fisierului\n");
		exit(1);
	}
	fseek(f, 0, SEEK_END);//seteaza cursorul la finalul fisierului
	long fsize=ftell(f);//returneaza pozitia curenta a cursorului
	fseek(f, 0, SEEK_SET);//plaseaza cursorul la iceputul documentului
	if(fsize==0)
		printf("eroare la detectare dimensiunii fisier\n");
	char* str=(char *)malloc(fsize);
	if(str==NULL)
		printf("eroare de alocare\n");
	fread(str, 1, fsize, f);
	fseek(f, 0, SEEK_SET);
	unsigned int cheie;
	printf("cheie de criptare=");
	scanf("%d",&cheie);
	for(int i=0;i<fsize;i++){
		str[i]+=cheie;
		printf("%d ",str[i]);
	}
	printf("\n");
	fwrite(str,1,fsize,f);
	fclose(f);
	return 0;
}
