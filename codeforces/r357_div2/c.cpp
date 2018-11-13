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

vector<pair<string, int>> ans;
priority_queue<int, vector<int>, greater<int>> pq;
string op[3] = {"insert", "getMin", "removeMin"};

int main(){
    ios_base::sync_with_stdio(false);
    
	int n;
	cin >>n;

	for(int i = 0; i < n; i++){
		string s; int v = 0;
		cin >>s ;
		if(s != op[2]) cin >>v;
		
		if(s == op[0]) {
			ans.eb(op[0], v);
			pq.push(v);
		}
		if(s == op[2]) {
			if(pq.empty()) 
				ans.eb(op[0], 1);
			else 
				pq.pop();

			ans.eb(op[2], 0);
		}
		if(s == op[1]) {
			if(pq.empty()) {
				pq.push(v);
				ans.eb(op[0], v);
			 else {
				int t = pq.top();
				if(t > v) {
					ans.eb(op[0], v);
					pq.push(v);
				}
				if(t < v) {
					while(!pq.empty() and pq.top() < v) {
						ans.eb(op[2], v);
						pq.pop();
					}
					if(pq.empty() or pq.top() > v) {
						ans.eb(op[0], v);
						pq.push(v);
					}
				}
			}
			ans.eb(op[1], v);
		}
	}

	cout <<ans.size() <<endl;
	for(int i = 0; i < ans.size(); i++) {
		cout <<ans[i].fi;
		if(ans[i].fi != op[2]) cout <<' ' <<ans[i].sec;
		cout <<endl;
	}

    return 0;
}

