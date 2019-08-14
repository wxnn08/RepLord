#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);

	int b1, b2, p1, p2, p3, p4;
	cin >>b1 >>b2 >>p1 >>p2 >>p3 >>p4;

	if(p1+p3 <= b1 and max(p2,p4) <= b2) cout <<"YES" <<endl; 
	else if(p1+p3 <= b2 and max(p2,p4) <= b1) cout <<"YES" <<endl; 
	else if(p1+p4 <= b1 and max(p2,p3) <= b2) cout <<"YES" <<endl; 
	else if(p1+p4 <= b2 and max(p2,p3) <= b1) cout <<"YES" <<endl; 
	else if(p2+p3 <= b1 and max(p1,p4) <= b2) cout <<"YES" <<endl; 
	else if(p2+p3 <= b2 and max(p1,p4) <= b1) cout <<"YES" <<endl; 
	else if(p2+p4 <= b1 and max(p1,p3) <= b2) cout <<"YES" <<endl; 
	else if(p2+p4 <= b2 and max(p1,p3) <= b1) cout <<"YES" <<endl; 
	else cout <<"NO" <<endl;

	return 0;
}

