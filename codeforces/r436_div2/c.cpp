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
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int a, b, f, k;
	cin >>a >>b >>f >>k;

    if(b < f) {
		cout <<-1 <<endl;
		return 0;
	}

    bool lr = 0; // 0 -> esquerda->direita
				 // 1 -> direita->esquerda

	int comp = b, ans = 0, t = 0;
	if(k > 1) {
		b -= f;
		while(t < k-1) {
			if(lr == 0) {
				if(2*(a-f) > b) {
					ans++;
					b = comp; 
				}
				b -= 2*(a-f);
			} else {
				if(2*f > b) {
					ans++;
					b = comp;
				}
				b -= 2*f;
			}

			if(b < 0) {
				cout <<-1 <<endl;
				return 0;
			}

			lr = 1-lr;
			t++;
		}

		if(lr == 0) {
			if((a-f) > b)
				ans++;
		} else {
			if(f > b)
				ans++;
		}
	} else {
		if(b >= a) ans = 0;
		else if(b >= (a-f)) ans = 1;
		else ans = -1;
	}
	cout <<ans <<endl;
    return 0;
}

