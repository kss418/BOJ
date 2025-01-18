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
ll p[26][2];
string a, b;
class _hash{
public:
    ll mod, key, v1 = 0, v2 = 0;
    _hash(){}
    void push(char c){ 
        v1 += p[c - 'a'][0]; v1 %= MOD; 
        v2 += p[c - 'a'][1]; v2 %= 1000000007;
    }
    void pop(char c){ 
        v1 -= p[c - 'a'][0]; v1 = (v1 + MOD) % MOD; 
        v2 -= p[c - 'a'][1]; v2 = (v2 + 1000000007) % 1000000007; 
    }
};

void run(){
    cin >> a >> b; p[0][0] = p[0][1] = 1;
    for(int i = 1;i < 26;i++) p[i][0] = (p[i - 1][0] * 31) % MOD;
    for(int i = 1;i < 26;i++) p[i][1] = (p[i - 1][1] * 67) % 1000000007;
    for(int i = min(a.size(), b.size());i >= 1;i--){
        _hash ha, hb; set <ll> num1, num2;
        for(int j = 0;j < i - 1;j++) ha.push(a[j]);
        for(int j = i - 1;j < a.size();j++){
            ha.push(a[j]);
            if(j >= i) ha.pop(a[j - i]);
            num1.insert(ha.v1); num2.insert(ha.v2);
        }

        for(int j = 0;j < i - 1;j++) hb.push(b[j]);
        for(int j = i - 1;j < b.size();j++){
            hb.push(b[j]);
            if(j >= i) hb.pop(b[j - i]);
            if(num1.count(hb.v1) && num2.count(hb.v2)) { cout << i; return; }
        }
    }

    cout << 0;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}