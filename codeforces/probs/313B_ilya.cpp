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
	
	const int N=1e5+5;
	int v[N];
	memset(v,0,sizeof(v));

	string s;
    getline(cin, s);

	for(int i=1; i<s.length(); i++){
		if(s[i]==s[i-1]){
			v[i]=v[i-1]+1;
		}
		else v[i]=v[i-1];
	}
	int n;
	cin >>n;
	while(n--){
		int a, b;
		cin >>a >>b;
		cout <<v[b-1]-v[a-1] <<endl;
	}
    
    return 0;
}

