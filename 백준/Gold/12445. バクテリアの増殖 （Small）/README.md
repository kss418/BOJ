# [Gold IV] バクテリアの増殖 (Small) - 12445 

[문제 링크](https://www.acmicpc.net/problem/12445) 

### 성능 요약

메모리: 10084 KB, 시간: 168 ms

### 분류

수학, 정수론, 분할 정복을 이용한 거듭제곱, 임의 정밀도 / 큰 수 연산

### 제출 일자

2025년 12월 26일 15:31:32

### 문제 설명

<p>微生物の研究者であるパスカルは、特殊な増殖の傾向を示すバクテリアを発見した。どうやらそのバクテリアは、ある時点で x 個存在したとすると、理想的な環境下では1時間後に x<sup>x</sup> 個に増えるようなのである。</p>

<p>そこであなたは、この興味深い性質をより深く調べるために、入力として 3 つの整数 <strong>A</strong>, <strong>B</strong>, <strong>C</strong> が与えられたときに、<strong>A</strong> 個のバクテリアが <strong>B</strong> 時間後には何個になっているかを出力するプログラムを書くことにした。答えの値は非常に大きくなるので、その値を <strong>C</strong> で割った余りを出力してほしい。</p>

### 입력 

 <p>最初の行はテストケースの個数 <strong>T</strong> を表す正の整数である。それ以降の行に、<strong>T</strong> 個のケースを表すデータが続く。</p>

<p>それぞれのテストケースは、スペースで区切られた3つの整数からなる1行の文字列で表現される。これらの整数は、順番に <strong>A</strong>, <strong>B</strong>, <strong>C</strong> を表す。</p>

<h3>制約</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 500</li>
	<li>1 ≤ <strong>A</strong> ≤ 1000</li>
	<li>1 ≤ <strong>C</strong> ≤ 1000</li>
	<li>1 ≤ <strong>B</strong> ≤ 2</li>
</ul>

### 출력 

 <p>それぞれのテストケースについて、</p>

<pre>Case #X: N
</pre>

<p>という1行の文字列を出力せよ。ここで、<strong>X</strong> は 1 から始まるテストケースの番号であり、<strong>N</strong> は求めるべきバクテリアの数を <strong>C</strong> で割った余りである。</p>

