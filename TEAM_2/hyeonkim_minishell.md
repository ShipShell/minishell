# MINISHELL

### PARSING

- STEP 1 (2021. 3. 4 초안 작성 완료)

  -  gnl을 통해 받아준 전체 커맨드(**char \* stdin_buf**)를  ;와 |를 기준으로 단일 커맨드(**char \*single_cmd**)로 잘라 단방향 연결리스트(**t_list \*single_cmd_list**)에 담아줌(quoted ;|는 무시!)

    > Ex) echo "asf \\bcvxnz';|" ; | ; grep 		ppp 라는 명령어가 들어왔을 때
    >
    > sinle_cmd_list->content == echo "asf \\bcvxnz';|" ;
    >
    > sinle_cmd_list->next->content == |
    >
    > sinle_cmd_list->next->content == ;
    >
    > single_cmd_list->next->content == grep 		ppp

- STEP 2 (2021. 3. 4 초안 작성 완료)

  - single_cmd_list의 각 노드에 담긴 스트링을 공백과 ;|를 기준으로 token(**char \*\*token**)으로 자름(quoted ;|는 무시!) 

    > Ex) 첫 번째 노드
    >
    > token[0] == "echo"
    >
    > token[1] == "\"asf \\bcvxnz';|\""
    >
    > token[2] == ";"
    >
    > 두 번째 노드
    >
    > token[0] == "|"
    >
    > 세 번째 노드
    >
    > token[0] == ";"
    >
    > 네 번째 노드
    >
    > token[0] == "grep"
    >
    > token[1] == "ppp"

  - 각 노드의 마지막 토큰을 검사한 값을 **int flag** 에 저장해줌

    >  **; ==  SEMICOLON**
    >
    >  **| == PIPE** 
    >
    >  **NULL**

  - 각 노드의 토큰과 플래그를 (**t_cmd \*cmd**)라는 구조체에 저장해주고 t_cmd를 다시 연결리스트(**t_list \*tokenized_single_cmd_list**)로 묶어줌

- STEP 3 (2021. 3. 5 ~)

  - (가제)substitute_token으로 특수문자(ex. $, \ 등등 처리해주기)

### AFTER PARSING

