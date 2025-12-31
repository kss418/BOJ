# [Gold III] 구간 합 최대? 1 - 15560 

[문제 링크](https://www.acmicpc.net/problem/15560) 

### 성능 요약

메모리: 2264 KB, 시간: 0 ms

### 분류

수학, 다이나믹 프로그래밍

### 제출 일자

2025년 12월 31일 13:49:33

### 문제 설명

<p>길이 <em>N</em>의 수열 <em>K</em><sub>1</sub>, <em>K</em><sub>2</sub>, ..., <em>K</em><sub><em>N</em></sub>과 상수 <em>U</em>, <em>V</em>가 주어진다.</p>

<p><em>Q</em>개의 쿼리가 주어지며, 그 종류는 두 가지가 있다.</p>

<ol>
	<li><em>A</em>, <em>B</em>가 주어지면, <em>max</em>(<em>U</em> × (<em>K</em><sub><em>i</em></sub> + <em>K</em><sub><em>i</em> + 1</sub> + ... + <em>K</em><sub><em>j</em></sub>) + <em>V</em> × (<em>j</em> - <em>i</em>)) (<em>A</em> ≤ <em>i</em> ≤ <em>j</em> ≤ <em>B</em>) 의 값을 구한다.</li>
	<li><em>A</em>, <em>B</em>가 주어지면, <em>K</em><sub><em>A</em></sub>의 값을 <em>B</em>으로 바꾼다.</li>
</ol>

### 입력 

 <p>첫 번째 줄에 정수 <em>N</em>과 <em>Q</em>, <em>U</em>, <em>V</em>가 입력된다. (1 ≤ <em>N</em>, <em>Q</em> ≤ 10<sup>3</sup>,  - 5 ≤ <em>U</em>, <em>V</em> ≤ 5)</p>

<p>두 번째 줄에 정수 <em>K</em><sub>1</sub>, <em>K</em><sub>2</sub>, ..., <em>K</em><sub><em>N</em></sub>이 주어진다. ( - 10<sup>2</sup> ≤ <em>K</em><sub><em>i</em></sub> ≤ 10<sup>2</sup>)</p>

<p>세 번째 줄부터 쿼리가 주어진다. 세 수 <em>C</em>, <em>A</em>, <em>B</em>가 주어진다. (1 ≤ <em>A</em>, <em>B</em> ≤ <em>N</em>, 0 ≤ <em>C</em> ≤ 1)</p>

<p><em>C</em>가 0이면 첫 번째 쿼리를, 아니면 두 번째 쿼리를 수행한다. 첫 번째 쿼리일 경우 1 ≤ <em>A</em> ≤ <em>B</em> ≤ <em>N</em> 이다. 두 번째 쿼리일 경우 1 ≤ <em>A</em> ≤ <em>N</em>,  - 10<sup>2</sup> ≤ <em>B</em> ≤ 10<sup>2</sup>이다.</p>

### 출력 

 <p>한 줄마다 첫 번째 쿼리의 결과값을 출력한다.</p>

