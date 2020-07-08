====================Seja bem-vindo ao Jogo Roda Roda=================================
=> Para que o executável do programa funcione é necessário baixar os seguintes arquivos:
•	palavras.dat
•	premios.dat
•	Projeto_JogoRodaRoda_Logica1.exe Após baixar este 3 arquivos é necessário deixá-los na mesma pasta ou diretório para executar o programa.


=> Caso deseje visualizar o código na Linguagem C é necessário baixar somente o arquivo Projeto_JogoRodaRoda_Logica1.c



=>Definição do Projeto de Lógica 1 do Curso de análise e desenvolvimento de Sistemas do IFSP


Objetivo: 

Gerar a aplicação, em LINGUAGEM C, para gerenciar o jogo que simula o programa “Roda a Roda” (do “Seu Silvio”)

O programa deverá funcionar conforme descrito a seguir.

1 – Deverá existir um arquivo chamado PALAVRAS.DAT para armazenar: a pista, quantas palavras serão tratadas e quais as palavras (no máximo 3).

2 – O layout do arquivo PALAVRAS.DAT será o seguinte:

Pista	Qtd	Palavras
char (17)	int	char vetpalavras[3][17]

Exemplificando:

Vegetal:	ACELGA	ALFACE	
Automóvel:	MOTOR	EMBREAGEM	ESCAPAMENTO
Cozinha:	PRATO	PANELA	FOGÃO
Réptil:	JARARACA		
Mamífero:	BALEIA	MACACO	


3 – Assim que o jogo começar, o programa deverá sortear, do arquivo PALAVRAS.DAT, um dos registros e mostrar a pista na tela.

Exemplificando: caso tenha sido sorteado o registro 4, a pista será: Réptil.

4 – Na tela, além da pista, deverá aparecer também a identificação de cada jogador (SÃO EXATAMENTE TRÊS JOGADORES) e quanto, em reais, cada um ganhou até o momento. Assim, no início do jogo, a tela deve estar da seguinte forma (considerando que a pista seja Réptil):


A palavra está associada com: Réptil



Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 0,00					R$ 0,00				R$ 0,00

5 – Depois de sorteada e mostrada a pista, o programa deverá, também, mostrar os espaços referentes a cada palavra (uma palavra em cada linha). No caso de Réptil, só existe uma palavra para tratar (JARARACA). Assim devem aparecer 8 espaços na tela para compor a palavra. Vide tela exemplo a seguir.


A palavra está associada com: Réptil

_ _ _ _ _ _ _ _

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 0,00					R$ 0,00				R$ 0,00

6 – A primeira rodada do jogo sempre é iniciada pelo jogador 1. Assim, o programa deverá solicitar ao jogador que "rode a roda!". Neste momento, o programa deverá sortear do arquivo chamado PREMIOS.DAT um dos prêmios. O layout do arquivo PREMIOS.DAT é o seguinte:

Premios
float

Exemplificando com alguns valores:
OBS.: 
0,00 = PASSA A VEZ
0,01 = PERDE TUDO

100,00
900,00
600,00
1000,00
0,00
400,00
200,00
800,00
0,01
300,00
500,00
700,00

Assim, suponha que foi sorteado o registro número 7 de PREMIOS.DAT, isto significa que cada letra que o jogador acertar valerá R$ 200,00. No nosso exemplo, o programa deverá pedir para o jogador "uma letra por R$ 200,00: ". Vide tela a seguir.


A palavra está associada com: Réptil

_ _ _ _ _ _ _ _

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 0,00					R$ 0,00				R$ 0,00

Roda a roda!
Uma letra por R$ 200,00: _


7 – Neste momento, o programa deverá permanecer em loop até que o usuário digite uma letra (maiúscula ou minúscula).

8 – Quando for digitada uma letra, o programa deverá verificar se a letra faz parte de alguma palavra a ser verificada. Caso a letra faça parte da(s) palavra(s), o programa deverá mostrar a letra na respectiva posição da palavra e, para cada ocorrência da letra, o prêmio do jogador deve ser atualizado (no nosso exemplo existem 4 letras 'A', logo o jogador 1 ganha R$ 800,00). 
Exemplificando: considerando o que foi feito até agora, suponha que o jogador 1 digitou a letra 'A'. O programa deverá procurar a existência desta letra na palavra em verificação (no caso, JARARACA). Neste caso a tela ficaria assim:


A palavra está associada com: Réptil

_ A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00


9 - Caso a letra não faça parte da palavra, o jogador não ganha prêmio algum neste momento e passa a vez para o próximo jogador.

Supondo que o jogador tenha errado, a tela ficaria assim;


A palavra está associada com: Réptil

_ _ _ _ _ _ _ _

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 0,00					R$ 0,00				R$ 0,00

Uma letra por R$ 200,00: X
Não existe letra X na palavra.
A vez será passada para o jogador 2.


