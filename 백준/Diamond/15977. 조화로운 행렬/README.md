# [Diamond IV] 조화로운 행렬 - 15977 

[문제 링크](https://www.acmicpc.net/problem/15977) 

### 성능 요약

메모리: 43732 KB, 시간: 528 ms

### 분류

자료 구조, 분할 정복, 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열: O(n log n), 다차원 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 11월 3일 15:46:36

### 문제 설명

<p>서로 다른 양의 정수로 구성된 2×<em>N</em> 또는 3×<em>N</em> 행렬(이차원 배열)을 고려 하자. 어떤 행렬 <em>Q</em>가 주어졌을 때, 1개 이상의 열을 선택하여 순서대로 붙여 만든 행렬을 <em>Q</em>의 열-부분행렬이라 한다. (<em>Q</em>도 자신의 열-부분행렬이다.)</p>

<p>예를 들어, 행렬 <em>Q</em>가 다음과 같이 주어졌을 때,</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e9d26371-63c3-4ebf-bd18-f3d76de06948/-/preview/" style="width: 296px; height: 98px;"></p>

<p>다음 행렬 <em>X</em>는 <em>Q</em>에서 2열, 3열, 5열, 6열, 8열을 선택하여 만든 열-부분행렬 이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fd94564e-52d0-4dc4-b614-4206c7031f39/-/preview/" style="width: 182px; height: 78px;"></p>

<p>행렬 <em>X</em>의 <strong>등수행렬</strong> <em>R<sub>X</sub></em>를 다음과 같이 정의하자. 행렬 <em>R<sub>X</sub></em>의 <em>i</em>행 <em>j</em>열 원소 <em>R<sub>X</sub></em>[<em>i</em>, <em>j</em>]는 행렬 <em>X</em>의 <em>i</em>행 <em>j</em>열의 원소 <em>X</em>[<em>i</em>, <em>j</em>]가 <em>X</em>의 <em>i</em>번째 행에서 몇 등(가장 큰 수가 1등)인지 나타낸다. <em>X</em>의 등수 행렬 <em>R<sub>X</sub></em>는 다음과 같다. (원본 행렬 <em>Q</em>의 원소는 모두 다르므로, <em>R<sub>X</sub></em>의 각 행에서 같은 등수는 존재하지 않는다.)</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6d780baa-9c74-403d-98aa-57e7fd901e89/-/preview/" style="width: 183px; height: 75px;"></p>

<p><em>X</em>[1,1]에 저장된 74는 <em>X</em>의 1행 원소들 74, 41, 89, 52, 63 중에서 두 번째로 크므로 <em>R<sub>X</sub></em>[1, 1]에 2가 저장된다. 다른 원소 값도 비슷하게 계산된다.</p>

<p>어떤 열-부분행렬의 등수행렬에서 모든 행이 일치하면, 그 열-부분행렬을 <strong>조화로운</strong> 행렬이라고 한다. <em>R<sub>X</sub></em>의 경우, 1행과 3행은 일치하나, 2행은 다른 행과 일치하지 않으므로 조화로운 행렬이 아니다.</p>

<p>다음은 행렬 <em>Q</em>에서 2열, 3열, 6열, 8열을 선택하여 만든 열-부분행렬 <em>Y</em>와 이의 등수행렬 <em>R<sub>Y</sub></em>이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/70b6236b-deb5-4c11-bc82-8ca402ac4e6b/-/preview/" style="width: 299px; height: 77px;"></p>

<p>등수행렬 <em>R<sub>Y</sub></em>의 모든 행이 일치하므로 열-부분행렬 <em>Y</em>는 조화로운 행렬이다. 행렬 <em>Q</em>의 조화로운 열-부분행렬 중 가장 큰 행렬의 크기는 3×4이다.</p>

<p>2×<em>N</em> 또는 3×<em>N</em> 행렬 <em>Q</em>가 주어졌을 때, <em>Q</em>의 조화로운 열-부분행렬 중 가장 큰 행렬의 열 개수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>표준 입력으로 행의 개수 <em>M</em>과 열의 개수 <em>N</em>이 첫 줄에 입력된다. 다음 <em>M</em>개의 줄에 각 행의 정보가 한 줄에 하나씩 입력된다. 한 줄에는 한 행의 원소를 나타내는 <em>N</em>개의 양의 정수가 열 순서대로 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>조화로운 열-부분행렬 중 가장 큰 행렬의 열 개수를 나타내는 정수를 표준 출력으로 출력한다.</p>

