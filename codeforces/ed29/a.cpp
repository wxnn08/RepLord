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
 
int main(){
    ios_base::sync_with_stdio(false);

		string s;
		cin >>s;
		bool ans = true, can = true;
		string t = "";

		bool b = true;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != '0') b = false;
			if(b and s[i] == '0') continue;
			if(!b) t += s[i];
		}

		int ini = 0, fim = t.size()-1;
		while(fim > ini and t[fim] == '0')
			fim--;
		for(int i = ini; i < fim and ans; i++) {
			if(t[i] != t[fim-i]) ans = false;
		}

		cout <<(ans?"YES":"NO") <<endl;
    
    return 0;
}
