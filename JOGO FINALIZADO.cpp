#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <tuple>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <atomic>
#include <chrono>
#include <future>

int batalha(char nome[101], int dano);
int batalharanha(char nome[101], int dano);
int batalhafinal(char nome[101], int dano);
int esq(char nome[101], int mochila[3][3], int din, int dano);
int escadaria(char nome[101], int dano);
void gotoxy(int x, int y);
using namespace std;
void toca(char nome[101], char nomeAMG[101]);
int mercador(char nome[101], int mochila[3][3], int din);
int mercadortribo(char nome[101], int mochila[3][3], int din);
int entradafloresta(char nome[101]);
int main()
{
	setlocale(LC_ALL, "Portuguese");
	char nome[101];
	char nomeAMG[101];
	char c;
	int escl, i, j, din, ch, it, dano, start, gld;
	int escl1, escl2, escl3, escl4, eagle, op;
	int F = 0;
	int mochila[3][3];
	escl2 = 0;
	c = 's';
	cout << R"(			 =============
			||  ATENÇÃO  ||
			 =============

DEIXE SUA TELA CHEIA PARA NÃO TER PROBLEMA NO CÓDIGO!
)" << endl;
	din = 100;
	dano = 1;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			mochila[i][j] = 0;
		}
	}
	op = 2;
	printf("Digite seu nick: \n");
	gets_s(nome);
	while ((op == 2))
	{
		do
		{
			system("CLS");
			printf("Confirme o nome: ");
			puts(nome);
			printf("? \n (1 para sim / 2 para não ) \n");
			scanf_s("%d", &op);
		} while ((c = getchar() != '\n' && c != EOF) || ((op < 1) || (op > 2)));
		if (op == 2)
		{
			printf("Digite seu nick: \n");
			gets_s(nome);
			system("CLS");
		}
	}
	system("CLS");
	op = 2;
	printf("Digite o nome da sua amiga (você terá uma parceira durante o jogo): \n");
	gets_s(nomeAMG);
	while (op == 2)
	{
		do
		{
			system("CLS");
			printf("Confirme o nome: ");
			puts(nomeAMG);
			printf("? (1 para sim/ 2 para não) \n");
			scanf_s("%d", &op);
		} while ((c = getchar() != '\n' && c != EOF) || ((op < 1) || (op > 2)));
		system("CLS");
		if (op == 2)
		{
			printf("Digite o nome: \n");
			gets_s(nomeAMG);
			system("CLS");
		}
	}
	system("CLS");
	toca(nome, nomeAMG);
	scanf_s("%d", &escl);
	system("CLS");
	while ((c = getchar() != '\n' && c != EOF) || ((escl != 1) && (escl != 2))) {
		printf("Por favor digite um valor válido!!! \n");
		scanf_s("%d", &escl);
		system("CLS");
	}
	if (escl == 1)
	{
		ch = mercador(nome, mochila, din);
		switch (ch)
		{
		case 1:
			do
			{
				cout << R"(Escolha qual item comprar pelo número:
1) Graveto de carvalho  2) Garra de Águia    3) Machado

4) Martelo de Guerra  5) Lança
)" << endl;
				scanf_s("%d", &it);
			} while ((c = getchar() != '\n' && c != EOF) || ((it < 1) && (it > 5)));
			switch (it)
			{
			case 1:
				printf("Espaço atual na mochila: \n");
				for (i = 0; i < 3; i++)
				{
					mochila[i][0] = 1;
				}
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						printf("[%d] \t", mochila[i][j]);
					}
					printf("\n");
				}
				din = din - 10;
				dano = 5;
				break;
			case 2:
				printf("Espaço atual na mochila: \n");
				mochila[0][0] = 1;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						printf("[%d] \t", mochila[i][j]);
					}
					printf("\n");
				}
				din = din - 20;
				dano = 10;
				break;
			case 3:
				printf("Espaço atual na mochila: \n");
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 2; j++)
					{
						mochila[i][j] = 1;
					}
				}
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						printf("[%d] \t", mochila[i][j]);
					}
					printf("\n");
				}
				din = din - 90;
				dano = 55;
				break;
			case 4:
				printf("Espaço atual na mochila: \n");
				for (j = 0; j < 3; j++)
				{
					mochila[0][j] = 1;
				}
				for (i = 1; i < 3; i++)
				{
					mochila[i][1] = 1;
				}
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						printf("[%d] \t", mochila[i][j]);
					}
					printf("\n");
				}
				din = din - 80;
				dano = 40;
				break;
			default:
				printf("Espaço atual na mochila: \n");
				for (j = 0; j < 3; j++)
				{
					mochila[0][j] = 1;
				}
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						printf("[%d] \t", mochila[i][j]);
					}
					printf("\n");
				}
				din = din - 50;
				dano = 20;
				break;
			}
		default:
			break;
		}
	}
	system("Pause");
	//floresta
	i = 0;
	do
	{
		F = entradafloresta(nome);
		switch (F)
		{
		case 1:
			if (esq(nome, mochila, din, dano) == 0)
			{
				escl2 = 0;
			}
			break;
		case 2:
			do
			{
				cout << nome << R"( e sua amiga seguem o odor que vem do lado direito da floresta.A trilha é bastante ampla. 
Os lémures avançam, devagar, quando percebem pegadas bastante grandes no chão.Estas pegadas seguem na floresta e terminam 
repentinamente no meio do mato. O odor é muito forte. Os lémures percebem um animal enorme saindo do mato alto e pulando 
para cima deles. Um urso. Em uma só mordida, sem qualquer reação, os lémures são abocanhados, não restando nada. 

 ~~~~~~~~~~~~~~~~
|  Você perdeu.  |
 ~~~~~~~~~~~~~~~~

)" << endl;
				system("Pause");
				system("CLS");
				printf("Deseja jogar novamente? 1 para sim e 2 para não \n");
				scanf_s("%d", &start);
			} while (((c = getchar()) != '\n' && EOF) || (start < 1) && (start > 2));
			if (start == 1)
			{
				main();
			}
			else
			{
				escl2 = 0;
			}
			break;
		default:
			if (i == 0)
			{
				cout << R"(Os lémures optam por fazerem uma escala na grande árvore em sua frente. Esta árvore poderá dar pistas de onde se 
localiza o local que precisam chegar. Após a escala. Os lémures atingem o topo e resolvem espiar. Uma águia, predadora 
voraz de lémures enxerga-os e parte para o ataque com suas afiadas garras e bico pontiagudo. 
Você só tem uma opção, lutar!
)" << endl;
				cout << R"(Enfrente a águia: 
)" << endl; // aqui a batalha com a águia;
				system("pause");
				start = batalha(nome, dano);
				if (start == 2)
				{
					dano = dano + 10;
					din = din + 20;
					printf("Agora que você removeu as garras da águia, conseguiu mais dano! \n");
					printf("Dano atual: %d, Ouro atual: %d \n", dano, din);
					system("Pause");
					escl2 = 2;
					i = 1;
				}
				else
				{
					do
					{
						system("CLS");
						cout << R"(
                                                                                                                                  
                      ...                                   ... .               ...                      ...         ..                               
                   ........       ..'.      ...      .'.  ........            ........   ...     ..  .........   .........                            
                  ...             .....     .''.    .''.  ...                ..     ...   ..    ...  ...         ...    ...                           
                  ...            ... ...    .....  .....  .....             ...      ..   ...  ...   .....       ....  ....                           
                  ..    ....    .... ...    ............  ......            ...      ..    ... ...   .......     ........                             
                  ...   ....    .........   ... ..'. ...  ...               ...     ...    ......    ...         ...   ...                            
                   ...   ...   ...     ...  ...  ..  ...  ...                ...   ...      .''.      ...        ...    ..                            
                    .......    ..       ..  ..        ..  .........           .......        ..       ........   ..     ...                           
                                                                                                                                                      
)" << endl;
						printf("Deseja jogar novamente? (1 para sim /2 para não) \n");
						scanf_s("%d", &start);
					} while ((c = getchar() != '\n' && c != EOF) || (start != 1) && (start != 2));
					if (start == 1)
					{
						system("CLS");
						main();
					}
					else
					{
						escl2 = 0;
					}
				}
			}
			else
			{
				system("CLS");
				printf("Nada por aqui, apenas volte. \n");
				escl2 = 2;
				system("Pause");
			}
		}
	} while (escl2 == 2);
	return 0;
}

