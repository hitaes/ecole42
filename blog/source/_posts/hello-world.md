---
title: Pipex 함수 배우기
tag: pipex
---
## [1] 필요한 함수들

### 1. open 
Synopsis
- int open(const char *pathname, int flags, mode_t mode)

Description
- pathname의 파일을 열게 됩니다. 만약 flags가 O_CREAT이고 파일이 존재하지 않는다면 파일을 만들어 냅니다.
- 반환값은 file descriptors입니다.
- $$


1. close
2. read
3. write
4. malloc
5. free
6. access
7. unlink
8.  fork
9.  wait
10. waitpid
11. dup
12. dup2
13. pipe
14. execve
15. perror
16. sterreor
17. exit
