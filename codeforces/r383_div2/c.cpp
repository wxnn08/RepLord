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

const int N = 100 + 5;
bool visit[N];
bool v[N];
int g[N], n;

int maiorCiclo(int at) {
	int dist[N];
	memset(dist, INF, sizeof dist);
	int cont = 0;
	while(true) {
		if(g[at] == at) break;
		if(visit[at]) {
			return cont - dist[at];
		}
		dist[at] = cont;
		visit[at] = true;
		cont++;
		at = g[at];
	}
	return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n;
    for(int i = 1; i <= n; i++) 
		cin >>g[i];
	
	for(int i = 1; i <= n; i++)
		v[g[i]] = true;

	for(int i = 1; i <= n; i++)
		if(!v[i]) {
			cout <<-1 <<endl;
			return 0;
		}

	int ans = -1;
	for(int i = 1; i <= n; i++) {
		if(!visit[i]) {
			ans = max(maiorCiclo(i), ans);
		}
	}
	cout <<(ans==2?1:ans) <<endl;

    return 0;
}

