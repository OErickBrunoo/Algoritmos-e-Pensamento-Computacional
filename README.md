Uma calculadora C com uma interface bem simples em html usando a biblioteca <stdlib.h> do C e a compilação em CGI (Comom Getway Interface) para que tenha cominicação entre a interface web, mais especificamente javascript e código C.

O javascript manda a informação necessária em uma strig via url para a calculadora.cgi, já que cgi é uma compilação reconhecida por ele, então ele sabe como e para onde mandar. Ele manda no seguinte formato: {num1}&${operador}&${num2}.

O stdlib.h é uma biblioteca de alocação de memória que pega essa string, então ao usar o getenvi() que pega no local de memória padrão "QUERY_STRING" para colocar na variavel dados.


Dependências:
- python


Como Executar:

1. Abra seu cmd no diretório main do projeto.

2. coloque o seguinte código: "py -m http.server --cgi 5000"

3. Abra o seu navegador no site: "http://localhost:5000/"