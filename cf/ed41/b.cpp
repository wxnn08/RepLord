#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    vector<pair<int, int> > v;
    //duracao palestra, duracao acordado
    int n, k;
    cin >>n >>k;
    
    pair<int, int> aux;
    for(int i=0; i<n; i++){
	cin >>aux.fi;
	v.pb(aux);
    }
    
    ll somaT=0;
    for(int i=0; i<n; i++){
	cin >>v[i].sec;
	somaT+=(v[i].sec*v[i].fi);
    }

    ll soma=0, maior=0;
    for(int i=0; i<k; i++){
	soma+=((1-v[i].sec)*v[i].fi);
    }

    maior = soma;
    for(int i=1; k+i<=n; i++){
	soma-=(1-v[i-1].sec)*v[i-1].fi;
	soma+=(1-v[k+i-1].sec)*v[k+i-1].fi;
	if(soma>maior) maior=soma;
    }

    cout <<somaT+maior <<endl;

    return 0;
}

