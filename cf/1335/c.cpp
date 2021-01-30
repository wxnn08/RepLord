#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int maxTeamSize(int setSize, int qt) {
	int teamA = setSize;
	int teamB = qt;
	if(teamA > teamB) teamA--;
	else teamB--;
	return min(teamA, teamB);
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		set<int> dif;
		map<int, int> qt;

		int n; cin >>n;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			dif.insert(a);
			qt[a]++;
		}
		
		int ans = 0;
		for(auto curr : qt) 
			ans = max(ans, maxTeamSize(dif.size(), curr.se));
		cout <<ans <<endl;
	}

    return 0;
}

