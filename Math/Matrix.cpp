template<class T>
class Matrix {
public:
	Matrix(int l, int c) {
		n = l, m = c;
		mat.resize(n, vector<T>(m));
	}

	void init(int l, int c, T x = 0) {
		n = l, m = c;
		mat.assign(n, vector<T>(m, x));
	}

	void assing(int i, int j, T x) {
		assert(0 <= i && i < n && 0 <= j && j < m);
		mat[i][j] = x;
	}

	Matrix<T> operator * (const Matrix<T> &o) {
		assert(m == o.n);
		Matrix<T> ans(n, o.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < o.m; j++) {
				for (int k = 0; k < m; k++) {
					ans.mat[i][j] = ans.mat[i][j] + mat[i][k] * o.mat[k][j];
				}
			}
		}
		return ans;
	}
private:
	int n, m;
	vector<vector<T>> mat;
}