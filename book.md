# Strings

## KMP

```c++
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
```

# Extras

## Zobrist hashing

Hashing for sets.

```c++
class ZHash {
	int n;
	ll *id;
public:
	ZHash(int n) : n(n) {
		id = new ll[n];
		init_zobrist();
	}

	void init_zobrist() {
		mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
		for(int i = 0; i < n; i++) 
			id[i] = rng();
	}

	ll hash(int i) {
		return id[i];
	}
```

