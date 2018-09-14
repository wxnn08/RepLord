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
const double EPS = 1e-5;

double norm(double x) {
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}

double sig_mul(double a, double b) {
	return norm(a)*norm(b);
}

struct Point {
	double x, y;
	
	Point(){}

	Point(int x, int y) {
		this->x = x; 
		this->y = y;
	}
	
	Point operator-(const Point &o) const {
		return Point(o.x - x, o.y - y);
	}

	double operator ^ (const Point &o) {
		return x*o.y - y*o.x;
	}

	bool operator < (const Point &o) const {
		return x < o.x or (x == o.x and y < o.y);
	}
	
	double orient(Point b) {
		return norm((*this)^b);
	}

	double len() {
		return sqrt((x*x)+(y*y));
	}

	double len2() {
		return (x*x)+(y*y);
	}

	static bool intersec(const Point &a, const Point &b, const Point &c, const Point &d) {
		Point ab = b-a;
		Point ac = c-a;
		Point ad = d-a;
		int s1 = sig_mul(ab^ac, ab^ad);
		if(s1 > 0.0){
			return false;
		}

		Point cd = d-c;
		Point ca = a-c;
		Point cb = b-c;
		int s2 = sig_mul(cd^ca, cd^cb);
		if(s2 > 0.0){
			return false;
		}
		
		if(s1 == 0 and s2 == 0) {
			if(ab.len() - ac.len() < EPS and ab.len() - ad.len() < EPS) 
				return false;
			if(cd.len() - ca.len() < EPS and cd.len() - cb.len() < EPS) 
				return false;
		}

		return true;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
	
	bool ans = false;
	
	Point p[4], q[4];
	fori(i,0,4) cin >>p[i].x >>p[i].y;
	fori(i,0,4) cin >>q[i].x >>q[i].y;
	
	sort(p, p+4);
	sort(q, q+4);

	fori(i,0,4){
		if((p[1]-p[0]).orient(q[i]-p[0]) != (p[3]-p[2]).orient(q[i]-p[2]))
		if((p[3]-p[1]).orient(q[i]-p[1]) != (p[2]-p[0]).orient(q[i]-p[0]))
			ans = true;
	}

	fori(i,0,4){
		if((q[1]-q[0]).orient(p[i]-q[0]) != (q[3]-q[2]).orient(p[i]-q[2]))
		if((q[3]-q[1]).orient(p[i]-q[1]) != (q[2]-q[0]).orient(p[i]-q[0])) 
			ans = true;
	}

	fori(i,0,4) fori(j,i+1,4)
	fori(k,0,4) fori(l,k+1,4) {
			ans |= Point::intersec(p[i],p[j],q[k],q[l]);
	}
	
	cout <<(ans?"YES":"NO") <<endl;

	return 0;
}
