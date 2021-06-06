#include<stdio.h>
#include<stdlib.h>
#include "lab.h"
#include <windows.h>
#include <conio.h>

	int cartas_usadas[35]; //cartas de todos os jogadores

	int CartaMeio = 0;
	int numcartas;	
	int turno=0;
	int pontuacaojogador=0;
	int pontuacaobot=0;
	int mesacabeca=0;
	
		int jogadores;
		char nome[4][10];
		int mao[4][7];
	
	
		void numerojogadores(char *nome, int *jogadores, int *botjogadores){
		
		int i = 0;
		
		drawRect(50, 05, 43, 05);	
		
		gotoxy(50,03);
		printf("Jogo de 0 a 5 jogadores");
		
		gotoxy(52,07);
		printf("Insira o numero de jogadores: ");
		scanf("%d", jogadores);
		fflush(stdin);
		
		
		
		while(*jogadores < 1 || *jogadores > 5)
		{																//Para valores impossíveis de jogadores
			system("cls");
			
			drawRect(50, 05, 43, 05);	
	
			gotoxy(50,03);
			printf("Jogo de 0 a 5 jogadores");
	
			gotoxy(52,07);
			printf("Insira o numero correto de jogadores: ");
			scanf("%d", jogadores);
			fflush(stdin);				
		}
				
		switch(*jogadores)
		{
			
			case 1:																	//Número de bots a gerar
				*botjogadores = 4;						
				system("cls");
				for(i = 0; i < 1; i++){
					printf("Insira o nome do jogador %d: ", i+1);
					gets(&nome[i]);
				}
				break;
			
			case 2:
				*botjogadores = 3;
				system("cls");
				for(i = 0; i < 2; i++){
					printf("Insira o nome do jogador %d: ", i+1);
					gets(&nome[i]);
				}
				break;
			
			case 3:
				*botjogadores = 2;
				system("cls");
				for(i = 0; i < 3; i++){
					printf("Insira o nome do jogador %d: ", i+1);
					gets(&nome[i]);
				}
				break;
			
			case 4:
				*botjogadores = 1;
				system("cls");
				for(i = 0; i < 4; i++){
					printf("Insira o nome do jogador %d: ", i+1);
					gets(&nome[i]);
				}
				break;
			
			case 5:
				system("cls");
				for(i = 0; i < 5; i++){
					printf("Insira o nome do jogador %d: ", i+1);
					gets(&nome[i]);
				}
				break;
		}
		
		system("cls");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

void drawrect(int x, int y, int width, int height)
{

	int i;
	gotoxy(x, y);
	printf("%c", 201);
	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}
	
	printf("%c", 187);
	gotoxy(x, height + y);
	printf("%c", 200);

	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 188);

	for (i = y + 1; i < height + y; i++)
	{
		gotoxy(x, i);
		printf("%c", 186);

		gotoxy(x + width, i);
		printf("%c", 186);
	} 
}



 int existeCarta(int numcartas ){ //verificar todas as cartas se ha repetidas
 	int u;
 	
 	for(u=0;u<35;u++){
		if(numcartas==cartas_usadas[u]){
				return 0;		
		}
 }
 		return 1;//nao ha repetidas
}



int cabecaboi(int a) 
{	
	if(a==55){
		return 7;	
	}
	if(a%11==0){
		return 6;
	}
	if(a%10==0){
		return 3;
	}
	if(a%5==0){
		return 2;
	}
	else{
		return 1;
	}
}

int contarcartas(int player) //contar as cartas da mao para aparecer ao pe do nome
{
	int contador=0;
	int o;
	for(o=0;o<7;o++){
			if(mao[player][o]!=500){
			contador++;
		}
	}
	return contador;
}



void OrdenarCards(int id) //ordenar as cartas de mao
	{
	int i,j,n = 7,aux;
	gotoxy(1,1);

			 	 
	for ( i = 0; i < n; i++)                    
	{
		for (j = 0; j < n; j++)            
		{
			if (mao[id][j] > mao[id][i])             
			{
				int tmp = mao[id][i];         
				mao[id][i] = mao[id][j];            
				mao[id][j] = tmp;             
			}  
		}
	}
		 
	}


void GerarCarta(int x, int y, int numero)
{
	int boi = cabecaboi(numero);
			drawrect(x,y,11,7);
			gotoxy (x+4,y+1);
			printf("%d ",numero);

			gotoxy(x+2,y+3);
			printf("Cabeças");
			gotoxy(x+2,y+4);
			printf("de boi:");
			gotoxy(x+3,y+5);
			printf("|%d| ",boi);
}


void opcoes() //opcoes de jogada numeros
{
		int i=0;
		int x=0;
	for(i=0;i<7;i++){
		if(i<contarcartas(0)){
	gotoxy(82+x,48);
	printf("|%d|",i+1);
	x=x+12;
}
	}		
}


