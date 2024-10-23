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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;


int main() {
    fastio;

    cin >> n;
    if(n == 1){
        cin >> m >> k; ll sum = m + k;

        ll mul = 1;
        for(int i = 1;i <= 12;i++) mul *= 26;

        for(int i = 12;i >= 0;i--){
            s.push_back((sum / mul) + 'a');
            sum -= (sum / mul) * mul; mul /= 26; 
        }

        cout << s;
    }
    else{
        cin >> s; reverse(all(s));
        ll cur = 0; ll mul = 1;
        for(auto& i : s){
            cur += mul * (i - 'a');
            mul *= 26;
        }

        cout << cur;
    }

    return 0;
}