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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class _fft{
    public:
        const ld PI = acos(-1);
        using cpd = complex <ld>;
    
        void fft(vector <cpd>& v, bool inv = 0){
            ll n = v.size();
            for(int i = 1,j = 0;i < n;i++){
                ll num = n >> 1ll;
                while(!((j ^= num) & num)) num >>= 1ll;
                if(i < j) swap(v[i], v[j]);
            }

            for(int k = 1;k < n;k <<= 1ll){
                ld a = PI / k * (inv ? 1 : -1);
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
        
        vector <cpd> mul(vector <cpd>& a, vector <cpd>& b){
            ll n = 1;
            while(n < a.size() + 1 || n < b.size() + 1) n <<= 1;
            n <<= 1; a.resize(n); b.resize(n); vector <cpd> ret(n);
            fft(a); fft(b);
        
            for(int i = 0;i < n;i++) ret[i] = a[i] * b[i];
            fft(ret, 1);
    
            return ret;
        }
        
        vector <ll> carry(vector <cpd>& a, vector <cpd>& b){
            reverse(all(a)); reverse(all(b));
            vector <cpd> c = mul(a, b);
            ll carry = 0, i = 0; vector <ll> r;
            for(i = 0;i < c.size();i++){
                ll tmp = (ll)round(c[i].real()) + carry;
                r.push_back(tmp % 10);
                carry = tmp / 10;
            }
    
            while(carry > 0){
                r.push_back(carry % 10);
                carry /= 10;
            }
    
            for(i = r.size() - 1;i >= 0 && !r[i];--i);
            if(i < 0) return vector<ll>(1, 0);
            while(r.size() > i + 1) r.pop_back();
            reverse(all(r));
    
            return r;
        }
        
        vector <cpd> tf(string& a){
            vector <cpd> ret;
            for(auto& i : a) ret.push_back({i - '0', 0});
            return ret;
        }
        
        vector <cpd> tf(vector <ll>& a){
            vector <cpd> ret;
            for(auto& i : a) ret.push_back({i, 0});
            return ret;
        }
    };

void run(){
    string a, b; cin >> a >> b; _fft fft;
    vector <complex<ld>> va = fft.tf(a), vb = fft.tf(b);
    vector <ll> ret = fft.carry(va, vb);

    for(auto& i : ret) cout << i;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}