#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
vector <int> fila;

void procuraRemove(int n){
    for(int i=0; i<fila.size(); i++){
	if(fila[i]==n){
	    fila.erase(fila.begin()+i);
	    return;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    //le n
    int n;
    cin >>n;
    
    //le fila 1-n
    int a;
	for(int i=0; i<n; i++){
	cin>>a;
	fila.pb(a);
    }
    
    //le m
    int m;
    cin >>m;

    //procura m em v
    int num;
    for(int i=0; i<m; i++){
	cin >>num;
	procuraRemove(num);
    }

    //imprime fila
    for(int i=0; i<fila.size(); i++){
	cout <<fila[i] <<' ';
    }
    cout <<endl;

    return 0;
}

