int main(){
    ios_base::sync_with_stdio(false);

	int n; cin >> n;

	vector<ll> a (n, 0);
	vector<ll> b;

	fori(i,0,n/2) {
		ll tmp; cin >> tmp;
		b.pb(tmp);
	}

	ll antL = 0, antR = b[0];
	fori(i,0,n/2) {
		a[i] = max(antL, b[i] - antR);
		a[n-i-1] = b[i] - a[i];
		antL = a[i];
		antR = a[n-i-1];
	}

	fori(i,0,n) {
		cout << a[i];
		if (i < (n-1)) cout << " ";
	}
	cout << endl;

	return 0;
}
