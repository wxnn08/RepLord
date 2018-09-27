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

double norm(double x){
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}

double sig_mul(double a, double b) {
	a = norm(a);
	b = norm(b);
	return a*b;
}

struct Point {
	double x, y;
	
	Point(){};
	Point(double x, double y){
		this->x = x;
		this->y = y;
	}

	Point operator - (const Point &o) const {
		return Point(x-o.x, y-o.y);
	}

	double operator ^ (const Point &o) const {
		return (double) x*o.y - y*o.x;
	}

	bool operator < (const Point &o) const {
		return x<o.x or (x==o.x and y<o.y);
	}
	
	double len() {
		return sqrt(x*x+y*y);
	}

	double len2() {
		return x*x+y*y;
	}
	
	static double ori (const Point &a, const Point &b, const Point &c) {
		Point ab = b-a;
		Point ac = c-a;
		return norm(ab^ac);
	}

	static bool inter (const Point &a, const Point &b, const Point &c, const Point &d) {
		// General cases
		Point ab = b-a;
		Point ac = c-a;
		Point ad = d-a;
		double s1 = sig_mul(ab^ac, ab^ad);
		if(s1 < 0.0) return true;

		Point cd = d-c;
		Point ca = a-c;
		Point cb = b-c;
		double s2 = sig_mul(cd^ca, cd^cb);
		if(s2 < 0.0) return true;
		
		//Special case: colinear points
		if(s1 == 0 and c.x <= max(a.x, b.x) and c.x >= min(a.x, b.x) and 
			c.y <= max(a.y, b.y) and c.y >= min(a.y, b.y)) return true;
		if(s1 == 0 and d.x <= max(a.x, b.x) and d.x >= min(a.x, b.x) and 
			d.y <= max(a.y, b.y) and d.y >= min(a.y, b.y)) return true;
		if(s2 == 0 and a.x <= max(c.x, d.x) and a.x >= min(c.x, d.x) and 
			a.y <= max(c.y, d.y) and a.y >= min(c.y, d.y)) return true;
		if(s2 == 0 and b.x <= max(c.x, d.x) and b.x >= min(c.x, d.x) and 
			b.y <= max(c.y, d.y) and b.y >= min(c.y, d.y)) return true;

		return false;
	}
};

int main(){
    ios_base::sync_with_stdio(false);

	double n, d;
	cin >>n >>d;

    Point A(0,d), C(n, n-d), B(n-d, n), D(d,0);
	int m;
	cin >>m;

	while(m--) {
		double x, y;
		cin >>x >>y;
		Point M(x,y);

		bool ans = false;
		if(Point::ori(A,B,M) != Point::ori(D,C,M) and Point::ori(B,C,M) != Point::ori(A,D,M)) 
			ans = true;

		cout <<(ans?"YES":"NO") <<endl;
	}

    return 0;
}

