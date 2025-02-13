# [Gold I] 괄호의 값 비교 - 22343 

[문제 링크](https://www.acmicpc.net/problem/22343) 

### 성능 요약

메모리: 87052 KB, 시간: 276 ms

### 분류

임의 정밀도 / 큰 수 연산, 자료 구조, 구현, 스택

### 제출 일자

2025년 2월 13일 22:46:58

### 문제 설명

<p>여는 괄호 <code>(</code>와 닫는 괄호 <code>)</code>를 이용해서 만들어지는 문자열 중에서 <strong>올바른 괄호열</strong>이란 다음과 같이 정의 된다.</p>

<ul>
	<li>한 쌍의 괄호로만 이루어진 문자열 <code>()</code>는 올바른 괄호열이다.</li>
	<li>X가 올바른 괄호열이면, X를 괄호로 감싼 <code>(</code>X<code>)</code>도 올바른 괄호열이다.</li>
	<li>X와 Y 가 올바른 괄호열이면, X와 Y 를 이어 붙인 XY도 올바른 괄호열이다.</li>
	<li>모든 올바른 괄호열은 위 세 가지 규칙을 통해서만 만들어진다.</li>
</ul>

<p>예를 들어 <code>(()(()))</code>나 <code>(())()()</code>는 올바른 괄호열이지만, <code>(()</code>나 <code>)((()()</code>은 모두 올바른 괄호열이 아니다. 우리는 올바른 괄호열 X에 대하여 그 괄호열의 값(<strong>괄호값</strong>)을 아래와 같이 정의하고 f[X]로 표시한다.</p>

<ul>
	<li>f[<code>()</code>] = 1</li>
	<li>X가 올바른 괄호열이면, f[(X)] = 2 × f[X]</li>
	<li>X와 Y 가 올바른 괄호열이면, f[XY] = f[X] + f[Y ]</li>
</ul>

<p>예를 들어 몇 가지 올바른 괄호열들의 괄호값을 구해 보자.</p>

<ul>
	<li>f[<code>()</code>] = 1</li>
	<li>f[<code>(())</code>] = 2 × f[<code>()</code>] = 2 × 1 = 2</li>
	<li>f[<code>()()</code>] = f[<code>()</code>] + f[<code>()</code>] = 1 + 1 = 2</li>
	<li>f[<code>()()()</code>] = f[<code>()</code>] + f[<code>()()</code>] = 1 + 2 = 3</li>
	<li>f[<code>(()())</code>] = 2 × f[<code>()()</code>] = 2 × 2 = 4</li>
	<li>f[<code>((()))</code>] = 2 × f[<code>(())</code>] = 2 × 2 = 4</li>
	<li>f[<code>()(())</code>] = f[<code>()</code>] + f[<code>(())</code>] = 1 + 2 = 3</li>
	<li>f[<code>(()())()(())</code>] = f[<code>(()())</code>] + f[<code>()(())</code>] = 4 + 3 = 7</li>
</ul>

<p>두 개의 올바른 괄호열 A와 B를 읽고, 두 문자열의 괄호값 f[A]와 f[B]를 <strong>비교하는</strong> 프로그램을 작성하라. 즉, f[A] = f[B]인지, f[A] < f[B]인지, f[A] > f[B]인지를 판단하는 프로그램을 작성하라.</p>

<p>하나의 입력에서 T개의 테스트 케이스를 해결해야 한다.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 T가 주어진다.</p>

<p>이후 T개의 테스트 케이스가 차례로 주어진다. 각 테스트 케이스의 형식은 다음과 같다.</p>

<ul>
	<li>첫 번째 줄에 A가 주어진다.</li>
	<li>두 번째 줄에 B가 주어진다.</li>
</ul>

### 출력 

 <p>각각의 테스트 케이스마다, 한 개의 줄에,</p>

<ul>
	<li>f[A] = f[B]이면 <code>=</code>,</li>
	<li>f[A] < f[B]이면 <code><</code>,</li>
	<li>f[A] > f[B]이면 <code>></code></li>
</ul>

<p>을 출력한다.</p>