- PIPE 처리 (2021. 3. 5 ~ )

  - > **“한 가지 일만 아주 잘하는 프로그램들을 작성하라. 프로그램들이 다른 프로그램들과 함께 일할 수 있도록 작성하라. 프로그램들이 텍스트 스트림을 처리할 수 있도록 작성하라. 왜냐하면 그것은 보편적인 인터페이스이기 때문이다.”**
    >
    > 원문 :
    >
    > *“Write programs that do one thing and do it well. Write programs to work together. Write programs to handle text streams, because that is a universal interface.”*
    >
    > -UNIX 파이프의 창시자 Doug McIlory

  -  파이프는 데이터가 한 프로세스에서 다른 프로세스로 전달되게 한다. **파이프로 인해 프로세스들의 명령들이 스트림에 의해 서로 연결(chained)된다. 이러한 체인을 파이프라인(pipeline)이라고 한다** : 한 파이프라인 안에 있는 각 명령들은 각자 독립적인 프로세스 안에서 실행되며, 각자 독립적인 메모리 공간에서 실행된다. 그러므로 각 프로세스들이 서로 통신할 수 있는 방법이 필요하게 되는데, 바로 **`pipe()`시스템 호출이 그 방법을 제공한다!**

  - 구현에 있어서 파이프는 그저 버퍼된 스트림(buffered stream)에 불과하다. 그 스트림은 2개의 파일 디스크립터에 연결되어 있다. 두 개의 파일 디스크립터 중 **첫 번째는 데이터를 읽기 위한 것**이고 **두 번째는 데이터에 쓰기 위한 것**이다. 더 구체적으로 얘기하면, 2개의 정수값을 저장하는 배열이 생성되고, `pipe()` 호출은 그 배열에 '사용 가능한 2개의 파일디스크립터 값(일반적으로 사용 가능한 가장 낮은 숫자 두 개, 예를 들어 3과 4)'을 채운다.

    - 아래의 예시(sort | grep ea)를 보며 이해하자!

      ![](https://github.com/architectophile/blog/blob/master/linux/concepts/images/linux-concepts-cmd-execution-2-pipe-1.1.1.png?raw=true)

      기본적으로 `sort` 명령은 사용자가 stdin(fd : 0)을 통해 입력(input)을 전달할 때까지 기다린다. 입력받은 스트링들은 알파벳 순서대로 정렬되고, 정렬된 결과가 stdout을 통해 파이프로 전달된다. 이것은 stdout으로 하여금 출력된 데이터를 터미널 디스플레이(fd : 1)가 아니라 **파이프의 왼쪽 끝(fd : 4)**으로 입력하도록 만듦으로써 가능해진다.

      > (여기서 생각해야할 중요한 점은 **각 프로세스가 자신만의 파일 디스크립터 테이블을 가진다**는 것이다. 그림에서 왼쪽 끝에 있는 0은 sort 명령을 실행하는 프로세스에 속하는 fd, 오른쪽 끝의 1은 grep명령어에 속하는 fd. 하지만 스트림은 프로세스 바운더리를 건너 데이터를 전송하도록 설정되어 있으므로, 데이터가 마지막 프로세스에 전달된다.)

      다시 예시를 살펴보면 `sort` 명령은 정렬된 스트링 리스트를 출력(output)으로 갖게 되고, 그 출력 데이터를 결과적으로 다음 프로세스(`grep`)에 전달하기 위해서, 생성된 파이프에게 출력 되이터를 전달해야 한다. 잠시 그림 안의 IN과 OUT에 집중해보자. 데이터는 `sort프로세스`로부터(OUT) `파이프`로(IN) 전달되고, 그것은 다시 `파이프`로부터 `grep프로세스`로 전달된다.

      `pipe()` 호출에 의해 전달되는 파일 디스크립터의 숫자 값 자체는 사실 중요하지 않다. 하지만 **각 파일디스크립터의 용도**는 매우 중요하다. 그리고 각 **파일 디스크립터의 용도**는 파일 디스크립터 배열 안에서 몇 번째 인덱스에 위치하느냐에 의해 결정된다.

      위의 그림을 살펴보자. 파일 디스크립터 4에 쓰여진 데이터가 3에서 읽히게 된다. 즉 예시에서는 `pipe()` 호출에 4를 **writable end**로, 3을 **readable end**로 설정한 것이다! 다시 말하면, `sort프로세스` 의 출력 값이 파이프의 writable end에 쓰이고, `grep프로세스` 의 입력으로 파이프의 readable end에 저장된 값을 읽는 것이다! 마지막으로 한 번 더 말하자면, **파이프를 연결할 때에는 두칸의 배열 fd[2]중 fd[1]에 쓰고 fd[0]을 읽는 것이다.**

      

  - pipeline 예제를 보기 전에 `dup2()` 함수를 보자

    ```c
    # include <unistd.h>
    int dup2( int fd, int fd2 ); 
    ```

    예를 들어 `int dup2(fd, stdout);` 와 같이 사용하면, 모든 출력이 fd로 향하게 된다. 즉, dup2 함수를 이용하면 부모프로세스가 자식프로세스에게 표준입력으로 문자열을 주는 프로그램을 만들 수 있게된다.

    

  - 이제 예제를 살펴 보자.

    ![](https://github.com/architectophile/blog/blob/master/linux/concepts/images/linux-concepts-cmd-execution-2-pipe-2.1.1.png?raw=true)

    ```c
    #include <unistd.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, char *argv[]) {
      int fds[2];                      // 2개의 fd를 담을 배열을 정의한다.
      pipe(fds);                       // pipe를 호출해 두 개의 fd로 배열을 채워준다.
      pid_t pid = fork();              // 부모 프로세스의 fd와 메모리를 복제한 자식 프로세스 생성한다.
    
      if (pid == 0) {                  // if pid == 0, 자식 프로세스
        dup2(fds[0], STDIN_FILENO);    // fds[0]으로 표준입력을 넘겨준다.
        close(fds[0]);                 // fds[0]은 자식 프로세스에서 더이상 필요하지 않기 떄문에 닫아준다. 복사본이기 때문에(?)
        close(fds[1]);                 // 원래부터 필요없었던 fd라 닫아준다.
        char *cmd[] = {(char *)"sort", NULL};   // sort 명령어 인자를 만들어준다.
        if (execvp(cmd[0], cmd) < 0) 
          exit(0);  // sort 명령어 실행하고 문제있으면 exit
      } 
    
      // 부모 프로세스 코드 시작
      close(fds[0]);                 // 쓰기만 하면되는 부모 프로세스에서는 필요 없는 fd라 닫아준다. 
      const char *words[] = {"pear", "peach", "apple"}; // 자식 프로세스에서 읽을 write input 
    
      for (int i = 0; i < 3; i++) {
        dprintf(fds[1], "%s\n", words[i]); // fds[1]에 출력을 쓴다.
      }
      close(fds[1]); 
    
      int status;
      pid_t wpid = waitpid(pid, &status, 0); // 자식 프로세스가 종료될때까지 기다린다.
      return (wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1);
    }
    ```

    