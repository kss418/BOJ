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
vector <ll> result;

void dnc(ll l, ll r){
    if(l > r) return;
    ll idx = l;
    for(int i = l;i <= r;i++){
        if(s[i] < s[idx]) idx = i;
    }

    result.push_back(idx);
    if(l == r) return;
    dnc(idx + 1, r);
    dnc(l, idx - 1);
}

int main() {
    fastio;

    cin >> s; n = s.size();
    dnc(0, n - 1);

    for(int i = 0;i < n;i++){
        string cur;
        sort(result.begin(), result.begin() + i + 1);
        for(int j = 0;j <= i;j++) cur.push_back(s[result[j]]);
        cout << cur << "\n";
    }

     
    return 0;
}