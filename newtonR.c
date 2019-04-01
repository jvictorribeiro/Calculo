#include <stdio.h>
#include <stdlib.h>

float Abs( float x ){	//funcao para pegar o valor absoluto
  return x >=0? x: -x;
}

float f(float x) {		//f(x)
	return x*x*x*x - 6*x*x*x + 10*x*x - 6*x + 9;
}

float der(float x) {
	return 4*x*x*x - 18*x*x + 20*x - 6; // derivada de f(x).
}

int main() {
	float erro, x0, *iter; // erro, valor incial, vetor iterações.
	int i, numIter; // iteração atual, número de iterações.

	printf("Método de Newton-Rhapson\n");
	
	printf("Digite o erro: \n");
	scanf("%f",&erro);

	printf("Digite o número máximo de iterações?\n");
	scanf("%d", &numIter);

	printf("Digite o X0? \n");
	scanf("%f", &x0);

	// Alocar dinâmicamente memória para o vetor das iterações.
	iter = malloc(sizeof(float) * numIter);

	// Condições iniciais.
	iter[0] = x0;
	i = 0;

	// Iterações.
	do{
		if(i > numIter) {
			printf("Não convergiu em %d iterações!!!\n", numIter);
			printf("Verifique o f(x).\n");
		}

		iter[i+1] = iter[i] - f(iter[i])/der(iter[i]);
		i++;
	}while(Abs(f(iter[i])) > erro);

	printf("X ~= %f ", iter[i]);
	printf("\nForam feitas %d iterações.\n",i);
}
