#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/* 방향키 */
#define UP 72            // 상
#define DOWN 80          // 하
#define LEFT 75          // 좌
#define RIGHT 77         // 우
#define Enter 13         // enter(선택)

/*게임 시작*/
#define GAMESTART 15
#define ELEMENTARY 17      // 게임 시작메뉴 - 초등학교 선택 좌표
#define MIDDLE 19          // 게임 시작메뉴 - 중학교 선택 좌표
#define HIGH 21            // 게임 시작메뉴 - 고등학교 선택 좌표
#define GAMERULES 23       
#define GAME_END 27        


/*아이템*/
#define ADDLIFE 0          // 아이템 - 목숨 + 1 추가
#define CHANGEWORD 1       // 단어 바꾸기
#define ADDTIME 2          // 시간 추가
#define BOMB 3             // 꽝

/*문제출력*/
#define SIZE 50

/*목숨*/
#define LIFE 3


/* 점수 계산 */
// 콤보점수
#define BonusPerCombo 50    // 콤보점수
#define MAX_Q 20           // 정오표 기록을 위한 최대 문제 개수

int Combo_num(int question);   // 연속 정답 개수 반환 함수
int ComboBonus(int Combo);  // 콤보점수 반환 함수
void OX_Correct(int num_Q); // 정오표 - 정답 기록
void OX_Wrong(int num_Q);   // 정오표 - 오답 기록
void reset_OX();            // 정오표 초기화




/*====================================== 함수 ========================================*/
/* 게임 시작 함수 */
void game_title();            // 게임 타이틀 출력
void game_start_menu();       // 게임 시작 메뉴 출력, 레벨 선택
void move_stage(int stage);  // 선택한 레벨로 이동
void get_name();            // 이름 입력
void rule_title();          // 게임 방법 타이틀 출력
void game_rules();          // 게임 방법 출력

/* 게임 방법*/
void game_rules();            // 게임 규칙
void rule_title();            // 규칙 상단바
void PAGE1();
void PAGE2();
void PAGE3();
void PAGE4();
void PAGE5();
void clear();                 // 내부만 지우기


/* 게임 진행 함수 */
void elementary(); // 초등학교
//// 초등학교 보스
void middle();  //중학교
//// 중학교 보스
//int high();  //고등학교
//// 수능


/* 아이템 함수 */
void item_random();         // 아이템 뽑기
//

/* 콘솔창 편집 함수 */
void gotoxy(int x, int y);  // 커서 이동 함수
void drawline();            // 화면 테두리 그리기
void drawmenu();            // 메뉴 
void drawitem();            // 아이템, 목숨 출력
void draws(char sch[10], int grade, int num, int score);           // 상단 바 테두리


/*목숨 증감 함수*/
int decrease_life();
int increase_life();

/*점수 계산*/
int elementary_score_add(int score);
double elementary_score_time(double timebonus); // 남은시간 보너스점수 누적

int middle_score_add(int score);

////**** 5/21 (현욱) 점수 리셋 추가////////////////////
void score_reset(void);

/* 시간기록 */
double TimeLeft(double timelimit, clock_t start, clock_t end); ///*제한 시간내에 문제를 해결했을 경우, 남은 시간을 초 단위로 반환*/
double TimeBonus(clock_t start, clock_t end, int timelimit); // 남은 시간에 대한 보너스 점수 반환
int TimeLimit(int level); // 단계별 제한 시간 초단위 반환


/* 메뉴 버튼 실행 */
void menu();


/* 보스 */
void elem_boss();
void elem_boss_word();

/* 단어랜덤생성 */
void word_rand_3();


/// 5/21 (현욱) - 성적표 관련
/*성적표 관련*/
void Final_Scorecard(char name[], int elementary_score, int middle_score, int high_score);

int Scorecard(char name[], char level, int score, int time_bonus, int combo_bonus, int combo_question, int Q_solved, int Q_corect); //level: e-elementary  m-middle  h-high
