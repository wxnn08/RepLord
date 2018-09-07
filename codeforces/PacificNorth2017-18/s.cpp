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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5+5; 
int t[N];

int dp[N][2];
string s;
int solve(int at, bool cat){
	if(at>=s.size()) return 0;
	int &r = dp[at][cat];
	if(r != -1) return r;
	
	if(cat){
		int L = solve(at+1, cat)+t[at];
		if(abs(L)>0) return r = L;
		return 0;
	} else {
		int L = solve(at+1, true)+t[at];
		int R = solve(at+1, false);
		if(abs(L)>abs(R)) return r = L;
		return r = R;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
		
	cin >>s;
	fori(i,0,s.size()){
		if(s[i]=='B') t[i] = 1;
		else t[i] = -1;
	}
    memset(dp, -1, sizeof dp);

	int qtd = solve(0,0);
	cout <<qtd <<endl;
    return 0;
}

