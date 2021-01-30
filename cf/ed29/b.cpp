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
		
	int n;
	cin >>n;
	
	vector<int> v;
	for(int i = 0; i < 2*n; i++) {
		int t; cin >>t;
		v.pb(t);
	}
	
	sort(v.begin(), v.end());
	int ans = INF;
	for(int i = 0; i < 2*n; i++) {
		for(int j = 0; j < 2*n; j++) {
			if(i == j) continue;

			int a = 0, b = 0;
			int val = 0;
			while(a < 2*n and b < 2*n){
				while(a == i or a == j) {
					a++;
				}
				while(b == i or b == j or b == a) {
					b++;
				}
				if(a < 2*n and b < 2*n) {
					val += abs(v[a]-v[b]);
				}
				a+=2;
				b+=2;
			}
			ans = min(val, ans);
		}
	}
	cout <<ans <<endl;
    return 0;
}

