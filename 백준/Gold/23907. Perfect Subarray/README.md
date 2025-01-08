# [Gold I] Perfect Subarray - 23907 

[문제 링크](https://www.acmicpc.net/problem/23907) 

### 성능 요약

메모리: 160640 KB, 시간: 12940 ms

### 분류

수학, 누적 합

### 제출 일자

2025년 1월 8일 20:35:33

### 문제 설명

<p>Cristobal has an array of <b>N</b> (possibly negative) integers. The i-th integer in his array is <b>A<sub>i</sub></b>. A contiguous non-empty subarray of Cristobal's array is <i>perfect</i> if its total sum is a <a href="https://en.wikipedia.org/wiki/Square_number">perfect square</a>. A perfect square is a number that is the product of a non-negative integer with itself. For example, the first five perfect squares are 0, 1, 4, 9 and 16.</p>

<p>How many subarrays are <i>perfect</i>? Two subarrays are different if they start or end at different indices in the array, even if the subarrays contain the same values in the same order.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. The first line of each test case contains the integer <b>N</b>. The second line contains <b>N</b> integers describing Cristobal's array. The i-th integer is <b>A<sub>i</sub></b>.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is the number of perfect subarrays.</p>

