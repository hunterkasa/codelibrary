// n permutation r
const int p = 1e9+7;
const int MAXN = 1e6;
long long fac[MAXN + 1];
long long inv[MAXN + 1];
long long exp(long long x, long long n, long long m) {
	x %= m; 
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}
void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}
void inverses() {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}
long long choose(long long n, long long r) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}