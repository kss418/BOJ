#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;

int main() {
    fastio;

    cin >> s;
    ll sum = 0;

    sort(s.begin(), s.end()); reverse(s.begin(), s.end());
    for (auto& i : s) sum += i - '0';
    
    if (sum % 3 || s.back() != '0') cout << -1;
    else for (auto& i : s) cout << i;


    return 0;
}