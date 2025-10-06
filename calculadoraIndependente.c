#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double pnumero, snumero, tnumero, qnumero, delta, resultado, resultado2, pcima1, pbaixo, pcima2, acao; // valores double para melhor precisão.
    int escolha, continuar = 0;
    const double pi = 3.1415926535897; // a constante de pi é feita
	double *array; // O array para as funções, soma, subtração e multiplicação.
    int tamanho;  // variavel auxiliar para as funções que usam array. 


	while (continuar <= 1) {  // inicio do loop, se continuar igual 1 ele reinicia.
	
	    pnumero = 0.0;
        snumero = 0.0;
        tnumero = 0.0;
        qnumero = 0.0;
        delta = 0.0;
        resultado = 0.0;    // todos os valores voltam a ser 0 para evitar lixo de memória.
        resultado2 = 0.0;
        pcima1 = 0.0;
        pbaixo = 0.0;
        pcima2 = 0.0;
        acao = 0.0;
        escolha = 0;
        tamanho = 0;
	
    printf("\n===========================================================================\n");
    printf("                          CALCULADORA CIENTIFICA\n");
    printf("===========================================================================\n\n");
    printf("  [ 1] Adicao             [ 2] Subtracao             [ 3] Multiplicacao\n");
    printf("  [ 4] Divisao            [ 5] Exponenciacao         [ 6] Modulo (Resto)\n");
    printf("  [ 7] Porcentagem        [ 8] Hipotenusa            [ 9] Raiz Quadrada\n");
    printf("  [10] Raiz Cubica        [11] Seno                  [12] Cosseno\n");
    printf("  [13] Tangente           [14] Arcseno               [15] Arccosseno\n");
    printf("  [16] Arctangente        [17] Logaritmo base 10     [18] Logaritmo Natural\n");
    printf("  [19] Fatorial           [20] Radianos para Graus   [21] Arredondar p Baixo\n");
    printf("  [22] Arredondar p Cima  [23] Graus para Radianos   [24] Teorema de Pitagoras\n");
    printf("  [25] Bhaskara\n\n");
    printf("===========================================================================\n\n");


    printf("Digite o numero da operacao desejada: ");
    scanf("%d", &escolha);

	// Otiização feita para evitar repetição em todas as funções.
	
    if (escolha >= 5 && escolha <= 8) {			// Funções que usam 2 números
        printf("Digite o primeiro numero: ");
        scanf("%lf", &pnumero);
        printf("Digite o segundo numero: ");
        scanf("%lf", &snumero);
    } 
    else if (escolha >= 9 && escolha <= 23) {  	// Funções que usam somente 1 número.
        printf("Digite o numero: ");
        scanf("%lf", &pnumero);
    }
	else if (escolha == 24 || escolha == 25) {		// Funções que usam 3 números
		printf("Digite o A: ");
		scanf("%lf", &pnumero);
		printf("Digite o B: ");
		scanf("%lf", &snumero);
		printf("Digite o C: ");
		scanf("%lf", &tnumero);
	}


    switch (escolha) {		// Switch case usado para escolha das funções.
        case 1:// Adição
			printf("Digite o total de números que vai querer somar: ");		// O tamanho do array é pedido
			scanf("%d", &tamanho);
			{
			acao = 0;
			}
			array = (int *) malloc(tamanho * sizeof(int));		// O tamanho do array e passado para o array em si.
			
			printf("Digite %d elementos:\n", tamanho);		// Um aviso é dado dizendo para digitar os valores.
			for (int i = 0; i < tamanho; i++) {				//laço "for" é feito para para a conta acontecer. 
			printf("Elemento %d: ", i + 1);					// O pedido dos números é feito.
			scanf("%d", &array[i]);							// O número é colocado no espaço da vez do array.
			acao += array[i]; 								// acha é somando com o valor do espaço do array da vez e o resultado é passado para acao.
			}
			
			printf("\nResultado: %g\n", acao);				// O resultado é dado, sendo ele o valor de achao.
			
			free(array);
            break;
		case 2: // Subtração
            printf("Digite o valor inicial: ");
            scanf("%lf", &acao); 							// Primeiro valor e dado, sendo ele o valor primário.

            printf("Quantos numeros deseja subtrair desse valor? ");  
            scanf("%d", &tamanho);

            if (tamanho > 0) {
            printf("Digite os %d numeros a serem subtraidos:\n", tamanho);
            for (int i = 0; i < tamanho; i++) {
            double subtracao;								// Uma variável é feita somente para essa função.
            printf("Subtrair o valor %d: ", i + 1);
            scanf("%lf", &subtracao);
            acao -= subtracao; 								// A cada ciclo uma nova subtração é feita no valor primário
                }
            }

            printf("\nResultado: %g\n", acao);
            break;
        case 3:// Multiplicação
            printf("Digite o total de números a Multiplicar:");
			scanf("%d", &tamanho);
			
			acao = 1;										// Ação é inicialmente 1 porque não dá para multiplicar por zero e continuar a função.

			array = (int *) malloc(tamanho * sizeof(int));
			
			printf("Digite %d elementos:\n", tamanho);
			for (int i = 0; i < tamanho; i++) {
			printf("Elemento %d: ", i + 1);
			scanf("%d", &array[i]);
			acao *= array[i]; 
			}
			
			printf("\nResultado: %g\n", acao);
			free(array);
            break;
        case 4:// Divisão
            if (snumero == 0) {
                printf("\nNão é possível dividir por zero.\n");		// Tratamento de erro caso o segundo número seja 0 é dado um aviso.
            } else {
                resultado = pnumero / snumero;
                printf("\nResultado: %g\n", resultado);
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
    
	printf("\n Continuar Calculando?\n 1 para sim \n 2 para não \n Resposta: ");  // parte do loop while, onde o valor de continuar e dado.
	scanf("%d", &continuar);
	
	}
    return 0;			// Termina a execução sem inconveniências.
}