void toca(char nome[101], char nomeAMG[101])
{
	cout << R"(
kkkkkkkkkkkkkkkkkkkkkkkkkkkkkOOkkkxxxxkkkkkkkkkkkkkkkkkkkkkkkkkkOkkkkkkkkOO00OOOkkkkkkkkOO00KKKK0Okk
kkkkkkkkOOO0KKKK0Okkkkkkkkxolcc::;;,,,;::cokkkkkkkkkkkkkkkkkkkkOKKKKKKKKKXNNWNXXKKKKKKKXXNNWWWMWXOkk
kOO000KKXXNWWMMWWX0OOkkdl:,''''',,,,,,,,''';lxkkkkkkkkkkkkkkkkOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOkk
kOKNWWWWWWWWWWWWWN0kkd:'',,,,,,,,,,,,,,,,,,'';cdkkkkkkkkkkkkkkOKNWWMMMMMMMMMMMWWWNNNNNXXXXXNNWWWXOkk
kO0XNNXK000000KKK0Okd;',,,,,,,,,,,,,,,,,,,,,,,',okkkkkkkkkkkkkkO0KKKXXNNNNNNNXK00OOOOOOOOOOOO00K0Okk
kkkOOOOkkkkkkkkkkkkx;',,,,,,,,,,,,,,,,,,,,,,,,,',codxkkkkkkkkkkkkkkkkOOOOOOOOOkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkkkd:',,,,,,,,,,,,,,,,,,,,,,,,,,,,'',;clxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkkxl,',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'',:coxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkd:',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'';:okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkkxl,',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,''lkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkkd:'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkkd;',,,,,,,,,,,,,,,,,,,,'',,,,,,,,,,,,,,,,,,,,,,,,,,',lxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkkd;',,,,,,,,,,,,,,'.....    ...'',,,,,,,,,,,,,,,,,,,,,'';ldkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkkd;',,,,,,,,,,,,'.                ...',,,,,,,,,,,,,,,,,,,,',;cllodkkkOkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkkd;',,,,,,,,,,,,..                     .',,,,,,,,,,,,,,,,,,,,,'''',;:ldkkkkkkkkkkkkkkkkkkkkkk
kkkkkkkx;',,,,,,,,,,,,.                         .',,,,,,,,,,,,,,,,,,,,,,,,,'',:lxkkkkkkkkkkkkkkkkkkk
kkkkkkkl'',,,,,,,,,,,.                           ..',,,,,,,,,,,,,,,,,,,,,,,,,,'';lkkkkkkkkkkkkkkkkkk
kkkkkkd;',,,,,,,,,,,'.                              .,,,,,,,,,,,,,,,,,,,,,,,,,,,'';ccloddxkxkkkkkkkk
kkkkkkc',,,,,,,,,,,,'.                              .',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'''',;;;;;:oxkkk
kkkkko,',,,,,,,,,,,,'.                               .,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'',:ok
kkkkk:',,,,,,,,,,,,,'.                                .,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',;
kkkkl'',,,,,,,,,,,,,,.                                .,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'
kkxl,',,,,,,,,,,,,,,,.                                .,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
xl;'',,,,,,,,,,,,,,,'.                                 .,,,,,,,,,,,,,,,,,,,,,,,'''''''''''',,,,,,,,,
''',,,,,,,,,,,,,,,,,,.                                 .'''''''''''''''''''''',,,,,,,,,,,,,,''''''''
',,,,,,,,,,,,,,,,,,,,...................................',;;::::::::::;;;;;;:::cccccccccccccc:::::;,
......................,,,,,,,,;;::::::::::::::::c::::ccccccccccccccccccccccccccccccccccccccccccccccc
:;;;;,,,,;;;;;;;;;;;:::::ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
)" << endl;
	system("Pause");
	cout << R"(,------------------,
| Toca dos lémures |
'------------------'
Em uma pequena e simples toca vivia um grupo de 10 lêmures. A matriarca da família está preocupada, pois o inverno está chegando e o estoque de comidas está bastante baixo. Os lémures precisam estocar provisões para o inverno que irá chegar.

Os lémures ouviram falar de uma lenda onde, em algum lugar da floresta existe um local com o segredo para encontrar a comida em abundância.

Observando a preocupação da matriarca, um jovem e bravo lémure, chamado(a) )" << nome << endl;

	cout << R"(voluntaria-se para ir em busca deste segredo escondido e salvar sua família.

O lémure então coloca sua vestimenta de couro, suas botas, coloca no bolso suas 100 moedas de ouro e pega sua arma, um pequeno, mas bem afiado, graveto feito de carvalho, coloca-o nas costas. Neste momento, sua melhor amiga: )" << nomeAMG << endl;
	cout << R"(
surge ao seu lado também pronta para acompanha-lo. Sua amiga é pequena, mas bastante forte, e carrega sempre consigo uma clava com espinhos.)" << endl;
	system("pause");
	system("CLS");
	cout << R"(Agora, o lémure se vê diante de duas opções: 
1 – Conversar com o mercador.

2 – Ir para a floresta.)" << endl;

	printf("O lêmure escolhe a opção: ");
}

int entradafloresta(char nome[101])
{
	int F;
	char c;
	do
	{
		system("CLS");
		cout << nome << R"( ruma em direção a floresta a busca pela sobrevivência de sua família junta de sua companheira inseparável. 
Na entrada da densa, úmida e escura floresta de araucárias e baobás o lémure se depara com três caminhos a serem seguidos:

1 – À esquerda, uma pequena trilha, bastante estreita.

2 – À direita, um largo e amplo caminho. Um odor fétido é exalado deste lado.

3 – No meio, uma grande árvore.

)" << endl;

		printf("Escolha um caminho: \n");
		scanf_s("%d", &F);
	} while (((c = getchar()) != '\n' && c != EOF) || ((F < 1) || (F > 3)));
	return F;
}

int esq(char nome[101], int mochila[3][3], int din, int dano)
{
	int escl1, escl2, escl3, escl4, i, j, gld, ch, it, bat, start;
	char c;
	escl3 = 0;
	do
	{
		system("CLS");
		cout << nome << R"( e sua amiga seguem a estreita trilha para a esquerda.
Aparentemente este caminho parece não ser muito usado e é de difícil acesso.Os lémures, 
por serem pequenos, conseguem se esgueirar por dentro os galhos e plantas no caminho até, 
após alguns quilômetros de caminhada avistarem uma pequena clareira com duas árvores de folhas brancas.
)" << endl;
		cout << nome << R"( lembra das histórias da matriarca onde, em uma clareira com duas árvores brancas, 
uma representa vida e outra morte. Ambas árvores apresentam uma abertura.

Você precisa optar qual delas entrar:
)" << endl;
		printf("1 – Árvore branca da esquerda.\n2 – Árvore branca da direita.\n");
		scanf_s("%d", &escl1);
	} while ((c = getchar() != '\n' && c != EOF) || ((escl1 != 1) && (escl1 != 2)));
	switch (escl1)
	{
	case 1:
		system("CLS");
		cout << R"(Os lémures decidem entrar pela árvore do lado esquerdo. Nesta árvore um feixe de luz bate direto na entrada da porta iluminando o interior.
 Ao entrar, nada é visto nem encontrado. Os lémures estão decepcionados. Quase antes de desistir, a fiel companheira de )" << nome << endl;
		cout << R"(enxerga uma fina linha amarrada alguns metros acima da cabeça deles, dentro da árvore. Ela resolve saltar o máximo que consegue para se agarrar nesta linha. 
Ela consegue mas se desprende e cai de costas no chão, quebrando seu pescoço e morrendo. Você perdeu sua companheira e consequentemente seu poder de luta.
Graças ao esforço dela, uma passagem se abriu e você pode passar por ela.

)" << endl;
		do
		{
			cout << R"(O lémure entra na caverna. A porta atrás dele se fecha. )" << nome << endl;
			cout << R"(avança lentamente pelo escuro. Aos poucos uma luz começa a emergir e vozes ecoam. 
Dobrando uma esquina na caverna, avista-se um grupo de lémures. A cor da pele dele é azul. Todos utilizam aparatos indígenas. 
Quando eles veem você, sorriem para recebe-lo. Neste momento,)" << nome << endl;
			cout << R"(, percebe que na verdade este são os lémures da tribo Chimichunga. A tribo citada pela matriarca que detêm o conhecimento que eles procuram.
Você se aproxima do chefe da tribo dos Chimichungas. Ele diz que se você seguir a escadaria que está atrás deles, e descer os 10 mil degraus, encontrará a resposta e a salvação para o seu povo. 
)" << endl;
			printf("Você tem duas opções \n1 – Conversar com o mercador da tribo. \n2 – Ir em frente pela escadaria. \n");
			scanf_s("%d", &escl3);
		} while ((c = getchar() != '\n' && c != EOF) || ((escl3 != 1) && (escl3 != 2)));
		switch (escl3)
		{
		case 1:
			// função de conversar com o mercador.
			ch = mercadortribo(nome, mochila, din);
			gld = din;
			do
			{
				din = gld;
				if (ch == 1)
				{
					do
					{
						system("CLS");
						cout << R"(Escolha qual item comprar pelo número:
1) Graveto de carvalho  2) Garra de Águia    3) Machado

4) Martelo de Guerra  5) Lança
)" << endl;
						scanf_s("%d", &it);
					} while ((c = getchar() != '\n' && c != EOF) || ((it < 1) || (it > 5)));
					switch (it)
					{
					case 1:
						din = din - 10;
						break;
					case 2:
						din = din - 14;
						break;
					case 3:
						din = din - 100;
						break;
					case 4:
						din = din - 80;
						break;
					default:
						din = din - 30;
						break;
					}
				}
				else
				{
					break;
				}
				if (din < 0)
				{
					printf("Ouro insuficiente. \n");
					system("pause");
				}
				else
				{
					switch (it)
					{
					case 1:
						printf("Espaço atual na mochila: \n");
						for (i = 0; i < 3; i++)
						{
							mochila[i][0] = 1;
						}
						for (i = 0; i < 3; i++)
						{
							for (j = 0; j < 3; j++)
							{
								printf("[%d] \t", mochila[i][j]);
							}
							printf("\n");
						}
						dano = 12;
						break;
					case 2:
						printf("Espaço atual na mochila: \n");
						mochila[0][0] = 1;
						for (i = 0; i < 3; i++)
						{
							for (j = 0; j < 3; j++)
							{
								printf("[%d] \t", mochila[i][j]);
							}
							printf("\n");
						}
						dano = 18;
						break;
					case 3:
						printf("Espaço atual na mochila: \n");
						for (i = 0; i < 3; i++)
						{
							for (j = 0; j < 2; j++)
							{
								mochila[i][j] = 1;
							}
						}
						for (i = 0; i < 3; i++)
						{
							for (j = 0; j < 3; j++)
							{
								printf("[%d] \t", mochila[i][j]);
							}
							printf("\n");
						}
						dano = 83;
						break;
					case 4:
						printf("Espaço atual na mochila: \n");
						for (j = 0; j < 3; j++)
						{
							mochila[0][j] = 1;
						}
						for (i = 1; i < 3; i++)
						{
							mochila[i][1] = 1;
						}
						for (i = 0; i < 3; i++)
						{
							for (j = 0; j < 3; j++)
							{
								printf("[%d] \t", mochila[i][j]);
							}
							printf("\n");
						}
						dano = 77;
						break;
					default:
						printf("Espaço atual na mochila: \n");
						for (j = 0; j < 3; j++)
						{
							mochila[0][j] = 1;
						}
						for (i = 0; i < 3; i++)
						{
							for (j = 0; j < 3; j++)
							{
								printf("[%d] \t", mochila[i][j]);
							}
							printf("\n");
						}
						dano = 66;
						break;
					}
				}
			} while ((din < 0));
			printf("Dano atual: %d, ouro atual: %d \n", dano, din);
			system("pause");
			return escadaria(nome, dano);
			break;
		default:
			printf("O Lêmure decide apenas seguir em frente \n");
			system("Pause");
			return escadaria(nome, dano);
			break;
		}
	default:
		cout << R"(Os lémures decidem entrar pela árvore do lado direito. Nesta árvore uma névoa densa e escura espreita dentro da oca árvore. Ao entrar, nada é visto nem encontrado. )" << nome << endl;
		cout << R"( tateia as paredes internas da árvore até que encontra uma saliência. Ele aperta. Uma passagem na árvore é aberta e você entrar por ela.)" << endl;
		cout << R"(O lémure avança escadaria abaixo. Degrau por degrau. Passo por passo. A luz é muito fraca, mas aos poucos os olhos dos lémures vão se adaptando e é possível ver pelo vão da escadaria um abismo profundo. 
Eles vão descendo, e descendo e descendo. Em um determinando momento, grunhidos são ouvidos. Duas aranhas, quase invisíveis aparecem na frente.)" << endl;
		printf("Enfrente as aranhas: \n");
		system("pause");
		// batalha com as aranhas. Derrota – perca o jogo.

		// Vitoria – As aranhas foram mortas.Continue seguindo pela escadaria.
		bat = batalharanha(nome, dano);
		if (bat == 1)
		{
			dano = dano + 15;
			return escadaria(nome, dano);
		}
		else
		{
			do
			{
				system("CLS");
				cout << R"(
                                                                                                                                  
                      ...                                   ... .               ...                      ...         ..                               
                   ........       ..'.      ...      .'.  ........            ........   ...     ..  .........   .........                            
                  ...             .....     .''.    .''.  ...                ..     ...   ..    ...  ...         ...    ...                           
                  ...            ... ...    .....  .....  .....             ...      ..   ...  ...   .....       ....  ....                           
                  ..    ....    .... ...    ............  ......            ...      ..    ... ...   .......     ........                             
                  ...   ....    .........   ... ..'. ...  ...               ...     ...    ......    ...         ...   ...                            
                   ...   ...   ...     ...  ...  ..  ...  ...                ...   ...      .''.      ...        ...    ..                            
                    .......    ..       ..  ..        ..  .........           .......        ..       ........   ..     ...                           
                                                                                                                                                      
)" << endl;
				printf("Deseja jogar novamente? (1 para sim /2 para não) \n");
				scanf_s("%d", &start);
			} while ((c = getchar() != '\n' && c != EOF) || (start != 1) && (start != 2));
			if (start == 1)
			{
				system("CLS");
				main();
			}
			system("CLS");
			return 0;
		}
		break;
	}
}

//Função gotoxy
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int mercador(char nome[101], int mochila[3][3], int din)
{
	int ch, it, i, j;
	char c;
	ch = 0;
	c = 's';
	do {
		system("CLS");
		cout << R"(
Mercador

Olá meu/minha jovem 
)" << nome << endl;
		cout << R"(
Tenho estes itens para venda. Gostaria de comprar algum? (Número 1 para espaço preenchido e 0 para vazio).


Graveto de carvalho   | Garra de Águia      | Machado
Preço: 10 moedas      | Preço: 20 moedas    | Preço: 90 moedas
Dano: 5               | Dano: 10            | Dano: 55
Espaço requisitado:   | Espaço requisitado: | Espaço requisitado: 
                      |                     |
[1] [0] [0]           | [1] [0] [0]         |[1] [1] [0]
[1] [0] [0]           | [0] [0] [0]         |[1] [1] [0]
[1] [0] [0]           | [0] [0] [0]         |[1] [1] [0]

Martelo de Guerra     | Lança
Preço: 80 moedas      | Preço: 50 moedas
Dano: 40              | Dano: 20      
Espaço requisitado:   | Espaço requisitado: 
                      |                     
[1] [1] [1]           | [1] [1] [1]         
[0] [1] [0]           | [0] [0] [0]         
[0] [1] [0]           | [0] [0] [0]         

1 – Comprar.

2 – Voltar. \n)" << endl;
		gotoxy(0, 33);
		printf("Moedas de ouro: %d \t", din);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("[%d] \t", mochila[i][j]);
			}
			printf("\n                   \t");
		}
		printf("  Espaço. \n");

		scanf_s("%d", &ch);
	} while ((c = getchar() != '\n' && c != EOF) || ((ch != 1) && (ch != 2)));
	return ch;
}

int mercadortribo(char nome[101], int mochila[3][3], int din)
{
	int ch, it, i, j, gd;
	char c;
	ch = 0;
	c = 's';
	gd = din;
	do {
		system("CLS");
		cout << R"(
Mercador Tribo

Olá meu/minha jovem 
)" << nome << endl;
		cout << R"(
Tenho estes itens para venda. Gostaria de comprar algum? (Número 1 para espaço preenchido e 0 para vazio).

----------------------------------------------------------------------
| AVISO: se você comprar um novo item o item antigo será DESCARTADO! |
----------------------------------------------------------------------

Graveto de carvalho   | Garra de Águia      | Machado
Preço: 10 moedas      | Preço: 14 moedas    | Preço: 100 moedas
Dano: 12              | Dano: 18            | Dano: 83
Espaço requisitado:   | Espaço requisitado: | Espaço requisitado: 
                      |                     |
[1] [0] [0]           | [1] [0] [0]         |[1] [1] [0]
[1] [0] [0]           | [0] [0] [0]         |[1] [1] [0]
[1] [0] [0]           | [0] [0] [0]         |[1] [1] [0]

Martelo de Guerra     | Lança
Preço: 80 moedas      | Preço: 30 moedas
Dano: 77              | Dano: 66      
Espaço requisitado:   | Espaço requisitado: 
                      |                     
[1] [1] [1]           | [1] [1] [1]         
[0] [1] [0]           | [0] [0] [0]         
[0] [1] [0]           | [0] [0] [0]         

1 – Comprar.

2 – Voltar. \n)" << endl;
		gotoxy(0, 33);
		printf("Moedas de ouro: %d \t", din);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("[%d] \t", mochila[i][j]);
			}
			printf("\n                   \t");
		}
		printf("     Espaço. \n");

		scanf_s("%d", &ch);
	} while ((c = getchar() != '\n' && c != EOF) || ((ch != 1) && (ch != 2)));
	return ch;
}

int batalha(char nome[101], int dano)
{
	int rd, ag, jg;
	float atq, vd, vdag;
	char c;
	c = 's';
	vd = 100;
	vdag = 200;
	srand(time(NULL));
	rd = 0;
	system("CLS");
	cout << R"(A batalha funciona da seguinte forma:
- Será gerado um número aleatório de 0 a 20, você deverá digitar um número de 0 a 20.
- A subtração dos dois números, deverá chegar próxima de 10, quanto mais perto, maior a porcentagem de dano, quanto mais longe, menor.
- O dano é calculado com a porcentagem tirada e o dano de sua arma, (se você não comprou nenuma arma, seu dano é 1.)" << endl;
	system("pause");
	system("CLS");
	while ((vd >= 0) && (vdag >= 0))
	{
		atq = dano;
		do
		{
			gotoxy(0, 79);
			printf("Sua vida: %.1f", vd);
			printf("\t\t\tVida da águia: %.2f", vdag);
			gotoxy(0, 36);
			cout << R"(                                                     ..    .'oKWMWNNXKOxodkxo:;;,';c:lccddl;'...',.....:oddkOO
                                                :;.,oc,',:okKNWWN0O00Okkxdo:'...'..'','';;;;;::,,,'';:clxkkkkd
                                              .oXxdKXKKXXNNNWWNKOxddooxxc'.   .......,'.';;;,,;::coxdodxkkxddd
                                             .c0NXKXXXNWNNXXXX0xoc;,....       .;c:'.;;',;;,,:ldolllodddollllc
                                            .:dk0XXOkO0K00Okkkdc:;;,..          ,xx:.';',;;;ldddoooddddollccll
                                            .,odoxOOxdk0Oxdolcllc:;'...     .,loxOd,.'..;;;ldddddddddoolllllll
                                            .;oxkxxkOOO00Okko:::;,,,,'..... .:dxdc,,'.';::oxddxdodxkdlccccccll
                                            .lxOK000K0OkOO0Okoccloodddddddolc,'','',,;loloolodxdddoc::cloooooo
                                         .;lx0KKK0000OOOO00OkkxxxxOO0OOkkkkkxdodddddddddolccldooolc::coxkOOOOO
                                      .;ok00OddxxxxxkkOOO00OOOOOkkOO000Okkkkxdoooool:;;:cldxkkkkkkkkOO00OOkxxx
                                   .,d0KXKOkd;....,cdkOO000OOkkkkkxxxkkxxxxxxddddddddxkO0K00OOO000000OOOOkOO00
                                  ,xKNNXKKK0OkxdodxkkOOOOOOOOOOOOOOOOOO0OOOkxxdxxkO0KKKK00OkkOOOOOOO00KKXXXKK0
                                .l0NNXXXKKKKKKK0OOOkkO0000000OOOO00OkxdoooooodxkO0OOkkxddxxxxxxkkO00000000Okkk
                               'd0XKKKK000KKKKXKKKK000KKK0OOOOOOkxolllllodxkdooodddddooooodollodxkkOOOOkkxxdxx
                              'd0000OOOOOOOO0000000KX0kxddddolcc::cc::cccc::cllllcclodxxxxkxxddxdooodxkOOOOOO0
                             .o00OOOkkkkkkkkOOOOOkxkx:;:cc;,,,;;'',,,',,;;codxkkkxxkOOOOOOxddddoodkO0000KKKKKK
                            .:k00OkkxxxxxxkkOkkxo:;;'.':,'',;,,',;;coddxxxkkkkOOOO00OOOkddooloxxk00KKKKKKKK00K
                            .lOOOkkxxxxxxxkkOxd:,,,'..','...''.',;;codxxxxxxxxddddolllooodkOO0KXXXXXXXXXXNXXXX
                            .oOkkkxxxxdddxkxdc'..,'..''''''''',,,,;;:clllllllcc::::;;;:cldkO0KXXXKXXXXXXXXXXXK
                            .okxkxxxxdoolc:,'...............',;;,;,;;:::;;;;;;;;;;;;:ccoxOO000KXXXXXXXXXXXXXKO
                            .cxkxxxxdoccc:;'......           ...',,,,,,,,,,,,,,,',,,:ldkO0000KKKKXXXXXXXXXXXK0
                             'oxxkkdl:;;,''....                  ...'',,,,,,,,,,,'',;lxkO0KKKXXXXXXXXXXKKKKKKK
                              ,oxxkxc'.....                           ...''''''','',cdkO0KKXXXNNNXXXXNXXKKOOOO
                              .;odxx,.                                   .........,cxO0KXXNNNNNNNXXXXNNXXKK0Ok
                               .,cdx,                                     ........;lk0KKXXXXXNNNXK00XNNXXXXXK0
                                 .:do.                                    .......'o0XXNNXXXXXXXXXKOkOKXXXXXXK0
                                  ..ll.                                   ......;xXNNNNNXXXXXXXXK0OkkOKKK0KXX0
                                    .''                                  .....,o0XNNNNNNXXNNNNXXX0O0K0OOOOOKX0
                                                                        ....,lOXNXXXNNXXKXNNNNNXXK0KNXOkkkO000
                                                                      ....,lONWNNXXXXXXKO0XNNNNNXXKXNNK0kxO0Ok
                                                                     ...'cOXNNNNXKXXXXKOxdOXXXNNKKKXNNXKOk0KOx
                                                                   ....'l0NNNNNX00KXXXKkocxKXXNN000KXXK000KX0x

)" << endl;
			rd = rand() % 10;
			gotoxy(0, 36);
			printf("Digite um número: ");
			scanf_s("%d", &jg);
		} while ((c = getchar() != '\n' && c != EOF) || ((jg < 0) || (jg > 20)));
		if (jg >= rd)
		{
			rd = jg - rd;
		}
		else
		{
			rd = rd - jg;
		}
		switch (rd)
		{
		case 0: case 20:
			atq = atq * 0;
			break;
		case 1: case 19:
			atq = atq * 0.1;
			break;
		case 2: case 18:
			atq = atq * 0.2;
			break;
		case 3: case 17:
			atq = atq * 0.3;
			break;
		case 4: case 16:
			atq = atq * 0.4;
			break;
		case 5: case 15:
			atq = atq * 0.5;
			break;
		case 6: case 14:
			atq = atq * 0.6;
			break;
		case 7: case 13:
			atq = atq * 0.7;
			break;
		case 8: case 12:
			atq = atq * 0.8;
			break;
		case 9: case 11:
			atq = atq * 0.9;
			break;
		default:
			atq = atq * 1;
		}
		vdag = vdag - atq;
		if (vdag <= 0)
		{
			system("CLS");
			break;
		}
		printf("\nSeu ataque foi de: %.1f\n", atq);
		printf("Vez da águia....\n");
		gotoxy(0, 79);
		printf("Sua vida: %.1f", vd);
		printf("\t\t\tVida da águia: %.2f", vdag);
		gotoxy(0, 40);
		system("pause");
		rd = rand() % 10;
		jg = rand() % 10;
		if (jg >= rd)
		{
			rd = jg - rd;
		}
		else
		{
			rd = rd - jg;
		}
		atq = 30;
		switch (rd)
		{
		case 0: case 20:
			atq = atq * 0;
			break;
		case 1: case 19:
			atq = atq * 0.1;
			break;
		case 2: case 18:
			atq = atq * 0.2;
			break;
		case 3: case 17:
			atq = atq * 0.3;
			break;
		case 4: case 16:
			atq = atq * 0.4;
			break;
		case 5: case 15:
			atq = atq * 0.5;
			break;
		case 6: case 14:
			atq = atq * 0.6;
			break;
		case 7: case 13:
			atq = atq * 0.7;
			break;
		case 8: case 12:
			atq = atq * 0.8;
			break;
		case 9: case 11:
			atq = atq * 0.9;
			break;
		default:
			atq = atq * 1;
		}
		vd = vd - atq;
		gotoxy(0, 41);
		printf("Um ataque veloz, dano de %.2f \n", atq);
		gotoxy(0, 79);
		printf("Sua vida: %.1f", vd);
		printf("\t\t\tVida da águia: %.2f", vdag);
		if (vd <= 0)
		{
			system("CLS");
			break;
		}
		gotoxy(0, 42);
		system("pause");
	}
	if (vd <= 0)
	{
		printf("Você perdeu. \n");
		return 1;
	}
	else
	{
		printf("Vitória!!! \n");
		printf("Você ganhou +20 de ouro e +10 de dano!!!");
		return 2;
	}
}

