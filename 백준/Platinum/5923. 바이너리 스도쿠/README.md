# [Platinum I] 바이너리 스도쿠 - 5923 

[문제 링크](https://www.acmicpc.net/problem/5923) 

### 성능 요약

메모리: 2200 KB, 시간: 28 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2025년 7월 7일 21:30:32

### 문제 설명

<p>바이너리 스도쿠 게임은 스도쿠의 변형 게임이다. 스도쿠와 비슷하게, 9*9칸으로 이루어져 있고, 이 칸은 각각 3*3 크기의 작은 칸으로 나누어져 있다. 스도쿠와 다른 점은 바이너리 스도쿠에서는 오직 0과 1만 이용해서 스도쿠 퍼즐을 푼다는 점이다.</p>

<pre>000 000 000
001 000 100
000 000 000

000 110 000
000 111 000
000 000 000

000 000 000
000 000 000
000 000 000</pre>

<p>바이너리 스도쿠의 목표는 최대한 적은 비트를 토글시켜서 각각의 행과 열, 그리고 3*3크기의 구간에 포함된 1의 개수가 짝수개가 되게 하는 것이다.</p>

<p>위의 예제는 3번 만에 퍼즐을 풀 수 있다.</p>

<pre>000 000 000
001 000 100
001 000 100

000 110 000
000 110 000
000 000 000

000 000 000
000 000 000
000 000 000</pre>

<p>바이너리 스도쿠 퍼즐의 초기 상태가 주어졌을 때, 이 퍼즐을 풀기 위해 필요한 최소 토글의 수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄부터 아홉 번째 줄 까지 바이너리 스도쿠의 초기 상태가 주어진다.</p>

### 출력 

 <p>바이너리 스도쿠를 풀기 위해 필요한 최소 토글의 수를 출력한다.</p>

