#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int N = 505;
int mi[N][N], mf[N][N];
vector<int> v[2*N], v2[2*N];

int main() {
    ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >>n >>m;

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			cin >>mi[i][j];

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			cin >>mf[i][j];

	for(int i = 0; i < 2*N; i++) {
		for(int j = 0; j < N; j++) {
			if(i-j >= n or j >= m or i-j < 0 or j < 0) continue;
			v[i].pb(mi[i-j][j]);
		}
		if(v[i].size() > 0) sort(v[i].begin(), v[i].end());
	}

	for(int i = 0; i < 2*N; i++) {
		for(int j = 0; j < N; j++) {
			if(i-j >= n or j >= m or i-j < 0 or j < 0) continue;
			v2[i].pb(mf[i-j][j]);
		}
		if(v2[i].size() > 0) sort(v2[i].begin(), v2[i].end());
	}
	
	for(int i = 0; i < 2*N; i++) {
		for(int j = 0; j < v[i].size(); j++) {
			if(v[i][j] != v2[i][j]) {
				cout <<"NO" <<endl;
				return 0;
			}
		}
	}

	cout <<"YES" <<endl;
    
    return 0;
}

