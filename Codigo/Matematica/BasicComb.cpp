// Combinatoria
//
// fe3faa

// remember to change BOUNDS accordingly!!!

using T = Mint<>;

T fat[MAXN], inv[MAXN];

void setup() {
	fat[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fat[i] = fat[i - 1] * i;
	}
	inv[MAXN - 1] = fexp(fat[MAXN - 1], MOD - 2);
	for (int i = MAXN - 2; i >= 1; i--) {
		inv[i] = inv[i + 1] * (i + 1);
	}
}

// C(n, k) = n choose k, number of ways to choose a set of k elements from a set of n elements
T C(int n, int k) {
	if (n < k || k < 0)
		return T(0);
	return fat[n] * inv[k] * inv[n - k];
}

// C(n) = n-th Catalan number - number of valid parenthesis sequences of size 2 * n
T C(int n) {
	return C(2 * n, n) - C(2 * n, n + 1);
}