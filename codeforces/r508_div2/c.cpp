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


// A -> 0
// B -> 1

int main(){
    ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	vector<int> l1, l2;
	fori(i,0,n) {
		int u;
		cin >>u;
		l1.pb(u);
	}

	fori(i,0,n) {
		int u;
		cin >>u;
		l2.pb(u);
	}
    
	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end());

	ll qtdA = 0, qtdB = 0;
	bool turno = false;
	while(!l1.empty() or !l2.empty()){
		int maxL1 = 0, maxL2 = 0;
		if(!l1.empty()) {
			maxL1 = l1[l1.size()-1];
		}
		if(!l2.empty()) {
			maxL2 = l2[l2.size()-1];
		}
		if(!turno){
			if(maxL1>=maxL2){
				qtdA += (ll)maxL1;
				l1.pop_back();
			} else {
				l2.pop_back();
			}
		} else {
			if(maxL2>=maxL1){
				qtdB += maxL2;
				l2.pop_back();
			} else {
				l1.pop_back();
			}
		}
		turno = 1-turno;
	}
	
	cout <<qtdA-qtdB <<endl;

    return 0;
}

