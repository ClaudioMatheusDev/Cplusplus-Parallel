//1 Crie:

//A[50]
//B[50]
//C[50]

//2

//Use parallel sections

//Section A:

//A[i] = i + 1

//Section B:

//B[i] = (i + 1) * 2

//Section C:

//C[i] = (i + 1) * 3

//3 //Depois use: ///#pragma omp parallel for reduction(+:resultado)


//e calcule:

//Se A[i] for par
 //   resultado += A[i]

//Senão
//    resultado -= (B[i] / C[i])
//4 Imprima:  RESULTADO = X


#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {
	
	//vetores
	int A[50], B[50], C[50];
	
	//calculo e resultado
	int resultado;
	resultado = 0;
	
	#pragma omp parallel 
    {
    	
    	//sections
    	#pragma omp sections
		{
			
			//vetor a
			#pragma omp section
			{
				for(int i = 0; i < 50; i++){
					A[i] = i + 1;
				}
			}
			
			//vetor b
			#pragma omp section
			{
				for(int i = 0; i < 50; i++){
					B[i] = (i + 1) * 2;
				}
			}
			//vetor C
			#pragma omp section
			{
				for(int i = 0; i < 50; i++){
					C[i] = (i + 1) * 3;
				}
			}
			
		} //SECTIONS
    	
    	
    } //PARAllels
    
    #pragma omp parallel for reduction(+:resultado)
	for(int i = 0; i < 50; i++){
		if (A[i]  % 2 == 0){
			resultado += A[i];
		}else{
			resultado -= (B[i] / C[i]);
		}
	}
	
	cout << "RESULTADO: " << resultado;
    
	return 0;
}
