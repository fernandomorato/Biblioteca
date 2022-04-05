// Classic problems using Zfunction:
// - String Matching Problem
// - Number of Different Substrings in O(n^2)
// - Find the root of a String
// - Search with at most 1 mistake in O(n)

template <class T>
struct ZFunc {
	// z[i] = lenght of the longest common preffix of v[0, n) and v[i, n)
	vector<int> z;
	ZFunc(const T &v): z((int) v.size()) {
		int n = (int) v.size(), l = 0, r = 0;
		if (!z.empty()) z[0] = n;
		for (int i = 1; i < n; i++) {
			if (i <= r) z[i] = min(z[i - l], r - i + 1);
			while (i + z[i] < n && v[i + z[i]] == v[z[i]]) z[i]++;
			if (r < i + z[i] - 1) l = i, r = i + z[i] - 1;
		}
	}
};