// Union Find
//

class DSU {
public:
	void init(int n) {
		p.resize(n);
		std::iota(p.begin(), p.end(), 0);
		sz.assign(n, 1);
	}

	int getSize(int x) { return sz[x]; }

	int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

	bool sameSet(int a, int b) { return find(a) == find(b); }

	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a != b) {
			if (sz[a] > sz[b])
				std::swap(a, b);
			op.emplace_back(a, p[a]);
			os.emplace_back(b, sz[b]);
			p[a] = b;
			sz[b] += sz[a];
		}
	}

	void rollback() {
		assert(!op.empty() && !os.empty());
		p[op.back().first] = op.back().second;
		op.pop_back();
		sz[os.back().first] = os.back().second;
		os.pop_back();
	}

private:
	std::vector<int> p, sz;
	std::vector<std::pair<int, int>> op, os;
};