int batalharanha(char nome[101], int dano)
{
	int rd, ag, jg;
	float atq, vd, vdar;
	char c;
	c = 's';
	vd = 100;
	vdar = 350;
	srand(time(NULL));
	rd = 0;
	system("CLS");
	cout << R"(A batalha funciona da seguinte forma:
- Será gerado um número aleatório de 0 a 20, você deverá digitar um número de 0 a 20.
- A subtração dos dois números, deverá chegar próxima de 10, quanto mais perto, maior a porcentagem de dano, quanto mais longe, menor.
- O dano é calculado com a porcentagem tirada e o dano de sua arma, (se você não comprou nenuma arma, seu dano é 1.)" << endl;
	system("pause");
	system("CLS");
	while ((vd >= 0) && (vdar >= 0))
	{
		atq = dano;
		do
		{
			gotoxy(0, 79);
			printf("Sua vida: %.1f", vd);
			printf("\t\t\tVida das aranhas: %.2f", vdar);
			gotoxy(0, 36);
			cout << R"(                                                              .....   ..     ..     ..         ..     ..             ..        
         ..      ..  ..   .........      ..   .:,.....                              ..  ..   ..     ..     ..         ..     ..             ..        
          ..      ..  ..    .;;..      ...    .....  ............       ..........';.   ..   ..     ..      .         ..     ..             ..        
           ..      ..  ..     .'.',....       ..  .'.           ..........      .....   ..   ..      .      ..        ..     ..             ..        
            ..      .. ..      ...''...      ..   .;;.....                     ..  ..   ..   ..      ..     ..        ..     ..             ..        
            ..      ..  ..       ......,;....     ...... ......              ..    ..   ..   ..      ..     ..        ..     ..             ..        
.            ..      ..  ..       ....  ''...    ..   ...    .;;..........,;'.     ..   ..    .      ..     ..        ..     ..             ..        
.            ..      ..  ..       .. ..  .. ..''''      ....lOXXk:.     .';l;.     ..    ..   ..     ..     ..        ..     ..             ..        
.             ..      ..  ..       .. ..  ..  .;l:.      .oKWMMMMWO,   .. .,;,.    ..    ..   ..     ..     ..        ..     ..             ..        
.             ..      ..  ..       ..  ..  .'. .:l,.... .xWMMMMMMMMK;...  .'.;,     .    ..   ..     ..     ..        ..     ..             ..        
.             ..      ..  ..       ..  ..  .:;. .cc.  ..dNMMMMMMMMMWk'     .',.     .    ..   ..      .     ..        ..     ..              .        
.             ..      ..  ..       .   ..  .'::..'l:   .OMMMMMMMMMMMO.    .,,.    ....    .   ..      ..    ..        ..     ..              ..       
              .       ..  ..      ..   ..  .. .:c.'o;  .xMMMMMMMMMMNl    .,,'.  .'. ..    ..   ..     ..    ..        ..     ..              ..       
             ..       .. ..      ..   ..   ..  .cc,;ll;.;KMMMMMMMMNd. ..,;. .,....   ..   ..   ..     ..    ..        ..      .              ..       
            ..       .....     ...   ..   ..  ...,ll:oxddkNMMMMMMXd:::cc:;,'''.      ..    ..  ..     ..     ..       ..      ..             ..       
           ..        ....    ...   ...  .''..,'....,clod0NWMMMMMMN0ko:,',;.  ..      ..    ..   ..     ..    ..       ..      ..              ..      
          ..       .....   ...   .''.....,'........''',:o0WMMMMMMNOl;,'.........      ..   ..   ..     ..    ..       ..      ..              ..      
        ...      ......  .''......,.      ....'''.     .,dKOdxxOXKd:'..'''','.';,.     ..   ..   ..    ..    ..       ..      ..              ..      
      ...     ...'''.....,,..      ..       .'  ..  ..';.,l'    cl,cc,.  .',,'......   ..    .   ..    ..    ..       ..       ..              ..     
    ...  ..'''...','.      ...      ...     ...  .''....  '.    .. .',c;..   ..    .... ..   ..   ..    ..    ..       ..      ..              ..     
 ..''...,'...      ...       ...      ..     ..  .;'..             .. .l,             ...,'   ..  ..    ..    ..       ..      ..               .     
.,'.    ...           ...      ..      ..     .. ,;'.               ...,;.      .........','. ..   ..    ..   ..       ..       ..              ..    
 ...      ...           ..       ..     ..    ..'c:................  ',..     ...          ....,'   ..   ..    ..      ..       ..              ..    
   ..       ..           ...     ..     ..   .';,.,,              ...,;.   ...    .............''..  ..  ..    ..       .        .               ..   
    ..       ..            ..     ..    ..  .,:,....'.............    .. ....  ....               ....'.  ..   ..       ..       ..              ..   
     ..       ...           ..     .    .. .;'.                  .........   ...       ...............,'. ..    ..      ..       ..               ..  
      ..        ..           ..    ..   ...;'...................      .,,  ...     .....                ...;'   ..      ..        ..               .. 
       ..        ..          ..    ..  .'...                  .......   ...'.    ...          .............''..  ..      ..        .               .. 
        ..        ..         ..    .. .,'                           ....':.     ..        .....               ...''.     ..        ..               ..
        ..         ..         ..  .. .,,....................            .'.    ..      ....           ........  ..,..     ..        ..               .
         ..        ..         ..  ....                     .......       ...  ..     ...        ........            ....  ..       
)" << endl;
			rd = rand() % 10;
			gotoxy(0, 36);
			printf("Digite um número: ");
			scanf_s("%d", &jg);
		} while ((c = getchar() != '\n' && c != EOF) || ((jg < 0) || (jg > 20)));
		if (jg >= rd)
		{
			rd = jg - rd;
		}
		else
		{
			rd = rd - jg;
		}
		switch (rd)
		{
		case 0: case 20:
			atq = atq * 0;
			break;
		case 1: case 19:
			atq = atq * 0.1;
			break;
		case 2: case 18:
			atq = atq * 0.2;
			break;
		case 3: case 17:
			atq = atq * 0.3;
			break;
		case 4: case 16:
			atq = atq * 0.4;
			break;
		case 5: case 15:
			atq = atq * 0.5;
			break;
		case 6: case 14:
			atq = atq * 0.6;
			break;
		case 7: case 13:
			atq = atq * 0.7;
			break;
		case 8: case 12:
			atq = atq * 0.8;
			break;
		case 9: case 11:
			atq = atq * 0.9;
			break;
		default:
			atq = atq * 1;
		}
		vdar = vdar - atq;
		if (vdar <= 0)
		{
			system("CLS");
			break;
		}
		printf("\nSeu ataque foi de: %.1f\n", atq);
		printf("Vez das aranhas....\n");
		gotoxy(0, 79);
		printf("Sua vida: %.1f", vd);
		printf("\t\t\tVida das aranhas: %.2f", vdar);
		gotoxy(0, 40);
		system("pause");
		rd = rand() % 10;
		jg = rand() % 10;
		if (jg >= rd)
		{
			rd = jg - rd;
		}
		else
		{
			rd = rd - jg;
		}
		atq = 30;
		switch (rd)
		{
		case 0: case 20:
			atq = atq * 0;
			break;
		case 1: case 19:
			atq = atq * 0.1;
			break;
		case 2: case 18:
			atq = atq * 0.2;
			break;
		case 3: case 17:
			atq = atq * 0.3;
			break;
		case 4: case 16:
			atq = atq * 0.4;
			break;
		case 5: case 15:
			atq = atq * 0.5;
			break;
		case 6: case 14:
			atq = atq * 0.6;
			break;
		case 7: case 13:
			atq = atq * 0.7;
			break;
		case 8: case 12:
			atq = atq * 0.8;
			break;
		case 9: case 11:
			atq = atq * 0.9;
			break;
		default:
			atq = atq * 1;
		}
		vd = vd - atq;
		gotoxy(0, 41);
		printf("Um ataque venenoso, dano de %.2f \n", atq);
		gotoxy(0, 79);
		printf("Sua vida: %.1f", vd);
		printf("\t\t\tVida da aranha: %.2f", vdar);
		if (vd <= 0)
		{
			system("CLS");
			break;
		}
		gotoxy(0, 42);
		system("pause");
	}
	if (vd <= 0)
	{
		printf("Você perdeu. \n");
		system("pause");
		return 2;
	}
	else
	{
		printf("Vitória!!! \n");
		printf("Você ganhou +15 de dano!!! \n");
		return 1;
	}
}

