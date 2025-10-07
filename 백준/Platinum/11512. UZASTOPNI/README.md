# [Platinum I] UZASTOPNI - 11512 

[문제 링크](https://www.acmicpc.net/problem/11512) 

### 성능 요약

메모리: 31076 KB, 시간: 112 ms

### 분류

비트 집합, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2025년 10월 7일 21:20:32

### 문제 설명

<p>Petar is throwing a birthday party and he decided to invite some of the employees of his company where he is the CEO.</p>

<p>Each employee, including Petar, has a unique label from 1 to N, and an accompanying type of jokes they tell V<sub>i</sub>. Also, each employee of the company except Petar has exactly one supervisor.</p>

<p>Since Petar is the CEO of the company, he has the label 1 and is directly or indirectly superordinate to all the employees.</p>

<p>At the birthday party, there are certain rules that all people present (including Petar) must follow.</p>

<ul>
	<li>At the party, there shouldn’t be two people that tell the same type of jokes.</li>
	<li>Person X cannot be invited if their direct supervisor is not invited.</li>
	<li>Person X cannot be invited if the set of jokes the invitees that person X is superior to (directly or indirectly) tell and person X don’t form a set of consecutive numbers.</li>
</ul>

<p>The numbers in the set are consecutive if the difference between adjacent elements is exactly 1 when the set is sorted ascendingly. For example, (3, 1, 2) and (5, 1, 2, 4, 3).</p>

<p>Petar wants to know how many different sets of jokes he can see at his party with the listed constraints. </p>

### 입력 

 <p>The first line of input contains the integer N, (1 ≤ N ≤ 10 000).</p>

<p>The second line of input contains N integers, the types of jokes person i tells, V<sub>i</sub>, (1 ≤ V<sub>i</sub> ≤ 100).</p>

<p>Each of the following N-1 lines contains two integers A and B, (1 ≤ A, B ≤ N), denoting that person A is directly superior to person B. </p>

### 출력 

 <p>The first and only line of output must contain the number of different sets of jokes that comply to the previously listed constraints.</p>

