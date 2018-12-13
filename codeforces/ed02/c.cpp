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
 
const int N = 30;
int alf[N];
int cont = 0;

int main(){
    ios_base::sync_with_stdio(false);

    string s;
	cin >>s;
	
	for(int i = 0; i < s.size(); i++)
		alf[s[i]-'a']++;

	int idMinImp = -1;

	/*
	if(s.size()%2 == 1) {
		for(int i = 0; i < N; i++) {
			if(alf[i]%2 == 1 and idMinImp == -1)
				idMinImp = i;
			if(alf[i]%2 == 1)
				idMinImp = min(idMinImp, alf[i]);
		}
		for(int i = 0; i < N; i++) {
			if(alf[i]%2 == 1){
				idMinImp = i;
				break;
			}
		}
	}
	*/

	for(int i = 0; i < N; i++) {
		if(i != idMinImp and alf[i]%2 == 1) {
			for(int j = N-1; j >= 0; j--) {
				if(j != idMinImp and j != i and alf[j]%2 == 1) {
					alf[j]--; alf[i]++;
					break;
				}
			}
		}
	}

	for(int i = 0; i < N; i++) {
		if(alf[i]%2 == 1) idMinImp = i;
		if(alf[i]%2 == 0) {
			for(int j = 0; j < alf[i]/2; j++) {
				cout <<char('a'+i);
			}
		}
	}
	if(idMinImp != -1)
		for(int i = 0; i < alf[idMinImp]; i++) {
			cout <<char('a'+idMinImp);
		}

	for(int i = N-1; i >= 0; i--) {
		if(alf[i]%2 == 0) {
			for(int j = 0; j < alf[i]/2; j++) {
				cout <<char('a'+i);
			}
		}
	}
	cout <<endl;
    return 0;
}

