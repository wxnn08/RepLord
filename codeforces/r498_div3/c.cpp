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
 
int main(){
    ios_base::sync_with_stdio(false);
	
	const int TAM = 2e5+5;
	int v[TAM];

	int n;
	cin >>n;
	
	fori(i,0,n) cin >>v[i];
	
	int ini=0, fim=n-1;
	ll res = 0, rLeft=0, rRight=0;

	while(ini<=fim && ini<n && fim>=0){
		
		if(rLeft<=rRight){
			rLeft+=v[ini++];
		}
		else {
			rRight+=v[fim--];
		}

		if(rLeft == rRight){
			res = rLeft;
		}
	}
	
	cout <<res <<endl;
    return 0;
}

