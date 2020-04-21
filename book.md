# Extras

## Zobrist hashing

Hashing para conjuntos.

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

