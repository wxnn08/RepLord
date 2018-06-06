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

const int T = 1e5+5;
bool vis[T];
int n, m, k, s;
vector <int> g[T];

void bfs (int beg){

	vis[beg] = true;
	queue<int> q;
	q.push(beg);

	while(!q.empty()){
		
	}
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n >>m >>k >>s;
	int u, v;
	fori(i, 0, m){
		cin >>u >>v;
	}
    
    return 0;
}

