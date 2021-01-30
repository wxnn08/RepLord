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

vector<int> pos;
pair<int,int> dis[55];
int n;

bool ordena(pair<int,int> a, pair<int,int> b){
	if(a.sec<=1) return false;
	else if(b.sec<=1) return true;
	if(a.sec<b.sec) return true;
	return false;
}

void calcDist(){
	memset(dis, 0, sizeof(dis));
	for(int i=0; i<n*2; i++){
		int u = pos[i];
		if(dis[u].sec==0) dis[u]= mk(i,i);
		else dis[u]=mk(dis[u].fi, i-dis[u].sec);
	}
	sort(dis, dis+50, ordena);
}

int main(){
    ios_base::sync_with_stdio(false);
		
	memset(dis, 0, sizeof(dis));
	cin >>n;
	for(int i=0; i<n*2; i++){
		int u; cin >>u;
		pos.pb(u);
	}
	
	calcDist();
	for(int i=0; i<n; i++){
		cout <<dis[i].fi <<"->" <<dis[i].sec <<endl;
	}

    return 0;
}

