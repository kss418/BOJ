# [Platinum III] Popular Cows - 27045 

[문제 링크](https://www.acmicpc.net/problem/27045) 

### 성능 요약

메모리: 5920 KB, 시간: 8 ms

### 분류

그래프 이론, 강한 연결 요소

### 제출 일자

2025년 2월 11일 14:17:11

### 문제 설명

<p>Every cow's dream is to become the most popular cow in the herd.  In a herd of N (1 ≤ N ≤ 10,000) cows, you are given up to M (1 ≤ M ≤ 50,000) ordered pairs of the form (A, B) that tell you that cow A thinks that cow B is popular.  Since popularity is transitive, if A thinks B is popular and B thinks C is popular, then A will also think that C is popular, even if this is not explicitly specified by an ordered pair in the input.  Your task is to compute the number of cows that are considered popular by every other cow.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, N and M</li>
	<li>Lines 2..1+M: Two space-separated numbers A and B, meaning that A thinks B is popular.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of cows who are considered popular by  every other cow.</li>
</ul>

