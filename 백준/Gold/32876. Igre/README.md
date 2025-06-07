# [Gold IV] Igre - 32876 

[문제 링크](https://www.acmicpc.net/problem/32876) 

### 성능 요약

메모리: 394676 KB, 시간: 852 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 6월 7일 14:05:14

### 문제 설명

<p>Kile has returned from a board game fair. He brought home n games. Before playing a game, it is necessary to learn its rules. Learning the rules of the $i$-th game takes $p_i$ minutes. Once the rules are learned, it is possible to play the game. Playing the $i$-th game takes $t_i$ minutes. Each game also has its own rating $o_i$.</p>

<p>In the coming days, Kile has planned to spend at most $d$ minutes on board games. He is interested in finding out the maximum sum of the ratings of the games he can play. Each game can be played an arbitrary number of times.</p>

### 입력 

 <p>The first line contains integers $n$ and $d$ ($1 ≤ n, d ≤ 5000$), the number of games and the time planned to spend on playing games.</p>

<p>The $i$-th of the following $n$ lines contains integers $p_i$, $t_i$ and $o_i$ ($0 ≤ p_i ≤ 5000$, $1 ≤ t_i ≤ 5000$, $1 ≤ o_i ≤ 10^9$), time required to learn the rules, time required to play and the rating of $i$-th game.</p>

### 출력 

 <p>In the first and only line, output the maximum sum of the ratings of the games played.</p>

