// Source: https://codeforces.com/blog/entry/61203?#comment-522213
namespace MO {
	constexpr int logn = 20;
	constexpr int maxn = 1 << logn;

	long long hilbertorder(int x, int y) {
		long long d = 0;
		for (int s = 1 << (logn - 1); s; s >>= 1) {
			bool rx = x & s, ry = y & s;
			d = ((((d << 2) | rx) * 3) ^ static_cast<int>(ry));
			if (!ry) {
				if (rx) {
					x = maxn - x;
					y = maxn - y;
				}
				swap(x, y);
			}
		}
		return d;
	}

	template <class T>
	void sortQueries(vector<T> &v) {
		for (auto &x : v)
			x.id = hilbertorder(x.l, x.r);
		sort(v.begin(), v.end());
	}

	struct Query {
		// maybe add new stuff here
		long long id;
		int l, r, idx;

		// Query(int _idx, int _l, int _r): idx(_idx), l(_l), r(_r) {}

		bool operator < (const Query &o) const {
			return id < o.id;
		}
	};
}

using namespace MO;