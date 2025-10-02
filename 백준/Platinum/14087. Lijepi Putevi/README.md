# [Platinum V] Lijepi Putevi - 14087 

[문제 링크](https://www.acmicpc.net/problem/14087) 

### 성능 요약

메모리: 12060 KB, 시간: 52 ms

### 분류

자료 구조, 분리 집합

### 제출 일자

2025년 10월 2일 18:12:32

### 문제 설명

<p>U jednoj dalekoj zemlji postoji N gradova koji su s pomoću N - 1 cesta povezani u stablo, što znači da između svakih dvaju gradova postoji jedinstven put. Udaljenost dvaju gradova definiramo kao broj cesta na tom putu između njih.</p>

<p>Neobično je što ova zemlja ima dva glavna grada označena brojevima 1 i 2; ostali gradovi označeni su brojevima od 3 do N.</p>

<p>Mirko je dobio zadatak organizirati autobusni promet u ovoj zemlji. Da bi uspio efikasno organizirati autobuse, definirao je najprije važnost grada kao udaljenost toga grada od njemu bližeg glavnoga grada, a potom važnost puta kao najmanju važnost nekog grada na tome putu.</p>

<p>Vaš je zadatak zbrojiti važnosti puteva između svakih dvaju različitih gradova (takvih parova ima N∙(N - 1) / 2). </p>

### 입력 

 <p>U prvome retku nalazi se prirodan broj N (1 ≤ N ≤ 100 000), broj gradova.</p>

<p>Svaki od sljedećih N - 1 redaka sadrži dva međusobno različita broja A, B (1 ≤ A, B ≤ N), što predstavlja cestu između gradova A i B. </p>

### 출력 

 <p>U jedini redak ispišite traženi zbroj važnosti svih puteva. </p>

