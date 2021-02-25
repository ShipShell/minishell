# mijeong의 연습장입니다.

## 2021/02/25(목)

### (임시)계획표

- [ ] 사용가능한 external function에 대해 먼저 익히기. (kilee가 올려준 )

- [ ] 대략적인 구조 세우기.

- [ ] 현킴과 구조에 대해 이야기 좀 나눠보기.

- [ ] 현킴과 파트 나누기.

- [ ] 바로 시이자악~!

- [ ] 하면서 문제가 발생할 시 문제를 집중적으로 고치는방식으로 진행하기.

- 숙제.

- [ ] lift에 gnl, ft_printf집어넣고 makefile 정리하기.

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