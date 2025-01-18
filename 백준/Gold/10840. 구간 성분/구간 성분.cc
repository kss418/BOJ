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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[26];
string a, b;
class _hash{
public:
    ll mod, key, v = 0;
    _hash(){}
    void push(char c){ v += p[c - 'a']; v %= MOD; }
    void pop(char c){ v -= p[c - 'a']; v = (v + MOD) % MOD; }
};

void run(){
    cin >> a >> b; p[0] = 1;
    for(int i = 1;i < 26;i++) p[i] = (p[i - 1] * 26) % MOD;
    for(int i = min(a.size(), b.size());i >= 1;i--){
        _hash ha;
        for(int j = 0;j < i - 1;j++) ha.push(a[j]);
        for(int j = i - 1;j < a.size();j++){
            ha.push(a[j]);
            if(j >= i) ha.pop(a[j - i]);

            _hash hb;
            for(int k = 0;k < i - 1;k++) hb.push(b[k]);
            for(int k = i - 1;k < b.size();k++){
                hb.push(b[k]);
                if(k >= i) hb.pop(b[k - i]);
                if(j >= i - 1 && k >= i - 1 && ha.v == hb.v) {
                    cout << i; return;
                }
            }
        }
    }

    cout << 0;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}