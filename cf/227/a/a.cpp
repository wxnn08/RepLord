/* O nosso maior medo não é sermos inadequados.
O nosso maior medo é sermos infinitamente poderosos.
É a nossa própria luz, não a nossa escuridão, que nos amedronta.
Sermos pequenos não engrandece o mundo.
Não há nada de transcendente em sermos pequenos,
pois assim os outros não se sentirão inseguros ao nosso lado.
Todos estamos destinados a brilhar, como as crianças.
Não apenas alguns de nós, mas todos.
E, enquanto irradiamos a nossa admirável luz interior,
inconscientemente estamos a permitir aos outros fazer o mesmo.
E, quando nos libertarmos dos nossos próprios medos,
a nossa presença automaticamente libertará os medos dos outros.  */

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

struct Point {ll x, y;};

int getOrientation(Point a, Point b, Point c) {
	b = Point({b.x-a.x, b.y-a.y});
	c = Point({c.x-a.x, c.y-a.y});
	ll ori = b.x*c.y - b.y*c.x;
	if(ori > 0) return 1;
	if(ori < 0) return 2;
	return 0;
}
 
int main() {
	ios_base::sync_with_stdio(false);

	Point a, b, c;
	cin >>a.x >>a.y >>b.x >>b.y >>c.x >>c.y;

	int ori = getOrientation(a, b, c);
	if(ori == 0) cout <<"TOWARDS" <<endl;
	if(ori == 1) cout <<"LEFT" <<endl;
	if(ori == 2) cout <<"RIGHT" <<endl;
	
	return 0;
}

