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

const int N = 4;
vector<pair<ll ,ll>> v;
int A[N][N], B[N][N], visit[N][N];
ll pontA, pontB;

void winner(int a, int b) {
	if(a == b) return;
	if(a == 1 and b == 3) pontA++;
	else if(a == 2 and b == 1) pontA++;
	else if(a == 3 and b == 2) pontA++;
	else pontB++;
}

int main(){
    ios_base::sync_with_stdio(false);

	ll k;
	int ai, bi;
	cin >>k >>ai >>bi;

	for(int i = 1; i < N; i++)
		for(int j = 1; j < N; j++)
			cin >>A[i][j];

	for(int i = 1; i < N; i++)
		for(int j = 1; j < N; j++)
			cin >>B[i][j];
	
	int a = ai, b = bi;
	ll i = 1;
	while(visit[a][b] == 0 and i <= k) {
		visit[a][b] = i;
		winner(a, b);
		v.eb(pontA, pontB);
		i++;
		a = A[ai][bi];
		b = B[ai][bi];
		ai = a;
		bi = b;
	}
	for(auto i:v) cout <<i.fi <<' ' <<i.sec <<endl;
	
	cc(visit[a][b]);
	cc(v.size());

	pair<ll, ll> pont(v[i-1].fi - v[visit[a][b]-1].fi, v[i-1].sec - v[visit[a][b]-1].sec);
	ll rep = ((k-visit[a][b]) / (i - visit[a][b]));

	return 0;
}

