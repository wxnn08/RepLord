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

    int n;
	cin >>n;
	pair<int, string> s(0, ""), q(0, "");

    for(int i = 0; i < n; i++) {
		string t; cin >>t;
		if(t == s.sec) s.fi++;
		else if(t == q.sec) q.fi++;
		else if(s.sec == "") s = mk(1, t);
		else q = mk(1, t);
	}

	cout <<(s > q? s.sec : q.sec) <<endl;
    return 0;
}

