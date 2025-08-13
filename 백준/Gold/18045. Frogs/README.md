# [Gold II] Frogs - 18045 

[문제 링크](https://www.acmicpc.net/problem/18045) 

### 성능 요약

메모리: 14676 KB, 시간: 376 ms

### 분류

자료 구조, 우선순위 큐, 정렬, 스위핑

### 제출 일자

2025년 8월 13일 13:05:19

### 문제 설명

<p>You may think that frogs are only good for leaping and croaking, but it turns out that they are also quite proficient coders! Your task is to choose three frogs which would form the best team for OpenFrogCup.</p>

<p>In the frogs’ favourite pond there are <em>n</em> stones in a row, spaced 1 meter apart from each other. On every stone, a frog sits. Stones (and frogs) are numbered 1, 2, . . . , <em>n</em> from the leftmost to the rightmost one. The <em>i</em>-th frog sits on <em>i</em>-th stone and is described by two parameters: its leap range <em>r<sub>i</sub></em> and its programming skill <em>s<sub>i</sub></em>. The frog can reach any stone which is not farther than <em>r<sub>i</sub></em> meters (in other words, any stone with index <em>j</em> in [<em>i</em> − <em>r<sub>i</sub></em>, <sub>i</sub> + <em>r<sub>i</sub></em>]). Each frog is willing to jump at most once.</p>

<p>The team for OpenFrogCup must consist of exactly three members which can train together. This means that there must be a stone that all three frogs can jump to (allowing zero-length jumps). Determine the largest possible sum of programming skills of such a team.</p>

<p>The limits for the problem guarantee that there always exists at least one possible three-frog team.</p>

### 입력 

 <p>The first line of input contains the number of test cases <em>z</em> (1 ≤ <em>z</em> ≤ 30). The test cases follow, each one in the following format:</p>

<p>The first line of a test case contains an integer <em>n</em> (3 ≤ <em>n</em> ≤ 200 000) – the number of stones (and also the frogs). Each of the following <em>n</em> lines contain two integers <em>r<sub>i</sub></em>, <em>s<sub>i</sub></em> (1 ≤ <em>r<sub>i</sub></em>, <em>s<sub>i</sub></em> ≤ 200 000) – the range and the skill of the <em>i</em>-th frog, respectively.</p>

<p>The sum of <em>n</em> values over all test cases does not exceed 500 000.</p>

### 출력 

 <p>For every test case, output a single integer – the largest possible sum of skills of a three-frog team.</p>

