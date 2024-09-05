#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 1e9 + 7;
vector <ll> dv;

int main() {
    fastio;

    while (1) {
        cin >> n; if (n == -1) break;
        ll sum = 0; dv.clear();

        for (int i = 1; i * i <= n; i++) {
            if (n % i) continue;
            if (i * i != n) {
                sum += n / i; dv.push_back(n / i);
            }
            sum += i; dv.push_back(i);
        }
        sort(dv.begin(), dv.end());

        if (sum == 2 * n) {
            cout << n << " = ";
            for (int i = 0; i < dv.size() - 2; i++) cout << dv[i] << " + ";
            cout << dv[dv.size() - 2] << "\n";
        }
        else cout << n << " is NOT perfect.\n";
    }
    

    return 0;
}