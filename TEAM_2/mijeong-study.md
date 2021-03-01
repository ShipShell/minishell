# minishell 공부 모음.

## 2021/02/24(수)

### [생활코딩](https://opentutorials.org/course/2598)



### 프롬프트란??

텍스트 기반의 환경에서 각종 명령을 입력하는 곳이다.

### 쉘이란??

커널과 사용자간의 다리역할을 하며 사람의 언어를 사용하여 쉽게 커널에게 명령을 하는 역할을 한다.

[자료](https://jhnyang.tistory.com/)

[명령어 간단한 설명](https://wikidocs.net/33075)



### PID, PPID, PGID, SID COMMAND

#### 실행중인 모든 프로세스의 PID, PPID, PGID, SID, COMMAND 보는 명령

```
ps -A -o pid,ppid,pgid,sid,command
```

[자료](https://leeyh0216.github.io/2020-01-02/sid_pid_ppid_pgid)

### [hi!daehyeonlee](https://velog.io/@hidaehyunlee/minishell-1.-%EA%B3%BC%EC%A0%9C%EC%86%8C%EA%B0%9C-%EB%B0%8F-%EC%84%A0%ED%96%89%EC%A7%80%EC%8B%9D)



### 내 생각...

- fork()를 실행한 시점에서 새로운 자식프로세스가 만들어진다. 그리고 그 이 후 계속 자식프로세스로써 진행하다가 종료가 되거나 새로운 프로세스를 만들면 그 때 새로운 자식 프로세스가 만들어진다. (가설)