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

int n;
vector<int> v;

int lul(int last, int at){
	if(at>=n) return 0;
	if(v[last]>v[at]) return 0;
	
	int maior=1, val=1;
	if(last==at)
		for(int i=0; i<n; i+=val){
			val = lul(i, i+1)+1;
			maior = max(maior, val);
		}
	
	else return lul(last+1, at+1)+1;

	return maior;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >>n;
	fori(i, 0, n){
		int u; cin >>u;
		v.pb(u);
	}

	cout <<lul(0, 0) <<endl;
    
    return 0;
}

