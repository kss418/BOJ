#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
vector <ll> p, num;
ll pn[MAX];


int main() {
    fastio;

    memset(pn, -1, sizeof(pn));
    pn[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (pn[i] != -1) continue;
        pn[i] = i; p.push_back(i);
        for (int j = 2 * i; j < MAX; j += i) {
            if (pn[j] != -1) continue;
            pn[j] = i;
        }
    }

    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m >> k;
        num.clear(); n--;
        
        ll cur = k;
        for (auto& i : p) {
            if (cur == 1 || i > cur) break;
            if (cur % i) continue;
            while (cur % i == 0) cur /= i;
            num.push_back(i);           
        }
        if (cur != 1) num.push_back(cur);
         


        ll pre = 0, nxt = 0;
        for (int i = 1; i < (1 << num.size()); i++) {
            ll cur = 1, cnt = 0;
            for (int j = 0; j < num.size(); j++) {
                if ((i & (1 << j)) == 0) continue;
                cur *= num[j]; cnt++;
            }

            ll mul = 0;
            if (cnt % 2) mul = 1;
            else mul = -1;

            nxt += mul * (m / cur); pre += mul * (n / cur);
        }

        cout << "Case #" << i << ": " << m - n - (nxt - pre) << '\n';
    }

    return 0;
}