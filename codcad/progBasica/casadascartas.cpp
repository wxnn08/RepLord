#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int m;

bool compara (ll a, ll b){
    if(a%m > b%m) return true;
    if(a%m < b%m) return false;
    if(a/m > b/m) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n >>m;
    
    int tam = n+5;
    ll prop[tam];
    for(int i=0; i<n; i++){
	cin >>prop[i];
    }
    sort(prop, prop+n, compara);

    for(int i=0; i<n; i++){
	cout <<prop[i] <<" ";
    }
    return 0;
}

