# [Platinum II] スパイ 2 (Spy 2) - 20983 

[문제 링크](https://www.acmicpc.net/problem/20983) 

### 성능 요약

메모리: 30104 KB, 시간: 300 ms

### 분류

방향 비순환 그래프, 그래프 이론, 그리디 알고리즘, 위상 정렬

### 제출 일자

2025년 10월 29일 15:48:41

### 문제 설명

<p>JOI 国には <var>N</var> 人の議員がおり，<var>1</var> から <var>N</var> までの番号がつけられている．JOI 国の大臣であるあなたは，議員の中にいるスパイを探し出そうとしている．あなたは各議員 <var>i</var> (<var>1 ≦ i ≦ N</var>) について次のような情報を得た．</p>

<ul>
	<li><var>T<sub>i</sub> = 1</var> のとき，議員 <var>i</var> はスパイである．</li>
	<li><var>T<sub>i</sub> = 2</var> のとき，議員 <var>i</var> はスパイではない．</li>
	<li><var>T<sub>i</sub> = 3</var> のとき，議員 <var>i</var> がスパイであるかどうかは不明である．</li>
</ul>

<p>更に聞き取り調査を行った結果，新たに <var>M</var> 個の情報を得ることができた．<var>j</var> 番目の聞き取り調査の情報 (<var>1 ≦ j ≦ M</var>) は，議員 <var>A<sub>j</sub></var> (<var>1 ≦ A<sub>j</sub> ≦ N</var>) が「議員 <var>B<sub>j</sub></var> (<var>1 ≦ B<sub>j</sub> ≦ N</var>) はスパイであり，かつ議員 <var>C<sub>j</sub></var> (<var>1 ≦ C<sub>j</sub> ≦ N</var>) はスパイでない」と証言したというものである．</p>

<p>ただし，議員 <var>A<sub>j</sub></var> がスパイであれば，<var>j</var> 番目の聞き取り調査の情報における証言は事実とは異なる．すなわち，もし議員 <var>A<sub>j</sub></var> がスパイであれば，「議員 <var>B<sub>j</sub></var> はスパイである」「議員 <var>C<sub>j</sub></var> はスパイでない」のうち，少なくとも一方は事実ではない．一方で，議員 <var>A<sub>j</sub></var> がスパイでないとき，<var>j</var> 番目の聞き取り調査の情報における証言は事実かもしれないし，そうでないかもしれない．</p>

<p>各議員の情報と，聞き取り調査の結果が与えられるので，それら <var>N + M</var> 個の情報が矛盾しているかを判定し，矛盾していないなら，それぞれの議員がスパイかどうかを求めるプログラムを作成せよ．<var>N + M</var> 個の情報と合致する答えが複数存在する場合は，そのうちどれを出力してもよい．</p>

### 입력 

 <p>入力は以下の形式で標準入力から与えられる．</p>

<p><var>N</var> <var>M</var><br>
<var>T<sub>1</sub></var> <var>T<sub>2</sub></var> <var>…</var> <var>T<sub>N</sub></var><br>
<var>A<sub>1</sub></var> <var>B<sub>1</sub></var> <var>C<sub>1</sub></var><br>
<var>A<sub>2</sub></var> <var>B<sub>2</sub></var> <var>C<sub>2</sub></var><br>
<var>:</var><br>
<var>A<sub>M</sub></var> <var>B<sub>M</sub></var> <var>C<sub>M</sub></var></p>

### 출력 

 <p>標準出力に出力せよ．</p>

<p>与えられた情報が矛盾している場合，<code>-1</code> を <var>1</var> 行で出力せよ．</p>

<p>そうでない場合，出力は <var>N</var> 行からなる．<var>i</var> 行目 (<var>1 ≦ i ≦ N</var>) には議員 <var>i</var> がスパイである場合 <var>1</var> を，議員 <var>i</var> がスパイでない場合 <var>2</var> を出力せよ．<var>N + M</var> 個の情報と合致する答えが複数存在する場合，そのうちどれを出力してもよい．</p>

