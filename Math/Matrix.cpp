// It's preferable to declare global matrices
// based on: https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Math/Matrix.cpp
template <const int n, const int m, class T = Mint<>>
struct Matrix {
	T mat[n][m];

	Matrix(int d = 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				v[i][j] = T(0);
			}
			if (i < m)
				v[i][i] = T(d);
		}
	}

	template <int p>
	Matrix<n, p, T> operator * (const Matrix<m, p, T> &o) {
		Matrix<n, p, T> ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				for (int k = 0; k < m; k++) {
					ans.mat[i][j] = ans.mat[i][j] + mat[i][k] * o.mat[k][j];
				}
			}
		}
		return ans;
	}
};