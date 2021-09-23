template <typename T>
class FenwickTree {
public:
	void init(int _n) {
		n = _n;
		bit.assign(n + 1, 0);
	}

	void init(vector<T> &v) {
		n = (int) v.size();
		bit.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			if (i + (i & -i) <= n)
				bit[i + (i & -i)] += bit[i];
		}
	}

	void update(int i, T x) {
		for (; i <= n; i += i & -i)
			bit[i] += x;
	}

	T query(int i) {
		T ans = 0;
		for (; i > 0; i -= i & -i)
			ans += bit[i];
		return ans;
	}

private:
	int n;
	std::vector<T> bit;
};