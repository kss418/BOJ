# [Platinum IV] Gourmet Grazers - 6142 

[문제 링크](https://www.acmicpc.net/problem/6142) 

### 성능 요약

메모리: 7560 KB, 시간: 84 ms

### 분류

이분 탐색, 자료 구조, 그리디 알고리즘, 정렬, 트리를 사용한 집합과 맵

### 제출 일자

2025년 2월 7일 20:51:00

### 문제 설명

<p>Like so many others, the cows have developed very haughty tastes and will no longer graze on just any grass. Instead, Farmer John must purchase gourmet organic grass at the Green Grass Grocers store for each of his N (1 <= N <= 100,000) cows.</p>

<p>Each cow_i demands grass of price at least A_i (1 <= A_i <= 1,000,000,000) and with a greenness score at least B_i (1 <= B_i <= 1,000,000,000). The GGG store has M (1 <= M <= 100,000) different types of grass available, each with a price C_i (1 <= C_i <= 1,000,000,000) and a greenness score of D_i (1 <= D_i <= 1,000,000,000). Of course, no cow would sacrifice her individuality, so no two cows can have the same kind of grass.</p>

<p>Help Farmer John satisfy the cows' expensive gourmet tastes while spending as little money as is necessary.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M.</li>
	<li>Lines 2..N+1: Line i+1 contains two space-separated integers: A_i and B_i</li>
	<li>Lines N+2..N+M+1: Line i+N+1 contains two space-separated integers: C_i and D_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer which is the minimum cost to satisfy all the cows. If that is not possible, output -1.</li>
</ul>

