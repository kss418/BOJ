#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
vector <ll> x, y;

int main() {
    fastio;

    cin >> n >> m >> k;

    x.push_back(0); y.push_back(0);
    x.push_back(n); y.push_back(m);

    while(k--){
        ll c, p;
        cin >> c >> p;
        if(c) x.push_back(p);
        else y.push_back(p);
    }
    sort(all(x)); sort(all(y));

    ll mx = 0, my = 0;
    for(int i = 0;i < x.size() - 1;i++){
        mx = max(mx, x[i + 1] - x[i]);
    }

    for(int i = 0;i < y.size() - 1;i++){
        my = max(my, y[i + 1] - y[i]);
    }

    cout << mx * my;


    return 0;
}
