
---

#  Calculadora em C com Interface Web (CGI)

Este projeto é uma **calculadora desenvolvida em C** que pode ser utilizada tanto via **console** quanto através de uma **interface web simples em HTML**.
A comunicação entre o código em C e a interface web é feita utilizando **CGI (Common Gateway Interface)**.

A calculadora é capaz de realizar desde operações básicas até funções matemáticas avançadas, usando as bibliotecas **stdlib.h** e **math.h**.

---

## Introdução

A interface web envia os dados para o código em C via **JavaScript**.
Esses dados são passados pela URL no formato:

```
{num1}&{operador}&{num2}&{num3}
```

O código em C utiliza a função **getenv()**, da biblioteca `<stdlib.h>`, para capturar a variável de ambiente padrão `QUERY_STRING`.

O processamento é feito no backend (C), e o resultado é retornado à página HTML.

---

## Funcionalidades

A calculadora suporta as seguintes operações:

* Adição
* Subtração
* Multiplicação
* Divisão
* Exponenciação (Potência)
* Módulo (Resto da divisão)
* Porcentagem
* Hipotenusa
* Raiz quadrada
* Raiz cúbica
* Seno
* Cosseno
* Tangente
* Arco seno
* Arco cosseno
* Arco tangente
* Logaritmo na base 10
* Logaritmo natural
* Fatorial
* Conversão: Radianos → Graus
* Arredondar para baixo (floor)
* Arredondar para cima (ceil)
* Conversão: Graus → Radianos
* Teorema de Pitagoras
* Equação de segundo grau (Bhaskara)

---

## Arquitetura

* **Frontend**: HTML + JavaScript (interface simples para entrada de dados).
* **Backend**: Código em C compilado como **CGI**.
* **Comunicação**: O navegador envia os dados via URL (`QUERY_STRING`) → o script em C processa → retorna o resultado em HTML.

---

## Dependências

* **Python** (para rodar o servidor local CGI)
* **MinGW** (para compilar o código em C no Windows)

---

## Instalação e Execução

1. Compile o código C para CGI:

   ```bash
   gcc calculadora.c -o cgi-bin/calculadora.cgi -lm
   ```

2. Inicie o servidor local (no diretório raiz do projeto):

   ```bash
   py -m http.server --cgi 5000
   ```

3. Acesse no navegador:

   ```
   http://localhost:5000/
   ```

---

## Uso

* Insira os valores e selecione a operação pela interface HTML.
* O **JavaScript** formatará os dados como string (`num1&operador&num2`) e enviará para `calculadora.cgi`.
* O backend processará e retornará o resultado em tempo real.

---

## Exemplos de Entrada

* **Adição:**

  ```
  10&+&5
  ```

  Resultado: `15`

* **Potência:**

  ```
  2&^&8
  ```

  Resultado: `256`

* **Bhaskara:**

  ```
  1&bhaskara&-3&2
  ```

  Resultado: `x1=2, x2=1`

---

## Versão Independente

Além da versão CGI, o projeto também possui o arquivo **calculadoraindependente.c**, que pode ser executado diretamente no console.

### Executar no console:

```bash
gcc calculadoraindependente.c -o calculadora -lm
./calculadora
```

---

## Contribuidores

* Desenvolvido por **Erick Bruno**, **Ector Falcão**, **Leonardo Tales**


---

