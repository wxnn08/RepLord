#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector <int> sol[8];
const int MAX_L = 8;
const int MAX_C = 8;
int posicoes[MAX_C];

bool verifica(int lin, int col){
    for(int i=0; i<col; i++){
	if(lin == posicoes[i] || posicoes[i]-i==lin-col || posicoes[i]+i==lin+col)
	    return false;
    }
    return true;
}
int cont=0;
void backTrack(int col){
    
    if(col==MAX_C){
	for(int i=0; i<MAX_C; i++) 
	    sol[i].pb(posicoes[i]+1);
	cont++;
	return;
    }

    for(int i=0; i<MAX_L; i++){
	if(verifica(i, col)){
	    posicoes[col] = i;
	    backTrack(col+1);
	    posicoes[col] = -1;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    backTrack(0);

    int menorSoma=INF, soma=0;
    int comp[MAX_C], n=1;

    while(cin>>comp[0]){
	menorSoma=INF; 

	for(int i=1; i<MAX_C; i++)
	    cin >>comp[i];

	for(int i=0; i<cont; i++){
	    soma=0;
	    for(int j=0; j<MAX_C; j++){
		if((comp[j]-sol[j][i])!=0) soma++;
	    }
	    menorSoma=min(soma, menorSoma);
	}

	cout <<"Case " <<n <<": " <<menorSoma <<endl;
	n++;
    }

    return 0;
}

