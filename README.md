# Trabalho de Métodos Numéricos da UFC: Tema 1


O deslocamento da extremidade de um foguete espacial ao entrar na atmosfera da terra é dado pela equação 

```
f(d) = a*d –d*ln(d)
```

onde ***d*** é o  deslocamento  medido  em  *metros*  e  ***a***  é  um  parâmetro  de  ajuste  para  que  se  projete  um  foguete  com  a  máxima  segurança  e  eficiência possível. 

Caso esse deslocamento passe dos *2 cm* esse foguete irá explodir, causando sérios danos e um prejuízo gigantesco. 

Vários testes e simulações são feitos de modo a garantir que o foguete seja desenvolvido com toda segurança possível. 

Desenvolva um sistema para calcular esse deslocamento da extremidade de um foguete espacial considerado com todos os requisitos apresentados nos itens abaixo:

1. Implementar algoritmo para calcular ***d*** pelo método da **Bisseção**. 
2. Implementar algoritmo para calcular ***d*** pelo método da **Posição Falsa**. 
3. Implementar algoritmo para calcular ***d*** pelo método de **Newton-Raphson**.
4. Calibrar o sistema usando como padrão ***a= 1***, ***isolamento = (2, 3)*** e ***ε= 10^-5***.
5. Fornecer um quadro resposta, variando os valores de apara vários foguetes.
6. Fornecer um quadro comparativo, com isolamento, raízes e dados para cada método.
7. Analisar o efeito da variação do valor de ***a*** de cada foguete, *para cada método dado*.

Dados de **ENTRADA**:
  - n (número de foguetes) 
  - a(de cada foguete)
  - ε(precisão).
  
Dados de ***SAÍDA***:
  - Quadros resposta (com d, e a para cada foguete e método) e comparativo.