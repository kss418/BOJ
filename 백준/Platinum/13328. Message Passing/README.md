# [Platinum V] Message Passing - 13328 

[문제 링크](https://www.acmicpc.net/problem/13328) 

### 성능 요약

메모리: 3728 KB, 시간: 52 ms

### 분류

수학, 다이나믹 프로그래밍, 분할 정복을 이용한 거듭제곱

### 제출 일자

2025년 9월 17일 08:52:07

### 문제 설명

<p>In International Computer Products Company (ICPC), there is frequently a need to pass an important message from the employer to all the employees. The task of passing a message from ICPC employer to all the employees is accomplished by a series of calls over the telephone along organizational reporting lines. Kim, the employer of ICPC, plans to renovate the message passing system so that an employee cannot make calls to other employees more than d times. For that purpose, Kim wants to know the number of telephone calls that are made at time t after he started the message passing subject to the constraints that:</p>

<ol>
	<li>Each call involves only two employees.</li>
	<li>Each call requires one unit of time.</li>
	<li>An employee can participate in only one call per unit of time.</li>
	<li>Each employee makes calls to d uninformed employees in consecutive d time units immediately after he or she is informed.</li>
</ol>

<p>Kim makes a call to an employee only when he starts the message passing. For example, the case when d = 2 is shown in the following table.</p>

<table class="table table-bordered">
	<thead>
		<tr>
			<th>Time t</th>
			<th>Telephone calls</th>
			<th>Number of calls at time t</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td>Kim starts a message passing by making a call to A.</td>
			<td>1</td>
		</tr>
		<tr>
			<td>1</td>
			<td>A makes a call to B (to pass the message).</td>
			<td>1</td>
		</tr>
		<tr>
			<td>2</td>
			<td>A makes a call to C. B makes a call to D.</td>
			<td>2</td>
		</tr>
		<tr>
			<td>3</td>
			<td>B, C, and D make calls to E, F, and G, respectively.</td>
			<td>3</td>
		</tr>
	</tbody>
</table>

<p>In this example, Kim starts the message passing by making a call to A at time 0. The call takes one unit of time. At time 1, A is the only employee who has the message, and A makes a call to an uninformed employee B. At time 2, both A and B have the message; A and B make calls to uninformed employees C and D, respectively. Note that each employee cannot make calls to other employees more than two times in this case. As in the above table, three telephone calls are made at time 3.</p>

<p>Given d and t, you are to write a program to compute the number of telephone calls that are made at time t after Kim started the message passing.</p>

### 입력 

 <p>Your program is to read from standard input. The input contains two integers, d and t (2 ≤ d ≤ 50, 1 ≤ t ≤ 2,000,000,000), where d represents the number of employees to which an employee can make calls, and t represents the time that has been passed since the message passing started.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line as follows: If m is the number of telephone calls that are made at the given time, print m mod 31,991. For example, if m = 32,000, the output should be 9.</p>

