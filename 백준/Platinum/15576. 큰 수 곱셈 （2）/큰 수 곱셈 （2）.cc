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

class _fft{
public:
    const ld PI = acos(-1);
    using cpd = complex <ld>;

    void fft(vector <cpd>& v, cpd w){
        ll n = v.size();
        if(n == 1) return;

        vector <cpd> even(n / 2), odd(n / 2);
        for(int i = 0;i < n;i++)(i % 2 ? odd : even)[i / 2] = v[i];
        fft(even, w * w); fft(odd, w * w);

        cpd wp(1, 0);
        for(int i = 0;i < n / 2;i++){
            v[i] = even[i] + wp * odd[i];
            v[i + n / 2] = even[i] - wp * odd[i];
            wp *= w;
        }
    }  
    vector <cpd> mul(vector <cpd>& a, vector <cpd>& b){
        ll n = 1;
        while(n < a.size() + 1 || n < b.size() + 1) n <<= 1;
        n <<= 1; a.resize(n); b.resize(n);
        vector <cpd> ret(n);
        cpd w(cos(2 * PI / n), sin(2 * PI / n));
        fft(a, w); fft(b, w);

        for(int i = 0;i < n;i++) ret[i] = a[i] * b[i];
        fft(ret, cpd(1, 0) / w);
        for(int i = 0;i < n;i++){
            ret[i] /= cpd(n, 0);
            ret[i] = cpd(round(ret[i].real()), round(ret[i].imag()));
        }

        return ret;
    }
    
    vector <ll> ret(string& a, string& b){
        vector<cpd> ca = tf(a), cb = tf(b);
        return ret(ca, cb);
    }

    vector <ll> ret(vector<ll> &a, vector<ll>& b){
        vector<cpd> ca = tf(a), cb = tf(b);
        return ret(ca, cb);
    }

    vector <ll> ret(vector <cpd>& a, vector <cpd>& b){
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
    for(auto& i : fft.ret(a, b)) cout << i;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}