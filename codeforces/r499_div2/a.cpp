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

int n, k;
string s;
string t;

int points() {
	int ans = 0;
	for(int i = 0; i < t.size(); i++) {
		ans += ((int)(t[i]-'a')+1);
	}
	return ans;
}

int solve(int pos, int cont) {
	if(cont == k) {
		return points();
	}
	if(pos >= n)
		return INF;
	
	int L = INF;
	if(s[pos] - t[t.size()-1] > 1) {
		t += s[pos];
		L = solve(pos+1, cont+1);
		t.pop_back();
	}
	
	int R = solve(pos+1, cont);

	return min(L, R);
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n >>k;
	cin >>s;
	sort(s.begin(), s.end());
	int ans = solve(0, 0);
	cout <<(ans == INF?-1:ans) <<endl;
    
    return 0;
}

