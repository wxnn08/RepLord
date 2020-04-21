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
vector <int> fazPrimo[20];
vector <int> caminho;
int percorrido[20], n;

bool ehPrimo (int num){
    if(num%2==0) return false;
    for(int i=3; i<=sqrt(num); i+=2){
	if(num%i==0) return false;
    }

    return true;
}

void dfs(int i, int cont){
    
    if(cont==n){
	if(ehPrimo(caminho[n-1]+1)){
	    for(int j=0; j<n; j++){
		cout <<caminho[j]; 
		if(j!=n-1) cout<<' ';
	    }
	    cout <<endl;
	}
	return;
    }

    for(int j=0; j<fazPrimo[i].size(); j++){
	if(percorrido[fazPrimo[i][j]]==0){
	    percorrido[fazPrimo[i][j]]=1;
	    caminho.pb(fazPrimo[i][j]);
	    dfs(fazPrimo[i][j], cont+1);
	    percorrido[fazPrimo[i][j]]=0;
	    caminho.pop_back();
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int TC=0;
    while(cin >>n){

	if(TC!=0) cout <<endl;
	TC++;
	cout <<"Case " <<TC <<":"<<endl;
	memset(percorrido, 0, sizeof(percorrido));
	caminho.clear();
	for(int i=0; i<=20; i++) fazPrimo[i].clear();

	for(int i=1; i<=n; i++){
	    for(int j=2; j<=n; j++){
		if(ehPrimo(i+j)) fazPrimo[i].pb(j);
	    }
	}
	
	caminho.pb(1);
	dfs(1,1);
    }
    return 0;
}

/*
    for(int i=1; i<=n; i++){
	cout <<i <<": ";
	for(int j=0; j<fazPrimo[i].size(); j++){
	    cout <<fazPrimo[i][j] <<' ';
	}
	cout <<endl;
    }
*/   
 
