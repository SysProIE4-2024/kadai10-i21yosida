# mysystem関数の作成

```system```関数のクローン```mysystem```関数を作りなさい．</br>
また，与えられたテストドライバを用いて動作確認をしなさい．</br>
system関数は様々なプログラムから呼び出される汎用的なものである．エラーが発生した場合，自分でエラーメッセージを出力せず，エラーの発生を戻り値で呼び出し側に伝えるだけに留めるべきである．

## レポジトリの内容

```
Makefile      makeコマンドが使用するファイル
mysysmain.c   テストドライバ（テスト用のmain関数）
mysystem.c    このファイルにmysystem関数を作成する．
```

## 作成

1. system関数の仕様</br>
文法：```int system(char *command);```</br>
説明：```command```で渡された文字列を```/bin/sh```に渡し実行させる．</br>
用途：Cプログラムの中からシェルのコマンドラインと同じ文法でコマンド実行ができる．</br>
詳細：
	* ```NULL```ポインタを渡された場合は```1```を返す．
	* forkできなかった場合は```-1```を返す．
	* それ以外では```/bin/sh```の終了ステータスを返す．
	* ```/bin/sh```を起動できない場合，子プロセスは```exit(127);```で終了する．

1. mysystem関数の作成</br>
  レポジトリをクローンし```mysystem.c```を編集してプログラムを完成する．</br>
  上の仕様を満たすプログラムを美しくコーディングする．</br>
  できたと思ったら十分な動作テストを行う．

1. 動作テスト</br>
  ```mysysmain.c```内に準備してあるmain関数を使用してテストを行う．

## 実行例

````bash
% ls -l                                     <--- コマンドラインで実行した結果
total 40
-rwxr-xr-x  1 sigemura  staff  12864  7 28 21:58 mysystem
-rw-r--r--  1 sigemura  staff   2288  7 28 21:58 mysystem.c

% ./mysysmain "ls -l"
mysystem:                                   <--- ここからmysystemの結果
total 40
-rwxr-xr-x 1 sigemura staff 12864 7 28 21:58 mysystem
-rw-r--r-- 1 sigemura staff 2288 7 28 21:58 mysystem.c
retval = 00000000
system:                                     <--- ここからsystemの結果
total 40
-rwxr-xr-x 1 sigemura staff 12864 7 28 21:58 mysystem
-rw-r--r-- 1 sigemura staff 2288 7 28 21:58 mysystem.c
retval = 00000000

% ./mysysmain                               <--- mysystemには引数が一つ必要
使い方 : ./mysystem コマンド文字列             <--- Usage メッセージを表示
````

## コンパイル方法

```Makefile```を準備してあるので```make```コマンドでコンパイルできる．

```zsh
% make
cc -Wall -std=c99 -o mysysmain mysysmain.c  mysystem.c
```
