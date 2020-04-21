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

    int n; cin >>n;
	int h, w, a, b;
	char c;
	cin >>c;
	cin >>a >>b;
	h = min(a, b);
	w = max(a, b);
	for(int i = 1; i < n; i++) {
		cin >>c;
		cin >>a >>b;
		if(c == '+') {
			h = max(min(a, b), h);
			w = max(max(a, b), w);
		}
		else {
			if((a >= h and b >= w) or (a >= w and b >= h))
				cout <<"YES" <<endl;
			else
				cout <<"NO" <<endl;
		}
	}
    return 0;
}

