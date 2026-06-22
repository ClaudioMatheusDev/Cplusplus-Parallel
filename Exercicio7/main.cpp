// Crie:

// A[50]
// B[50]

// Preencha:
 
// A[i] = i + 1
// B[i] = (i + 1) * 5

// Depois encontre paralelamente:

// Maior valor de A
// Menor valor de B

#include <iostream>
#include <ctime>
#include <climits>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {
	
int A[50], B[50];	

	#pragma omp parallel for	
	for(int i = 0; i < 50; i++){
		A[i] = i + 1;
		B[i] = (i + 1) * 5;
	}	
	
	int maximo = INT_MIN;  
    int minimo = INT_MAX;  
    
     #pragma omp parallel for reduction(max:maximo) reduction(min:minimo)
     for(int i = 0; i < 50; i++){
     	if(A[i] > maximo){
     		maximo = A[i];
		 }
		 
		 if(B[i] < minimo){
     		minimo = B[i];
		 }
	 }
	 
	 
	 cout << "Maior valor de A: " << maximo << "\n";
	 
	 
	 cout << "Menor valor de B: " << minimo << "\n";
	 
	
	return 0;
}
