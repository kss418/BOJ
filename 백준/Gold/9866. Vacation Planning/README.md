# [Gold I] Vacation Planning - 9866 

[문제 링크](https://www.acmicpc.net/problem/9866) 

### 성능 요약

메모리: 248988 KB, 시간: 832 ms

### 분류

데이크스트라, 그래프 이론, 그래프 탐색, 최단 경로

### 제출 일자

2025년 5월 9일 14:58:37

### 문제 설명

<p>Air Bovinia operates flights connecting the N farms that the cows live on (1 <= N <= 20,000). As with any airline, K of these farms have been designated as hubs (1 <= K <= 200, K <= N).</p><p>Currently, Air Bovinia offers M one-way flights (1 <= M <= 20,000), where flight i travels from farm u_i to farm v_i and costs d_i (1 <= d_i <= 10,000) dollars.  As with any other sensible airline, for each of these flights, at least one of u_i and v_i is a hub.  There is at most one direct flight between two farms in any given direction, and no flight starts and ends at the same farm.</p><p>Bessie is in charge of running the ticketing services for Air Bovinia. Unfortunately, while she was away chewing on delicious hay for a few hours, Q one-way travel requests for the cows' holiday vacations were received (1 <= Q <= 50,000), where the ith request is from farm a_i to farm b_i.</p><p>As Bessie is overwhelmed with the task of processing these tickets, please help her compute whether each ticket request can be fullfilled, and its minimum cost if it can be done.</p><p>To reduce the output size, you should only output the total number of ticket requests that are possible, and the minimum total cost for them. Note that this number might not fit into a 32-bit integer.</p>

### 입력 

 <ul><li>Line 1: The integers N, M, K, and Q.</li><li>Lines 2..M + 1: Line i+1 contains u_i, v_i, and d_i. (1 <= u_i, v_i <= N, u_i != v_i)</li><li>Lines M + 2..M + K + 1: Each of these lines contains the ID of a single hub (in the range 1..N).</li><li>Lines M + K + 2..M + K + Q + 1: Two numbers per line, indicating a request for a ticket from farm a_i to b_i. (1 <= a_i, b_i <= N, a_i != b_i)</li></ul>

### 출력 

 <ul><li>Line 1: The number of ticket requests that can be fullfilled.</li><li>Line 2: The minimum total cost of fulling the possible ticket requests</li></ul>

