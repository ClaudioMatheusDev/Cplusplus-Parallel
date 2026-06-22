//Faça um programa que:

//Mostre o total de núcleos. -- ok
//Crie A[50], B[50], C[50]. --  ok 
//Use #pragma omp parallel sections. -- ok 
//Section A: preencher A com números aleatórios entre 1 e 100. --ok 
//Section B: preencher B com números aleatórios entre 1 e 100 multiplicados pelo ID da thread. --ok
//Section C: preencher C com números aleatórios entre 1 e 100 multiplicados pelo ID da thread. --ok
//Depois imprima: Vetores gerados com sucesso!


#include <iostream>
#include <ctime>
#include <stdlib.h>>
#include <omp.h>

using namespace std;

//função para gerar nuneros aleatorios 
int RandI(int i, int n){
	return (rand() % n ) + 1; 
}

int main(int argc, char** argv) {
	//numeros aleatorios
	srand(time(NULL));
	
	// total de nucleos
	int total_nucleos = omp_get_max_threads();
	cout <<  "Total de nucleos: "<< total_nucleos << "\n";	
	
	//Vetores 
	 int A[50], B[50], C[50];
	 
	 //calculo
	 int soma;
	 soma = 0;
	 
	 
	cout << "Regioes paralelas: \n\n";
	//Regiao paralela
	#pragma omp parallel 
    {
    		//sections
    	    #pragma omp sections
        	{	
					// Vetor  A 
					#pragma omp section
					{
						for(int i = 0; i < 50; i++){
							A[i] = RandI(1,100)+ 0;
						}
					}
					// Vetor  B 
					#pragma omp section
					{
						int id_thread = omp_get_thread_num();
						for(int i = 0; i < 50; i++){
							B[i] = RandI(1,100) * id_thread;
						}
					}  
					
					// Vetor  C 
					#pragma omp section
					{
						int id_thread = omp_get_thread_num();
						for(int i = 0; i < 50; i++){
							C[i] = RandI(1,100) * id_thread;
						}
					}           	
	        		
    		}
	}
	
	cout<<"\n\nVetores gerados com sucesso!\n\n";

	return 0;
}
