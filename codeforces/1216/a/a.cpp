#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >>n;
	string s; cin >>s;

	int contA = 0, contB = 0;
	int ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'a') contA++;
		else contB++;
		if((i+1)%2 == 0 and contA != contB) {
			ans++;
			if(contA > contB) s[i] = 'b', contB++, contA--;
			else s[i] = 'a', contA++, contB--;
		}
	}
	cout <<ans <<endl;
	cout <<s <<endl;
	
	

	return 0;
}