int possojogar()
{
	int i;
	for(i=0;i<contarcartas(0);i++)
	{
		if(mao[0][i]>CartaMeio){
			return 1;
		}
	}
	return 0;
}


void startgame()
{
	
	int temp;	
	int i,o;
	temp = 0; 
		for(i=0;i<jogadores;i++){  //jogadores
			printf("Digite o(s) nome(s) do %d jogador\t\n",i+1);
			scanf("%s",&nome[i]);		 

			for(o=0;o<7;o++){ //as 7 cartas
	
				numcartas = rand() % 104+1;
				if(existeCarta(numcartas)==1){
					mao[i][o]=numcartas;
					cartas_usadas[temp] = numcartas;
					temp++; 
				}
				else{
					o--;	//se ouver a carta ele recua e volta a por outra carta nessa posiçao
				}
				}
			}
		
}



void gerarmesa()
{
	int i,o;
	int cartaescolha;
	char tempo;
	OrdenarCards(0); //ordenar as cartas do jogador
	OrdenarCards(1); //ordenas as cartas do bot
	
	drawrect(40,6,160,50); //quadrado grande
	
	
	drawrect(110,8,20,5); //quadrado bot/jogador
	gotoxy(111,9);
	printf("Bot_1");
	gotoxy(111,10);
	printf("%d Cartas", contarcartas(1));
	gotoxy(111,12);
	printf("%d Cabeças",pontuacaobot);
	
	drawrect(110,50,20,5); //quadrado jogador
	gotoxy(111,51);
	printf("%s",nome[0]);
	gotoxy(111,52);
	printf("%d Cartas", contarcartas(1));
	gotoxy(111,54);
	printf("%d Cabeças",pontuacaojogador);
	
	drawrect(50,18,20,5); //quadrado jogador bot/jogador
	gotoxy(51,19);
	printf("Bot_2");
	gotoxy(51,20);
	printf("%d Cartas", contarcartas(1));
	gotoxy(51,22);
	printf("%d Cabeças",pontuacaobot);
	
	
	drawrect(50,31,20,5); //quadrado jogador bot/jogador
	gotoxy(51,32);
	printf("Bot_3");
	gotoxy(51,33);
	printf("%d Cartas", contarcartas(1));
	gotoxy(51,35);
	printf("%d Cabeças",pontuacaobot);
	
	drawrect(171,23,20,5); //quadrado bot/jogador
	gotoxy(172,24);
	printf("Bot_4");
	gotoxy(172,25);
	printf("%d Cartas", contarcartas(1));
	gotoxy(172,27);
	printf("%d Cabeças",pontuacaobot);
	

	
	

	int x=66; 
	int y=40; //coordenadas das cartas
	
for(o=0;o<7;o++){ // gerar as 7 cartas
	if(mao[0][o]!=500){
	GerarCarta(x+12,y,mao[0][o]);
	x=x+12;
	}
}


	if(CartaMeio == 0) //carta do meio
	{
		do{
		numcartas = rand() % 104+1;
		if(existeCarta(numcartas)==1){ //carta do jogador ir para o meio
			CartaMeio = numcartas;	
			mesacabeca=cabecaboi(CartaMeio);
			break;					
		}
	}while(1);
	}
		
	GerarCarta(115,23,CartaMeio);

	gotoxy(113,32);
	printf("N de cabecas de boi: %d",mesacabeca);
	
	
//----------------------------------------------	


	if(turno==0){ //ser o jogador 1 a jogar
	
	gotoxy(20,20);
	printf("Carta a jogar:\t");
	opcoes(); //opcoes de jogar
	if(possojogar()==1){
		
		tempo=getch();
		
		if(isdigit(tempo) && tempo-48<=contarcartas(0) && tempo>0) 
		{
			cartaescolha = tempo-48;//para ser um numero
			if(mao[0][cartaescolha-1] > CartaMeio){ //cartaescolha-1=numero 1 corresponde a carta 0 da matriz
			gotoxy(20,21);
			
				CartaMeio=mao[0][cartaescolha-1];//Carta do meio e substituida
				mesacabeca=mesacabeca+cabecaboi(CartaMeio);
				mao[0][cartaescolha-1]=500;
				system("cls");
				turno=1;				
			}
		else{
				gotoxy(20,21);
				printf("ESCOLHA INVALIDA.ESCOLHA OUTRA!!!!");
		}
		}
		
}

else{
	
	tempo=getch();
	
	if(isdigit(tempo) && tempo-48<=contarcartas(0) && tempo>0) 
	{
		cartaescolha = tempo-48;//para ser um numero
		gotoxy(20,21);
		pontuacaojogador=pontuacaojogador+mesacabeca;
		mesacabeca=0;
		CartaMeio=mao[0][cartaescolha-1];//Carta do meio e substituida
		mesacabeca=mesacabeca+cabecaboi(CartaMeio);
		mao[0][cartaescolha-1]=500;
		system("cls");
		turno=1;
		
}
}
}
//---------------------------
//bot a jogar
else{
	int pode = 1;
	int o;
	for(o=0;o<7;o++){
		if(mao[1][o] != 500){
	}	
	}	
	
	for(i=0;i<contarcartas(1);i++){ //pecorrer as cartas dela para ver se pode jogar
	if(mao[1][i] > CartaMeio){	
	CartaMeio=mao[1][i];
	mesacabeca=mesacabeca+cabecaboi(CartaMeio);
	mao[1][i]=500;
	
	
	gotoxy(20,20);
	printf("O bot jogou");

	sleep(1);
	turno=0;
	pode = 0;
	
	break;

	}
	
}
	if(pode == 1){
		pontuacaobot=pontuacaobot+mesacabeca;
		mesacabeca=0;
		CartaMeio=mao[1][0];
			mesacabeca=mesacabeca+cabecaboi(mao[1][0]);
			mao[1][0]=500;
		
		
		gotoxy(20,20);
		printf("O bot jogou");
	
		sleep(1);
		turno=0;
		
}
}
}


