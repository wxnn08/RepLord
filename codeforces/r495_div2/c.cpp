#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
bool visit[N];
ll v[N], ac[N];

int main(){
	ios_base::sync_with_stdio(false);
	
	int n; cin >>n;
	for(int i = 0; i < n; i++)
		cin >>v[i];
	
	for(int i = n-1; i >= 0; i--) {
		if(!visit[v[i]]) {
			visit[v[i]] = 1;
			ac[i] = ac[i+1]+1;
		}
		else 
			ac[i] = ac[i+1];
	}

	memset(visit, 0, sizeof visit);
	ll ans = 0;
	for(int i = 0; i < n-1; i++) {
		if(!visit[v[i]]) {
			visit[v[i]] = 1;
			ans += ac[i+1];
		}
	}
	
	cout <<ans <<endl;
	return 0;
}

