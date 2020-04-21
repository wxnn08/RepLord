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
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	const int N = 40;
	int alf[N], qtd[N];
	memset(alf, 0, sizeof alf);
	alf['a'-'a'] = 0;
	alf['e'-'a'] = 1;
	alf['i'-'a'] = 2;
	alf['o'-'a'] = 3;
	alf['u'-'a'] = 4;

	int goal = 0;
	for(int i = 0; i < 5; i++) goal |= 1<<i;

    int tc;
	cin >>tc;
	while(tc--) {
		int n;
		cin >>n;
		memset(qtd, 0, sizeof qtd);
		while(n--) {
			string s;
			cin >>s;
			int mask = 0;
			for(int i = 0; i < s.size(); i++) mask |= (1<<alf[s[i]-'a']);
			qtd[mask]++;
		}

		int ans = 0;
		for(int i = 0; i < N; i++) {
			if(qtd[i] == 0) continue;
			for(int j = i+1; j < N; j++) {
				if(qtd[j] == 0) continue;
				int val = i|j;
				if(val == goal) {
					ans += qtd[i]*qtd[j];
				}
			}
		}
		cout <<ans <<endl;
	}
    
    return 0;
}

