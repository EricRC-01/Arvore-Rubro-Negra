/************************************************************
*            Eric Rodrigues das Chagas                      *
*    [ICMC - Bacharelado em Ciências da Computação - 2021]  *
*    NºUSP: 12623971                                        *
*||----------------------Contatos-------------------------||*
*            Telegram [ @EricRC_123 ]                       *
*            Email  [ eric.r.c@usp.br ]                     *
*************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "Head_my_string_.h"


/*
    Copia uma  string para outra
    @param strDes string destino que será sobreposta
    @param str string que que será copiada
*/
char *copyStr(char *strDes, char *str) {
    if(str == NULL){
        printf("Error > copyStr: parametro (str) é NULO\n");
        return NULL;
    }
  
    char verification = 'X';
    int i = 0;

    while (verification != '\0'){
        /* 
        printf("Char D = (%c) - Char C = (%c)\n",
            strDes[i],str[i]);
        */    
        
        //Caso: fim da strDes
        if(strDes[i] == '\0'){
            //printf("Fim do strDes\n");
      
            while (verification != '\0'){
                /* 
                printf("Char D = (%c) - Char C = (%c)\n",
                    strDes[i],str[i] );
                */
                strDes = realloc(strDes, (i+1)*sizeof(char));

                strDes[i] = str[i];

                verification = str[i];
                i++;    
            }
            break;
        }    
    
        strDes[i] = str[i];
        verification = str[i];
        i++;
    }

  return strDes;
}

/*
    Le até encontrar um: '\ n','\ 0', '\ r' ou EOF
    Aloca dinamicamente. Não esqueça do free
    @param stream 
*/
char *readline(FILE *stream) {
    
    char *string = NULL;
    string = malloc(sizeof(char));
    int i=0;
    char caractere='X';
    
    do{
        caractere = getc(stream);
        string = realloc(string, (i+1)*sizeof(char));
        string[i] = caractere;
        i++;
    }while( caractere != ('\r' & '\0' & EOF & '\n') );

    string[i]='\0';
    return string;
}

/* 
    Le uma palavra; para ao encontrar um: '\ n', '\ 0', 'espaço' ou EOF 
    @param stream arquivo de onde será lido  
*/
char *readword(FILE *stream) {

    char *string = NULL;
    string = malloc(sizeof(char));
    int i=0;
    char caractere='X';
    do{
        caractere=getc(stream);
        string=realloc(string, (i+1)*sizeof(char));
        string[i]=caractere;
        i++;

    }while( caractere != (' ' & '\r' & '\0' & '\n' & EOF ) );

    string[i]='\0'; 
    return string;
}


/*
    Compara duas strings e verifica a ordem alfabetica delas 
    1 se string 1 vem antes
    2 se string 2 vem antes
    0 se strings iguais
    -1 se houver erro na comparação 
*/
int compareStr(char *string1 ,char *string2) {
    printf("ENTROU: comparar strings\n");
    
    int i = 0;
    char caractere1 = string1[i]; 
    char caractere2 = string2[i];

    //Iterar até encontrar caracteres diferentes na string
    while (caractere1 == caractere2)
    {

        caractere1=string1[i];
        caractere2=string2[i];

        //Caso: fim da string 1
        if(caractere1 == '\0'){
            if(caractere2 == '\0') return 0;
            
            //Atribuir caractere anterior ao '\0'
            caractere1 = string1[i-1];

            //Realizar comparação
            if(caractere1 < caractere2) return 1;
            else if(caractere2 < caractere1) return 2;
            else return -1;
        }
        //Cso: fim da string 2
        if(caractere2 == '\0'){
            if(caractere1 == '\0') return 0;
            
            //Atribuir caractere anterior ao '\0'
            caractere2 = string2[i-1];
 
            //Realizar comparação
            if(caractere1 < caractere2) return 1;
            else if(caractere2 < caractere1) return 2;
            else return -1;
        }
        i++;
    }
    //Realizar comparação
    if(caractere1 < caractere2) return 1;
    else if(caractere2 < caractere1) return 2;
    else return -1;

}

//Formata o fim de uma linha para liberar a leitura
void formatar(FILE *stream) {
    char c = '\n';
    int i = 0;
    
    while ( c < 31 && i < 4)
    {
        c = getc(stream);
        //printf("c = (%i)\n",c);
        i++;

        if(c >= 32 || c == EOF || i >= 4) break;
    }
    ungetc(c,stream);

}






