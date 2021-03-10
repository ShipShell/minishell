# mijeong의 연습장입니다.

## 2021/02/25(목)

### (임시)계획표

- [x] 사용가능한 external function에 대해 먼저 익히기. (kilee가 올려준 )

- [x] 대략적인 구조 세우기.

- [x] 현킴과 구조에 대해 이야기 좀 나눠보기.

- [x] 현킴과 파트 나누기.

- [x] 바로 시이자악~!

- [ ] 하면서 문제가 발생할 시 문제를 집중적으로 고치는방식으로 진행하기.

- 숙제.

- [x] lift에 gnl, ft_printf집어넣고 makefile 정리하기.

### 이해가 계속 안가던 프로세스에 대해서 예시를 이용해서 이해를 조금 함.

``` c
#include <stdio.h>
#include <unistd.h>

int gval = 10;

int main()
{
    int lval = 20;
    gval++;
    lval += 5;

    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        gval += 2;
        lval += 2;
    }
    else
    {
        gval -= 2;
        lval -= 2;
    }
    printf("gval: %d\nlval: %d\n", gval, lval);
}
```

이 코드를 실행하면 printf가 두개가 나온다. 결국 쓰레드 같은 느낌으로 진행이 된다는 느낌인듯.... 프로세스를 분기했을 때에 자식 프로세스와 부모 프로세스를 어떻게 다루냐가 중요한거 같다.

- 참고: 함수 안에서 실행이 되든 밖에서 실행이 되든 계속 분기가 된 상태로 진행이 됨.

### cd.c

#### 구현해야할 기능

- 환경변수 PATH에 변수가 없을 경우 
- command에 대한 에러 처리를 어떻게 나눴는지 궁금
- 환경변수 PWD와 OLDPWD를 다 바꿔줘야함.

#### 사용함수

- chdir : 
  - 리턴값 : 에러시 -1, 정상동작 0

### echo.c

#### 구현해야할 기능

- arg가 여러개 들어 왔을 때 : 각 arg사이 공백을 넣고 출력한다.

- arg가 없을 때에는 그냥 줄바꿈만.
- -n 옵션이 들어가면 마지막 줄바꿈을 없앤다.



### export.c

#### 구현해야할 기능

- declare -x 환경변수.
- "가 들어오는 경우 \\"로 표현해야한다.

#### 주의점

- arg의 첫번째 문자로 '!', '*', '=', 등이 오면 에러문자를 내보내지만 이 전 명령은 실행되어야한다.
- =이 있으면 빈문자열 없으면 null을 넣어준다.
- 이미 있는 환경변수에 = null을 집어넣을 수 없다.(export test로 test="a"를 test로 바꿀 수 없다는 뜻)
- 어느경우에 null을 넣어줘야하는데 그 경우를 특정하기 힘들다...

#### 에러처리

- 앞에 숫자, 특수문자(@$%^&*)가 오면 exit status = 1



### unset.c

#### 구현해야할 기능

- g_env에서 직접 환경변수 삭제한다.



### exit.c

#### 구현해야할 기능

- 그냥 exit 함수를 사용하여 꺼버려라아!!!

#### 주의할 점

- exit 숫자가 크면 255이상의 종료값은 안나옴 unsigned char로 관리하는 느낌이다. 256이 들어가면 0이 리턴됨.
- 숫자가 아니면 에러 (따로 처리)



### not_built_in.c

#### 구현해야할 기능

- Built_in 함수가 아닌경우 모두 이쪽으로
- execve를 사용하기 위해 filename, argv, envp를 만들어야 한다.

- 여기서 argv는 정리된 모든 token이다. (command와 인자들.)



### export, env 차이

#### export

- export TEST : TEST만 저장된다.
- export TEST2= : TEST2=""가 저장된다.

#### env

- export TEST : TEST는 출력이 안된다.
- export TEST2= : TEST2=까지 출력된다.
- 환경변수를 인자로 주면 잘 출력되지만 환경변수가 아닐 경우 에러를 준다. 여기서 환경변수는 key=value의 형태여야한다.

### 에러처리

- [exit status]()
- 전역변수 g_exit_code를 각 실행함수에서 관리를 해줘야한다.
- 각 실행이 끝나면 에러인지 아닌지 확인 후 그에 대한 출력을 해줘야한다.
- bash: cd: HOME not set 에러를 보면 exit_code는 1이기 때문에 얼핏보면 no such file or directory 에러를 내야할 거 같지만 아님. 따라서 각 실행함수 내에서 에러처리를 하는 것을 알 수 있음.
- 커맨드에서 잘못된 이름을 넣으면 127, 인자부에서 잘못되 이름을 넣으면 1, 둘 다 에러 메세지ㅣ는 같다.

### pipe 개념 공부

![파이프](https://github.com/architectophile/blog/blob/master/linux/concepts/images/linux-concepts-cmd-execution-2-pipe-1.1.1.png?raw=true)



### 논제

- parsing에서 사용하는 env구조체 추가함수를 나도 쓸 수 있으면 좋을듯. export에서 쓰기 위해서. (물어보자~!)
- 위의 export.c 주의점에서 !, *, =이런 친구들 어디까지 에러로 잡아야 할까 ??? 생각보다 예외사항이 많음. [여기](https://heesy.tistory.com/109)를 보면 bash에서 저런 친구들에 대한 사전정의를 해두기 때문이라는데 어디까지 구현을 해야할까...
- execve인자로 들어오는 token은 과연 path를 빼줘야할지 붙여줘야할지 궁금하구만..
- /bin/cat으로 입력하다가 control + c로 나가면 shipshell이 두개 생김.
- echo(space), echo(nospace)의 결과가 다르다. (상관없나??)



### 기억해야할 부분

- export에서 '"hello"'이렇게 들어온 토큰은 "hello"로 정리를 한 후에 mijeong에게 넘겨준다. \는 안넣어줘도 된다. export에만 해당되는 사항이기 때문이다.
- 절대경로로 command가 들어오면 따로 처리

### 해야할 것

- 자식에서 종료코드를 부모에게 넘기는거. not_built_in에서
- strerr 공부

1. 에러 고치고

   - [x] export

   - [x] not_built_in

   - [x] exit
2. 에러 처리하고.

- redir 계획

  1. 구조체 파싱.

     1. 구조체 구조.

     - 명령 > a.txt > b.txt > c.txt 일 때 명령부와 각 파일명에 대해서 나눠야함.

  2.  주의점

     1. indir에서 파일이 존재하지 않으면 중간에 있어도 경고.

### 궁금한 점

- not_built_in에서 에러 발생시 에러 처리 뭐뭐 했는지..
- pipe에서 list가 잘 못된 값을 본다...
- echo hi > a.txt > b.txt < c.txt ; env
