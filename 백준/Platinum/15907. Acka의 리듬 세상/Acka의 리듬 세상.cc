#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], pn[1010101], cnt[1010101];
vector <ll> pr;

class _es {
public:
    ll n; vector <ll> p;
    _es(ll n) {
        this->n = n;
        p.resize(n + 1, -1);
    }

    void init() {
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (p[i] != -1) continue; p[i] = i;
            pr.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                if (p[j] == -1) p[j] = i;
            }
        }
    }

    vector<ll> ret() {
        return p;
    }

    ll prime(ll n) {
        if (n == 1) return 0;
        if (p[n] == -1) {
            p[n] = n; return 1;
        }
        return p[n] == n;
    }
};

int main() {
    fastio;

    _es es(2000001);
    es.init();

    cin >> n;
    ll c = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] % 2) c++;
    }
    ll result = max(c, n - c);

    
    for (auto& i : pr) {
        if (i > 2000000 / result) break;

        for (int j = 1; j <= n; j++) {
            cnt[arr[j] % i]++; 
            result = max(cnt[arr[j] % i], result);
        }

        for (int j = 1; j <= n; j++) cnt[arr[j] % i]--;
    }

    cout << result;


    return 0;
}