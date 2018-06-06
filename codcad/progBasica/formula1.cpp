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
 
int gp[105][105];
int g, p; 
vector<pair<int,int> > score;

void pontua(int pos, int pontos){
	for(int i=0; i<g; i++){
		int u = gp[i][pos];
		score[u].sec += pontos;
	}
}

bool ordena(pair<int,int> a, pair<int,int> b){
	if(a.sec > b.sec) return true;;
	if(a.sec == b.sec && a.fi < b.fi) return true;
	return false;
}

void imprimeGanhadores(){
	int u = score[0].sec;
	for(int i=0; score[i].sec==u; i++){
		int v = score[i].fi+1;
		cout <<v <<' ';
	}
	cout <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	while(cin >>g >>p, g!=0 && p!=0){

		memset(gp,0,sizeof(gp));
		fori(i,0,g){
			fori(j,0,p){
				int u; cin >>u;
				gp[i][u-1]=j;
			}
		}

		int s; cin >>s;
		fori(i,0,s){
			score.clear();
			fori(k,0,p) score.pb(mk(k,0));
			int np; cin >>np;
			fori(j,0,np){
				int pontos; cin >>pontos;
				pontua(j, pontos);
			}
			sort(score.begin(), score.end(), ordena);
			imprimeGanhadores();
		}
	}
    
    return 0;
}