10 – Caso seja sorteado "PASSA A VEZ", o jogador não perde o que tem até o momento, mas não poderá jogar agora. Assim, a vez será do próximo jogador que deverá "rodar a roda!" e proceder conforme já descrito anteriormente.

Exemplificando: suponha que o jogador 1 tenha sorteado o "PASSA A VEZ". A tela ficaria assim até que uma tecla fosse pressionada.


A palavra está associada com: Réptil

_ _ _ _ _ _ _ _

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 0,00					R$ 0,00				R$ 0,00

PASSA A VEZ

A vez será passada para o jogador 2.


Depois de pressionada qualquer tecla, a tela ficaria assim (e o jogo seguiria conforme já descrito anteriormente):


A palavra está associada com: Réptil

_ _ _ _ _ _ _ _

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 0,00					R$ 0,00				R$ 0,00

                                   Roda a roda!


11 – Quando faltarem 3 letras, ou menos, para completar a(s) palavra(s) o jogador da vez deverá obrigatoriamente responder qual é(são) a(s) palavra(s). Assim, o programa deverá fazer e exibir uma contagem regressiva de 5 segundos para depois solicitar a digitação da(s) palavra(s). Neste caso, a resposta certa valerá o total acumulado até o momento pelo jogador adicionado do prêmio sorteado nesta rodada.

Exemplificando: suponha que é a vez do jogador 1, que tenha sido sorteado o prêmio de R$ 1000,00 e que faltem 3 letras para completar a palavra (que no caso é JARARACA). A tela ficaria assim:


A palavra está associada com: Réptil

J A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00

Roda a roda!

Jogador 1: Faltam 3 letras para completar a palavra.
Valendo R$ 1800,00, a palavra é: _


12 – Caso o jogador acerte a(s) palavra(s) o programa deverá mostrá-la(s) na tela e totalizar a premiação dos jogadores até o momento, identificando, inclusive o vencedor.

Exemplificando: suponha que o jogador 1 tenha acertado a palavra, a tela ficaria assim:


A palavra está associada com: Réptil

J A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00

Roda a roda!

Jogador 1: Faltam 3 letras para completar a palavra.
Valendo R$ 1800,00, a palavra é: JARARACA


E depois assim:


A palavra está associada com: Réptil

J A R A R A C A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 1800,00					R$ 0,00				R$ 0,00

VENCEDOR


13 – Caso o jogador errar na rodada em que faltarem 3 letras, ou menos, para completar a(s) palavra(s), a vez deverá ser passada para o próximo jogador. Tal procedimento deverá acontecer até que os 3 jogadores tenham tido uma oportunidade de responder qual(is) é(são) a(s) palavra(s).

Exemplificando: suponha que o jogador 1 não saiba a resposta, a tela ficaria assim:
 


A palavra está associada com: Réptil

J A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00

Roda a roda!

Jogador 1: Faltam 3 letras para completar a palavra.
Valendo R$ 1800,00, a palavra é: NÃO SEI


Neste caso, a vez será passada para o jogador 2 que deverá "rodar a roda!". Considerando ainda o prêmio de R$ 1.000,00; somando ao valor que o próximo jogador já tem, a tela ficaria assim:

A palavra está associada com: Réptil

J A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00



Jogador 2: Roda a roda!
Faltam 3 letras para completar a palavra.
Valendo R$ 1.000,00, a palavra é: _


Supondo que o jogador 2 tenha acertado a palavra, a tela ficaria assim:

A palavra está associada com: Réptil

J A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00



Jogador 2: Roda a roda!
Faltam 3 letras para completar a palavra.
Valendo R$ 1.000,00, a palavra é: JARARACA

E depois assim:

A palavra está associada com: Réptil

J A R A R A C A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 1.000,00				R$ 0,00

                    VENCEDOR
14. Caso o segundo jogador também não acerte a palavra, a vez será passada para o terceiro jogador.

Considerando ainda o prêmio de R$ 1.000,00; somando ao valor que o próximo jogador já tem, a tela ficaria assim:

A palavra está associada com: Réptil

J A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00



Jogador 3: Roda a roda!
Faltam 3 letras para completar a palavra.
Valendo R$ 1.000,00, a palavra é: _


Supondo que o jogador 3 tenha acertado a palavra, a tela ficaria assim:

A palavra está associada com: Réptil

J A _ A _ A _ A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 0,00				R$ 0,00



Jogador 3: Roda a roda!
Faltam 3 letras para completar a palavra.
Valendo R$ 1.200,00, a palavra é: JARARACA

E depois assim:

A palavra está associada com: Réptil

J A R A R A C A

Jogador 1					Jogador 2				Jogador 3
==========					=========				=========
R$ 800,00					R$ 1.000,00				R$ 1.200,00

                                    	VENCEDOR

