#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101010;
constexpr ll MOD = 998244353;

class _es { // flag (1 == prime / 2 == phi / 4 == mobius)
public:
    ll n; vector <ll> pv, pn, mov, phiv;
    vector <bool> v;
    _es(ll n, ll flag = 1) {
        this->n = n;

        if(flag & 1){
            pv.resize(n + 1, -1); pv[1] = 1;
            for (ll i = 2;i <= n;i++) {
                if(pv[i] != -1) continue; pv[i] = i;
                pn.push_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    if(pv[j] == -1) pv[j] = i;
                }
            }
        }

        if(flag & 2){
            phiv.resize(n + 1); iota(all(phiv), 0);
            v.resize(n + 1);
            for(ll i = 2;i <= n;i++){
                if(v[i]) continue;
                for(ll j = i;j <= n;j += i){
                    phiv[j] /= i; phiv[j] *= (i - 1); v[j] = 1;
                }
            }
        }

        if(flag & 4){
            mov.resize(n + 1, -2);
            mov[0] = 0; mov[1] = 1;
            for(ll i = 2;i <= n;i++){
                if(mov[i] != -2) continue; mov[i] = -1;
                for(ll j = 2 * i;j <= n;j += i) {
                    if(mov[j] == -2) mov[j] = 1;
                    mov[j] *= -1;
                }
                for(ll j = i * i;j <= n; j += i * i) mov[j] = 0;
            }
        }
    }

    ll mp(ll n) { return pv[n]; } // 최소 소인수 반환
    vector<ll> ret() { return pn; } // 소수 벡터 반환
    bool prime(ll n) { // 소수 판별
        if (n == 1) return 0;
        return pv[n] == n;
    }
    ll mobius(ll n){ return mov[n]; }
    ll phi(ll n){ return phiv[n]; }
};

int main() {
    fastio;

    ll a, b, c, d; cin >> a >> b >> c >> d;
    _es es(min(b, d), 4);
    
    ll result = 0;
    for(int i = 1;i <= min(b, d);i++){
        ll st = (b / i) - ((a - 1) / i);
        ll en = (d / i) - ((c - 1) / i);

        result += es.mobius(i) * st * en;
    }

    cout << result;
    
    
    return 0;
}