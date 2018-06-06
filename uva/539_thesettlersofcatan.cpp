#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define for_(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n, m, x, y;
int percorrido[25][25];
vector <int> no[25];

int cMax=0;

void procuraMaior (int i, int cont){
    
    for(int j=0; j<no[i].size(); j++){
	if(percorrido[i][no[i][j]] == 0){
	    percorrido[i][no[i][j]] = 1;
	    percorrido[no[i][j]][i] = 1;
	    procuraMaior(no[i][j], cont+1);
	    percorrido[i][no[i][j]] = 0;
	    percorrido[no[i][j]][i] = 0;
	}
    }

    cMax = max(cont, cMax);
}

int main(){
    ios_base::sync_with_stdio(false);

    while(cin >>n >>m, n!=0 && m!=0){
	int x, y;
	for(int i=0; i<m; i++){
	    cin >>x >>y;
	    no[x].pb(y);
	    no[y].pb(x);
	}
	for(int i=0; i<n; i++){
	    memset(percorrido, 0, sizeof(percorrido));
	    procuraMaior(i, 0);
	}
	cout <<cMax <<endl;

	for(int i=0; i<n; i++)
	    no[i].clear();
	cMax=0;
    }
    
    return 0;
}

