# [Platinum III] Next Permutation - 12825 

[문제 링크](https://www.acmicpc.net/problem/12825) 

### 성능 요약

메모리: 3656 KB, 시간: 0 ms

### 분류

애드 혹

### 제출 일자

2025년 11월 27일 16:53:03

### 문제 설명

<p>Permutations are intensively studied in mathematics and computer science. Pattern avoiding permutations are of special interest. A permutation p<sub>1</sub>, p<sub>2</sub>, . . . , p<sub>n</sub> of the natural numbers 1, . . . , n is called 3-1-2 pattern avoiding if there are no three indices 1 ≤ i < j < k ≤ n such that p<sub>i</sub> > p<sub>j</sub> , p<sub>i</sub> > p<sub>k</sub> and p<sub>j</sub> < p<sub>k</sub>.</p>

<p>Write a program that computes for a given 3-1-2 pattern avoiding permutation the next 3-1-2 pattern avoiding permutation according to the lexicographic ordering.</p>

### 입력 

 <p>The first line of the input contains one integer n (3 ≤ n ≤ 10000). The second line contains n positive integers separated by single spaces, a 3-1-2 pattern avoiding permutation of the natural numbers 1, . . . , n. The input is not the decreasing sequence n, n − 1, . . . , 1.</p>

### 출력 

 <p>The first line of the output must contain the 3-1-2 pattern avoiding permutation that follows the input permutation in the lexicographic ordering. The numbers must be separated by a single space.</p>

