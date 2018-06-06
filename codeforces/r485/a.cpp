#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

	/*
		purple - 0 - Power
		green - 1 - Time
		blue - 2 - Space
		orange - 3 - Soul
		red - 4 - Reality
		yellow - 5 - Mind

	*/

	set <string> s;
	string c[6] = {"purple", "green", "blue", "orange", "red", "yellow"};
	string g[6] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};

	int n;
	cin >>n;
	fori(i, 0, n){
		string colo; cin >>colo;
		s.insert(colo);
	}
	
	vector<string> res;
	int cont=0;
	fori(i,0,6){
		if(!s.count(c[i])){
			res.pb(g[i]);
			cont++;
		}
	}

	cout <<cont <<endl;
	fori(i, 0, (int)res.size()){
		cout <<res[i] <<endl;
	}
    
    return 0;
}

