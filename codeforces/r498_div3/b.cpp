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

//dificuldade, indice
vector<pair<int,int>> v;

bool cmp1(pair<int,int> a, pair<int,int> b){
	if(a.sec!=b.sec) return a.fi>b.fi;
	return a.sec<b.sec;
}

bool cmp2(pair<int,int> a, pair<int,int> b){
	return a.sec<b.sec;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, k;
	cin >>n >>k;

	fori(i,0,n){
		int u;
		cin >>u;
		v.pb(mk(u,i));
	}
    
	if(k!=1){
		//vector<pair<int,int>> v2 = v;
		sort(v.begin(), v.end(), cmp1);
		sort(v.begin(), v.begin()+k, cmp2);

		int res = 0;
		fori(i,0,k) res+=v[i].fi;
		cout <<res <<endl;
		
		for(int i=1; i<k; i++){
			if(i==1) cout <<v[i].sec <<' ';
			else cout <<v[i].sec-v[i-1].sec <<' ';
		}
		cout <<n-v[k-1].sec <<endl;
	}
	else {
		int res = -INF;
		for(auto i:v){
			res = max(res,i.fi);
		}
		cout <<res <<endl <<n <<endl;
	}
    return 0;
}

