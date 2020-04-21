#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e6 + 5;
 
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);

	int b; cin >>b;
	ll score[N];
	set<int> books;
	for(int i = 0; i < b; i++) cin >>score[i];
	
	ll result = 0;
	int libQt; cin >>libQt;
	while(libQt--) {
		int idLib, bookQt;
		cin >>idLib >>bookQt;
		for(int i = 0; i < bookQt; i++) {
			ll a; cin >>a;
			books.insert(a);
		}
		for(auto at:books)
			result += score[at];
	}

	cout <<result <<endl;

    return 0;
}

