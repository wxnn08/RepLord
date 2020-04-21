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

	string s;
	cin >>s;
	
	// abcdefg
	string ans = "";
	int i = 0;
	int tam = s.size();
	for(i = 0; i < tam-2; i++) {
		if(s[i] == 'W' and s[i+1] == 'U' and s[i+2] == 'B') {
			i += 2;
			if(ans.size() > 0 and ans[ans.size()-1] != ' ') ans += ' ';
		}
		else ans += s[i];
	}

	for(int j = i; j < tam; j++) ans += s[j];

	cout <<ans <<endl;
    
    return 0;
}

