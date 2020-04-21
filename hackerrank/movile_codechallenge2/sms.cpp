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

    set<string> s;
	int u; 
	cin >>u;

	fori(i,0,u){
		string num;
		cin >>num;
		s.insert(num);
	}

	int TC;
	cin >>TC;

	while(TC--){
		string num;
		cin >>num;
		if(s.count(num)) cout <<"N";
		cout <<"OK"<<endl;
	}
    
    return 0;
}