int main(){
	int escolha;
	int jogadores=1;
	int comecar = 1;
	int escolha_correta=1;
	int i;
	
	srand(time(0)); //random atraves dos segundos do pc

	HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	
		do{
	
	drawrect(33,4,95,20);
	
    	gotoxy(40,7);
    printf("                                   __ ");
    	gotoxy(40,8);
    printf(" ___         _                _   |  |");
    	gotoxy(40,9);
    printf("|  _|   ___ |_| _____  _____ | |_ |  |");
    	gotoxy(40,10);
    printf("| . |  |   || ||     ||     ||  _||__|");
    	gotoxy(40,11);
    printf("|___|  |_|_||_||_|_|_||_|_|_||_|  |__|");
    	gotoxy(40,12);
    printf("                                      ");
    	gotoxy(40,13);
    
	
	printf("Escolha uma opção:\n");
	gotoxy(40,15);
	printf("1-Jogar uma Partida de Leva 6!\n");
	gotoxy(40,16);
	printf("2-Carregar uma partida a partir de ficheiro.\n");
	gotoxy(40,18);
	printf("3-Apresentar uma descrição do jogo na consola.\n");
	gotoxy(40,20);
	printf("4-Sair da aplicação.\n");
	gotoxy(40,22);
	
	printf("Escolha uma opção:\t");
	gotoxy(60,22);
		
	scanf("%d", &escolha);
	gotoxy(47,25);
	system("cls");


	switch(escolha){
		case 1: printf("Jogar uma Partida de Leva 6!\n");
		do{
			printf("Insira o número de jogadores:\t");
			scanf("%d",&jogadores);
				if(jogadores==1 || jogadores ==2 || jogadores ==3 || jogadores ==4 || jogadores ==5)
				{
					break;
				}
				else{
					printf("Numeros primitidos de 1 a 5\n");
				}
				
			
		}while(1);
			for(i=0;i<jogadores;i++){
			printf("Digite o(s) nome(s) do %d jogador\t\n",i+1);
			scanf("%s",&nome[i]);		
		}
			
	do{		
		if((contarcartas(1)==0 && contarcartas(0)==0) || comecar == 1 ){
			comecar=0;
			startgame();
			
		}
	gerarmesa();
		}while(pontuacaojogador<66 && pontuacaobot<66);
	
	system("cls");
	
		if(pontuacaojogador< pontuacaobot){
			printf("O JOGADOR VENCEDOR É %s", nome);
		}
		if(pontuacaojogador > pontuacaobot){
			printf("O JOGADOR VENCEDOR É O BOT");
		}
		if(pontuacaojogador == pontuacaobot){
			printf("O JOGO FICOU EMPATADO");
		}

		escolha_correta=1;
					break;
		case 2: printf("Carregar uma partida a partir de ficheiro");
		escolha_correta=0;
					break;
		case 3: printf("Apresentar uma descrição do jogo na consola");
		system("cls");
		
				printf("O jogo é realizado com um minimo de 1 jogador e um máximo de 5 jogadores;\n");
				printf("O jogo é consittuido por um baralho de 104 cartas, cada carta tendo um (x) de cabeças de boi;\n");
				printf("São distribuidas 7 cartas para cada jogador e uma é posta na mesa;\n");
				printf("Cada jogador deve jogar uma carta maior que a que esta na mesa;\n");
				printf("Não tendo menor carta o jogador leva todas as carta existentes na mesa e joga uma outra na mesa;\n");
				printf("Os turnos repetem-se até que algum dos jogadores atinja 66 cabeças de boi;\n");
				printf("O jogador no final do jogo com menos cabeças de boi ganha.\n\n\n\n");escolha_correta=0;
				system("pause");
				system("cls");
					break;
		case 4: printf("Sair da aplicação.");
			
				
					break;
		default:
				printf("Valor errado.Insira outro!\n"); //como meto para voltar para o menu?
				escolha_correta=0;
				
				break;
	}
	}while(escolha_correta == 0);
	
}
