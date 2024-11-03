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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
pll a[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        if(a[i].y > a[i].x) swap(a[i].x, a[i].y);
    }
    cin >> m;
    sort(a + 1, a + n + 1);

    ll result = 0;
    for(int i = 1;i <= n;i++){
        pq.push(a[i].y);
        while(!pq.empty() && pq.top() < a[i].x - m) pq.pop();

        result = max<ll>(result, pq.size());
    }   
    
    cout << result;


    return 0;
}

