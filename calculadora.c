#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

	printf("Content-Type: text/plain\n\n");	

    double pnumero, snumero, tnumero, qnumero, delta, resultado, resultado2, pcima1, pbaixo, pcima2;
	float pri_grau, radianos;
    int escolha;
	const double pi = 3.1415926535897;
    char *dados = getenv("QUERY_STRING"); // String exemplo :: 
	
	
    sscanf(dados, "%lf&%d&%lf&%lf", &pnumero, &escolha, &snumero, &tnumero); // formato {num1}&${operador}&${num2}&${num3}
    
    switch (escolha) {
        case 1:// Adição
            resultado = pnumero + snumero;
            printf("%g", resultado);
            break;
        case 2:// Subtração
            resultado = pnumero - snumero;
            printf("%g", resultado);
            break;
        case 3:// Multiplicação
            resultado = pnumero * snumero;
            printf("%g", resultado);
            break;
        case 4:// Divisão
            if (snumero == 0) {
                printf("\nNão é possível dividir por zero.\n");
            } else {
                resultado = pnumero / snumero;
                printf("%g", resultado);
            }
            break;
        case 5:// Exponenciação
            resultado = pow(pnumero, snumero);
            printf("%g", resultado);
            break;
        case 6:// Modulo resto da divisão
            resultado = fmod(pnumero, snumero);
            printf("%g", resultado);
            break;
        case 7:// Porcentagem
            resultado = (pnumero / 100.0) * snumero;
            printf("%g", resultado);
            break;
        case 8:// Hipotenusa
            resultado = hypot(pnumero, snumero);
            printf("%g", resultado);
            break;
        case 9:// Raiz quadrada
                resultado = sqrt(pnumero);
                printf("%g", resultado);
            break;
        case 10:// Raiz cubica
            resultado = cbrt(pnumero);
            printf("%g", resultado);
            break;
        case 11:{// Seno
            double radianos = pnumero * (pi / 180.0);
            resultado = sin(radianos);
            printf("%g", resultado);
		}
            break;
        case 12:{// Cosseno
            double radianos = pnumero * (pi / 180.0);
            resultado = cos(radianos);
            printf("%g", resultado);
		}
            break;
        case 13:{ // Tangente
            double radianos = pnumero * (pi / 180.0);
                resultado = tan(radianos);
                printf("%g", resultado);
		}
            break;
        case 14:// Arcseno
                resultado = asin(pnumero) * (180.0 / pi);
                printf("(em graus): %g", resultado);
            break;
        case 15:// Arccosseno
                resultado = acos(pnumero) * (180.0 / pi);
                printf("(em graus): %g", resultado);
            break;
        case 16:// Arctangente
            resultado = atan(pnumero) * (180.0 / pi);
            printf("(em graus): %g", resultado);
            break;
        case 17:// Logaritmo na base 10
                resultado = log10(pnumero);
                printf("%g", resultado);
            break;
        case 18:// Logaritmo natural
                resultado = log(pnumero);
                printf("%g", resultado);
            break;
        case 19:// Fatorial
                resultado = 1;
                for (int i = 1; i <= (int)pnumero; i++) {
                    resultado *= i;
                }
                printf("%g", resultado);
            break;
        case 20:// Radianos para Graus
            resultado = pnumero * (180.0 / pi);
            printf("%g", resultado);
            break;
        case 21:// Arredondar para baixo
            resultado = floor(pnumero);
            printf("%g", resultado);
            break;
        case 22:// Arredondar 
            resultado = ceil(pnumero);
            printf("%g", resultado);
            break;
        case 23:// Graus para radianos
            resultado = pnumero * (pi / 180.0);
            printf("%g", resultado);
            break;
        case 24:// Teorema de Pitagoras
			    if (pnumero == 0) {
				pnumero = (snumero * snumero) + (tnumero * tnumero);
				resultado = sqrt(pnumero);
				printf("%g", resultado);
			} else if (snumero == 0) {
				pcima1 = (tnumero * tnumero);
				pbaixo = (pnumero * pnumero);
				pcima2 = pbaixo - pcima1;
				resultado = sqrt(pcima2);
				printf("%g", resultado);
			} else if (tnumero == 0) {
				pcima1 = (snumero * snumero);
				pbaixo = (pnumero * pnumero);
				pcima2 = pbaixo - pcima1;
				resultado = sqrt(pcima2);
				printf("%g", resultado);
			}
            break;
        case 25:// Equação de segundo grau usando baskara
			delta = pow(snumero, 2) - (4 * (pnumero * tnumero));
			if (delta > 0) {
				pcima1 = -snumero + sqrt(delta);
				pcima2 = -snumero - sqrt(delta);
				pbaixo = 2 * pnumero;
				resultado = pcima1 / pbaixo;
				resultado2 = pcima2 / pbaixo;
				printf("Primeiro Resultado %.2lf \n", resultado);
				printf("Segundo Resultado %.2lf\n", resultado2);
				
			} else if (delta == 0) {
			resultado = -snumero / (2 * pnumero);
        
			printf("A equacao possui uma unica raiz real:\n");
			printf("x = %.2lf\n", resultado);
				
			} else if (delta < 0) {
			printf("Delta negativo.\n");
			printf("A raiz não está nos números reais.\n");
				
			}

            break;
        default:
            printf("\nOperação invalida ou não implementada.\n");
    }
    
    return 0;
}