# Métodos Numéricos I
Trabalho de métodos numéricos, tema 3.


## Para usar esse sistema, clone o repositório e siga os passos:

-Para uma melhor compilação, digite o seguinte comando no terminal:

       g++ -Wall -Wextra -pedantic --std=c++17 Nome_Arquivo.cpp Nome_Arquivos.hpp -o main.out

-Para executar o programa, digite:

       ./main.out

### Para saber mais informações sobre o sistema acesse o pdf.


**Autores:**

Carlos Eduardo [Git-Hub](https://github.com/Cadusantos27)

João Victor  [Git-Hub](https://github.com/jva411)

Gabriel Brilhante [Git-Hub](https://github.com/brilhante14) 

Gabriel Passos [Git-Hub](https://github.com/GabrielPassos25)

Laura Petrola [Git-Hub](https://github.com/petrolau)

### Explicação das variáveis do programa:
| *Variáveis*   | *Função*                                            |
| ------------- |:---------------------------------------------------:|
| **d**         | Alterar o valor da nova variável                    | 
| **Fd**        | Valor assumido por f(d)                             |
| **FdDx**      | Derivada do valor assumido por f(d)                 |
| **FL**        | Função especificada pela questão                    |
| **Fxk**       | Valor assumido por f(xk), ou seja, nova aproximação |
| **iterMax**   | Número de iteracões máximas                         |
| **k**         | Contador do while                                   |
| **respostas** | Vetor com todos os valores dos casos de teste       |
| **xk**        | Aproximação nova                                    |
| **xw**        | Backup do último valor xk válido                    |

### Explicação das funções do programa:
| *Funções*                | *Descrição*                                                                            |
| **calcularFuncao**       | Retorna o valor que a função assume para o valor passado                               |
| ------------------------ |:--------------------------------------------------------------------------------------:|
| **derivadaFuncao**       | Retorna o valor que a função assume para o valor passado em sua derivada               |
| **NewtonRaphson**        | Método padrão para o cálculo de raízes de equações a partir de uma aproximação inicial |
| **NewtonRaphsonFL**      | Método de Newton com adaptações para os casos em que f'(xk) = 0                        |