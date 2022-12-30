#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica(char *p, int t){
  int i, r;
  for(i=0;i<t;i++)
      if(p[i] != '0' && p[i] != '1'){
        return 1;
        break;
      }
  return 0;
}

int main(){
  char palavra[1001];
  int t = 0;
  FILE *file;
  if((file = fopen("palavras.txt", "r")) == NULL){
    printf("ERROR: abrirArquivo fopen == NULL\n");
    exit(1); 
  }
  
  while(!feof(file)){
    fscanf(file, "%s", palavra);
    t = strlen(palavra);
    if(verifica(palavra, t) == 1){
      printf("palavra - %s, rejeitada\n", palavra);
    }
    else {
      printf("palavra - %s, reconhecida\n", palavra);
    }
  }

  fclose(file);
  return 0;
}

