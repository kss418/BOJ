# [Diamond IV] Railway Trip 2 - 24477 

[문제 링크](https://www.acmicpc.net/problem/24477) 

### 성능 요약

메모리: 63344 KB, 시간: 1168 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 세그먼트 트리, 희소 배열

### 제출 일자

2025년 9월 24일 08:59:48

### 문제 설명

<p>IOI Railway Company is operating lines on a railway track. There are $N$ stations in a straight line, numbered from $1$ to $N$. For each $i$ ($1 ≤ i ≤ N - 1$), Station $i$ and Station $i + 1$ are connected directly by a railway track.</p>

<p>IOI Railway Company is operating $M$ lines, numbered from $1$ to $M$. In Line $j$ ($1 ≤ j ≤ M$), the starting station is Station $A_j$, and the terminal station is Station $B_j$. A train stops at every station. Namely, if $A_j < B_j$ a train of Line $j$ stops at Station $A_j$, Station $A_j + 1$, $\dots$, Station $B_j$, in this order. If $A_j > B_j$, a train of Line $j$ stops at Station $A_j$, Station $A_j - 1$, $\dots$, Station $B_j$, in this order.</p>

<p>JOI-kun is a traveler. He has $Q$ travel plans. In the $k$-th plan ($1 ≤ k ≤ Q$), he travels from Station $S_k$ to Station $T_k$ by taking lines.</p>

<p>However, JOI-kun is tired from a long journey. He wants to take a vacant train and get a seat. Thus, JOI-kun decided that he takes a train of a line at a station only if it is the $K$-th or earlier stop from the starting station of the line. In other words, if $A_j < B_j$, he can take a train of Line $j$ only at Station $A_j$, Station $A_j + 1$, $\dots$, Station $\min{\{A_j + K - 1, B_j - 1\}}$. If $A_j > B_j$, he can take a train of Line $j$ only at Station $A_j$, Station $A_j - 1$, $\dots$, Station $\max{\{A_j - K + 1, B_j + 1\}}$. JOI-kun will get out of the train at a station between the station next to where he takes the train and the terminal station, inclusive.</p>

<p>Under these conditions, JOI-kun wants to minimize the number of times of taking trains.</p>

<p>Given the information of the lines of IOI Railway Company and JOI-kun’s plans, write a program which calculates, for each of JOI-kun’s plans, the minimum number of times of taking trains needed for JOI-kun to achieve it.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<p>$\begin{align*}&N\,K \\ & M \\ & A_1\,B_1 \\ & A_2\,B_2 \\ & \vdots \\ & A_M\,B_M \\ & Q \\ & S_1\,T_1 \\ & S_2\,T_2 \\ & \vdots \\ & S_Q\,T_Q\end{align*}$</p>

### 출력 

 <p>Write $Q$ lines to the standard output. The $k$-th line ($1 ≤ k ≤ Q$) should contain the minimum number of times of taking trains needed for JOI-kun to achieve the $k$-th plan. If it is not possible to achieve the $k$-th plan, output <code>-1</code>.</p>

