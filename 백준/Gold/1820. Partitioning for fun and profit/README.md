# [Gold II] Partitioning for fun and profit - 1820 

[문제 링크](https://www.acmicpc.net/problem/1820) 

### 성능 요약

메모리: 6256 KB, 시간: 36 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2025년 8월 10일 13:00:25

### 문제 설명

<p>A partition of a positive integer number <em>m</em> into <em>n</em> elements (<em>n</em> ≤ <em>m</em>) is a sequence of positive numbers <em>a<sub>1</sub></em>,...,<em>a<sub>n</sub></em> such that <em>a<sub>1</sub></em>+...+<em>a<sub>n</sub></em> = <em>m</em> and <em>a<sub>1</sub></em> ≤ <em>a<sub>2</sub></em> ≤ ... ≤ <em>a<sub>n</sub></em>. Your task is to find a partition of a number <em>m</em> which occupies the <em>k</em>-th position in the lexicographically ordered sequence of all partitions of <em>m</em> into <em>n</em> elements.</p>

<p>The lexicographic ordering among the partitions of a number is defined as follows. For two partitions <em>a</em> and <em>b</em> of <em>m</em> into <em>n</em> elements such that <em>a</em> = [<em>a<sub>1</sub></em>,...,<em>a<sub>n</sub></em>] and <em>b</em> = [<em>b<sub>1</sub></em>,...,<em>b<sub>n</sub></em>] we have <em>a</em>  <  <em>b</em> if and only if there exists an 1 ≤ <em>i</em> ≤ <em>n</em> such that for all <em>j</em> < <em>i</em> we have <em>a<sub>j</sub></em> = <em>b<sub>j</sub></em> and <em>a<sub>i</sub></em> < <em>b<sub>i</sub></em>. The sequence of all partitions is ordered in increasing lexicographic order and at the first we have the following sequence 1, 1, ... 1, <em>m</em>-<em>n</em>+1.</p>

### 입력 

 <p>The first line of input contains a number <em>c</em> giving the number of cases that follow. Each of the subsequent <em>c</em> lines contains three numbers: 1 ≤ <em>m</em> ≤ <em>220</em>, 1 ≤ <em>n</em> ≤ <em>10</em> and 1 ≤ <em>k</em> which is not bigger than the number of partitions of <em>m</em> into <em>n</em> elements.</p>

### 출력 

 <p>For each input data set print the <em>k</em>-th partition of <em>m</em> into <em>n</em> elements. Each element of a partition is to be printed in a separate line.</p>

