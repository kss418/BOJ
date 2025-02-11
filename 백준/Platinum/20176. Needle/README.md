# [Platinum I] Needle - 20176 

[문제 링크](https://www.acmicpc.net/problem/20176) 

### 성능 요약

메모리: 8784 KB, 시간: 44 ms

### 분류

고속 푸리에 변환, 수학

### 제출 일자

2025년 2월 11일 11:14:39

### 문제 설명

<p>The “needle” is a legendary assassin who lives in the North Kingdom. As you know, the needle is very thin and long. More than anything, it is deadly sharp. The king of the North Kingdom is obsessed with the idea that the needle might kill him by stabbing countless times. The king issued an emergency order to arrest the needle. So, the needle decided to escape to the South Kingdom.</p>

<p>As shown in the figure below, the border between two kingdoms consists of three horizontal barriers (line segments), each of which has one or more infinitesimally small holes inside. (The holes are marked as x in the figure.) Three barriers have the same length and are aligned vertically as in the figure. The upper barrier is one unit above the middle barrier, which is one unit above the lower barrier. Two kingdoms are surrounded by impenetrable outer wall. Each kingdom also has a very large territory so that the needle can move (translate or rotate) freely inside the kingdom. The needle is at least twice as long as the barriers. The needle is rigid, i.e., not bendable, and has zero-thickness, so it can pass the holes freely, but cannot drill any other part of the barriers than the holes.</p>

<p>The only way from the Northern Kingdom to the Southern Kingdom is through three holes, one from each of the three barriers, at the same time. In other words, the needle can pass the border only through three holes, exactly one from each barrier, which are aligned on a line. The border in the figure has two possible escape passages from the north to the south.</p>

<p>For this pity assassin, write a program to tell how many possible escape passages from the North Kingdom to the South Kingdom are available.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ba6c16d8-ae84-4b90-91cc-b3a7ecdbc411/-/preview/" style="width: 399px; height: 353px;"></p>

### 입력 

 <p>Your program is to read from standard input. The input consists of six lines. The first line contains a positive integer <em>n<sub>u</sub></em> representing the number of holes of the upper barrier. The second line contains <em>n<sub>u</sub></em> integers separated by a space that represent the <em>x</em>-coordinates of the holes. The third and fourth lines are for the middle barrier, each containing <em>n<sub>m</sub></em>, the number of holes of the middle barrier, and <em>n<span style="font-size: 10.8333px;">m</span></em> <em>x</em>-coodinates of the holes. The fifth and sixth lines are for the lower barrier, each containing <em>n<sub>l</sub></em>, the number of holes of the lower barrier, and <em>n<sub>l</sub></em> <em>x</em>-coodinates of the holes. 1 ≤ <em>n<sub>u</sub></em>, <em>n<sub>m</sub></em>, <em>n<sub>l</sub></em> ≤ 50,000 and all <em>x</em>-coordinates of the holes are integers between −30,000 and 30,000. Holes of each barrier have all distinct <em>x</em>-coordinates.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain a nonnegative integer representing the number of all possible passages from the north to the south.</p>

