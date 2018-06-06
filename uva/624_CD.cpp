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
 
vector <int> cd, faixas, playlist;
int n, q;
int sumMax=0;
void backtrack (int i, int sum){

    if(sum>sumMax){
	sumMax=sum;
	playlist=faixas;
    }
    
    fori(j,i,cd.size()){
	if(sum+cd[j]<=n){
	    faixas.pb(cd[j]);
	    backtrack(j+1,sum+cd[j]);
	    faixas.pop_back(); 
	}
    }

    return;
}

int main(){
    
    while(cin>>n){
	sumMax=0;
	cd.clear();
	faixas.clear();
	playlist.clear();

	cin >>q;
	int tam;
	fori(i, 0, q){
	    cin >>tam;
	    cd.pb(tam);
	}
	
	backtrack(0, 0);
	fori(i, 0, playlist.size()){
	    cout <<playlist[i] <<' ';
	}
	cout <<"sum:" <<sumMax <<endl;
    }
    
    return 0;
}

