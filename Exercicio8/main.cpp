//A[80], B[80], C[80], D[80]

//Preencha:

//A[i] = i + 1;
//B[i] = 100 - i;
//C[i] = (i + 1) * 2;
//D[i] = 80 - i;

//Depois encontre em paralelo:

//Maior de A
//Menor de B
//Maior de C
//Menor de D

//Resultado esperado:

//Maior de A: 80
//Menor de B: 21
//Maior de C: 160
//Menor de D: 1


#include <iostream>
#include <ctime>
#include <climits>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {
	
//vetores
int A[80], B[80], C[80], D[80], E[80];
	
	#pragma omp parallel for
	for(int i = 0; i < 80; i++)
	{
		A[i] = i + 1;
		B[i] = 100 - i;
		C[i] = (i + 1) * 2;
		D[i] = 80 - i;
	}	
	
		
	#pragma omp parallel for
	for(int i = 0; i < 80; i++)
	{
		E[i] = A[i] + B[i] - C[i] + D[i];
	}	
	
	int maximo_A = INT_MIN;  
    int minimo_B = INT_MAX;  
    int maximo_C = INT_MIN;  
    int minimo_D = INT_MAX;  
    
    
    int soma_positivos = 0;
    int qtd_negativos = 0;
    
         #pragma omp parallel for reduction(max:maximo_A) reduction(min:minimo_B) reduction(max:maximo_C) reduction(min:minimo_D)
	    for(int i = 0; i  < 80; i++){
	    	if(A[i] > maximo_A){
	    		maximo_A = A[i];
			}
			
			if(B[i] < minimo_B){
	    		minimo_B = B[i];
			}
			
			if(C[i] > maximo_C){
	    		maximo_C = C[i];
			}
		
			if(D[i] < minimo_D){
	    		minimo_D = D[i];
			}
		}
		
		
		
		
	#pragma omp parallel for reduction(+:soma_positivos,qtd_negativos)
	for(int i = 0; i < 80; i ++){
		if(E[i] > 0){
			soma_positivos += E[i];
		}
		
		if(E[i] < 0){
			qtd_negativos += 1; 
		}
	}
		
		
	cout << "Maior valor de A: " << maximo_A << "\n";
	 
	 
	cout << "Menor valor de B: " << minimo_B << "\n";
	 
	cout << "Maior valor de C: " << maximo_C << "\n";
	 
	cout << "Menor valor de D: " << minimo_D << "\n";
	
	
	cout << "Soma dos positivos de E: " << soma_positivos<< "\n";
	
	cout << "Quantidade de negativos de E: " <<  qtd_negativos<< "\n";
	 
    
	
	
	return 0;
}



