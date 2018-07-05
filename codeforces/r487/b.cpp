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
 
int n, p;
const int N = 2e3+5;
int v[N];
string s;
bool valido = true;

int preenche(int pos){
	if(pos>=n) return 0;
	if(v[pos]!=-1) return v[pos];

	return v[pos]=1-preenche(pos+p);
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n >>p >>s;
	memset(v,0,sizeof v);

	fori(i,0,n){
		if(s[i]=='.') v[i]=-1;
		else{
			v[i]=s[i]-'0';
		}
	}

	for(int i=0; i<n && valido; i++){
		//se for um numero
		if(v[i]!=-1){
			if(i+p<n){
				//se for um ponto
				if(v[i+p]==-1) v[i+p]=1-v[i];
				//se for um número
				else if(v[i]==v[i+p]) valido = false;
			}
		}
		//se for um ponto
		else {
			preenche(i);
		}
	}

    fori(i,0,n-p)
		if(v[i]==v[i+p]) valido = false;

	if(valido)
		for(int i=0; i<n; i++)
			cout <<v[i];
	else cout <<"No";
	cout <<endl;
		

    return 0;
}

