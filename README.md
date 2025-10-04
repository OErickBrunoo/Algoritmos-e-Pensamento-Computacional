Uma calculadora em C com uma interface bem simples em HTML, utilizando a biblioteca <stdlib.h> e compilação via CGI (Common Gateway Interface). Isso permite que haja comunicação entre a interface web e o código em C.

O JavaScript envia as informações necessárias em uma string, via URL, para o script calculadora.cgi. Ele manda os dados no seguinte formato: {num1}&{operador}&{num2}.

A biblioteca <stdlib.h> fornece a função getenv(), que é usada para capturar essa string. A função lê a variável de ambiente padrão "QUERY_STRING" e armazena seu conteúdo na variável dados.

Também existe uma versão da calculadora (calculadoraindependente.c) que possui as mesmas funções, mas funciona de forma autônoma, com toda a interatividade via console.

Sobre o funcionamento da Calculadora em si:

Para a escolha de função foi usado o switch case, e para o funcionamento da vasta maioria das funções foi usando as funções da biblioteca <math.h>.

Funções:

- Adição
- Subtração
- Multiplicação
- Divisão
- Exponenciação (Potência)
- Módulo (Resto da divisão)
- Porcentagem
- Hipotenusa
- Raiz quadrada
- Raiz cúbica
- Seno
- Cosseno
- Tangente
- Arco seno
- Arco cosseno
- Arco tangente
- Logaritmo na base 10
- Logaritmo natural
- Fatorial
- Valor absoluto
- Arredondar para baixo
- Arredondar para cima
- Converter Graus para radianos
- Converter Radianos para graus
- Equação de segundo grau (Bhaskara)

Dependências:
- python
- MinGW

Como Executar:

1. Abra seu cmd no diretório main do projeto.

2. coloque o seguinte código: "py -m http.server --cgi 5000"

3. Abra o seu navegador no site: "http://localhost:5000/"