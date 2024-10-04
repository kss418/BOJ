#pragma GCC optimize("O3")
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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
int cnt[MAX];
map <int, int> num;

class _mos{
public:
    int sq; vector <int> result, arr;
    class query{
    public:
        int l, r, n, sq;
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

    void add(int l, int r, int n){ // 쿼리 추가
        q.push_back({l, r, n, sq});
    }

    void con(ll idx, ll val){ // 배열 삽입
        arr[idx] = val;
    }

    ll push(ll idx){
        ll ret = 0;
        if(!cnt[arr[idx]]) ret = 1;
        cnt[arr[idx]]++;
        return ret;
    }

    ll pop(ll idx){
        ll ret = 0;
        if(cnt[arr[idx]] == 1) ret = -1;
        cnt[arr[idx]]--;

        return ret;
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
pll arr[MAX]; ll seq = 1;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> arr[i].x; arr[i].y = i;
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1;i <= n;i++){
        if(!num.count(arr[i].x)) num[arr[i].x] = seq++;
        arr[i].x = num[arr[i].x];
    }
    cin >> m; _mos mos(n, m);

    for(int i = 1;i <= n;i++) mos.con(arr[i].y, arr[i].x);
    for(int i = 1;i <= m;i++){
        ll l, r; cin >> l >> r;
        mos.add(l, r, i);
    }
    mos.init(); mos.print();


    return 0;
}