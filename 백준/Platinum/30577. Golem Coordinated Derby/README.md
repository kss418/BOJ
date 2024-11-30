# [Platinum V] Golem Coordinated Derby - 30577 

[문제 링크](https://www.acmicpc.net/problem/30577) 

### 성능 요약

메모리: 346876 KB, 시간: 276 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 그리디 알고리즘, 수학, 외판원 순회 문제

### 제출 일자

2024년 11월 30일 22:55:07

### 문제 설명

<p>Robotic labs in Tomorrow Programming School produce minirobots in big numbers. To perform various complex tasks, robots often form teams. Before the task begins, a team measures its strength. The robots in the team select one robot among themselves to be the team captain. Next, the robots arrange themselves in one row behind the captain. Each robot refers to the captain the value of the greatest common divisor of its own height and the height of the neighbour robot standing directly in front of it. That value predicts the strength of the bond between these robots when they perform the task. The captain totals all received values and claims the total to be the strength of the team.</p>

<p>The height of each robot is always expressed in centimeters and it is an integer ranging from 1 to 20. The strength of the team depends on the order of the robots in the row behind the captain. Also note, that a selection of the captain also influences the team strength. Any robot in a team can be selected as its captain.</p>

<p>The robots in a team always tend to maximize the team strength by selecting an appropriate captain and positioning themselves appropriately in the row. However, that is not an easy exercise for the robots, because checking all their possible arrangements is often beyond their computational scope.</p>

### 입력 

 <p>The first input line contains one integer N (2 ≤ N ≤ 10<sup>5</sup>), the number of robots in the team. The second line contains N space-separated integers A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ 20), the list of heights of all robots in the team.</p>

### 출력 

 <p>Output a single integer, the maximum strength of the team specified in the input.</p>

