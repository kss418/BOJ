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
constexpr ll MAX = 3010101;
constexpr ll MOD = 998244353;
deque <ll> q;
ll a[MAX], cnt[3010];

int main() {
    fastio;

    cin >> n >> k >> m >> t;
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll result = 0, num = 0;
    for(int i = 1;i <= 2 * n;i++){
        ll cur = a[(i - 1) % n + 1];
        q.push_back(cur);

        if(!cnt[cur]) num++;
        cnt[cur]++;

        if(q.size() > m){
            cnt[q.front()]--;
            if(!cnt[q.front()]) num--;
            q.pop_front();
        }
        
        if(q.size() != m) continue;
        if(!cnt[t]) result = max(result, num + 1);
        else result = max(result, num);
    }

    cout << result;


    return 0;
}

