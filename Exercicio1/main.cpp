//Exercicio 1 
//Região Paralela 1

//Cada thread deve:
	//descobrir seu ID
	//calcular a soma dos números de 0 até seu ID
	


#include <iostream>
#include <cstdio>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int soma = 0;
        
        for (int i = 0; i <= thread_id; i++) {
            soma += i;
        }
        
        #pragma omp critical
        {
            printf("Thread %d Soma : %d\n", thread_id, soma);
        }
    }
    return 0;
}



