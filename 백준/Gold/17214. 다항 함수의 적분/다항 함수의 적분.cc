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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll x, c;

void parsh(string& s){
    ll idx = -1;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'x') idx = i;
    }

    if(idx != -1){
        ll sign = (s[0] == '-') ? -1 : 1;
        if(sign == -1) {
            if(idx == 1) x = -1;
            else x = stoll(s.substr(1, idx - 1)) * -1;
        }
        else {
            if(!idx) x = 1;
            else x = stoll(s.substr(0, idx));
        }

        if(idx + 1 >= n) return;
        sign = (s[idx + 1] == '-') ? -1 : 1;
        c = stoll(s.substr(idx + 1, n - idx));
    }
    else{
        ll sign = (s[0] == '-') ? -1 : 1;
        if(sign == -1) c = stoll(s.substr(1, idx - 1)) * -1;
        else c = stoll(s.substr(0, idx));
    }
}

int main() {
    fastio;

    cin >> s; n = s.size(); parsh(s);
    if(x > 2 || x < -2) cout << x / 2;
    if(x == -2) cout << "-";
    if(x) cout << "xx";

    if(c > 0 && x) cout << "+";
    if(c > 1 || c < -1) cout << c;
    if(c == -1) cout << "-";
    if(c) cout << "x";

    if(c || x) cout << "+"; cout << "W";
    
     
    return 0;
}