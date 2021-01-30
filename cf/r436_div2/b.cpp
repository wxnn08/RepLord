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

bool valid(char c) {
	return c >= 'a' and c <= 'z';
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int n; cin >>n;
    string s;
	cin >>s;
	
	string t;
	int i = 0;
	int maior = 0;

	while(i < s.size()) {
		bool isin[30];
		memset(isin, 0, sizeof isin);
		t = "";
		while(i < s.size() and valid(s[i])) {
			if(!isin[s[i]-'a']) {
				isin[s[i]-'a'] = true;
				t += s[i];
			}
			i++;
		}
		i++;
		int tam = t.size();
		maior = max(maior, tam);
	}

	cout <<maior <<endl;

    return 0;
}

