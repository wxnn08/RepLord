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

ll solve(vector<pii> &v){
	sort(v.begin(), v.end(), greater<pii>());
	//for(auto i:v) cout <<i.fi <<' ';
	//cout <<endl;
	


	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, k;
	vector<pii> pos, neg;
	cin >>n >>k;
	fori(i,0,n){
		int v, u;
		cin >>v >>u;
		if(v>0) pos.eb(v,u);
		else neg.eb(-1*v,u);
	}
	
	cout <<solve(neg)+solve(pos) <<endl;
    
    return 0;
}

