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

int norm(int x) {
	if(x > 0) return 1;
	if(x < 0) return -1;
	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);

    int x, y;
	cin >>x >>y;
	
	int tam = abs(x) + abs(y);
	vector<ii> ans;
	ans.pb(ii(norm(x)*tam, 0));
	ans.pb(ii(0, norm(y)*tam));
    
	sort(ans.begin(), ans.end());
	fori(i,0,2) {
		cout <<ans[i].fi <<' ' <<ans[i].sec <<' ';
	}
	cout <<endl;
    return 0;
}

