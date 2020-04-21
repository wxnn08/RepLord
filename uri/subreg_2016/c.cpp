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

struct state {
	int v[2][4];
	state(){}
	
	void read(){
		fori(i,0,2)
			fori(j,0,4)
				cin >>v[i][j];
	}

	bool operator<(const state &b) const{
		fori(i,0,2)
			fori(j,0,4)
				if(v[i][j] != b.v[i][j]) 
					return v[i][j]<b.v[i][j];
		return false;
	}

	bool operator==(const state &b) const{
		if((*this)<b or b<(*this)) return false;
		return true;
	}

} beg, last;

int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

bool pode(int i, int j){
	return i>=0 and j>=0 and i<2 and j<4;
}

int go(){
	map<state, int> m;
	priority_queue<pair<int, state>, vector<pair<int, state> >, greater<pair<int,state> > > pq;
	m[beg] = 0;

	pq.emplace(0, beg);
	while(!pq.empty()){
		
		state at = pq.top().sec;
		int dist = pq.top().fi;
		pq.pop();
		
		if(at == last) 
			return dist;

		for(int i=0; i<2; i++){
			for(int j=0; j<4; j++){
				for(int k=0; k<4; k++){
					int ii = i+dir[k][0];
					int jj = j+dir[k][1];
					
					if(!pode(ii,jj)) continue;

					state next = at;
					swap(next.v[ii][jj], next.v[i][j]);

					int peso = next.v[ii][jj] + next.v[i][j];
					if(!m.count(next) or m[next]>peso+dist){
						m[next] = peso+dist;
						pq.emplace(peso+dist, next);
					}
				}
			}
		}
	}

	return INF;
}

 
int main(){
    ios_base::sync_with_stdio(false);

    beg.read();
    last.read();

	cout <<INF <<endl;
    cout <<go() <<endl;

    return 0;
}

