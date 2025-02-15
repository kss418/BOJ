# [Gold I] kdh9949 - 17455 

[문제 링크](https://www.acmicpc.net/problem/17455) 

### 성능 요약

메모리: 20176 KB, 시간: 164 ms

### 분류

방향 비순환 그래프, 다이나믹 프로그래밍, 그래프 이론, 위상 정렬

### 제출 일자

2025년 2월 15일 19:55:57

### 문제 설명

<p>SNUPS 회장 동현이가 쓰는 ID인 <code>kdh9949</code>는 도대체 무슨 뜻일까? 바로 동현이의 생일이 19<strong>99</strong>년 <strong>4</strong>월 <strong>9</strong>일이라는 뜻이다!</p>

<p>어느덧 4월 9일이 다가왔고, 동현이는 생일 선물로 각 정점에 알파벳 <code>K</code>, <code>D</code>, 또는 <code>H</code>가 적힌 정점 <span style="font-style: italic;">N</span>개, 간선 <span style="font-style: italic;">M</span>개짜리 양방향 그래프를 받았다. 정성 가득한 선물에 감동을 받은 동현이는 이 그래프에 특별한 의미를 부여하고 싶어졌다.</p>

<p>그래서, 동현이는 이 그래프에서 자신의 이니셜인 <code>KDH</code>가 연속적으로 나타나는 가장 긴 경로가 찾고 싶어졌다. 즉, 다음과 같이 정의된 경로 중 길이가 최대인 것을 찾고 싶어졌다.</p>

<ul>
	<li><span style="font-style: italic;">C</span><sub><span style="font-style: italic;">i</span></sub> : <span style="font-style: italic;">i</span>번 정점에 적힌 글자, <span style="font-style: italic;">X</span><sub><span style="font-style: italic;">j</span></sub> : 경로에서 <span style="font-style: italic;">j</span>번째로 나타나는 정점의 번호라 하자.</li>
	<li>경로의 길이 <span style="font-style: italic;">P</span>는 3의 배수이다.</li>
	<li>모든 정수 1 ≤ <span style="font-style: italic;">i</span> ≤ <span style="font-style: italic;">P</span>-1에 대해, <span style="font-style: italic;">X</span><sub><span style="font-style: italic;">i</span></sub>번 정점과 <span style="font-style: italic;">X</span><sub><span style="font-style: italic;">i</span>+1</sub>번 정점은 간선으로 직접 연결되어 있다.</li>
	<li>모든 정수 1 ≤ <span style="font-style: italic;">k</span> ≤ <span style="display: inline-block; position: relative; vertical-align: middle; letter-spacing: 0.001em; text-align: center;"><span style="display: block; padding: 0.1em;"><span style="font-style: italic;">P</span></span><span style="display: none; padding: 0.1em;">/</span><span style="display: block; padding: 0.1em; border-top: thin solid black;">3</span></span>에 대해, <span style="font-style: italic;">C</span><sub><span style="font-style: italic;">X</span><sub>3<span style="font-style: italic;">k</span>-2</sub></sub> = <code>K</code>, <span style="font-style: italic;">C</span><sub><span style="font-style: italic;">X</span><sub>3<span style="font-style: italic;">k</span>-1</sub></sub> = <code>D</code>, <span style="font-style: italic;">C</span><sub><span style="font-style: italic;">X</span><sub>3<span style="font-style: italic;">k</span></sub></sub> = <code>H</code> 를 만족한다.</li>
</ul>

<p>위 조건을 만족하는 가장 긴 경로의 길이를 출력하라. 단, <strong>무한히 긴 경로가 존재하는 등</strong>의 이유로 그런 경로가 존재하지 않으면 <code>-1</code>을 출력한다.</p>

### 입력 

 <p>첫 줄에 동현이가 받은 그래프의 정점 개수 <span style="font-style: italic;">N</span>과 간선 개수 <span style="font-style: italic;">M</span>이 주어진다. (2 ≤ <span style="font-style: italic;">N</span> ≤ 200,000, 1 ≤ <span style="font-style: italic;">M</span> ≤ 300,000)</p>

<p>두 번째 줄에 길이 <span style="font-style: italic;">N</span>의 문자열이 주어지는데, 이 문자열의 <span style="font-style: italic;">i</span>번째 글자가 그래프의 <span style="font-style: italic;">i</span>번 정점에 적힌 글자이다. 문자열의 각 문자는 <code>K</code> 또는 <code>D</code> 또는 <code>H</code>임이 보장된다.</p>

<p>다음 <span style="font-style: italic;">M</span>개의 줄에 걸쳐 각 간선이 잇는 두 정점의 번호 <span style="font-style: italic;">U</span>, <span style="font-style: italic;">V</span>가 주어진다. 루프나 중복 간선이 없음이 보장된다. (1 ≤ <span style="font-style: italic;">U</span> ≤ <span style="font-style: italic;">N</span>, 1 ≤ <span style="font-style: italic;">V</span> ≤ <span style="font-style: italic;">N</span>, <span style="font-style: italic;">U</span> ≠ <span style="font-style: italic;">V</span>)</p>

### 출력 

 <p>동현이가 조건을 만족하며 만들 수 있는 가장 긴 경로의 길이를 출력한다. 단, 무한히 긴 경로가 존재하는 등의 이유로 그런 경로가 존재하지 않으면 <code>-1</code>을 출력한다.</p>

