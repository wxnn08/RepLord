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
const int N = 55;

//				s  h  d  c
int suits[4] = {0, 1, 2 ,3};
int mode, n;
int lis[N]; 
ii card[N];

bool cmp(ii a, ii b) {
	if(a.se != b.se) return suits[a.se] < suits[b.se];
	if((mode&(1<<a.se)) > 0) return a.fi > b.fi;
	return a.fi < b.fi;
}

int calc()  {  
    lis[0] = 1;    
	int ans = 1;
    for(int i = 1; i < n; i++) { 
        lis[i] = 1; 
        for(int j = 0; j < i; j++)
			if(cmp(card[j], card[i]) and lis[i] < lis[j]+1) {
                lis[i] = lis[j]+1;  
				ans = max(ans, lis[i]);
			}
    } 
    return ans; 
}  

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >>n;
	map<char, int> m;
	m['T'] = 10; m['J'] = 11; 
	m['Q'] = 12; m['K'] = 13; m['A'] = 14;
	m['s'] = 0; m['h'] = 1; 
	m['d'] = 2; m['c'] = 3;

	for(int i = 0; i < n; i++) {
		string s; cin >>s;
		if(s[0] >= '0' and s[0] <= '9') card[i].fi = s[0]-'0';
		else card[i].fi = m[s[0]];
		card[i].se = m[s[1]];
	}
	
	int ans = INF;
	do {
		for(mode = 0; mode < 16; mode++) {
			//sort(card, card+n, cmp);
			ans = min(ans, n-calc());
		}
	} while(next_permutation(suits, suits+4));
	
	cout <<ans <<endl;
	return 0;
}

