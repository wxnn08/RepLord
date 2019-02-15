#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

    float a, b, c, d, e;
	scanf(" %f %f %f %f %f", &a, &b, &c, &d, &e);
	
	float sum = a+b+c+d+e;
	float menor = a, maior = a;
	if(b < menor) menor = b;
	if(c < menor) menor = c;
	if(d < menor) menor = d;
	if(e < menor) menor = e;

	if(b > maior) maior = b;
	if(c > maior) maior = c;
	if(d > maior) maior = d;
	if(e > maior) maior = e;

	printf("%.1f\n", sum-menor-maior);
    return 0;
}

