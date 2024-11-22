# [Gold V] ONE - 3264 

[문제 링크](https://www.acmicpc.net/problem/3264) 

### 성능 요약

메모리: 10588 KB, 시간: 36 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 그리디 알고리즘

### 제출 일자

2024년 11월 22일 13:31:30

### 문제 설명

<p>The city consists of intersections and streets that connect them.</p>

<p>Heavy snow covered the city so the mayor Milan gave to the winter-service a list of streets that have to be cleaned of snow. These streets are chosen such that the number of streets is as small as possible but still every two intersections to be connected i.e. between every two intersections there will be exactly one path. The winter service consists of one snow plover and one driver Mirko and his starting position is on one of the intersections.</p>

<p>The snow plover burns one liter of fuel per meter (even if it is driving through a street that has already been cleared of snow) and it has to clean all streets from the list in such order so the total fuel spent is minimal. When all the streets are cleared of snow, the snow plover is parked on the last intersection it visited.</p>

<p>Write a program that calculates the total amount of fuel that the snow plover will spend.</p>

### 입력 

 <p>The first line of the input file contains two integers: N and S, 1 ≤ N ≤ 100000, 1 ≤ S ≤ N. N is the total number of intersections; S is ordinal number of the snow plover starting intersection. Intersections are marked with numbers 1..N.</p>

<p>Each of the next N-1 lines contains three integers: A, B and C, meaning that intersections A and B are directly connected by a street and that street’s length is C meters, 1 ≤ C ≤ 1000.</p>

### 출력 

 <p>Write to the output file the minimal amount of fuel needed to clean all streets.</p>

