#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
    int det=0;
	cin >> a >> b >> c >> d;
	long long int ans = 0;
	for (int i = 0; i <= d; i++) {
		for (int j = 0; j <= d; j++) {
			N = d - a * i - b * j;
            det++;
			if (N >= 0 && N%c == 0)ans++;
		}
	}
	cout << det << endl;
	return 0;
}
