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

const int N = 205;
bool visit[N][N];
int m[N][N];
int h, l;
int tc = 0;

int dfs(int i, int j){
	visit[i][j] = true;
	int val = 1;
	if(i-1>=0 && !visit[i-1][j] && m[i-1][j]==m[i][j]) val += dfs(i-1,j);
	if(j-1>=0 && !visit[i][j-1] &&m[i][j-1]==m[i][j]) val += dfs(i,j-1);
	if(i+1<h && !visit[i+1][j] &&m[i+1][j]==m[i][j]) val += dfs(i+1,j);
	if(j+1<l && !visit[i][j+1] &&m[i][j+1]==m[i][j]) val += dfs(i,j+1);
	
	return val;
}

int main(){
    ios_base::sync_with_stdio(false);

	memset(m, -1, sizeof m);
	cin >>h >>l;
	fori(i,0,h){
		fori(j,0,l){
			cin >>m[i][j];
		}
	}
	memset(visit, 0, sizeof visit);
	int menor = INF;
	fori(i,0,h){
		fori(j,0,l){
			if(!visit[i][j]){
				menor = min(menor, dfs(i,j));
			}
		}
	}
	cout <<menor <<endl;

    return 0;
}

