# [Platinum IV] Fast Forward - 30563 

[문제 링크](https://www.acmicpc.net/problem/30563) 

### 성능 요약

메모리: 369528 KB, 시간: 1948 ms

### 분류

이분 탐색, 자료 구조, 희소 배열

### 제출 일자

2025년 9월 22일 15:18:51

### 문제 설명

<p>Gry has started to use the new Expify song streaming platform. Since, Gry does not want to spend money Expify forces him to listen to advertisements. An advertisement can be played only after some song (it cannot be played in the middle) and only if the time from the end of the previous advertisement is at least $c$ seconds.</p>

<p>Gry has a circular playlist with $n$ songs where the duration of the $i$-th song is $d_i$ seconds. He wants to minimize the number of advertisements, so, he wants to find out how many advertisements will be if he starts listening to his whole playlist from $i$-th song, i.e., the circular playlist stops playing after $n$ songs.</p>

<p>We suppose that there is an advertisement right before Gry starts listening. Neither this advertisement nor the one, after the playlist stops, count.</p>

### 입력 

 <ul>
	<li>One line containing the number of songs in the playlist $n$, and the refresh time between advertisements $c$ ($1 \leq n \leq 10^6$, $1 \leq c \leq 10^9$)</li>
	<li>One line containing the $n$ durations of the songs $d_1 \ldots d_n$ ($1 \leq d_i \leq 10^3$)</li>
</ul>

### 출력 

 <p>Output the number of advertisements if Gry starts listening to the playlist from the $i$-th song.</p>

