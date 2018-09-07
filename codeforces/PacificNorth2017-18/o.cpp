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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	char mat[40][40];
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			cin >> mat[i][j];
	
	set<char>ind;
	bool flag = true;
	for(int i = 0; i < n; i++) {
		if(!flag) break;
		ind.clear();
		for(int j = 0; j < n; j++) {
			ind.insert(mat[i][j]); 
		}
		if(ind.size() < n) {
			flag = false;
			break;
		}
	}
	if(flag) {
		for(int j = 0; j < n; j++) {
			if(!flag) break;
			ind.clear();
			for(int i = 0; i < n; i++) {
				ind.insert(mat[i][j]);
			}
			if(ind.size() < n) {
				flag = false;
				break;
			}
		}
	}
	if(!flag) { cout << "No" << endl; return 0;}
	
	for(int i = 1; i < n; i++) {
		if(mat[i-1][0] > mat[i][0]) { flag = false; break; }
		if(mat[0][i-1] > mat[0][i]) { flag = false; break; }
	}
	cout << (flag? "Reduced" : "Not Reduced") << endl;
				
    return 0;
}

