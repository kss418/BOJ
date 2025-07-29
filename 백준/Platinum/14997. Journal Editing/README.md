# [Platinum V] Journal Editing - 14997 

[문제 링크](https://www.acmicpc.net/problem/14997) 

### 성능 요약

메모리: 18404 KB, 시간: 392 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2025년 7월 29일 13:36:48

### 문제 설명

<p>David is writing an article for the Bulletin of the Association of Proof Completions. In his article, he proves several theorems. For every theorem, David came up with a proof. Since David is a very eager student, he even came up with multiple proofs for some of the theorems. As usual, a proof for a theorem may depend on a number of other theorems.</p>

<p>The article has to be as short as possible to publish it, and David only really cares about the main theorem, Theorem 0. In order to achieve this, he has estimated the number of words he will need for every proof. Can you help David find the shortest possible length of his article?</p>

### 입력 

 <ul>
	<li>A single line containing 1 ≤ n ≤ 20, the number of theorems.</li>
	<li>For each theorem:
	<ul>
		<li>A single line containing 1 ≤ p<sub>i</sub> ≤ 10, the number of proofs for the ith theorem.</li>
		<li>p<sub>i</sub> lines, each of the form l, k, d<sub>0</sub>, . . . , d<sub>k−1</sub>, where 0 ≤ l ≤ 10<sup>6</sup> is the length of the proof, 0 ≤ k ≤ n − 1 is the number of theorems the proof depends on, and the 0 ≤ d<sub>i</sub> ≤ n − 1 are the numbers of the theorems the proof depends on.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>Print one line with a single integer, the shortest possible length of David’s article.</p>

