#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], la[MAX], cur, result;


int main() {
    fastio;

    cin >> n >> t;
    while (t--) {
        cin >> m >> k;
        
        if (m == k) cout << 1 << "\n";
        else if (m > k) {
            if (n + k + 1 - 2 * (m - 1) > 0) cout << 1 << "\n";
            else cout << 0 << '\n';
        }
        else {
            if (n + m - 2 * (k - 1) > 0) cout << 1 << "\n";
            else cout << 0 << '\n';
        }
    }
   

    return 0;
}