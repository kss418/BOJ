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

string cal(string a, string b){
    if(a.size() > b.size()) b = string(a.size() - b.size(), '0') + b;
    for(int i = 0;i < a.size();i++) a[i] = (a[i] != b[i] ? '1' : '0');
    if(a.find('1') == -1) return "0";
    return a.substr(a.find('1'));
}

void run(){
    cin >> n >> s;
    if(!count(all(s), '1')){ cout << 0 << "\n"; return; }
    if(!count(all(s), '0')){
        s.back() = '0';
        for(auto& i : s) cout << i;
        cout << "\n"; return;
    }

    ll idx = s.find('1'), len = 0;
    while(idx + len < n && s[idx + len] == '1') len++;
    if(idx + len == n){
        for(auto& i : s.substr(idx)) cout << i; 
        cout << "\n"; return;
    }
    idx += len;

    for(int i = 1;i <= len;i++){
        if(idx + i >= n) break;
        if(s[idx + i] == '0') continue;
        cout << cal(s, s.substr(idx - i, n - idx)) << "\n";
        return;
    }
    cout << cal(s, s.substr(idx - len, n - idx)) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

