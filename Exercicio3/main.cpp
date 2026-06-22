//Faça um programa que:

//Mostre o total de núcleos.
//Crie três vetores:
//A[20], B[20], C[20]
//Use uma região paralela com sections.
//Cada section deve preencher um vetor:
//A[i] = i + 1
//B[i] = (i + 1) * 2
//C[i] = (i + 1) * 3
//Ao final, fora da região paralela, imprima:
//Vetores gerados com sucesso!
//Depois imprima os 5 primeiros valores de cada vetor.

//Saída esperada parecida:

//A: 1 2 3 4 5
//B: 2 4 6 8 10
//C: 3 6 9 12 15


#include <iostream>
#include <omp.h>

using namespace std;


int main(int argc, char** argv) {
	
	// Total de nucleos
	int total_nucleos = omp_get_max_threads();
	cout <<  "Total de nucleos: "<< total_nucleos << "\n\n";	
	
	//VETORES 
	 int A[20], B[20], C[20];
	 
	 
	 cout << "Regioes paralelas: \n\n";
	//Regiao paralela
	#pragma omp parallel 
    {
    	//sections
    	        #pragma omp sections
        {
        	 // section A
			 #pragma omp section 
	            {
	                for (int i = 0; i < 20; i++) {
					A[i] = i + 1;
					}
	            }
	            
	            //section B
	            #pragma omp section 
	            {
	            	for (int i = 0; i < 20; i ++){
	            		B[i] = (i + 1) * 2;
					}
				}
				
				//section C 
				#pragma omp section 
				{
				for (int i = 0; i < 20; i ++)
					{
	            		C[i] = (i + 1) * 3;
					}
				}
		
		}
	
	}
	
	printf("A: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }
    
    printf("\nB: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", B[i]);
    }
    
    printf("\nC: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
	return 0;
}
