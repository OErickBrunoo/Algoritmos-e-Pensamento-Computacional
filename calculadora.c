#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

	printf("Content-Type: text/plain\n\n");	

    double pnumero, snumero, resultado;
	float pri_grau, radianos;
    int escolha;
	const double pi = 3.1415926535897;
    char *dados = getenv("QUERY_STRING"); // String exemplo :: 
	
    //printf("Selecione a função \n Adição (1)\n subtração (2)\n Multiplicação (3)\n Divisao (4):\n Exponenciação (5) \n Raiz Quadrada (6) \n Seno (7) \n Cosseno (8)\n Resposta:");
	
    sscanf(dados, "%lf&%d&%lf", &pnumero, &escolha, &snumero); // formato {num1}&${operador}&${num2}
    
	if (escolha <= 5) {

		switch (escolha) {
        case 1:
            resultado = pnumero + snumero;
            printf("\nResultado: %g", resultado);
            break;
        case 2:
            resultado = pnumero - snumero;
            printf("\nResultado: %g", resultado);
            break;
        case 3:
            resultado = pnumero * snumero;
            printf("\nResultado: %g", resultado);
            break;
        case 4:
				if (snumero == 0) {
        printf("operação invalida 1");
		return 0;
		} else {
			resultado = pnumero / snumero;
            printf("\nResultado: %g", resultado);
		}
            break;
        case 5:
            resultado = pow(pnumero,snumero);
		    printf("\nResultado: %g", resultado);
		    break;
		}
	} else {
		switch (escolha) {
        case 6:
			printf("Digite o Número: ");
			scanf("%f", &pnumero);
		if (pnumero >= 0) {
            resultado = sqrt(pnumero);
            printf("\nResultado: %g", resultado);
		} else {
			printf("Resultado inválido");
		}
            break;
		case 7:
			printf("Digite o Número: ");
			scanf("%f", &pnumero);
			pri_grau = pi / 180.0;
			radianos = pnumero * pri_grau;
			
			resultado = sin(radianos);
			printf("\n Resultado: %g", resultado);
            break;
		case 8:
			printf("Digite o Número: ");
			scanf("%f", &pnumero);
			pri_grau = pi / 180.0;
			radianos = pnumero * pri_grau;
			
			resultado = cos(radianos);
			printf("\n Resultado: %g", resultado);
            break;
        
        default:
            printf("resultado invalido22");
    }
	}
    return 0;
}