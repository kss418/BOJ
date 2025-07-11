# [Platinum I] 화물열차 - 1665 

[문제 링크](https://www.acmicpc.net/problem/1665) 

### 성능 요약

메모리: 100488 KB, 시간: 388 ms

### 분류

수학, 정렬, 누적 합, 스위핑, 차분 배열 트릭

### 제출 일자

2025년 7월 1일 23:05:53

### 문제 설명

<p>화물열차가 두 대가 있을 때, 이웃한 레일 위에 놓인 두 화물 열차 사이에 짐을 옮기려고 한다. 화물 열차의 각 칸에는 컨테이너가 놓여 있기도 하고, 놓여 있지 않기도 한데 컨테이너가 놓인 칸이 가장 많이 겹치도록 두 화물 열차를 겹쳐 놓으면 짐을 옮기는 과정이 수월하다.</p>

<p>처음에 두 화물 열차는 아래 그림과 같이 첫 칸의 앞부분이 서로 마주보며 같은 선에 위치하고 있다. 화물 열차 A는 가만히 있고, 화물 열차 B를 움직여 컨테이너가 놓인 칸이 가능한 많이 겹쳐지게 하려고 한다. 화물 열차 B를 몇 칸 앞으로 움직여야 하는지 구하는 프로그램을 작성하시오.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5a0468d3-d509-47ab-868c-6fa364e91f65/-/preview/" style="width: 263px; height: 114px;"></p>

### 입력 

 <p>첫째 줄에는 화물 열차 A에 연속적으로 컨테이너가 놓여 있는 구간의 개수 N이 주어진다. 이어 N줄에는 X<sub>i</sub>와 Y<sub>i</sub> (X<sub>i</sub> ≤ Y<sub>i</sub>)가 공백을 사이에 두고 주어지는데 이는 화물 열차 A의 X<sub>i</sub>칸부터 Y<sub>i</sub>칸까지 컨테이너가 놓여 있음을 의미한다. 다음 줄에는 화물 열차 B에 연속적으로 컨테이너가 놓여 있는 구간의 개수 M이 주어진다. 이어 M줄에는 Z<sub>i</sub>와 W<sub>i</sub> (Z<sub>i</sub> ≤ W<sub>i</sub>)가 공백을 사이에 두고 주어지는데 이는 화물 열차 B의 Z<sub>i</sub>칸부터 W<sub>i</sub>칸까지 컨테이너가 놓여 있음을 의미한다. N과 M은 1,000이하의 자연수이고, X<sub>i</sub>, Y<sub>i</sub>, Z<sub>i</sub>, W<sub>i</sub>는 10<sup>9</sup>이하의 자연수이다.</p>

### 출력 

 <p>첫째 줄에 두 열차의 컨테이너가 놓인 칸이 최대로 겹쳐지게 하기 위하여 화물 열차 B를 몇 칸 앞으로 움직여야 하는지를 출력한다. 최대로 겹쳐지게 하도록 열차 B를 움직이는 칸수가 여러 가지인 경우에는 그 중 최솟값을 출력한다.</p>

