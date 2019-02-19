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

double EPS = 1e-6;

double sig_mul(double a, double b) {
    a = norm(a);
    b = norm(b);
    return a*b;
}

class Point {
public:
	double x, y;

	Point () { }

	Point (double x, double y) {
		this->x = x;
		this->y = y;
	}

	bool operator == (const Point &b) const {
		return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
	}

	bool operator < (const Point &b) const {
		return ((x < b.x) or ((x == b.x) and y < b.y));
	}

	double operator ^ (const Point &b) const {
		return (this->x * b.y) - (this->y * b.x); 
	}

	double operator * (const Point &b) const {
		return (this->x * b.x) + (this->y * b.y);
	}

	/**/
	Point operator * (double k) const {
		return Point (x*k, y*k);
	}

	Point operator / (double k) const {
		if (k == 0.0) cout << "Class Point (operador /): divisao por zero" << endl;
		return Point (x/k, y/k);
	}
	
	/**/
	Point operator + (const Point &b) const {
		return Point (x + b.x, y + b.y);
	}

	/**/
	Point operator - (const Point &b) const {
		return Point (x - b.x, y - b.y);
	}

	static bool inter (const Point &a, const Point &b, const Point &c, const Point &d) {
        Point ab = b-a;
        Point ac = c-a;
        Point ad = d-a;

        Point cd = d-c;
        Point ca = a-c;
        Point cb = b-c;

        // a, b, c, d -> Colineares
        // Se estiver desconsiderando endpoints nao precisa, essa parte +- testada
		/*
        if(abs(ab^ac) < EPS and abs(ab^ad) < EPS) {
            Point bc = c-b;
            Point bd = d-b;
            Point da = a-d;
            Point db = b-d;
            if((ac*ad) < 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((bc*bd) < 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((ca*cb) < 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((da*db) < 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            return false;
        }
		*/

        // >= para desconsiderar endpoints
        if(sig_mul(ab^ac, ab^ad) >= 0.0)
            return false;

        // >= para desconsiderar endpoints
        if(sig_mul(cd^ca, cd^cb) >= 0.0)
            return false;

        return true;
	}
};

int main() {
    ios_base::sync_with_stdio(false);

    
	// intersecção
	double x1, y1, x2, y2;
	cout <<Point::inter(Point(0, 0), Point(2, 2), Point(0, 2), Point(2, 0)) <<endl;
	
    return 0;
}

