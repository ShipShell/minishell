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

- 쉘 변수와 환경변수
http://throughkim.kr/2016/12/22/linux-4/
-> 하다가 환경변수 개념 자체에 대한 것 말고 env를 쳤을 때 그 목록은 어디에 저장되고 어떻게 출력을 시켜야하는지
를 알아봐야했음 -> main의 함수 envp 인자를 이용합니다!
https://m.blog.naver.com/PostView.nhn?blogId=no1rogue&logNo=30096808780&proxyReferer=https:%2F%2Fwww.google.com%2F
https://brunch.co.kr/@sinclairo/21



# 개인적으로 정리한 것

## 시작 방향
우선 명령 프롬프트를 띄우는 일 -> (각종 초기와 및 에러처리)

-> 무한루프로 입력(명령)을 기다려야 할 것

-> 명령 입력 받은걸 어떻게 처리할 것인지? -> 각 명령을 토큰 단위로 파싱! by hidaehyunlee

-> 각 명령을 어떤 구조체든, 리스트든, 테이블 데이터 구조에 삽입

-> 테이블에 들어있는 모든 명령에 대해 새 프로세스 생성
	필요한 경우, 파이프(|)를 생성해 한 프로세스 출력을 다음 프로세스 입력으로 전달(이건 우선 나중 일)

-> 실행 파일을 올바르게 찾아서 실행시켜야 한다 (exec)

## 20210223 (화) / minishell 작업 방향 정리

우선 int main(int ac, char **av, char **env)
로 시작해야할 것 같음

-> while(1) 등 처럼 뭐 무한루프를 띄웠을 때 명령이 들어오지 않는 경우에 한해 $> 같은 걸 한!번!만! 띄우고 대기하고 있을 수 있게 해야할 것

-> char **env 를 통해서 환경변수 목록을 받아오는데, 이것도 따로 파싱을 해서 어떤 env 리스트에 담아야 할까?

-> 사용자가 명령을 입력하면 그것을 파싱하는 과정이 필요한데, 어떤 식으로 읽어올지?
1. 세미콜론(;), 파이프(|) 등을 기준으로 나눈 후 명령들을 리스트에 순차적으로 넣을지 ,,? 아니면 echo 'hello';pwd 등이 있으면
토큰 단위인가로 애초부터 나눠담을건지 ? 뭐 암튼 이정도

-> 어찌저찌해서 세미콜론, 리디렉션, 파이프 등을 기준으로 명령들이 담긴 command list 가 만들어졌다면 이제 이걸 수행해야할 것! 

-> execute 해야할 것입니당. 빌트인 명령 ? 새프로세스(부모자식프로세스) ? 또 음 부모-자식간 프로세스를 어떻게 관리를 해야할 건지도
생각해봐야할 것 같고
앞서 고민했던(issue 내용), echo의 경우는 따옴표나 $치환 처리, env의 경우는 파싱해온걸 출력하면 될 것 같고, 경로가 들어가는 명령들 -> 이것도 환경변수를 이용해서 출력만 시키면 되는 부분인가? 실행 파일들이 어디 담겨있고 어떻게 이용해서 각 명령을 불러와야할지도 정리해봐야할 것 같습니다~




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
