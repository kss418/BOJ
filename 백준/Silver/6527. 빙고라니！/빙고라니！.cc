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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};

map <string, bool> use;
ll parse(string& s){
    ll l = -1, ret = 0;
    for(auto& i : s){
        if(i >= 'A' && i <= 'Z') i ^= 32;
    }

    for(int i = 0;i < s.size();i++){
        if(s[i] >= 'a' && s[i] <= 'z') {
            if(l == -1) l = i;
        } 
        else{
            if(l == -1) continue;
            string now = s.substr(l, i - l); l = -1;
            if(use[now]) continue;
            use[now] = 1; ret++;
        }
    }

    if(l != -1){
        string now = s.substr(l, s.size() - l + 1);
        if(!use[now]) use[now] = 1, ret++;
    }

    return ret;
}

int main() {
    fastio;

    ll all = 0, cnt = 0, cur = 0; _gcd gcd;
    while(cin >> s){
        if(s == "BULLSHIT") { 
            all += cur; cur = 0;
            cnt++; use.clear();
            continue; 
        }
        cur += parse(s);
    }

    ll g = gcd.ret(all, cnt);
    all /= g; cnt /= g;
    
    cout << all << " / " << cnt;
    
    
    return 0;
}