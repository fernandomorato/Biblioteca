// Linear Sieve of Eratosthenes
//
// Can be used to calculate Multiplicative Functions, such as phi(n) (Mobius)

int phi[MAXN];
bool isPrime[MAXN];
vector<int> primes;

void sieve(int n = MAXN - 1) {
	for (int i = 1; i <= n; i++) {
		isPrime[i] = true;
		phi[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			phi[i] = -1;
		}
		for (auto p : primes) {
			if (1ll * p * i > n)
				break;
			isPrime[i * p] = false;
			if (i % p == 0) {
				phi[i * p] = 0;
				break;
			} else {
				phi[i * p] = -phi[i];
			}
		}
	}
}