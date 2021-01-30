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

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main(){
    ios_base::sync_with_stdio(false);
	
	const int N = 1e6 + 5;
	int v[N], n;
	cin >>n;
	memset(v, 0, sizeof v);

	for(int i = 2; i <= n; i++) {
		if(v[i] == 0) 
			for(int j = i+i; j <= n; j += i) v[j] = i;
		v[i] = i-v[i]+1;
	}
	int ans = INF;
	for(int i = v[n]; i <= n; i++) 
		ans = min(v[i], ans);
	
	cout <<ans <<endl;
}	

