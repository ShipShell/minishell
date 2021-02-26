



# 🐚 Minishell

As beautiful as a shell

> 요약 : 이 프로젝트의 목적은 간단한 셸을 만드는 것입니다. 그래요, 당신이 만든 작은 bash 또는 zsh를 말하는거랍니다. 프로세스 및 파일 디스크립터에 대해 많이 배우게 될겁니다.



## 🍺 Chapter 1. Introduction

쉘의 존재는 IT의 존재와 연결되어 있습니다. 당 시대의 모든 코더들은, **정렬 된 1/0 스위치를 사용하여 컴퓨터와 소통하는 것은 매우 짜증나는일**이라는 것에 는 동의했습니다.. 영어와 비슷한 언어로 대화형 명령줄을 사용하여 컴퓨터와 소통하자는 아이디어는 매우 논리적인 아이디어였습니다.

**Minishell** 과제와 함께, 여러분은 **Windows가 존재하지 않았을 때**의 사람들이 직면했던 문제로의 시간여행을 할 수 있을 것입니다. 



## 🍻 Chapter 2. Common Instructions

생략



## 🥂 Chapter 3. Mandatory part

| Program name     | minishell                                                    |
| ---------------- | ------------------------------------------------------------ |
| Makefile         | Yes                                                          |
| External functs. | printf, malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, exec, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno |
| Lift authorized  | Yes                                                          |
| Description      | Write a shell                                                |



여러분의 쉘은 반드시:

- 새 명령어를 기다릴 때 프롬프트를 표시해야합니다.
- bash에서와 같이 올바른 실행 파일을 검색하고 실행합니다 (PATH 변수 또는
  상대 또는 절대 경로에 기반하여)
- bash에서와 같은 내장 기능을 구현해야합니다.
  - **echo** with option '-n'
  - **cd** with only a relative or absolute path
  - **pwd** without any options
  - **export** without any options
  - **unset** without any options
  - **env** without any options and any arguments
  - **exit** without any options
- `;` 는 명령어에서 bash에서와 같이 명령어들을 분리해야합니다.
- `’ `및 `"` 는 여러 줄 명령어를 제외하고 bash 에서처럼 작동해야합니다.
- 리디렉션 `<` `>` `>>` 은 파일 디스크립터 집합을(❗원문: file descriptor aggregation)를 제외하고 bash 에서처럼 작동해야합니다.
- 파이프는 `|` bash 에서처럼 작동해야합니다.
- 환경 변수 ($문자)는 bash 에서처럼 작동해야합니다.
- `$?` 는 bash 에서처럼 작동해야합니다.
- `ctrl-C`, `ctrl-D` 및 `ctrl- \ `는 bash에서와 동일한 결과를 가져야합니다.



## 💈 Chapter 4. Bonus part

> ❗보너스 파트 번역은 아직 파악하지 못한 기능들이 있어 번역이 어색할 수 있습니다.

- 필수 부분이 완벽하지 않다면 보너스에 대해 생각조차하지 마세요 
- 모든 보너스를 할 필요는 없습니다. 
- bash에서와 같이 `<<` 리디렉션 
- Termcaps를 사용한 히스토리 및 명령줄 편집 (예 : man tgetent) 
  - 커서가있는 줄을 편집합니다. 
  - 특정 위치에서 선을 편집 할 수 있도록 커서를 왼쪽과 오른쪽으로 이동합니다. 분명히 기존 문자 사이에 새 문자를 삽입해야합니다. 클래식 쉘과 유사하게 구현합니다.
  - 위쪽 및 아래쪽 화살표를 사용하여 명령 내역을 탐색합니다. 그런 다음 원하면 편집 할 수 있습니다 (히스토리가 아닌 명령줄을). 
  - 원하는 키 시퀀스를 사용하여 줄의 전체 또는 일부를 잘라 내고 복사하고 / 또는 붙여 넣습니다. 
  - `ctrl + LEFT` 와 `ctrl + RIGHT`를 사용하여 왼쪽 또는 오른쪽으로 단어 단위로 이동할 수 있게 합니다. 
  - `home` 과 `end` 키를 눌러 명령줄의 시작 또는 끝으로 바로 이동합니다. 
  - 몇 줄에 걸쳐 명령을 작성하고 편집합니다. 이 경우 우리는 `ctrl + UP` 및 `ctrl + DOWN` 을 사용하면 명령줄에서 다른 줄로 이동할 수 있습니다. 동일한 열 또는 그렇지 못하면 가장 적합한 열에 남아 있는것을 원합니다.
- 괄호와 함께 `&&`,  `||` 는 bash에서와 같이 우선 순위 동작.
- wilcard `*` bash에서 처럼 동작