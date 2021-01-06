// Euler’s Totient function Φ (n) for an input n is the count of numbers in {1, 2, 3, …, n}
// that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) 
// with n is 1.
// Time complexity - O(sqrt(n))

long long int phi(long long int m) {
	long long int ans = m;
	for(long long int p = 2; p * p <= m; p++) {
		if(m % p == 0) {
			while(m % p == 0) {
				m /= p;
			}
			ans -= ans / p;
		}
	}
	if(m > 1) {
		ans -= ans / m;
	}
	return ans;
}
