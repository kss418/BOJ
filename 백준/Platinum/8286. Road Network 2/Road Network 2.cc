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
constexpr ll MAX = 2010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum;
priority_queue <ll, vector<ll>, greater<ll>> leaf;
priority_queue <pll, vector<pll>, greater<pll>> fo;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i];
    if(sum != 2 * n - 2){ cout << "BRAK"; return 0; }
    
    for(int i = 1;i <= n;i++){
        if(a[i] == 1) leaf.push(i);
        else fo.push({a[i], i});
    }

    while(!leaf.empty()){
        ll now = leaf.top(); leaf.pop();
        if(!fo.empty()){
            auto[num, nxt] = fo.top(); fo.pop();
            if(num == 2) leaf.push(nxt);
            else fo.push({num - 1, nxt});
            cout << now << " " << nxt << "\n";
        }
        else{
            ll nxt = leaf.top(); leaf.pop();
            cout << now << " " << nxt << "\n";
        }
    }

    return 0;
}