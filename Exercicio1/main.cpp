#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {


	#pragma omp parallel
	{
	
        int thread_id = omp_get_thread_num();
        int soma;
        int i;
        
        soma =  0; 
        
        for (i = 0; i < thread_id; i ++)
        {
        	soma = i + 1;
		}
		
		cout << "\nThread "<< thread_id << " Soma : " << soma << " " ;
		
	}
	return 0;
}


