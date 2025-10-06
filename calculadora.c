#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//iniciando a função principal
//ela retornará um valor inteiro e se chamará "main", por padrão
int main() {

	//declarando o tratamento do texto de entrada
	printf("Content-Type: text/plain\n\n");	

	//definindo variáveis para multiplos valores
    double pnumero, snumero, tnumero, delta, resultado, resultado2, pcima1, pbaixo, pcima2;
	float radianos;
    int escolha;
	//variável constante par armazenar o valor de pi
	const double pi = 3.1415926535897;

	//Aponta na memória onde está localizada a informação
	//char é o padrão para armazenamento de caracteres
	//o asterisco(*) sinaliza um ponteiro de dados
	//getenv, do stdlib, vai pegar a variável de ambiente e armazenar no ponteiro de dados
    char *dados = getenv("QUERY_STRING");
	
	//o primo do scanf que não pede input, ele vai usar um output e armazenar em outra variável
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
            resultado = pow(pnumero, snumero);				//Foram útilizadas muitas das funções da biblioteca math.h daqui para frente.
            printf("\nResultado: %g\n", resultado);
            break;
        case 6:// Modulo resto da divisão
            resultado = fmod(pnumero, snumero);
            printf("\nResultado: %g\n", resultado);
            break;
        case 7:// Porcentagem
            resultado = (pnumero / 100.0) * snumero;		//Praticamente uma regra de 3 feita em código.
            printf("\nresultado: %g\n", resultado);
            break;
        case 8:// Hipotenusa
            resultado = hypot(pnumero, snumero);			
            printf("\nResultado: %g\n", resultado);
            break;
        case 9:// Raiz quadrada
            resultado = sqrt(pnumero);
            printf("\nResultado: %g\n", resultado);
            break;
        case 10:// Raiz cubica
            resultado = cbrt(pnumero);
            printf("\nResultado: %g\n", resultado);
            break;
        case 11:{// Seno
            double radianos = pnumero * (pi / 180.0);		//Equação para transformar graus em radianos, já que ele só aceita radianos.
            resultado = sin(radianos);
            printf("\nresultado: %g\n", resultado);
		}
            break;
        case 12:{// Cosseno
            double radianos = pnumero * (pi / 180.0);
            resultado = cos(radianos);
            printf("\nResultado: %g\n", resultado);
		}
            break;
        case 13:{ // Tangente
            double radianos = pnumero * (pi / 180.0);
            resultado = tan(radianos);
            printf("\nResultado: %g\n", resultado);
		}
            break;
        case 14:// Arcseno
            resultado = asin(pnumero) * (180.0 / pi);
            printf("\nResultado (em graus): %g\n", resultado);
            break;
        case 15:// Arccosseno
            resultado = acos(pnumero) * (180.0 / pi);
            printf("\nResultado (em graus): %g\n", resultado);
            break;
        case 16:// Arctangente
            resultado = atan(pnumero) * (180.0 / pi);
            printf("\nResultado (em graus): %g\n", resultado);
            break;
        case 17:// Logaritmo na base 10
            resultado = log10(pnumero);
            printf("\nResultado: %g\n", resultado);
            break;
        case 18:// Logaritmo natural
            resultado = log(pnumero);
            printf("\nResultado: %g\n", resultado);
            break;
        case 19:// Fatorial
            resultado = 1;
                for (int i = 1; i <= (int)pnumero; i++) {
                    resultado *= i;
                }
                printf("\nResultado: %g\n", resultado);
            break;
        case 20:// Radianos para Graus
            resultado = pnumero * (180.0 / pi);
            printf("\nResultado graus: %g\n", resultado);
            break;
        case 21:// Arredondar para baixo
            resultado = floor(pnumero);
            printf("\nResultado: %g\n", resultado);
            break;
        case 22:// Arredondar 
            resultado = ceil(pnumero);
            printf("\nresultado: %g\n", resultado);
            break;
        case 23:// Graus para radianos
            resultado = pnumero * (pi / 180.0);
            printf("\nResultado radianos: %g\n", resultado);
            break;
        case 24:// Teorema de Pitagoras ;; Cada passo da equação foi feito para cada possível icognita.
			    if (pnumero == 0) {
				pnumero = (snumero * snumero) + (tnumero * tnumero);		
				resultado = sqrt(pnumero);
				printf("\nResultado: %g\n", resultado);
			} else if (snumero == 0) {
				pcima1 = (tnumero * tnumero);
				pbaixo = (pnumero * pnumero);
				pcima2 = pbaixo - pcima1;
				resultado = sqrt(pcima2);
				printf("\nResultado: %g\n", resultado);
			} else if (tnumero == 0) {
				pcima1 = (snumero * snumero);
				pbaixo = (pnumero * pnumero);
				pcima2 = pbaixo - pcima1;
				resultado = sqrt(pcima2);
				printf("\nResultado: %g\n", resultado);
			}
            break;
        case 25:// Equação de segundo grau usando baskara, tem tratamento de erro para cada possível delta.
			delta = pow(snumero, 2) - (4 * (pnumero * tnumero));
			if (delta > 0) {
				pcima1 = -snumero + sqrt(delta);
				pcima2 = -snumero - sqrt(delta);
				pbaixo = 2 * pnumero;
				resultado = pcima1 / pbaixo;
				resultado2 = pcima2 / pbaixo;
				printf("\nPrimeiro Resultado %.2lf \n", resultado);
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
            printf("\nOperação invalida.\n");		// fim da operação do switch case, caso nenhuma das operações válidas forem selecionadas.
    }
    
    return 0;
}
