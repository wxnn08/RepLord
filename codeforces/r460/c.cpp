#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int TAM = 2e3+5;
int main(){
    ios_base::sync_with_stdio(false);

    int n, m, k;
	cin >>n >>m >>k;
   
	char l[TAM][TAM];
	
	ll res = 0;
	

	fori(i,0,n){
		fori(j,0,m){
			cin >>l[i][j];
			if(l[i][j]=='.') res++;
		}
	}
	if(k!=1){
		res = 0;
		fori(i,0,n){
			int cont = 0;
			fori(j,0,m){
				if(l[i][j] == '*'){
					if(cont>=k) res += (cont-k)+1;
					cont = 0;
				}
				else cont++;
			}
			if(cont>=k) res += (cont-k)+1;
		}
		fori(j,0,m){
			int cont = 0;
			fori(i,0,n){
				if(l[i][j] == '*'){
					if(cont>=k) res += (cont-k)+1;
					cont = 0;
				}
				else cont++;
			}
			if(cont>=k) res += (cont-k)+1;
		}
	}

	cout <<res <<endl;

    return 0;
}

