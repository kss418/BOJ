#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
priority_queue <pll> pq;
deque <pll> arr;

void run(){
    cin >> n; arr.clear();
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        arr.push_back({i - a[i].x, i});
    }

    sort(all(arr)); ll result = 0;
    while(!pq.empty()) pq.pop();

    for(int i = 1;i <= n;i++){
        while(!arr.empty() && arr.front().x <= i){
            auto[v, idx] = arr.front(); arr.pop_front();
            pq.push({a[idx].y, idx + a[idx].x});
        }

        vector <pll> vec;
        while(!pq.empty()){
            if(vec.size() == 3) break;
            auto now = pq.top(); pq.pop();

            if(i > now.y) continue;
            vec.push_back(now);
        }

        for(auto& i : vec) pq.push(i);
        if(vec.size() != 3) continue;
        ll now = 0;
        for(auto& i : vec) now += i.x;
        result = max(result, now);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}