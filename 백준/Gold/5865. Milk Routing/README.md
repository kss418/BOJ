# [Gold II] Milk Routing - 5865 

[문제 링크](https://www.acmicpc.net/problem/5865) 

### 성능 요약

메모리: 2176 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘, 데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 5월 19일 08:58:48

### 문제 설명

<p>Farmer John's farm has an outdated network of M pipes (1 <= M <= 500) for pumping milk from the barn to his milk storage tank.  He wants to remove and update most of these over the next year, but he wants to leave exactly one path worth of pipes intact, so that he can still pump milk from the barn to the storage tank.</p><p>The pipe network is described by N junction points (1 <= N <= 500), each of which can serve as the endpoint of a set of pipes.  Junction point 1 is the barn, and junction point N is the storage tank.  Each of the M bi-directional pipes runs between a pair of junction points, and has an associated latency (the amount of time it takes milk to reach one end of the pipe from the other) and capacity (the amount of milk per unit time that can be pumped through the pipe in steady state).  Multiple pipes can connect between the same pair of junction points.</p><p>For a path of pipes connecting from the barn to the tank, the latency of the path is the sum of the latencies of the pipes along the path, and the capacity of the path is the minimum of the capacities of the pipes along the path (since this is the "bottleneck" constraining the overall rate at which milk can be pumped through the path).  If FJ wants to send a total of X units of milk through a path of pipes with latency L and capacity C, the time this takes is therefore L + X/C.</p><p>Given the structure of FJ's pipe network, please help him select a single path from the barn to the storage tank that will allow him to pump X units of milk in a minimum amount of total time.</p>

### 입력 

 <ul><li>Line 1: Three space-separated integers: N M X (1 <= X <= 1,000,000).</li><li>Lines 2..1+M: Each line describes a pipe using 4 integers: I J L C. I and J (1 <= I,J <= N) are the junction points at both ends of the pipe.  L and C (1 <= L,C <= 1,000,000) give the latency and capacity of the pipe.</li></ul>

### 출력 

 <ul><li>Line 1: The minimum amount of time it will take FJ to send milk along a single path, rounded down to the nearest integer.</li></ul>

