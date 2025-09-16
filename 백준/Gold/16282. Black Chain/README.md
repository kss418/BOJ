# [Gold III] Black Chain - 16282 

[문제 링크](https://www.acmicpc.net/problem/16282) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학

### 제출 일자

2025년 9월 16일 14:37:00

### 문제 설명

<p>n개의 블랙 고리가 일렬로 연결된 체인이 있다. 블랙 고리 하나는 무게가 정확히 1g 이다. 이 고리들을 이용하여 1g 부터 <em>n</em>g 까지 가능한 모든 무게를 생성하려고 한다. 이를 위해 고리를 일부 풀어야 하는데, 고리를 푸는데 힘이 들어 최소 개의 고리만 풀기를 원한다. 예를 들어 아래의 그림 A.1 처럼 7 개의 고리로 구성된 블랙 체인이 있다고 하자. 이 체인에서 3 번 고리 하나를 풀어 내면 그림 A.2 처럼 3 번 고리 1 개와 두 개의 체인(1~2 번 고리가 연결된 체인과 4~7 번 고리가 연결된 체인)으로 분리된다. 이들을 이용하면 그림 A.3 처럼 1g 부터 7g 까지의 모든 무게를 생성할 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/84c90735-fd4c-4678-80a1-9abf12a9fab6/-/preview/" style="width: 226px; height: 52px;"></p>

<p style="text-align: center;">그림 A.1: 길이가 7 인 블랙 체인</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c77fe2b3-587c-4266-9c20-8a5129f6baad/-/preview/" style="width: 271px; height: 72px;"></p>

<p style="text-align: center;">그림 A.2: 3 개로 분리된 블랙 체인</p>

<table class="table table-bordered" style="width: 100%;">
	<thead>
		<tr>
			<th style="text-align: center;">무게</th>
			<th style="text-align: center;">1g</th>
			<th style="text-align: center;">2g</th>
			<th style="text-align: center;">3g</th>
			<th style="text-align: center;">4g</th>
			<th style="text-align: center;">5g</th>
			<th style="text-align: center;">6g</th>
			<th style="text-align: center;">7g</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center;">고리<br>
			구성</td>
			<td style="text-align: center;"><code>[3]</code></td>
			<td style="text-align: center;"><code>[1-2]</code></td>
			<td style="text-align: center;"><code>[3]</code><br>
			<code>[1-2]</code></td>
			<td style="text-align: center;"><code>[4-7]</code></td>
			<td style="text-align: center;"><code>[3]</code><br>
			<code>[4-7]</code></td>
			<td style="text-align: center;"><code>[1-2]</code><br>
			<code>[4-7]</code></td>
			<td style="text-align: center;"><code>[3]</code><br>
			<code>[1-2]</code><br>
			<code>[4-7]</code></td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">그림 A.3: 1g 부터 7g 까지 가능한 모든 무게를 생성하는 고리 구성</p>

<p><em>n</em>개의 고리가 연결된 체인이 주어져 있을 때, 1g 부터 <em>n</em>g 까지 가능한 모든 무게를 생성하기 위해 풀어야 할 고리의 최소 개수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>입력은 표준입력을 사용한다. 첫 번째 줄에 블랙 고리의 개수를 나타내는 양의 정수 <em>n</em> (3 ≤ <em>n</em> ≤ 10<sup>18</sup>)이 주어진다.</p>

### 출력 

 <p>출력은 표준출력을 사용한다. 1g 부터 <em>n</em>g 까지 가능한 모든 무게를 생성하기 위해 풀어야 할 고리의 최소 개수를 출력한다.</p>

