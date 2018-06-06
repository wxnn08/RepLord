#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int x=1, y=1;

bool ordena(int a, int b){
    return a/x>b/x;
}

int main(){
    ios_base::sync_with_stdio(false);

    //le n
    int n;
    cin >>n;
    
    vector<int> v;
    int aux;

    bool nextLine=false, erro=false, conf = true;

    for(int i=0; i<n && !erro; i++){
	cin >>aux;
	v.pb(aux);

	//se o valor lido nao for o seguinte nessa linha 
	if(i!=0 && abs(aux-v[i-1])>1){
	    //se nao existir uma distancia base
	    if(!nextLine){
		//se o valor lido for maior q o anterior, mas nao for pelo menos o dobro -> erro
		if(aux>v[i-1] && aux<(2*v[i-1])) erro = true;
		//se o valor lido for menor que o anterior, mas nao for menor ou igual a metade do anterior ->erro
		else if(aux<v[i-1] && aux>(v[i-1]/2)) erro = true;

		nextLine=true;
		x = abs(aux-v[i-1]);
	    }
	    else {
		// a dif entre os dois nao for a estabelecida 'x' 
		if(abs(aux-v[i-1]) != x) erro=true;
	    }

	}
	if(aux==v[i-1]) erro = true;
	if(nextLine && ceil((double)aux/x)!=ceil((double)v[i-1]/x) && abs(aux-v[i-1])==1) erro = true;
    }

    if(erro) cout <<"NO" <<endl;
    else{
	sort (v.begin(), v.end(), ordena);
	y=v[0]/x;
	if(v[0]%x!=0) y++;
	cout <<"YES" <<endl;
	cout <<y <<' ' <<x <<endl;
    }
    

    return 0;
}
