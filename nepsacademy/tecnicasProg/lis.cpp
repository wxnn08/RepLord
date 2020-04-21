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

int lis(vector<int> &v){
	vector<int> p;

	for(int i=0; i<v.size(); i++){
		vector<int>::iterator it = lower_bound(p.begin(), p.end(), v[i]);
		if(it == p.end()) p.pb(v[i]);
		else *it = v[i];
	}
	return p.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    
	vector<int> v;
	int n;
	cin >>n;
	fori(i,0,n) {
		int u;
		cin >>u;
		v.pb(u);
	}
	cout <<lis(v) <<endl;

    return 0;
}

