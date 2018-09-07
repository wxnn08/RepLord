#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
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
 
int main(){
    ios_base::sync_with_stdio(false);

    ll p1 = 0, p2 = 0;
	int antP1 = 0, antP2 = 0;
	int n;
	cin >>n;
	fori(i,0,n){
		int v;
		cin >>v;
		if(p1<p2){
			p1+=v;
			antP1 = v;
		}
		else {
			p2+=v;
			antP2 = v;
		}
	}

	ll t = max(p1,p2);
	ll dif = abs(p1-p2);
	
	bool res = 0;
	if(dif!=0) {
		if(p1>p2){
			p2 += min(p1-antP1, dif/2);
			p1 -= min(p1-antP1, dif/2);
		} else if(p2>p1){
			p1 += min(p2-antP2, dif/2);
			p2 -= min(p2-antP2, dif/2);
		}
	}
	cout <<min(p1,p2) <<endl;
    
    return 0;
}

