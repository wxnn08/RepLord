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

int m[4][3];
int m2[4][3];

int main(){
    ios_base::sync_with_stdio(false);
	
	map<char, int> ma;
	ma['S'] = 0;
	ma['M'] = 1;
	ma['L'] = 2;
    int n; cin >>n;
	for(int i = 0; i < n; i++) {
		string s; cin >>s;
		int nx = s.size()-1;
		m[nx][ma[s[nx]]]++;
	}
	
	for(int i = 0; i < n; i++) {
		string s; cin >>s;
		int nx = s.size()-1;
		m2[nx][ma[s[nx]]]++;
	}
	
	int ans = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			m2[i][j] = m2[i][j] - m[i][j];
			if(m2[i][j] != 0) ans+=abs(m2[i][j]);
		}
	}
	
	cout <<ans/2 <<endl;
/*
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			cout <<m[i][j] <<' ';
		}
		cout <<endl;
	}
*/
    
    return 0;
}

