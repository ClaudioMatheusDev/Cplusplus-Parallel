#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 50

// Função para gerar número aleatório entre i e n
int RandInt(int i, int n)
{
    return (rand() % n) + i;
}

int main()
{
    srand(time(NULL));

    int A[N], B[N], C[N];
    int resultado = 0;

    // =============================
    // TOTAL DE NÚCLEOS
    // =============================
    cout << "Total de Nucleos: " << omp_get_max_threads() << endl;

    // =============================
    // PRIMEIRA REGIÃO PARALELA
    // =============================
    cout << "\nPrimeira Regiao Paralela ==========================\n";

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int soma = 0;

        for (int i = 0; i <= id; i++)
        {
            soma += i;
        }

#pragma omp critical
        {
            cout << "Thread " << id << " soma: " << soma << endl;
        }
    }

    // =============================
    // SEGUNDA REGIÃO PARALELA
    // =============================
    cout << "\nSegunda Regiao Paralela ===========================\n";
    cout << "Gerando os vetores...\n";

#pragma omp parallel sections
    {
        // Vetor A -> thread 0
#pragma omp section
        {
            for (int i = 0; i < N; i++)
            {
                A[i] = RandInt(1, 100) + 0; // thread 0
            }
        }

        // Vetor B -> thread aleatória
#pragma omp section
        {
            int id = omp_get_thread_num();
            for (int i = 0; i < N; i++)
            {
                B[i] = RandInt(1, 100) * id;
            }
        }

        // Vetor C -> thread aleatória
#pragma omp section
        {
            int id = omp_get_thread_num();
            for (int i = 0; i < N; i++)
            {
                C[i] = RandInt(1, 100) * id;
            }
        }
    }

    // =============================
    // TERCEIRA REGIÃO PARALELA
    // =============================
    cout << "\nTerceira Regiao Paralela ==========================\n";

#pragma omp parallel for reduction(+:resultado)
    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 == 0)
        {
            resultado += A[i];
        }
        else
        {
            if (C[i] != 0)
                resultado -= (B[i] / C[i]);
        }
    }

    // =============================
    // RESULTADO FINAL
    // =============================
    cout << "\nRESULTADO DA EXPRESSAO....: " << resultado << endl;

    return 0;
}
