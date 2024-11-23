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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

using tld = tuple<ld, ld, ld>;
priority_queue <tld> pq;

ld dist(ld a, ld b){
    return sqrtl(a * a + b * b);
}
vector <ld> num;

int main() {
    fastio;

    cin >> t;
    while(t--){
        ld a, b; cin >> a >> b >> k;
        ld c = dist(a, b);
        ld h = (a * b) / (a + b + c);
        
        num.clear();
        while(!pq.empty()) pq.pop();
        
        pq.push({h, a - h, dist(h, a - h)});
        pq.push({h, b - h, dist(h, b - h)});
        pq.push({h, h, dist(h, h)});

        num.push_back(h);
        for(int i = 1;i <= 2 * k;i++){
            auto[ca, cb, cc] = pq.top(); pq.pop();
            ld na = (ca * cc - ca * ca) / (ca + cc);
            ld nb = cb * na / ca;
            ld nc = dist(na, nb);
            pq.push({na, nb, nc});
            num.push_back(na);
        }
        sort(all(num)); reverse(all(num));

        ld r = num[k - 1];
        cout.precision(20);
        cout << r * r * M_PI << "\n";
    }


    return 0;
}

