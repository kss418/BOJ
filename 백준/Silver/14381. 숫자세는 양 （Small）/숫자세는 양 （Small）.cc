#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];
set <ll> num;


int main() {
    fastio;

    cin >> t;
    for(int i = 1;i <= t;i++){
        cout << "Case #" << i << ": ";

        cin >> n;
        if(!n) cout << "INSOMNIA\n";
        else{
            num.clear(); ll cnt = 1;
            while(num.size() != 10){    
                ll cur = n * cnt++;
                string st = to_string(cur);

                for(auto& i : st) num.insert(i - '0');
            }

            cout << n * (cnt - 1) << "\n";
        }
    }
    

    return 0;
}