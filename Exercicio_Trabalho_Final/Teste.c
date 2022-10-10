/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

int value = 0;
int numero = 0;
int flag = 0;

typedef struct Parameter{
    int number;
    int tid; 
    int answer;
} Parameter;

typedef struct malucos
{
  int n;
  int result;
}malucos;

void *calcule_sequaseprimo_maluco(void *s){
    
    malucos *c = (struct malucos *) s;
    
    int resultdivisores = c -> n + 1;
    
    while(1){   
        if(resultdivisores == 1 || resultdivisores % 2 == 0){     
            resultdivisores++;
        }

        int contador=0;
        
        for(int i=3, f = floor(sqrt(resultdivisores)); i<f; i+=2){
            if(resultdivisores%i==0 && i<11){
                break;
            }
            else if(resultdivisores%i==0 && i>10){
                 contador++;
            }
        }
        if(contador > 10){
            c->result = resultdivisores;
            break;
        } 
        resultdivisores++;
    }

}

int main(void){

    scanf("%d",&value);
    
    while(1)
    {   
        int aux = 0;
        
        pthread_t PARAMETRO_A;
        pthread_t PARAMETRO_B;
        
        malucos A,B;
        
        if(scanf("%d", &numero) == EOF){
            break;
        }
        
        A.n = numero;
        
        A.result =0;
        
        aux =1;
        
        flag++;
        pthread_create(&PARAMETRO_A,NULL, &calcule_sequaseprimo_maluco,&A);

        if(value % 2 != 0 && flag == value){
            pthread_join(PARAMETRO_A,NULL);
            printf("%d\n",A.result);
            exit(0);
        
            
        }else{
            
            if(scanf("%d", &numero)== EOF){
                break;
            }
            
            B.n = numero;
            B.result =0;
            flag++;
            pthread_create(&PARAMETRO_B,NULL, &calcule_sequaseprimo_maluco,&B);
        }
        

        pthread_join(PARAMETRO_A,NULL);
        printf("%d\n",A.result);
        
        pthread_join(PARAMETRO_B,NULL);
        printf("%d\n",B.result);
    }
    
    return 0;
}