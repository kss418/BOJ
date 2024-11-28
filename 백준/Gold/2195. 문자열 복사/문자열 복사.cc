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
string a, b;

bool chk(string& s){
    for(int i = 0;i < a.size();i++){
        if(i + s.size() - 1 >= a.size()) return 0;
        string now = a.substr(i, s.size());
        if(s == now) return 1;
    }
    
    return 0;
}

int main() {
    fastio;

    cin >> a >> b; ll result = 1;
    ll r = b.size() - 1, l = b.size() - 1;

    while(r >= 0 && l >= 0){
        string now = b.substr(l, r - l + 1);
        if(chk(now)) l--;
        else r = l, result++;
    }

    cout << result;
    
     
    return 0;
}