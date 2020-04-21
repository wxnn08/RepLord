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

int lis(string s) {
	
	vector<int> v;
	for(int i = 0; i < s.size(); i++) {
		int at = s[i] - 'A';
		vector<int>::iterator it = upper_bound(v.begin(), v.end(), at);
		if(it == v.end()) v.pb(at);
		else {
			if(*it == at) it++;
			*it = at;
		}
	}
	return v.size();
}

int main(){
    ios_base::sync_with_stdio(false);

    string s;
	cin >>s;

	cout <<lis(s) <<endl;
    
    return 0;
}

