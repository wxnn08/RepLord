/* Aí, você já parou pra pensar, por que que você vive?
 * O que é que te move?
 * Aquele momento que decodifica o segredo da sua alma
 * E de repente tudo começa a fazer sentido.
 * É um chamado legítimo que vem lá do íntimo 
 * É quando a poesia entra em sincronia com o ritmo 
 * E te faz pensar 
 * Se não fosse isso eu podia até respirar, mas vivo eu também não ia tá!
 */
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int, int, int> ti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e3 + 5;
int mat[N][N];
int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j, int n, int m) {
	return i >= 0 and j >= 0 and i < n and j < m;
}

int dij(int ini, int inj, int n, int m) {
	
	int dist[N][N];
	bool visit[N][N];
	priority_queue<ti, vector<ti>, greater<ti>> pq;
	memset(visit, 0, sizeof visit);
	memset(dist, INF, sizeof dist);

	dist[ini][inj] = mat[ini][inj];
	pq.emplace(dist[ini][inj], ini, inj);

	while(!pq.empty()) {
		int w, ati, atj;
		tie(w, ati, atj) = pq.top();
		pq.pop();
		if(visit[ati][atj]) continue;
		visit[ati][atj] = true;

		for(int i = 0; i < 4; i++) {
			int ii = ati+pos[i][0];
			int jj = atj+pos[i][1];
			if(valid(ii, jj, n, m) and dist[ii][jj] > w + mat[ii][jj]) {
				dist[ii][jj] = w + mat[ii][jj];
				pq.emplace(dist[ii][jj], ii, jj);
			}
		}
	}
	return dist[n-1][m-1];
}
 
int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int n, m;
		cin >>n >>m;
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++) 
				cin >>mat[i][j];

		cout <<dij(0, 0, n, m) <<endl;

	}
	
	return 0;
}

