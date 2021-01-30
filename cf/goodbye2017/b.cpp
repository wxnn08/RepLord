#include<bits/stdc++.h>
using namespace std;

/*
	0=esq
	1=dir
	2=cima
	3=baixo
*/

char m[55][55];
int l, c, xi, yi;
string s;


bool possivel(char esq, char dir, char cima, char baixo){
	
	//POS INICIAL
	int x=xi;
	int y=yi;

	//PERCORRE S E COMPARA NO MAPA
	for(int i=0; i<=s.length(); i++){
		

		if(i==s.length()) return 0; //SE ACABAR A STRING
		
		if(s[i]==esq){ //ESQUERDA
			x--;
		}
		else if(s[i]==dir){ //DIREITA
			x++;
		}
		else if(s[i]==cima){ //CIMA
			y--;
		}
		else if(s[i]==baixo){ //BAIXO
			y++;
		}
		
		if(y<0 || x<0 || y>=l || x>=c) return 0; //SAIR DA MATRIZ
		
		else{
			if(m[y][x]=='E') return 1; //SAIDA
			if(m[y][x]=='#') return 0; //PAREDE
		}
	}

}

int main(){
	
	int cont=0;
	//LINHAS COLUNAS
	cin >>l >>c;

	//MATRIZ ROBO
	for(int j=0; j<l; j++){
		for(int i=0; i<c; i++){
			cin >>m[j][i];
			if(m[j][i]=='S'){
				yi=j; //POS INICIAL
				xi=i;
			}
		}
	}
	
	cin >>s; //COMANDOS DO ROBO
	
	// VARIACOES:
	if(possivel('0','1','2','3')) cont ++;
	if(possivel('0','1','3','2')) cont ++;
	if(possivel('0','2','1','3')) cont ++;
	if(possivel('0','2','3','1')) cont ++;	
	if(possivel('0','3','1','2')) cont ++;
	if(possivel('0','3','2','1')) cont ++;
	if(possivel('1','0','2','3')) cont ++;
	if(possivel('1','0','3','2')) cont ++;
	if(possivel('1','2','0','3')) cont ++;	
	if(possivel('1','2','3','0')) cont ++;
	if(possivel('1','3','0','2')) cont ++;
	if(possivel('1','3','2','0')) cont ++;
	if(possivel('2','0','3','1')) cont ++;
	if(possivel('2','0','1','3')) cont ++;	
	if(possivel('2','1','0','3')) cont ++;
	if(possivel('2','1','3','0')) cont ++;
	if(possivel('2','3','0','1')) cont ++;
	if(possivel('2','3','1','0')) cont ++;
	if(possivel('3','0','1','2')) cont ++;	
	if(possivel('3','0','2','1')) cont ++;
	if(possivel('3','1','2','0')) cont ++;
	if(possivel('3','1','0','2')) cont ++;
	if(possivel('3','2','0','1')) cont ++;
	if(possivel('3','2','1','0')) cont ++;	

	cout <<cont;
return 0;
}
