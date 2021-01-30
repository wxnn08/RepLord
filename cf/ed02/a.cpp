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

int cont = 0;
string split(string s) {
	string ans = "";
	for(int i = cont; i < s.size(); i++) {
		if(s[i] == ',' or s[i] == ';') {
			cont = i+1;
			return ans;
		}
		ans += s[i];
	}
	cont = s.size();
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	vector<string> v;

	string s;
	cin >>s;

	while(cont < s.size()) {
		v.pb(split(s));
	}
	if(s[s.size()-1] == ',' or s[s.size()-1] == ';') 
		v.pb("");
    
	vector<string> a, b;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].size() == 0) {
			b.pb(v[i]);
			continue;
		}
		char fi = '-';
		bool f = false;
		bool l = false;
		for(int j = 0; j < v[i].size(); j++) {
			if(v[i][j] >= '0' and v[i][j] <= '9' and !f) {
				f = true;
				fi = v[i][j];
			}
			else if(v[i][j] >= '0' and v[i][j] <= '9' and f) {
				if(fi == '0') 
					l = true;
			}
			else if(v[i][j] < '0' or v[i][j] > '9')
				l = true;
		}
		if(l) b.pb(v[i]);
		else a.pb(v[i]);
	}
	
	if(a.size() == 0) cout <<'-';
	else {
		cout <<"\"";
		for(int i = 0; i < a.size()-1; i++) 
			cout <<a[i] <<',';
		cout <<a[a.size()-1];
		cout <<"\"";
	}
	cout <<endl;
	if(b.size() == 0) cout <<'-';
	else {
		cout <<"\"";
		for(int i = 0; i < b.size()-1; i++) 
			cout <<b[i] <<',';
		cout <<b[b.size()-1];
		cout <<"\"";
	}
	cout <<endl;
    return 0;
}

