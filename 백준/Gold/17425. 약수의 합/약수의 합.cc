#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], sum[MAX];

int main() {
    fastio;

    for (int i = 2; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) arr[j] += i;
    }

    for (int i = 1; i < MAX; i++) {
        arr[i]++;
        sum[i] = sum[i - 1] + arr[i];
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << sum[n] << '\n';
    }

    return 0;
}