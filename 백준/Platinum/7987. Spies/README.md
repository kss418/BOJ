# [Platinum I] Spies - 7987 

[문제 링크](https://www.acmicpc.net/problem/7987) 

### 성능 요약

메모리: 42884 KB, 시간: 184 ms

### 분류

그래프 이론, 그리디 알고리즘

### 제출 일자

2025년 12월 5일 12:26:44

### 문제 설명

<p>Byteotian Intelligence Agency (BIA) employs many spies. Each of them has duty to shadow exactly one other spy.</p>

<p>King Byteasar wants to entrust as many agents as possible with a top secret operation. However, the operation is so important that each spy taking part has to be traced by at least one agent not involved in the operation (assignment of shadowing BIA spies does not change).</p>

<p>Write a programme that:</p>

<ul>
	<li>reads from standard input the description of whom each spy shadows,</li>
	<li>calculates how many agents can be assigned to the operation in a way that each of them would be spied by at least one agent not taking part in the operation,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the input there is one positive integer written, n - the number of spies, 2 ≤ n ≤ 1,000,000. The spies are numbered from 1 to n. In the following n lines there is a description of whom each agent spies. Each of these lines contains one positive integer. A number a<sub>k</sub> situated in line no. k+1 indicates, that the spy no. k shadows the spy no. ak, 1 ≤ k ≤ n, 1 ≤ a<sub>k</sub> ≤ n, a<sub>k</sub>≠k.</p>

### 출력 

 <p>Your programme should write one integer in the first line of the output - the maximal number of spies that can be assigned to the secret operation.</p>

