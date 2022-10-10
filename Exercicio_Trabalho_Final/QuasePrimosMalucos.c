#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int n1, n2;

void *verificaQuasePrimo()
{
    int n = n1++;
    int contador = 0;
    //se n for par incrementa 1
    if (n % 2 == 0)
        n++;

    while (contador <= 10)
    {
        int f = floor(sqrt(n));// f recebe o maior valor inteiro não maior q sqrt(n)
        int contador = 0;
        for (int i = 3; i < f; i += 2)
            if (n % i == 0 && i < 11)
                break;
            else if (n % i == 0 && i > 10)
                contador++;

        if (contador >= 10)
            return n;
        
        n+=2;
        contador = 0;
    }
}

void *verificaQuasePrimo2()
{
    int n = n2++;
    int contador = 0;
    //se n for par incrementa 1
    if (n % 2 == 0)
        n++;

    while (contador <= 10)
    {
        int contador = 0;
        int f = floor(sqrt(n));// f recebe o maior valor inteiro não maior q sqrt(n)
        for (int i = 3; i < f; i += 2)
            if (n % i == 0 && i < 11)
                break;
            else if (n % i == 0 && i > 10)
                contador++;

        if (contador >= 10)
            return n;
        
        n+=2;
        contador = 0;
    }
}

int main()
{

    int T;
    void *result1, *result2;
    scanf("%d", &T);

    pthread_t t1, t2;
    //solucionando problema para quando a entrada foi impar
    if (T % 2 != 0)// consome uma thread caso o T seja impar
    {
        scanf("%d", &n1);
        //cria uma thread 
        pthread_create(&t1, NULL, verificaQuasePrimo, NULL);
        //espera a thread
        pthread_join(t1, &result1);
        printf("%d\n", result1);
        T--;
    }

    while (T > 0)// cada laço executa duas threads até acabar todos as T entradas
    {   
        scanf("%d", &n1);
        scanf("%d", &n2);
        //cria uma thread 
        pthread_create(&t1, NULL, verificaQuasePrimo, NULL);
        //cria uma thread 
        pthread_create(&t2, NULL, verificaQuasePrimo2, NULL);
        //espera a thread
        pthread_join(t1, &result1);
        printf("%d\n", result1);
        //espera a thread
        pthread_join(t2, &result2);
        printf("%d\n", result2);
        T = T - 2;
    }

    return 0;
}