// remember to change BOUNDS accordingly!!!

Mint<> fat[MAXN], inv[MAXN];

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

// C(n) = n-th Catalan number - number of valid parenthesis sequences of size 2 * n
Mint<> C(int n) {
	return C(n + n, n) / (n + 1);
}

// C(n, k) = n choose k, number of ways to choose a set of k elements from a set of n elements
Mint<> C(int n, int k) {
	if (n < k || k < 0)
		return Mint<>(0);
	return fat[n] * inv[k] * inv[n - k];
}