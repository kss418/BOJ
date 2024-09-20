#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "Algorithm") cout << 204 << '\n';
        else if (s == "DataAnalysis") cout << 207 << '\n';
        else if (s == "CyberSecurity") cout << "B101" << "\n";
        else if (s == "Network") cout << 303 << "\n";
        else if (s == "Startup") cout << 501 << '\n';
        else if (s == "TestStrategy") cout << 105 << "\n";
        else cout << 302 << "\n";
    }

    return 0;
}