#include<stdio.h>

void quick(int vetor[10], int inicio, int fim);
int particiona(int *v, int inicio, int fim);

int main(){

	int vetor[10] = {7, 9, 4, 3, 6, 1, 18, 2, 10, 5};

	int i;
	printf("Vetor desordenado:\n");
	for(i = 0; i < 10; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");

	quick(vetor, 0, 9);

	printf("Vetor ordenado:\n");
	for(i = 0; i < 10; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void quick(int *v, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(v, inicio, fim); // separa os dados em duas partes
        quick(v, inicio, pivo-1); //chama a função para
        quick(v, pivo+1, fim);   // as duas metades
    }
}

int particiona(int *v, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio; // a variavel esq vai ser o elemento do lado esquerdo do pivo
    dir = fim;   // a variave dir vai ser o elemento do lado direito do pivo
    pivo = v[inicio]; // o pivo vai ser o primeiro elemento d vetor
    while(esq < dir){ // enquanto o lado esquerdo for menor que o lado direito então ele continua
        while(v[esq] <= pivo) esq++; // enquanto o lado esquerdo for menor ou igua ao pivo então ele avança pela esquerda, caso contrario ele fica parado no index que o elemento é maior que o pivo

        while(v[dir] > pivo) dir--; //  enquanto o lado direito for maior que o pivo ele recua, caso contrario ele fica parado no index que o valor é menor que o pivo

        if(esq < dir){ // aqui ele faz a troca de valores da esquerda pela direita
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }

    v[inicio] = v[dir]; // qui troca o valor da direita pelo valor de inicio que era o meu pivo
    v[dir] = pivo;

    return dir; // retorna o index da direita
}
