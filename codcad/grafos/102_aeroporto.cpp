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

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.fi != b.fi) return a.fi>b.fi;
	return a.sec<b.sec;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m, cont = 1;
	pair<int,int> v[105];

	cin >>n >>m;

	while(n!=0 || m!=0){

		fori(i,0,n){
			v[i].fi = 0;
			v[i].sec = i;
		}

		fori(i, 0, m){
			int tmp;
			cin >>tmp;
			v[tmp-1].fi++;
			cin >>tmp;
			v[tmp-1].fi++;
		}

		cout <<"Teste " <<cont++ <<endl;

		sort(v, v+n, cmp);

		for(int i=0; v[i].fi == v[0].fi; i++){
			cout <<(v[i].sec+1) <<' ';
		}
		cout <<endl;

		cin >>n >>m;
	}
    
    return 0;
}

