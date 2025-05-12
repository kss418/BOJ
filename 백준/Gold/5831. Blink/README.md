# [Gold III] Blink - 5831 

[문제 링크](https://www.acmicpc.net/problem/5831) 

### 성능 요약

메모리: 28724 KB, 시간: 20 ms

### 분류

비트마스킹, 브루트포스 알고리즘, 그래프 이론, 구현, 수학

### 제출 일자

2025년 5월 12일 13:07:34

### 문제 설명

<p>Unhappy with the dim lighting in his barn, Farmer John has just installed a fancy new chandelier consisting of N (3 <= N <= 16) lights bulbs arranged in a circle.</p>

<p>The cows are fascinated by this new light fixture, and enjoy playing the following game: at time T, they toggle the state of each light bulb if its neighbor to the left was turned on at time T-1. They continue this game for B units of time (1 <= B <= 10^15). Note that B might be too large to fit into a standard 32-bit integer.</p>

<p>Given the initial states of the light bulbs, please determine their final states after B units of time have elapsed.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, N and B.</li>
	<li>Lines 2..1+N: Line i+1 contains the initial state of bulb i, either 0 (off) or 1 (on).</li>
</ul>

### 출력 

 <ul>
	<li>Lines 1..N: Line i should contain the final state of bulb i, either 0 (off) or 1 (on).</li>
</ul>