int batalhafinal(char nome[101], int dano)
{

	{
		int rd, ag, jg;
		float atq, vd, vdag;
		char c;
		c = 's';
		vd = 200;
		vdag = 500;
		srand(time(NULL));
		rd = 0;
		system("CLS");
		cout << R"(A batalha funciona da seguinte forma:
- Será gerado um número aleatório de 0 a 20, você deverá digitar um número de 0 a 20.
- A subtração dos dois números, deverá chegar próxima de 10, quanto mais perto, maior a porcentagem de dano, quanto mais longe, menor.
- O dano é calculado com a porcentagem tirada e o dano de sua arma, (se você não comprou nenuma arma, seu dano é 1.)" << endl;
		printf("\n");
		printf("-------------------------------------------------------------------------- \n");
		printf("DETERMINADO A VENCER VOCÊ GANHA UM BOOST EM SEUS ATAQUES [DANO SUBIU + 20] \n");
		printf("--------------------------------------------------------------------------");
		printf("\n");
		system("pause");
		system("CLS");
		while ((vd >= 0) && (vdag >= 0))
		{
			atq = dano + 20;
			do
			{
				gotoxy(0, 79);
				printf("Sua vida: %.1f", vd);
				printf("\t\t\tVida do chefe: %.2f", vdag);
				gotoxy(0, 36);
				cout << R"(                                           .;:cc;'.                                                                 
                                               .lk0XXX0x:.                                                               
                                               ,d0KXNNNNKx;.                                                             
                                               .ckKXXXXXXX0ko;.                                                          
                                                .lOKXK0KKXXNXKOc.                                                        
                                                 ,d0KK0kOKXNNNNKd;,,,'''.....                                            
                                                 .;xO0KOxOKKK0Okdoolccllcccc:,'..                                        
                                                  .;lxOOkkkkdllllodolcccccc:cll:;,'..                                    
                                                   .,lkOOkxdddx0KKKK0Okxdoccc::cccc::;'..                                
                                                    .,x0OkxdkkKWWWWWWWWNXKK0xl:;,,;;;;:::,..                             
                                                     .col:;ldxKWWWWWMMWWWWWWXOoc;,,,''',:::;;'.                          
                                                   ..,,''..,cxKNWWWWMWWWWWWWWNKkoc;,,'...',;:cc:'.                       
                                                  .','......'dKNWWWWWWWNNWWWWWWNKOxl;'....'',;:ll:;:cllc:;..             
                                                ..,c:..'...'lOXNNNNXKKXXXXXXNNNNNXKkl;''...',:lxO00KKKK0OOxl'            
                                                .:dxc..':cdkKXNNX0OkxolcldkkOOOO00OOxl:,''',cd00000000Okdodxl.           
                                    ...        .'lOkl::clldxOO00Oxdl;'....,;:::loooxkxdoc;;cdkOOOOkkxol:,';ld;           
                    ....:lolc;,,.   .;dxc,''''',cdxk0Ol;,... ........',:oxO0Oxoodxkkkxoc;,....,:lo;.          
                  .,loodkkxxxdddl' .':;.........,lxkOklc:.   ..........;cdO0Okxddxxxl:'......,:odo'           
                 .cdxxxxxxddl;',co:'....','.....'oxO0Okkxo:'.':c;'. ....:okOxocldxoc,..  ..',:dxd:.           
                'oxxddxdodxdocccoxxo,. ....  ...'oOOOOOkkkxl:;,;c;......:dOkdlllll;.     .';:ldxl.            
              .,oxkdlodddxxxkxolloodl'.   .......,okxxxxxkxdol;'......':dO0kxxdl;..      ..,lodl.             
              ,okkxdoooodkxdc;,''';clc;,..........lxxxkkxdollloolcc:::cloxO00Ol..         ..:ol,              
             .:xkxdoooodkkl'       ..',,'..      .,ldkkOkkxoc::cccclooxkkO0KXKx;..';,.......;c:.              
             .ckxdoooooxkd:.                    ...';:looxkOOkdc::ldxxO0KKXXNNNXKO0XXK0Okdol;'.               
             .ldollooloxko'.                    ......;cldxk0OxdxkOOkO0KKXXXXNNNNNNNK0xdoc,..                 
             'llcccllodkkl.             ...........'';codxxkkkO0KK00KXXXXXXXXXXKK0Oxoc;'..                    
            .;:::;:ccokKOl.               ..'',,;;:ccodxkOkkO000KKKKKXXXKKKKK000Okdc;'.                       
            ';,;;;;:cdOKk:.                .....'';;:loodxdodxkkO0KK000000OkkOOkdoc,..                        
           .,,,;;;:cok0Oo,.                 .....',,;::ccodoodxxkkOOOOOOOOOOOOkdoc,..                         
          ..,,,,,;;:lxkxc.                    ...,,;:clloodxkOOO0000O00000KK0kdl:'.                           
          ..,:,',;;:lxOx:.                     ..,:clodxxk0KXXXXXXXXXKKKKKK0Oko:'..                           
          .',;,.',,:oxkx:.                 ....';loxOKKXXNNNWWWWWWWWWNNNXXXK0kl,.......                       
          .'';'.',;:ldkkd:.        .    ....,:odxOKXNNWWWWWWWWWWWWWWWWWWWNNX0d:,'''......                     
          .',,,.',;;codxkxc.     ..''..',;codk0KXNNWWWWWWWWWWWWWWWWWWWWWWWWXKkdolc:;,,,'..                    
          .',,,'',;:cldxkkx, ...',,,'...';lxk0KNNNWWWWWWWWWWWWWWWWWWWWWWWWWNXXKKK0Oxdoc:,,...                 
          .',;;,,,;::cloxkd,.';:;;,'....,:ok00KXNNNNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNX0Oxolc:,'..              
          .,,;;,,;::::clodl;;::::;;''...';ok0KXNNNNNNWWWWNNWWWWWWWWWWWWWWWWWWWWWWWWNNXK0Okdlc:;;'...          
          .',;;;;;;;;;:clooolc::;;;;,'...':dk0KXNNNWWNWWWWNNNNNNNNNNNNNWWWWWWWNWWNNNNXXK0Oxol:;,;;;,..        
          .',;;;;;:;;;;:lodxxoc:::::;,,''',;ldOKXNNWWNNWNNNXXXXNNNXNNWWWNNNNNNWWNNNNNXXXXK0xo:,,:::::;'....   
           .,,;;;::;,;;;:odxkdlcc::;;,,,::;,,;cokKXNNNNNNNNNXXXXNNNNXNNNNNNXXNWWWNNXXXNNXKOxc;,;;:c:clccc:,.  
           .,,,,,;:;,,;;:ldxkxdl:::;,,,::;;,'..,lOXNNWWNNNNNNXXXNNNK00XXNNNNNWWWWNXXXNNXKkl;,,;::;;;;:::cll:,.
           .',,,,;;;,,;;:codxkkxl:;;;:::;:ccllldk0KXNNNNNNNNNXXXNNX0O0KKKXNWWWWNXKKXNNXKOo:;:cclc;,,;;:ccllool
)" << endl;
				rd = rand() % 10;
				gotoxy(0, 36);
				printf("Digite um número: ");
				scanf_s("%d", &jg);
			} while ((c = getchar() != '\n' && c != EOF) || ((jg < 0) || (jg > 20)));
			if (jg >= rd)
			{
				rd = jg - rd;
			}
			else
			{
				rd = rd - jg;
			}
			switch (rd)
			{
			case 0: case 20:
				atq = atq * 0;
				break;
			case 1: case 19:
				atq = atq * 0.1;
				break;
			case 2: case 18:
				atq = atq * 0.2;
				break;
			case 3: case 17:
				atq = atq * 0.3;
				break;
			case 4: case 16:
				atq = atq * 0.4;
				break;
			case 5: case 15:
				atq = atq * 0.5;
				break;
			case 6: case 14:
				atq = atq * 0.6;
				break;
			case 7: case 13:
				atq = atq * 0.7;
				break;
			case 8: case 12:
				atq = atq * 0.8;
				break;
			case 9: case 11:
				atq = atq * 0.9;
				break;
			default:
				atq = atq * 1;
			}
			vdag = vdag - atq;
			if (vdag <= 0)
			{
				system("CLS");
				break;
			}
			printf("\nSeu ataque foi de: %.1f\n", atq);
			printf("Vez do chefe da tribo....\n");
			gotoxy(0, 79);
			printf("Sua vida: %.1f", vd);
			printf("\t\t\tVida do chefe: %.2f", vdag);
			gotoxy(0, 40);
			system("pause");
			rd = rand() % 10;
			jg = rand() % 10;
			if (jg >= rd)
			{
				rd = jg - rd;
			}
			else
			{
				rd = rd - jg;
			}
			atq = 70;
			switch (rd)
			{
			case 0: case 20:
				atq = atq * 0;
				break;
			case 1: case 19:
				atq = atq * 0.1;
				break;
			case 2: case 18:
				atq = atq * 0.2;
				break;
			case 3: case 17:
				atq = atq * 0.3;
				break;
			case 4: case 16:
				atq = atq * 0.4;
				break;
			case 5: case 15:
				atq = atq * 0.5;
				break;
			case 6: case 14:
				atq = atq * 0.6;
				break;
			case 7: case 13:
				atq = atq * 0.7;
				break;
			case 8: case 12:
				atq = atq * 0.8;
				break;
			case 9: case 11:
				atq = atq * 0.9;
				break;
			default:
				atq = atq * 1;
			}
			vd = vd - atq;
			gotoxy(0, 41);
			printf("Um ataque perspicaz, dano de %.2f \n", atq);
			gotoxy(0, 79);
			printf("Sua vida: %.1f", vd);
			printf("\t\t\tVida do chefe: %.2f", vdag);
			if (vd <= 0)
			{
				system("CLS");
				break;
			}
			gotoxy(0, 42);
			system("pause");
		}
		if (vd <= 0)
		{
			printf("Você perdeu. \n");
			return 2;
		}
		else
		{
			printf("Vitória!!! \n");
			return 1;
		}
	}
}

