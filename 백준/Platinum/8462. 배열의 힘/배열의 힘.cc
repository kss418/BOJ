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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[1010101];

class _mos{
public:
    ll sq; vector <ll> result, arr;
    class query{
    public:
        ll l, r, n, sq;
        bool operator <(query& ot){
            if((l / sq) == (ot.l / sq)) return r < ot.r;
            return (l / sq < ot.l / sq);
        }
    };
    vector <query> q;

    _mos(ll n, ll m){ // 배열 크기, 쿼리 크기
        sq = sqrt(n); arr.resize(n + 1);
        result.resize(m + 1);
    }

    void add(ll l, ll r, ll n){ // 쿼리 추가
        q.push_back({l, r, n, sq});
    }

    void con(ll idx, ll val){ // 배열 삽입
        arr[idx] = val;
    }

    ll push(ll idx){
        cnt[arr[idx]]++;
        return (2 * cnt[arr[idx]] - 1) * arr[idx];
    }

    ll pop(ll idx){
        cnt[arr[idx]]--;
        return (-2 * cnt[arr[idx]] - 1) * arr[idx];
    }

    void init(){
        sort(q.begin(), q.end());

        ll s = q[0].l, e = q[0].r, cur = 0;
        for(int i = s;i <= e;i++) cur += push(i);
        result[q[0].n] = cur;

        for(int i = 1;i < m;i++){
            while(q[i].l > s) cur += pop(s++);
            while(q[i].r < e) cur += pop(e--);
            while(q[i].l < s) cur += push(--s);
            while(q[i].r > e) cur += push(++e);
            result[q[i].n] = cur;
        }
    }

    void print(){
        for(int i = 1;i <= m;i++) cout << result[i] << "\n";
    }
};

void run(){
    cin >> n >> m; _mos mos(n, m);
    for(int i = 1;i <= n;i++) cin >> a[i], mos.con(i, a[i]);

    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e;
        mos.add(s, e, i);
    }
    mos.init(); mos.print();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}