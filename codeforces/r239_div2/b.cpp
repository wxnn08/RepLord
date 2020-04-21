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

const int N = 30;
int q[N];
bool hav[N];

int main() {
	ios_base::sync_with_stdio(false);

	string s, v;
	cin >>s >>v;
	
	for(char at:s) {
		q[at-'a']++;
		hav[at-'a'] = true;
	}

	
	int ans = 0;
	for(char at:v) {
		if(q[at-'a'] > 0) {
			q[at-'a']--;
			ans++;
		} else {
			if(!hav[at-'a']) {
				cout <<-1 <<endl;
				return 0;
			}
		}
	}
	cout <<ans <<endl;

	return 0;
}

