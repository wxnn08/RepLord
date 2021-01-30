#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 

bool cmp (char a, char b) {
	if(a == '0') return false;
	return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	string s;
	cin >>s;
	
	int c1 = 0, c0 = 0, c2 = 0;
	string t = "";
	string one = "";
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != '1')
			t += s[i];
		else
			one += s[i];

		if(s[i] == '1')
			c1++;
		if(s[i] == '2')
			c2++;
		if(s[i] == '0')
			c0++;
	}
	
	// Vazia
	if(t.size() == 0)
		cout <<one <<endl;
	// Tem 0
	else if(c0 > 0 and c2 == 0) {
		t += one;
		cout <<t <<endl;
	}
	// Tem 2
	else if(c2 > 0 and c0 == 0) {
		one += t;
		cout <<one <<endl;
	}
	// Tem os 2
	else {
		string ans = "";
		bool aa = false;
		for(int i = 0; i < t.size(); i++) {
			if(aa) {
				ans += t[i];
				continue;
			}
			if(t[i] == '0') {
				ans += t[i];
			}
			else {
				for(int j = 0; j < c1; j++) {
					ans += '1';
				}
				aa = true;
				ans += t[i];
			}
		}
		cout <<ans <<endl;
	}

    return 0;
}

