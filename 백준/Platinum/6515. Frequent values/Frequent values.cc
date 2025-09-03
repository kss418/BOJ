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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
ll cur, cnt[MAX], pre[MAX];

class _mos{
public:
    ll sq, n, m; vector <ll> result, arr;
    class query{
    public:
        ll l, r, n, sq;
        bool operator <(query& ot){
            if((l / sq) == (ot.l / sq)) return r < ot.r;
            return (l / sq < ot.l / sq);
        }
    };
    vector <query> q;

    _mos(){}
    _mos(ll n, ll m) : n(n), m(m){ // 배열 크기, 쿼리 크기
        sq = sqrt(n); arr.resize(n + 1);
        result.resize(m + 1);
    }

    void add(ll l, ll r, ll n){ // 쿼리 추가
        q.push_back({l, r, n, sq});
    }

    void set(ll idx, ll val){ // 배열 삽입
        arr[idx] = val;
    }

    void push(ll idx){
        ll num = arr[idx];
        cnt[num]++;
        pre[cnt[num] - 1]--;
        pre[cnt[num]]++;

        if(pre[cur + 1]) cur++;
    }   

    void pop(ll idx){
        ll num = arr[idx];
        cnt[num]--;
        pre[cnt[num] + 1]--;
        pre[cnt[num]]++;
        
        if(!pre[cur]) cur--;
    }

    void init(){
        if(q.empty()) return;
        sort(all(q));

        ll s = q[0].l, e = s - 1;
        while (e < q[0].r) push(++e);
        while (s > q[0].l) push(--s);
        while (s < q[0].l) pop(s++);
        result[q[0].n] = cur;

        for(int i = 1;i < m;i++){
            while(q[i].l < s) push(--s);
            while(q[i].r > e) push(++e);
            while(q[i].l > s) pop(s++);
            while(q[i].r < e) pop(e--);
            result[q[i].n] = cur;
        }
    }

    void print(){
        for(int i = 1;i <= m;i++) cout << result[i] << "\n";
    }
};
ll arr[MAX];

int main() {
    fastio;
    
    while(1){
        cin >> n; if(!n) return 0;
        cin >> m; _mos mos(n, m); cur = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(pre, 0, sizeof(pre));
        
        for(int i = 1;i <= n;i++) cin >> arr[i];
        for(int i = 1;i <= n;i++) mos.set(i, arr[i]);

        for(int i = 1;i <= m;i++){
            ll l, r; cin >> l >> r;
            mos.add(l, r, i);
        }
        mos.init(); mos.print();
    }


    return 0;
}