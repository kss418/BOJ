#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
unordered_map <string, bool> num;
pll a[MAX];

string h(pll a){
    ll num = a.x + a.y * 100000 + 10000;
    return to_string(num);
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; ll result = 0; num.clear();
        for(int i = 1;i <= n;i++) {
            cin >> a[i].x >> a[i].y;
            num[h(a[i])] = 1;
        }
        
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ll dx = a[j].x - a[i].x;
                ll dy = a[j].y - a[i].y;

                pll v1 = {a[i].x - dy, a[i].y + dx};
                pll v2 = {a[i].x + dx - dy, a[i].y + dy + dx};

                if(!num.count(h(v1))) continue;
                if(!num.count(h(v2))) continue;
                result = max(result, dx * dx + dy * dy);
            }
        }

        cout << result << "\n";
    }


    return 0;
}

