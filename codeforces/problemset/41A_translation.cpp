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
 
int main(){
    ios_base::sync_with_stdio(false);

    string s, r;
	cin >>s >>r;
	
	bool ans = true;
	if(r.size() != s.size()) ans = false;
	int t = s.size();
	for(int i = 0; ans and i < t; i++) {
		if(s[i] != r[t-i-1]) ans = false;
	}
    
	cout <<(ans?"YES":"NO") <<endl;

    return 0;
}

