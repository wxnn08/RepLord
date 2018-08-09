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

pair<char,char> p[3];
vector<char> v;
bool cmp(char a, char b){
	return a<b;
}
bool verifica(int pos){
	
	if(pos>=3) {
		vector<char> f = v;
		sort(f.begin(), f.end());
		if(f[0]=='b' && f[1]=='b' && f[2]=='o') return true;
		return false;
	}
		
	bool r = false;
	v.pb(p[pos].fi);
	r |= verifica(pos+1);
	v.pop_back();

	v.pb(p[pos].sec);
	r |= verifica(pos+1);
	v.pop_back();

	return r;
}

int main(){
    ios_base::sync_with_stdio(false);

    int TC;
	cin >>TC;
	
	while(TC--) {
		char c1,c2,c3,c4,c5,c6;
		cin >>c1 >>c2 >>c3 >>c4 >>c5 >>c6;
		p[0] = mk(c1,c4);
		p[1] = mk(c2,c5);
		p[2] = mk(c3,c6);
		if(verifica(0)) cout <<"yes" <<endl;
		else cout <<"no" <<endl;
	}
    return 0;
}

