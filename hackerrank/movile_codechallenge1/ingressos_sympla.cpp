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
 
vector<pair<int,int>> v;
int busca(int ini, int fim, int x){
	int meio = (ini+fim)/2;

	if(ini>fim) return -1;
	if(x == v[meio].fi) return v[meio].sec;
	if(x < v[meio].fi) return busca(ini, meio-1, x);
	if(x > v[meio].fi) return busca(meio+1, fim, x);
	
	return -1;
}

int main(){
    ios_base::sync_with_stdio(false);

    int TC;
	cin >>TC;

	while(TC--){
		int d, n;
		cin >>d >>n;
		v.clear();

		fori(i,0,n){
			int aux;
			cin >>aux;
			v.pb(mk(aux,i));
		}

		sort(v.begin(), v.end());
		
		bool vai = true;
		for(int i=0; i<n && vai; i++){
			if(d>=v[i].fi){
				int pos = busca(0, v.size()-1, d-v[i].fi);
				if(pos!=-1 && pos!=v[i].sec){
					cout <<min(v[i].sec+1,pos+1) <<' ' <<max(v[i].sec+1,pos+1) <<endl;
					
					vai = false;
				}
			}
		}
	}
    
    return 0;
}

