//Mostre o total de núcleos

//Exemplo:

//Total de Núcleos: 12
//Primeira Região Paralela

//Cada thread deve calcular:

//soma = 1² + 2² + 3² + ... + (id+2)²

#include <iostream>
#include <omp.h>

using namespace std;


int main(int argc, char** argv) {
	
	int total_nucleos = omp_get_max_threads();
	cout <<  "Total de nucleos: "<< total_nucleos << "\n";	
			
	#pragma omp parallel 
	{
		int thread_id = omp_get_thread_num();
		int soma;
		soma = 0;
		
		for (int i = 1; i <= (thread_id + 2); i++) {
		            soma += (i * i);
		        }
		#pragma omp critical
		        {
		            printf("Thread %d soma: %d\n", thread_id, soma);
		        }
	}
	


	return 0;
}
