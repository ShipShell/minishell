# 쉘과 커널

## 학습 자료

- shell과 kernel의 차이
https://treeroad.tistory.com/entry/shell%EA%B3%BC-kernel-%EC%B0%A8%EC%9D%B4?category=730034

- 쉘스크립트 개발/ 리눅스 기초, 명령어 관련 전반적인 개념
https://wikidocs.net/33076


# 쉘 명령어

## 리눅스 명령어

https://www.fun-coding.org/linux_basic2.html
https://zzsza.github.io/development/2017/12/04/linux-1/


- fork, exec 계열 함수들
https://blackinkgj.github.io/fork_and_exec/
https://bbolmin.tistory.com/35

- export, echo
http://keepcalmswag.blogspot.com/2018/06/linux-unix-export-echo_49.html

- pipe
https://reakwon.tistory.com/80


# 개인적으로 정리한 것

## 시작 방향
우선 명령 프롬프트를 띄우는 일 -> (각종 초기와 및 에러처리)

-> 무한루프로 입력(명령)을 기다려야 할 것

-> 명령 입력 받은걸 어떻게 처리할 것인지? -> 각 명령을 토큰 단위로 파싱! by hidaehyunlee

-> 각 명령을 어떤 구조체든, 리스트든, 테이블 데이터 구조에 삽입

-> 테이블에 들어있는 모든 명령에 대해 새 프로세스 생성
	필요한 경우, 파이프(|)를 생성해 한 프로세스 출력을 다음 프로세스 입력으로 전달(이건 우선 나중 일)

-> 실행 파일을 올바르게 찾아서 실행시켜야 한다 (exec)

## 가용 함수

https://www.it-note.kr/253

malloc, free
read, write, open, close
opendir, readdir, closedir => 특정 디렉토리에 포함된 디렉토리명|파일명 설정
getcwd, chdir 			=> 현재작업경로/ 변경
stat, lstat, fstat 		=> 파일의 상태 및 정보/ 심볼릭링크의 / 열린파일의
fork, execve 			=> 프로세스 생성! / 프로그램 실행!
wait, waitpid, wait3, wait4 => 임의의 자식 프로세스 상태변화 대기/ 특정프로세스(waitpid)
signal, kill 			=>	process에 무엇인가 발생했음을 알림
exit
strerror, errono
dup, dup2, pipe
