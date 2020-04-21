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

map<string, ll> posSca = {{"Do", 0b110101011010}, {"Do#", 0b011010101101},
{"Re", 0b101101010110}, {"Re#", 0b010110101011}, {"Mi", 0b101011010101},
{"Fa", 0b110101101010}, {"Fa#", 0b011010110101}, {"Sol", 0b101101011010},
{"Sol#", 0b010110101101}, {"La", 0b101011010110}, {"La#", 0b010101101011},
{"Si", 0b101010110101}};

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	ll mask = (1 << 12) - 1, cnt = 1;
	for (int i = 0;i < n;i++) {
		cin >> s;
		ll x = posSca[s];
		mask &= x;
		if (!mask) cnt++, mask = x;
	}
	cout << cnt << endl;
	
	return 0;
}

