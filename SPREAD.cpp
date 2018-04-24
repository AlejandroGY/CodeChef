#include <bits/stdc++.h>

class fenwick_tree {
public:
	fenwick_tree(long long n)
	: mem_(n + 1) {
	}

	void actualiza(long long i, long long v) {
		for (++i; i < mem_.size( ); i += (i & -i)) {
			mem_[i] += v;
		}
	}

	long long cuenta(long long i) {
		long long res = 0;
		for (i += 1; i != 0; i -= (i & -i)) {
			res += mem_[i];
		}
		return res;
	}

private:
	std::vector<long long> mem_;
};

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long long n, m, c;
	std::cin >> n >> m >> c;

	fenwick_tree arbol(n + 1);
	while (m--) {
		char op;
		std::cin >> op;

		if (op == 'S') {
			long long u, v, k;
			std::cin >> u >> v >> k;
			arbol.actualiza(u, k);
			arbol.actualiza(v + 1, -k);
		} else {
			long long p;
			std::cin >> p;
			std::cout << arbol.cuenta(p) + c << "\n";
		}
	}
}