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

string soma(string s) {
	int ans = 0;
	fori(i, 0, s.size()) {
		ans += (s[i]-'0');
	}
	return to_string(ans);
}

int main(){
    ios_base::sync_with_stdio(false);

    string s;
	cin >>s;
	int cont = 0;
	while(s.size() > 1) {
		s = soma(s);
		cont++;
	}
	cout <<cont <<endl;
    
    return 0;
}

