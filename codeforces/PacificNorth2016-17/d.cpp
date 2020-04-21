#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int N = 1e5+5;
int n, k, r;
int a[N], v[N];

void add(int i, int qtd){
	if(qtd==0) {
		a[min(i+r,n)-1]=1;
		a[min(i+r,n)-2]=1;
	} else {
		if(a[min(i+r,n)-1]==0)
			a[min(i+r,n)-1]=1;
		else
			a[min(i+r,n)-2]=1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >>n >>k >>r;
	fori(i,0,k){
		int aux;
		cin >>aux;
		a[aux-1] = 1;
	}
	
	int res = 0;
	int cont = 0;
	for(int i=0; i<min(r,n); i++) cont += a[i];
	if(cont<2) {
		add(0,cont);
		res += 2-cont;
		cont += 2-cont;
	}

	for(int i=1; i<=n-r; i++){
		cont -= a[i-1];
		cont += a[i+r-1];

		if(cont<2) {
			add(i,cont);
			res += 2-cont;
			cont += 2-cont;
		}
	}
	cout <<res <<endl;
	return 0;
}
