/*
	Author : ExploitNetworMx
	Version : 1.0.1
	Languaje : c++

*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>

#define UP 72
#define DOWN 80
#define RIGTH 77 
#define LEFTH 75
#define ESC 27
#define SPA 32

int body[200][2];
int tam = 5;
int dir = 3;
int vel = 120;
int pun = 0;

int o = 4; 
int n = 1;
int h = 1;
int x = 10, y = 12;
int a = 30, b = 15; 

char key; 

void gotoxy(int x, int y){ // method get position from the screen
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X= x;
	dwPos.Y= y;
	hCon= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon , dwPos);
}

void printSnake(){ // method print snake
	for(int i= 2; i< 78; i++){
		gotoxy(i,3); printf("%c", 205);
    	gotoxy(i,23); printf("%c", 205);
	}
	
	for(int i= 4; i< 23; i++){
		gotoxy(2,i); printf("%c", 186);
    	gotoxy(77,i); printf("%c", 186);
	}
	
	gotoxy(2,3); printf("%c", 201);
    gotoxy(2,23); printf("%c", 200);
    gotoxy(77,3); printf("%c", 187);
    gotoxy(77,23); printf("%c", 188);
	
}

void screenMenu(){ // method print screen menu from this the user
	for(int i= 2; i< 78; i++){
		gotoxy(i,3); printf("%c", 205);
    	gotoxy(i,23); printf("%c", 205);
	}
	
	for(int i= 4; i< 23; i++){
		gotoxy(2,i); printf("%c", 186);
    	gotoxy(77,i); printf("%c", 186);
	}
	
	gotoxy(2,3); printf("%c", 201);
    gotoxy(2,23); printf("%c", 200);
    gotoxy(77,3); printf("%c", 187);
    gotoxy(77,23); printf("%c", 188);
}

void savedPosition(){ // method saved position from this snake
	body[n][0] = x;
	body[n][1] = y;
	n++;
	if(n == tam) n= 1;
}

void printBody(){ // method print snake added food
	for(int i= 1; i< tam; i++){
		gotoxy(body[i][0], body[i][1]); printf("%c", 42);
	}
}

void deleteBody(){ // method deleting body
	gotoxy(body[n][0], body[n][1]); printf(" ");
}

void dirColition(){ // method direction from this snake to key
	if(kbhit()){
    		key = getch();
			switch(key){
				case UP:
    				if(dir!= 2)
    				dir= 1;
    				break;
    			case DOWN:
    				if(dir!= 1)
    				dir= 2;
    				break;
    			case RIGTH:
    				if(dir!= 4)
					dir= 3;
					break;
				case LEFTH:
					if(dir!= 3)
		       		dir= 4;
					break;
				}
}

void foodScore(){ // method add food to snake
	if(x == a && y == b){
		a = (rand()%70)+4;
		b = (rand()%15)+4;
		tam++;
		pun +=10;
		gotoxy(a, b); printf("%c", 46);
	}
}

bool gameOver(){ // lose the level
	if(y == 3 || y == 23 || x == 2 || x == 77 ) return false;
		for(int j = tam -1; j > 0; j--){
			if(body[j][0] == x && body[j][1] == y)
			return false;
	}
	return true;
}

void scoreLevel(){ // method add score to food consumable
	gotoxy(3, 1); printf("SCORE %d", pun);
	gotoxy(15, 1); printf("DIFICULTY %d", h);
}

void increaseSpeed(){ // method increment speed to snake
	if(pun == h*20){
		vel -= 10;
		h++;
	}
}

int main(){ // main method
	system("color 0F");
	printSnake();
	gotoxy(a, b); printf("%c", 46);
	while(key != ESC && gameOver()){
    	deleteBody();
    	savedPosition();
    	printBody();
    	dirColition();
    	dirColition();
    	foodScore();
    	scoreLevel();
    	increaseSpeed();
	
		if(dir == 1) y--;
		if(dir == 2) y++;
		if(dir == 3) x++;
		if(dir == 4) x--;
    	Sleep(vel);
	}
	system("cls>nul");
	exit(ESC);
	system("pause>nul");
	system("cls>nul");
}
