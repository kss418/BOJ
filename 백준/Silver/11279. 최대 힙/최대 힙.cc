#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll n;
// 큰 값 먼저 출력
priority_queue <ll> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++){
        ll x; cin >> x;
        if(x) pq.push(x); // x 삽입
        else{
            // 우선순위 큐가 비어있으면 0 출력
            if(pq.empty()) cout << 0 << "\n";
            
            // 아니면
            else{
                // 최댓값 출력
                cout << pq.top() << "\n";
                pq.pop(); // 값 삭제
            }
        }
    }

    return 0;
}

