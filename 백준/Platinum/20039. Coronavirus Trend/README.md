# [Platinum III] Coronavirus Trend - 20039 

[문제 링크](https://www.acmicpc.net/problem/20039) 

### 성능 요약

메모리: 36812 KB, 시간: 928 ms

### 분류

값 / 좌표 압축, 자료 구조, 다이나믹 프로그래밍, 세그먼트 트리

### 제출 일자

2025년 9월 15일 15:01:33

### 문제 설명

<p>Finally, the pandemic comes to an end and scientists start to study the cause and process of it. Specially, a group of scientists is paying attention to the world’s daily record of confirmed cases. They have a sequence <em>Q</em> of <em>n</em> daily confirmed cases. It is assumed that all <em>n</em> positive integers in the sequence <em>Q</em> are different. The figure below is a graph showing the actual pandemic situation that occurred during a specific period.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d5e57326-a19d-4cb8-87c7-5a3f0698bada/-/preview/" style="width: 652px; height: 160px;"></p>

<p>They are interested in the pattern of the repetition of successive increases and successive decreases in the sequence of confirmed cases while observing the spread of the virus. A run in the sequence of distinct numbers is a maximal contiguous subsequence that is either increasing or decreasing. For example, the sequence (8,5,1,3,4,7,6,2) consists of three runs (8,5,1), (1,3,4,7), and (7,6,2), which have lengths 3, 4, and 3, respectively. The sequence (8,5,1,7,6,2,3,4) consists of four runs (8,5,1), (1,7), (7,6,2), and (2,3,4).</p>

<p>A sequence of distinct numbers whose every run has a length of at least 3 is said to be an UD-sequence. The sequence (8,5,1,3,4,7,6,2) is an UD-sequence, but (8,5,1,7,6,2,3,4) is not an UD-sequence because it has a run (1,7) with length 2.</p>

<p>Scientists believe that a run with length less than 3 is insufficient to reflect the trend of confirmed cases, so they try to find a longest UD-sequence which is a subsequence of <em>Q</em>. The sequence (8,5,1,3,4,7,6,2) is itself the longest UD-sequence, and the longest UD-sequence of (8,5,1,7,6,2,3,4) is (8,5,1,2,3,4) with length 6.</p>

<p>Write a program to find a longest UD-sequence which is a subsequence of a given sequence <em>Q</em> of <em>n</em> daily confirmed cases in order to help them.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing one integer <em>n</em> (3 ≤ <em>n</em> ≤ 500,000), where <em>n</em> is the number of days observed. The second line contains <em>n</em> positive integers, separated by a space, representing <em>n</em> daily confirmed cases, where they are all different and no more than 10<sup>9</sup>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain an integer which represents the length of a longest UD-sequence, as a subsequence of the given input. If the input sequence has no UD-sequence as its subsequence, print 0.</p>

