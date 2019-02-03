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
 
int main(){
    ios_base::sync_with_stdio(false);

	int n, k;
	while(cin >>n) {
		cin >>k;
		int sum = 0;
		priority_queue<int, vector<int>, greater<int> > pq;
		for(int i = 0; i < n; i++) {
			int v; cin >>v;
			sum += v;
			if(i > 0 and (i+1)%(k+1) == 0) {
				pq.push(v);
			} else if(!pq.empty() and v > pq.top()) {
				pq.pop();
				pq.push(v);
			}
		}

		int free = 0;
		while(!pq.empty()) {
			free += pq.top();
			pq.pop();
		}
		cout <<sum-free <<endl;
	}

    return 0;
}

