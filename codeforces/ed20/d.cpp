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

int n;
vector<string> ss;
vector<int> ts;

bool check(int t) {
	int lines = 0;
	int last = 0;
	while(last < ts[ts.size()-1]) {
		int x = upper_bound(ts.begin(), ts.end(), last+t)-ts.begin()-1;
		if(x < 0 or ts[x] == last) return false;
		last = ts[x];
		lines++;
	}
	return lines <= n;
}

int search() {
	int l = 0, r = 1e6;
	int ans = -1;
	while(l <= r) {
		int mid = (l+r)>>1;
		if(check(mid)) r = mid-1, ans = mid;
		else l = mid+1;
	}
	return ans;
}

int main() {
	
	cin >>n;
	
	string line;
	vector<string> words;
	
	getchar();
	getline(cin, line);
    
	string w = "";
	for(char at:line) {
		w += at;
		if(at == ' ') {
			words.pb(w);
			w = "";
		}
	}
	words.pb(w);

	for(string s:words) {
		string add = "";
		for(char at:s) {
			add += at;
			if(at == '-') {
				ss.pb(add);
				ts.pb(add.size());
				add = "";
			} 
		}
		ss.pb(add);
		ts.pb(add.size());
	}
    
	for(int i = 1; i < ts.size(); i++) {
		ts[i] += ts[i-1];
	}

	int width = search();
	cout <<width <<endl;

	/* Imprimindo resposta: */
	//int last = 0;
	//cout <<width <<endl;
	//for(int i = 0; i < ss.size(); i++) {
	//	if(ts[i]-last > width) {
	//		cout <<endl;
	//		last = ts[i-1];
	//	}
	//	cout <<ss[i];
	//}
	//cout <<endl;

	return 0;
}


