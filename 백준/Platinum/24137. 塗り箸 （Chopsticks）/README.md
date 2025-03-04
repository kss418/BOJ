# [Platinum I] 塗り箸 (Chopsticks) - 24137 

[문제 링크](https://www.acmicpc.net/problem/24137) 

### 성능 요약

메모리: 2732 KB, 시간: 24 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 10일 15:06:50

### 문제 설명

<p>漆塗りお箸協会 (Japan Ohashi Institute) は，お箸の国際普及のためにデザインされたお箸 を用意することになった．お箸のうち，彩色される部分は一端から長さ Nmm にわたる部分で， 1mm ごとに色が定まっており，色が塗られない部分はない．また，お箸の彩色に使用する漆の 色は 52 色である．</p>

<p>漆塗り職人のあなたは，決められた色の通りに，お箸を塗る作業を依頼された．漆塗りには 手間がかかるため，なるべく少ない作業回数でお箸を完成させたい．</p>

<p>お箸を塗るための 1 作業とは，連続する区間を選び，その区間すべてを一色で塗ることであ る．この際，すでに色が塗られていた場所も必ず新しい色となる．お箸を完成させるために必 要な作業回数の最小値を求めるプログラムを書け．</p>

### 입력 

 <p>入力の 1 行目には 1 つの整数 N (1 ≤ N ≤ 300) が書かれて いる．これはお箸の彩色される部分の長さが Nmm であることを表す．</p>

<p>2 行目には，N 文字からなる英字 (A～Z, a～z) の列が与えられる．文字列の i 文字目が端から (i − 1)mm から imm までの色を表す．</p>

### 출력 

 <p>出力は，標準出力に行うこと．作業回数の最小値を表す 1 つの整数を出力せよ．</p>

