#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *criar_lista(){
celula *le=malloc (sizeof(celula));
le->prox=le;
return le;
}

celula *enfileira (celula *f, int x){
celula *novo=malloc(sizeof(celula));
novo->prox=f->prox;
f->prox=novo;
f->dado=x;
return novo;
}

int desenfileira (celula *f, int *y){
celula *lixo=f->prox;
if (lixo==NULL)return 0;
f->prox=lixo->prox;
*y=lixo->dado;
free(lixo);
return 1;
}

void imprime_lista(celula *le){
for (celula *elem=le->prox;elem!=le;elem= elem->prox)
    printf("%d ->", elem->dado);
printf ("NULL\n");
}

int percorre_vetor(int fisica[100000],int tamanho,int elemento){
    int encontrou=0;
    for(int i=0;i<tamanho;i++){
        if (fisica[i]==elemento){
            encontrou=1;
        }
    }
    if (encontrou==1){
        return 1;   
    }
    else{
        return 0;
    }
}

int procuraFila(int fisica[100000],int tamanho,int elemento){
  for(int i=0;i<tamanho+1;i++)
  {
    if(fisica[i]==elemento){
      return i;
    }
  }
}

int main()
{
  int N=0,P=0,Q=0,pageFaults=0,contador=0,indice=0,percorre=0,Qz=0,belady=0 ;
  int Qs[3],pageFaultz[3];
  int desinfileiras=0;
  int fisica[100000];
  int *stringReferencia;
  scanf("%d",&N);
  celula *le;
  le=criar_lista();

  stringReferencia = (int *) malloc(N * sizeof(int));

  for(int i=0;i<N;i++)
  {
    scanf("%d",&P);
    stringReferencia[i]=P;
  }
  while(scanf("%d",&Q)!=EOF)
  {
    pageFaults=0;
    contador=0;
    percorre=0;
    for(int i=0;i<N;i++)
    {
      if(contador<Q){
        if(percorre_vetor(fisica,Q,stringReferencia[i])==0)
        {
        fisica[percorre]=stringReferencia[i];
        le=enfileira(le,stringReferencia[i]);
        pageFaults++;
        percorre++;
        //printf("%d\n",pageFaults);
        }
        else{
            contador--;
        }
        
      }
      else{
        //imprime_lista(le);
        //printf("%d\n",pageFaults
        if (percorre_vetor(fisica,Q,stringReferencia[i])==0)
        {
            
        desenfileira(le,&desinfileiras);
        if(desinfileiras==0){
            break;
        }else{
          indice=procuraFila(fisica,Q,desinfileiras);
          fisica[indice]=stringReferencia[i];
          pageFaults++;
          le=enfileira(le,stringReferencia[i]);
        }
        }
        else{
            //printf("encontrei %d!\n",stringReferencia[i]);
        }
        //percorre_vetor!=0, ou seja encontrou
      }
      contador++;
    }
    for(int i=0;i<N;i++)
            {
                fisica[i]=0;
            }
    for(int i=0;i<Q;i++)
            {
                desenfileira(le,&desinfileiras);
            }
    printf("%d %d\n",Q,pageFaults);
    if(Qz==0)
    {
        Qs[0]=Q;
        pageFaultz[0]=pageFaults;
    }
    else{
        if(Q>Qs[0]){
            if(pageFaultz[0]<pageFaults)
            {
                belady=1;
                //printf("pageFaultz[0]:%d pagefault:%d\n",pageFaultz[0],pageFaults);
            }
        }
    }
    Qz++;
  }
  if(belady==1){
      printf("Belady detectado\n");
  }
  else{
      printf("Sem anomalia\n");
  }
  return 0;
}
