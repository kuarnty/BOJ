#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int n, a, b, c;
const int maxSize = 1000010;
vll v(maxSize), s(maxSize), dp(maxSize), xpos(maxSize), stk(maxSize);
int scnt;

inline ll func(ll x) {
	return (ll)a * x * x + (ll)b * x + c;
}

inline ll k(ll i) {
	return -2 * a * s[i];
}

inline ll m(ll i) {
	return a * s[i] * s[i] - b * s[i] + dp[i];
}

double getCross(int p, int q) { //����
	ll k1 = k(p), m1 = m(p);
	ll k2 = k(q), m2 = m(q);
	return (double)(m1 - m2) / (k2 - k1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; i++) cin >> v[i], s[i] = s[i - 1] + v[i];
	int pt = 1;
	for (int i = 1; i <= n; i++) {
		// �ϴ� i�� ������� ��� �� Ư����� ������� ���� �������� dp�� �ֱ�
		dp[i] = func(s[i]);
		if (scnt) {
			while (pt < scnt && xpos[pt + 1] < s[i]) pt++; //��ȭ���� ������ �ִ��� ��ġ ����
			int j = stk[pt];
			dp[i] = max(dp[i], dp[j] + func(s[i] - s[j]));

			while (scnt > 1 && xpos[scnt] > getCross(stk[scnt], i)) --scnt;
			stk[++scnt] = i;
			xpos[scnt] = getCross(stk[scnt - 1], i);
			if (pt > scnt) pt = scnt;
		}
		else {
			stk[++scnt] = i;
			xpos[scnt] = -1e9;
		}
	}
	cout << dp[n] << endl;
	return 0;
}