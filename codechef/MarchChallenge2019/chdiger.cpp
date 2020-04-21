#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    int tc;
	scanf(" %d", &tc);
	
	while(tc--) {
		ll n; scanf(" %lld", &n);
		int d; scanf(" %d", &d);
		
		stack<int> s;
		int tam = 0;
		int ant = 10;
		while(n != 0) {
			int at = n%10;
			if(at <= ant) {
				s.push(at);
				ant = at;
			}
			n /= 10;
			tam++;
		}
		
		vector<int> v;
		while(!s.empty()) {
			v.pb(s.top());
			s.pop();
		}

		while(v.size() < tam) v.pb(d);
		
		for(int i = v.size()-1; i >= 0; i--) {
			if(v[i] >= d) v[i] = d;
			else break;
		}

		for(int at:v) cout <<at;
		cout <<endl;
	}
    
    return 0;
}

