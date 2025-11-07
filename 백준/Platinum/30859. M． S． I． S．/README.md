# [Platinum III] M. S. I. S. - 30859 

[문제 링크](https://www.acmicpc.net/problem/30859) 

### 성능 요약

메모리: 3212 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2025년 11월 7일 15:46:55

### 문제 설명

<p>We are given a $2 \times n$ matrix $M$ of positive integers, and each row of $M$ does not contain duplicate numbers. For $i$-th row $r_i$ of $M$, $i = 1, 2$, we find the maximum sum $s_i$ of increasing subsequence contained in $r_i$. For example, if $M$ is given as the figure below, $s_1$ is $1 + 2 + 3 + 4 + 5 + 6$ and $s_2$ is $2 + 3 + 5$. We call $s_1 + s_2$ <em>the maximum sum of increasing subsequences, MSIS</em>.</p>

<p>$$\begin{bmatrix} \color{red}{1} & \color{red}{2} & \color{red}{3} & \color{red}{4} & \color{red}{5} & \color{red}{6}\\ 6 & \color{red}{2} & \color{red}{3} & \color{red}{5} & 4 & 1 \end{bmatrix}$$</p>

<p>Once we permute the columns of $M$, MSIS can change. For example, if we permute the columns of the above matrix $M = [c_1\, c_2\, c_3\, c_4\, c_5\, c_6]$ to $[c_2\, c_3\, c_4\, c_5\, c_6\, c_1]$ as the figure below, MSIS becomes $36$.</p>

<p>$$\begin{bmatrix} \color{red}{2} & \color{red}{3} & \color{red}{4} & \color{red}{5} & \color{red}{6} & 1 \\ \color{red}{2} & \color{red}{3} & \color{red}{5} & 4 & 1 & \color{red}{6} \end{bmatrix}$$</p>

<p>Given a $2 \times n$ matrix $M$, write a program to output the maximum of MSIS among all possible permutations of the columns of $M$.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer, $n$ ($1 ≤ n ≤ 10\,000$), where $n$ is the number of columns of the input matrix $M$. In the following two lines, the $i$-th line contains $n$ positive integers of the $i$-th row of $M$, for $i = 1, 2$. The integers given as input are between $1$ and $50\,000$, and each row does not contain duplicate numbers.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the maximum of MSIS among all possible permutations of columns of $M$.</p>

