//A[20]
//preencher A[i] = i + 1
//usar reduction
//imprimir Resultado: 210

#include <iostream>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {
	
	int A[20];
	int soma;
	soma = 0;
	
	#pragma omp parallel for reduction(+:soma)
    
    	for(int i = 0; i < 20; i ++){
    		A[i] = i + 1;
    		 soma += A[i];
		}
		


		cout << "O resultado eh " <<  soma;
    	

	
	
	return 0;
}
