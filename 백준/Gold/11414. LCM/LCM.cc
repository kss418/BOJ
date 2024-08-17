#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1e9 + 1;
ll result = INF, tmp = INF;
vector <ll> p;


ll gcd(ll a, ll b) {
    ll mod;
    while (b) {
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

int main()
{
    fastio;
    cin >> n >> m;
    if (n == m) cout << 1;
    else {
        for (int i = 1; i * i <= abs(n - m); i++) if (abs(n - m) % i == 0) {
            if (i * i == abs(n - m)) { p.push_back(i); break; }
            p.push_back(i);
            p.push_back(abs(n - m) / i);
        }
        
        for (auto& i : p) {
            ll mod = n % i;
            ll cur = (n + i - mod) / gcd(n + i - mod, m + i - mod) * (m + i - mod);
            if (cur > tmp) continue;
            if (cur == tmp && result < i - mod) continue;
            tmp = cur; result = i - mod;
        }

        cout << result;
    }
    
 
    return 0;
}