// Sparse Table
//
// Based on Juvitus and tfg implementations
// 21b1d0
template <class T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
	void init(const vector<T> &v, const F &_f) {
		f = _f;
		n = (int) v.size();
		int l = 0;
		while ((1 << l) / 2 < n) {
			l++;
		}
		pw.assign(n + 1, -1);
		tab.assign(l, vector<T>(n));
		for (int i = 0; i < n; i++) {
			tab[0][i] = v[i];
			pw[i + 1] = pw[(i + 1) / 2] + 1;
		}
		for (int i = 0; i + 1 < l; i++) {
			for (int j = 0; j + (1 << i) < n; j++) {
				tab[i + 1][j] = f(tab[i][j], tab[i][j + (1 << i)]);
			}
		}
	}

	T query(int l, int r) {
		int k = pw[r - l];
		return f(tab[k][l], tab[k][r - (1 << k)]);
	}

private:
	F f;
	int n;
	vector<int> pw;
	vector<vector<T>> tab;
};