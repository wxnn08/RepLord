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

    map<int, int> comp;
	int c, n;
	cin >>c >>n;
	for(int i = 0; i < c; i++) {
		int p, v; 
		cin >>p >>v;
		if((comp[p] != 0 and comp[p] < v) or comp[p] == 0)
			comp[p] = v;
	}
	map<int, int> net;
	for(int i = 0; i < n; i++) {
		int p, v; 
		cin >>p >>v;
		if((net[p] != 0 and net[p] < v) or net[p] == 0)
			net[p] = v;

	}
    map<int, int>::iterator it;
	map<int, int> ans;
	for(it = net.begin(); it != net.end(); it++) {
		if(it->sec > comp[it->fi]) 
			ans[it->fi] = it->sec;
	}

	for(it = ans.begin(); it != ans.end(); it++)
		cout <<it->fi <<' ' <<it->sec <<endl;

    return 0;
}

