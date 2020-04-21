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

char div(string s, int n) {
	ll sum = 0, mod = 1;
	int tam = s.size();
	for(int i = 0; i < s.size(); i++) {
		int t = s[tam-1-i] - '0';
		mod %= n;
		sum += (t * mod);
		mod *= 10;
	}
	if(sum%n == 0) return 'S';
	return 'N';
}

int main(){
    ios_base::sync_with_stdio(false);

    string s;
	cin >>s;
	//cout <<div(s, 2) <<endl;
	//cout <<div(s, 3) <<endl;
	//cout <<div(s, 5) <<endl;
	//cout <<div(s, 4) <<endl;
	//cout <<div(s, 9) <<endl;
	cout <<div(s, 11) <<endl;
	//cout <<div(s, 25) <<endl;

    return 0;
}

