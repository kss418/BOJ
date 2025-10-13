# [Platinum II] 크래이피쉬 글쓰는 기계 - 5812 

[문제 링크](https://www.acmicpc.net/problem/5812) 

### 성능 요약

메모리: 366012 KB, 시간: 1448 ms

### 분류

자료 구조, 희소 배열

### 제출 일자

2025년 10월 13일 22:27:49

### 문제 설명

<p>활자 인쇄기를 발명한 독일 대장장이인 요하네스 구텐베르크는 레오나르도가 열렬히 존경하는 사람이었다. 레오나르도는 크래이피쉬 글쓰는 기계 — il gambero scrivano —로 불리는 매우 단순한 타자 기계를 설계하여 구텐베르크에게 존경을 표시하였다. 이것은 단순한 현대의 타자기와 매우 비슷하며, 단지 두 개의 명령어만 받아들인다: 하나는 그 다음 문자를 타자하는 것이고, 다른 하나는 가장 최근의 명령어들을 취소(undo)하는 것이다. 이 타자 기계의 주목할만한 특징은 취소 기능이며, 이는 매우 강력한 기능이다: 취소 명령은 자기자신, 즉 취소 명령어에 대해서도 적용될 수 있다.</p>

<p>여러분이 할 일은 크래이피쉬 글쓰기 기계와 같이 동작하는 소프트웨어를 구현하는 것이다: 빈 텍스트에서 시작하고, 사용자가 입력한 명령어의 순서들을 받아들이고, 다음과 같이 텍스트의 현재 상황의 특정 위치에 대한 질의를 수행한다.</p>

<ul>
	<li>Init() — 실행 초기에 인자가 없이 한번만 호출된다. 이 함수는 자료 구조를 초기화 하는데 사용될 수 있다. 이것은 결코 취소될 필요가 없을 것이다.</li>
	<li>TypeLetter(L) — a, …, z으로부터 선택된 하나의 소문자 L을 텍스트의 끝에 추가한다.</li>
	<li>UndoCommands(U) — 양의 정수 U에 대해, 가장 최근의 U 개의 명령어를 취소한다.</li>
	<li>GetLetter(P) — 음이 아닌 인덱스 P에 대해, 현재 텍스트에서 위치 P의 문자를 되돌려준다. 텍스트에서 첫 번째 문자의 인덱스는 0 이다. (이 질의는 명령어가 아니어서 취소 명령어에서는 무시된다.)</li>
</ul>

<p>Init()를 호출한 후에, 그 외의 루틴들은 임의의 순서로 0번 이상 호출 될 수 있다. U는 이전에 들어온 명령어들의 수를 초과하지 않음이 보장되며, P는 현재의 텍스트의 길이보다 작을 것이다 (현재 텍스트에서의 문자의 수).</p>

<p>UndoCommands(U)에서는 이전의 U개의 명령어를 역순으로 취소한다: 만약 취소될 명령어가 TypeLetter(L)라면, 이것은 현재 텍스트의 끝에서부터 L을 삭제한다: 만약 취소될 명령어가 어떤 값 X에 대해 UndoCommands(X) 라면 이것은 이전의 X개의 명령어를 원래의 순서대로 다시 실행한다.</p>

<p>하나의 가능한 호출순서에 대해서 각 호출후의 텍스트의 상태를 보인다.</p>

<table class="table table-bordered table-center-50">
	<thead>
		<tr>
			<th>Call</th>
			<th>Returns</th>
			<th>Current text</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>Init()</td>
			<td> </td>
			<td> </td>
		</tr>
		<tr>
			<td>TypeLetter(a)</td>
			<td> </td>
			<td>a</td>
		</tr>
		<tr>
			<td>TypeLetter(b)</td>
			<td> </td>
			<td>ab</td>
		</tr>
		<tr>
			<td>GetLetter(1)</td>
			<td>b</td>
			<td>ab</td>
		</tr>
		<tr>
			<td>TypeLetter(d)</td>
			<td> </td>
			<td>abd</td>
		</tr>
		<tr>
			<td>UndoCommands(2)</td>
			<td> </td>
			<td>a</td>
		</tr>
		<tr>
			<td>UndoCommands(1)</td>
			<td> </td>
			<td>abd</td>
		</tr>
		<tr>
			<td>GetLetter(2)</td>
			<td>d</td>
			<td>abd</td>
		</tr>
		<tr>
			<td>TypeLetter(e)</td>
			<td> </td>
			<td>abde</td>
		</tr>
		<tr>
			<td>UndoCommands(1)</td>
			<td> </td>
			<td>abd</td>
		</tr>
		<tr>
			<td>UndoCommands(5)</td>
			<td> </td>
			<td>ab</td>
		</tr>
		<tr>
			<td>TypeLetter(c)</td>
			<td> </td>
			<td>abc</td>
		</tr>
		<tr>
			<td>GetLetter(2)</td>
			<td>c</td>
			<td>abc</td>
		</tr>
		<tr>
			<td>UndoCommands(2)</td>
			<td> </td>
			<td>abd</td>
		</tr>
		<tr>
			<td>GetLetter(2)</td>
			<td>d</td>
			<td>abd</td>
		</tr>
	</tbody>
</table>

### 입력 

 <p>첫째 줄에 명령어와 질의의 수 L이 주어진다. 다음 줄부터 L개 줄에는 명령어와 질의가 주어진다.</p>

<p>첫 번째 문자가 T인 경우에는 TypeLetter 명령이다. T a와 같이 주어진 경우에는 TypeLetter(a)를 호출하면 된다. U인 경우에는 UndoCommands, P는 GetLetter를 의미하며, 공백으로 구분되어 주어지는 숫자를 인자로 호출하면 된다.</p>

### 출력 

 <p>GetLetter에 의해 리턴된 문자를 한 줄에 하나씩 출력한다.</p>

