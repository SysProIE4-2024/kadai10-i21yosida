/*
 *  mysystem.c : system 関数のクローン
 */

#include <stdio.h>
#include <stdlib.h>    // exit, system のため
#include <unistd.h>    // fork, execXX のため
#include <sys/wait.h>  // wait のため
#include "mysystem.h"  // インタフェース

// system関数のクローン
int mysystem(char *command) {
  int status = 0;

  //ここにプログラムを書く

  if (command == NULL) {
    return 1;
  }
  int pid = fork();
  if (pid < 0) {      // fork失敗
    return -1;
  } else if (pid == 0) {    // 子プロセス
    execl("/bin/sh", "sh", "-c", command, (char *)NULL);    // execlが失敗した場合
    exit(127);
  } else {      // 親プロセス
    if (wait(&status) != pid ) {
      return -1;
    }
  }
  return status;
}

/* 実行例
% ls -n
total 584
-rw-r--r--  1 501  20     143  7  4 09:43 Makefile
-rw-r--r--  1 501  20    2795  7  4 09:43 README.md
-rw-r--r--  1 501  20  238232  7  4 09:43 README.pdf
-rwxr-xr-x  1 501  20   33656  7  4 09:49 mysysmain
-rw-r--r--  1 501  20     925  7  4 09:43 mysysmain.c
-rw-r--r--  1 501  20    1876  7  4 09:56 mysystem.c
-rw-r--r--  1 501  20      90  7  4 09:43 mysystem.h

% ./mysysmain "ls -l"
mysystem:
total 584
-rw-r--r--  1 yoshidakota  staff     143  7  4 09:43 Makefile
-rw-r--r--  1 yoshidakota  staff    2795  7  4 09:43 README.md
-rw-r--r--  1 yoshidakota  staff  238232  7  4 09:43 README.pdf
-rwxr-xr-x  1 yoshidakota  staff   33832  7  4 10:09 mysysmain
-rw-r--r--  1 yoshidakota  staff     925  7  4 09:43 mysysmain.c
-rw-r--r--  1 yoshidakota  staff    1996  7  4 10:09 mysystem.c
-rw-r--r--  1 yoshidakota  staff      90  7  4 09:43 mysystem.h
retval = 00000000
system:
total 584
-rw-r--r--  1 yoshidakota  staff     143  7  4 09:43 Makefile
-rw-r--r--  1 yoshidakota  staff    2795  7  4 09:43 README.md
-rw-r--r--  1 yoshidakota  staff  238232  7  4 09:43 README.pdf
-rwxr-xr-x  1 yoshidakota  staff   33832  7  4 10:09 mysysmain
-rw-r--r--  1 yoshidakota  staff     925  7  4 09:43 mysysmain.c
-rw-r--r--  1 yoshidakota  staff    1996  7  4 10:09 mysystem.c
-rw-r--r--  1 yoshidakota  staff      90  7  4 09:43 mysystem.h
retval = 00000000

% ./mysysmain "date"   
mysystem:
2024年 7月 4日 木曜日 10時09分30秒 JST
retval = 00000000
system:
2024年 7月 4日 木曜日 10時09分30秒 JST
retval = 00000000

% ./mysysmain
使い方 : ./mysysmain コマンド文字列

% ./mysysmain "aaaa"   
mysystem:
sh: aaaa: command not found
retval = 00007f00
system:
sh: aaaa: command not found
retval = 00007f00

% ./mysysmain "rm"   
mysystem:
usage: rm [-f | -i] [-dIPRrvWx] file ...
       unlink [--] file
retval = 00004000
system:
usage: rm [-f | -i] [-dIPRrvWx] file ...
       unlink [--] file
retval = 00004000
*/