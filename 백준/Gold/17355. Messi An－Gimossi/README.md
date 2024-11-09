# [Gold II] Messi An-Gimossi - 17355 

[문제 링크](https://www.acmicpc.net/problem/17355) 

### 성능 요약

메모리: 172272 KB, 시간: 468 ms

### 분류

수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 11월 9일 12:19:51

### 문제 설명

<p><a href="https://www.acmicpc.net/user/messi">메시</a>는 축구 선수이다. 메시는 기분이 안 좋다.</p>

<p>messi: <em>Messi An-Gimossi</em></p>

<p>메시의 기분은 예측 가능하다. N일의 기분 예보가 있다. <strong>기분이 나쁠 확률</strong>이 각 날마다 기약분수 A/B 꼴로 주어진다.</p>

<p>기분이 나쁜 것이 독립적인 사건이라 할 때, 메시의 기분이 <strong>매일 좋을 확률(N일 내내 좋을 확률)</strong>을 기약분수로 구해 보자.</p>

### 입력 

 <p>첫째 줄에 예보의 수 N이 주어진다. (1 ≤ N ≤ 10<sup>5</sup>)</p>

<p>둘째 줄부터 N개의 줄에 걸쳐, A<sub>i</sub>와 B<sub>i</sub>가 주어진다. 이는 i번째 날에 기분이 나쁠 확률이 A<sub>i</sub>/B<sub>i</sub>라는 뜻이다. (1 ≤ A<sub>i</sub> < B<sub>i</sub> ≤ 10<sup>7</sup>, A<sub>i</sub>와 B<sub>i</sub>는 서로소인 정수)</p>

### 출력 

 <p>메시의<strong> </strong>기분이 <strong>N일 내내 좋을 확률</strong>이 기약분수 A/B와 같다고 할 때, A를 10<sup>9</sup>+7로 나눈 나머지와 B를 10<sup>9</sup>+7로 나눈 나머지를 공백을 사이에 두고 차례대로 출력한다.</p>