int escadaria(char nome[101], int dano)
{
	int dc, start;
	char c;
	cout << R"(,----------------------,
|  Final da escadaria  |
'----------------------'
Finalmente, após horas, ou talvez dias descendo, os lémures chegam a final da imensa escadaria. No final dela, escritas antigas estão colocadas na parede. 
“O segredo!”, pensou )" << nome << endl;
	cout << R"(Você, como um bom jovem aprendiz, entende a leitura desta antiga língua. Porém, antes de começar a ler, você percebe que existe uma espécie de túnel/buraco na parede. 
Vozes ecoam por ele e, poucos segundos depois, a tribo Chimichunga aparece por este escorregador. O chefe da tribo diz: “Enganamos vocês! Não existe segredo nenhum! 
Agora vocês estão aqui, presos com a gente e morrerão. Em seguida iremos comer a carne de vocês. Sim, somos lémures canibais!”.)" << endl;
	system("Pause");
	dc = batalhafinal(nome, dano);

	if (dc == 1)
	{
		cout << R"( A tribo Chimichunga foi derrotada.Após vencê - los você começa a ler tudo que está nas paredes.
Porém, não existe nenhuma solução para o problema deles.Triste, )" << nome << R"( opta por voltar de mãos vazias.
Após dias subindo a escadaria de volta e chegando ao antigo alojamento dos Chimichunga, agora vazio, eles percebem muitas caixas cheias de mantimentos, roupas, provisões.
“Estamos salvos, com estes mantimentos teremos provisões por muitos anos!”.)" << endl;
		cout << R"(
 .lkkkd,   'dkxko.   .lkkkkkkkkkkx;    ,xkkkc.     'dkxko.                      ,xkkkc.     'dkxko.   .lkkkkkkxxkkkkko. ,dkkkc.     'dkxko.       
     .kXXXK:   ;0XXXk' .ld0XOl:::::dKXOo:. :KXXXx.     ;0XXXk'                      :KXXNx.     ;0XXXk'    ':::l0XXXKd:::,. :KXXX0dc.   ;0XXXk'       
     .xXXX0;   ;0XXXk' :KXXXx.     ;0XXXk' :KXXXx.     ;0XXXk'                      :KXXXx.     ;0XXXk'        .kXXX0;      :KXXXXXXxl, ;0XXXk'       
     .cxOXKo,,,oKXOxc. :KXXXx.     ;0XXXk. :KXXXd.     ;0XXXk'                      :KXXXx. .'. ;0XXXk'        .kXXX0;      :KXXXXXXXXk:oKXXXk'       
        :k0KKKKK0k:    :0KKXd.     ;OKKKx. :0KKKd.     ;OXKKx.                      :0KKXd';OKd':0KKKx.        .xKKXO;      :0KKKKO0KKKKKKXKXx.       
         .;OKKXO;.     :0XXXd.     ;OXXXx. :0KKKd.     ;OKXKx.                      :0KKXKOOKK0O0KKKXx.        .xKKKO,      :0XKKx';kKKKKXXXXx.       
          'kKKKk'      :0KKKd.     ;OKKXx. :0KKKd.     ;OKKKx.                      :0KKKKK0o:xKKKKKKx.        .xXXXO;      :0KKKd. .;xKKKKKKx.       
          ,OXXXO'      .,cOX0doooookKXx:'  .,cOX0doooookKXx:'                       :KXXXOc,. .;dKXXXk'   .:ooox0XXXKkooo:. :KXXXx.   .;dKXXXk'       
          .:lll:.        .;lllllllllll'      .;lllllllllll'                         .clll;      .clll:.   .;lllllllllllll:. .clll;.     .clll:.       
                                                                                                                                                      
                                                                                                                                                      
)" << endl;
		system("Pause");
		system("CLS");
		cout << R"(
