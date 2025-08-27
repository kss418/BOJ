#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    ll num, cnt, mx;
    vector <ll> arr;
};
deque <node> q;
ll nxt[MAX], mn[MAX];

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
    vector<ll>& ret() { return pn; } // 소수 벡터 반환
    bool prime(ll n) { // 소수 판별
        if (n == 1) return 0;
        return pv[n] == n;
    }
    ll mobius(ll n){ return mov[n]; }
    ll phi(ll n){ return phiv[n]; }
};

void run(){
    cin >> n; _es es(101010); nxt[1] = 2;
    memset(mn, 0x3f, sizeof(mn));

    for(int i = 0;i < es.ret().size() - 1;i++){
        ll a = es.ret()[i], b = es.ret()[i + 1];
        nxt[a] = b;
    }

    q.push_back({1, 1, 1, {}});
    while(!q.empty()){
        auto& [num, cnt, mx, arr] = q.front();

        if(mn[cnt] <= num) {
            q.pop_front(); continue; 
        }

        mn[cnt] = num;
        for(int i = 0;i < es.ret().size();i++){
            ll mul = es.ret()[i];
            if(num * mul > n) break;
            if(mul > mx){
                arr.push_back(1);
                q.push_back({num * mul, 2 * cnt, mul, arr});
                break;
            }

            ll nc = cnt / (arr[i] + 1) * (arr[i] + 2);
            arr[i]++;
            q.push_back({num * mul, nc, mx, arr});
            arr[i]--;
        }

        q.pop_front();
    }

    for(int i = 10000;i >= 1;i--){
        if(mn[i] > n) continue;
        cout << mn[i]; return;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}