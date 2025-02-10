#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> a(MAX), b(MAX), ret;

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
} es(MAX);

class _fft{
public:
    const ld PI = acos(-1);
    using cpd = complex <double>;

    void fft(vector <cpd>& v, bool inv = 0){
        ll n = v.size();
        for(int i = 1,j = 0;i < n;i++){
            ll bit = n >> 1ll;
            for(;j >= bit;bit >>= 1ll) j -= bit;
            j += bit;
            if(i < j) swap(v[i], v[j]);
        }

        for(int k = 1;k < n;k <<= 1ll){
            double a = PI / k * (inv ? 1 : -1);
            cpd w(cos(a), sin(a));
            for(int i = 0;i < n;i += 2 * k){
                cpd wp(1, 0);
                for(int j = 0;j < k;j++){
                    cpd x = v[i + j], y = v[i + j + k] * wp;
                    v[i + j] = x + y;
                    v[i + j + k] = x - y;
                    wp *= w;
                }
            }
        }

        if(inv) for(int i = 0;i < n;i++) v[i] /= n;
    }  
        
    vector <ll> mul(vector <ll>& a, vector <ll>& b){
        vector<cpd> av(all(a)), bv(all(b));
        ll n = 2;
        while(n < a.size() + b.size()) n <<= 1;
        av.resize(n); bv.resize(n);
        fft(av); fft(bv);
        for(int i = 0;i < n;i++) av[i] *= bv[i];
        fft(av, 1);

        vector <ll> ret(n);
        for(int i = 0;i < n;i++) ret[i] = round(av[i].real());
    
        return ret;
    }
        
    vector <ll> carry(vector <ll>& a, vector <ll>& b){
        reverse(all(a)); reverse(all(b));
        vector <ll> ret = mul(a, b);

        for(int i = 0;i < ret.size();i++){
            if(ret[i] < 10) continue;
            if(i < ret.size() - 1) ret[i + 1] += ret[i] / 10;
            else ret.push_back(ret[i] / 10);
            ret[i] %= 10;
        }
        
        while(!ret.empty() && !ret.back()) ret.pop_back();
        if(ret.empty()) return vector<ll>(1, 0);
        reverse(all(ret));
        return ret;
    }
} fft;

void run(){
    cin >> n;
    cout << ret[n] << "\n";
}

int main() {
    fastio; cin >> t;
    for(auto& i : es.ret()){
        if(i != 2) a[i] = 1;
        if(2 * i >= MAX) continue;
        b[2 * i] = 1;
    }
    b[4] = 1;
    ret = fft.mul(a, b);
    while(t--) run(); 

    return 0;
}