_______________________________________________________
| DESENVOLVIDO POR: ISAIAS ROBERTO E RAFAEL ALEJANDRO. |
'------------------------------------------------------'
)" << endl;
		system("pause");
		return 0;
	}
	else
	{
		do
		{
			system("CLS");
			cout << R"(
                                                                                                                                  
                      ...                                   ... .               ...                      ...         ..                               
                   ........       ..'.      ...      .'.  ........            ........   ...     ..  .........   .........                            
                  ...             .....     .''.    .''.  ...                ..     ...   ..    ...  ...         ...    ...                           
                  ...            ... ...    .....  .....  .....             ...      ..   ...  ...   .....       ....  ....                           
                  ..    ....    .... ...    ............  ......            ...      ..    ... ...   .......     ........                             
                  ...   ....    .........   ... ..'. ...  ...               ...     ...    ......    ...         ...   ...                            
                   ...   ...   ...     ...  ...  ..  ...  ...                ...   ...      .''.      ...        ...    ..                            
                    .......    ..       ..  ..        ..  .........           .......        ..       ........   ..     ...                           
                                                                                                                                                      
)" << endl;
			printf("Deseja jogar novamente? (1 para sim /2 para não) \n");
			scanf_s("%d", &start);
		} while ((c = getchar() != '\n' && c != EOF) || (start != 1) && (start != 2));
		if (start == 1)
		{
			system("CLS");
			main();
		}
		else
		{
			return 0;
		}
	}

}

