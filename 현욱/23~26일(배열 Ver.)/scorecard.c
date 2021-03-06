#include "common.h"

//최종 종료시 성적표 - 아직 수정전
void Final_Scorecard(int elementary, int middle, int high)
{
	extern char name[]; //############ 색빛 - 이름(전역변수)
	int grade;
	int scoresum = elementary + middle + high; ////############ 색빛 - scoresum보단 total_score가 더 좋을거같습니다.


	//등급 산정-추후 조정하기
	if (scoresum < 10000)
		grade = 9;
	else if (10000 <= scoresum && scoresum < 20000)
		grade = 8;
	else if (20000 <= scoresum && scoresum < 30000)
		grade = 7;
	else if (30000 <= scoresum && scoresum < 40000)
		grade = 6;
	else if (40000 <= scoresum && scoresum < 50000)
		grade = 5;
	else if (50000 <= scoresum && scoresum < 60000)
		grade = 4;
	else if (60000 <= scoresum && scoresum < 70000)
		grade = 3;
	else if (70000 <= scoresum && scoresum < 80000)
		grade = 2;
	else
		grade = 1;

	printf("                     성적표                     \n");
	printf("                                    이름:	%s  \n", name);//이름 출력
	printf("                                                \n");
	printf("             초등학교:  %d점\n\n", elementary);
	printf("             중학교  :  %d점\n\n", middle);
	printf("             고등학교:  %d점\n\n", high);
	printf("             총점    :  %d점\n\n", elementary + middle + high);
	printf("             최종 등급: %d등급", grade);

}


int Scorecard(int level)
{
	extern char name[];
	extern int life;
	extern int TotalScore;
	extern int e_score[], m_score[], h_score[];
	extern int E_O, E_num_Q, E_O_BOSS, E_num_Q_boss;
	extern int M_O, M_num_Q, M_O_BOSS, M_num_Q_boss;
	extern int H_O, H_num_Q, H_O_BOSS, H_num_Q_boss;

	char ch, school[10], next[10];
	int go;
	int t1 = 0, t2 = 0;

	drawline();
	drawitem();
	drawmenu();

	switch (level)
	{
	case ELEMENTARY:
		strcpy(school, "초등");
		strcpy(next, "중");
		break;
	case MIDDLE:
		strcpy(school, "중");
		strcpy(next, "고등");
		break;
	case HIGH:
		strcpy(school, "고등");
		break;
	}

	if (life)
	{
		happyKU();
		drawline();
		gotoxy(45, 12);
		printf("! %s학교 졸업을 축하합니다 ! \n\n", school);
	}
	else
	{
		sadKU();
		drawline();
		gotoxy(45, 12);
		printf(" --  조금 더 연습해보아요!  --");
	}


	switch (level)
	{
	case ELEMENTARY:
	{
		gotoxy(75, 14);
		printf("이름: %s\n", name);//이름 출력
		gotoxy(58, 16);
		printf("학교");
		gotoxy(73, 16);
		printf("교장");
		gotoxy(28, 18);
		printf("맞은 문제수 / 푼 문제수");
		gotoxy(35, 20);
		printf("획득 점수");
		gotoxy(33, 22);
		printf("시간 추가 점수");
		gotoxy(35, 24);
		printf("콤보 점수");
		gotoxy(57, 18);
		printf("%d / %d", E_O, E_num_Q);
		gotoxy(72, 18);
		printf("%d / %d", E_O_BOSS, E_num_Q_boss);
		gotoxy(54, 20);
		printf("%7d 점", e_score[correct_score]);
		gotoxy(69, 20);
		printf("%7d 점", e_score[boss_correct_score]);

		gotoxy(54, 22);
		printf("%7d 점", e_score[time_bonus]);
		gotoxy(69, 22);
		printf("%7d 점", e_score[boss_time_bonus]);

		gotoxy(56, 24);
		printf("%4d 점", e_score[combo_bonus]);
		gotoxy(71, 24);
		printf("%4d 점", e_score[boss_combo_bonus]);
		gotoxy(56, 25);
		printf("(%d COMBO)", e_score[combo_bonus] / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", e_score[combo_bonus] / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("합계");
		gotoxy(56, 28);
		printf("%d 점", e_score[total_score]);
		gotoxy(72, 28);
		printf("%d 점", e_score[boss_total_score]);
		gotoxy(67, 30);
		printf("총점: %7d 점", e_score[total_score] + e_score[boss_total_score]);
		gotoxy(67, 32);
		printf("누적: %7d 점", TotalScore);
		break;
	}
	case MIDDLE:
	{
		gotoxy(75, 14);
		printf("이름: %s\n", name);//이름 출력
		gotoxy(58, 16);
		printf("학교");
		gotoxy(73, 16);
		printf("교장");
		gotoxy(28, 18);
		printf("맞은 문제수 / 푼 문제수");
		gotoxy(35, 20);
		printf("획득 점수");
		gotoxy(33, 22);
		printf("시간 추가 점수");
		gotoxy(35, 24);
		printf("콤보 점수");
		gotoxy(57, 18);
		printf("%d / %d", M_O, M_num_Q);
		gotoxy(72, 18);
		printf("%d / %d", M_O_BOSS, M_num_Q_boss);
		gotoxy(54, 20);
		printf("%7d 점", m_score[correct_score]);
		gotoxy(69, 20);
		printf("%7d 점", m_score[boss_correct_score]);

		gotoxy(54, 22);
		printf("%7d 점", m_score[time_bonus]);
		gotoxy(69, 22);
		printf("%7d 점", m_score[boss_time_bonus]);

		gotoxy(56, 24);
		printf("%4d 점", m_score[combo_bonus]);
		gotoxy(71, 24);
		printf("%4d 점", m_score[boss_combo_bonus]);
		gotoxy(56, 25);
		printf("(%d COMBO)", m_score[combo_bonus] / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", m_score[combo_bonus] / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("합계");
		gotoxy(56, 28);
		printf("%d 점", m_score[total_score]);
		gotoxy(72, 28);
		printf("%d 점", m_score[boss_total_score]);
		gotoxy(67, 30);
		printf("총점: %7d 점", m_score[total_score] + m_score[boss_total_score]);
		gotoxy(67, 32);
		printf("누적: %7d 점", TotalScore);
		break;
	}
	case HIGH:
	{
		gotoxy(75, 14);
		printf("이름: %s\n", name);//이름 출력
		gotoxy(58, 16);
		printf("학교");
		gotoxy(73, 16);
		printf("교장");
		gotoxy(28, 18);
		printf("맞은 문제수 / 푼 문제수");
		gotoxy(35, 20);
		printf("획득 점수");
		gotoxy(33, 22);
		printf("시간 추가 점수");
		gotoxy(35, 24);
		printf("콤보 점수");
		gotoxy(57, 18);
		printf("%d / %d", H_O, H_num_Q);
		gotoxy(72, 18);
		printf("%d / %d", H_O_BOSS, H_num_Q_boss);
		gotoxy(54, 20);
		printf("%7d 점", h_score[correct_score]);
		gotoxy(69, 20);
		printf("%7d 점", h_score[boss_correct_score]);

		gotoxy(54, 22);
		printf("%7d 점", h_score[time_bonus]);
		gotoxy(69, 22);
		printf("%7d 점", h_score[boss_time_bonus]);

		gotoxy(56, 24);
		printf("%4d 점", h_score[combo_bonus]);
		gotoxy(71, 24);
		printf("%4d 점", h_score[boss_combo_bonus]);
		gotoxy(56, 25);
		printf("(%d COMBO)", h_score[combo_bonus] / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", h_score[combo_bonus] / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("합계");
		gotoxy(56, 28);
		printf("%d 점", h_score[total_score]);
		gotoxy(72, 28);
		printf("%d 점", h_score[boss_total_score]);
		gotoxy(67, 30);
		printf("총점: %7d 점", h_score[total_score] + h_score[boss_total_score]);
		gotoxy(67, 32);
		printf("누적: %7d 점", TotalScore);
		break;
	}
	}




	/*
	printf("%d 문제중 %d 문제 정답!", Q_solved, Q_correct);
	gotoxy(48, 18);
	printf("획득한 점수  :  %5d 점", e_correct_score);
	gotoxy(48, 20);
	printf("시간추가 점수:  %5d 점", e_time_bonus);
	gotoxy(48, 22);
	printf("콤보점수     :  %5d 점 (%d COMBO)", e_combo_bonus, e_combo_bonus / BonusPerCombo);
	gotoxy(48, 24);
	printf("보스점수     :  %5d 점", eboss_total_score);
	gotoxy(34, 26);
	printf("----------------------------------------------------");
	gotoxy(48, 28);
	printf("총점         :  %5d 점", e_total_score + eboss_total_score);
	*/

	system("pause");/// 임시****

	gotoxy(25, 31);
	if (level != HIGH && life != 0) {
		printf("[ %s학교로 진행하려면 g, 메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.]", next);
		gotoxy(25, 32);
		printf(" 아무키도 누르지 않으면 자동으로 %s학교로 입학합니다. [8초]", next);
		t1 = clock(0);
	}
	else
		printf("[ 메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.]");

	while (1)
	{
		do {	// **********************************5/23 민영 시간 8초 지나면 자동 이동 기능 
			t2 = clock(0);
			if (difftime(t2, t1) > 8000) {
				return 1;
				break;
			}
		} while (!_kbhit());
		ch = _getch();
		if (ch == ESC)
		{
			go = 0;
			score_reset();
			//score_reset();
			break;
		}
		if (ch == 'g')
		{
			go = 1;
			break;
		}
	}
	system("cls");
	return go;
	}


void sadKU()
{
	system("cls");
	gotoxy(0, 9);
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t            ■  ■    ■■■■■    ■  ■\n");
	printf("\t\t\t\t            ■    ■■          ■■    ■\n");
	printf("\t\t\t\t            ■  ■■              ■■  ■\n");
	printf("\t\t\t\t        ■■■■        ■    ■      ■■■■\n");
	printf("\t\t\t\t    ■■  ■            ■    ■          ■  ■■\n");
	printf("\t\t\t\t  ■      ■      ■      ■  ■  ■      ■      ■\n");
	printf("\t\t\t\t■      ■      ■          ■      ■      ■      ■\n");
	printf("\t\t\t\t■      ■                                  ■      ■\n");
	printf("\t\t\t\t  ■■■                                      ■■■\n");
	printf("\t\t\t\t      ■      ■■■■■      ■■■■■      ■\n");
	printf("\t\t\t\t      ■        ■  ■          ■  ■        ■\n");
	printf("\t\t\t\t    ■                  ■  ■                  ■\n");
	printf("\t\t\t\t    ■            ■■■■■■■■■            ■\n");
	printf("\t\t\t\t    ■        ■■■              ■■■        ■\n");
	printf("\t\t\t\t    ■    ■■          ■■■          ■■    ■\n");
	printf("\t\t\t\t    ■  ■            ■      ■            ■  ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t        ■                                  ■\n");
	printf("\t\t\t\t        ■■                              ■■\n");
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t              ■■                  ■■\n");
	printf("\t\t\t\t                  ■■■■■■■■■\n");
	Sleep(2000);
	system("cls");
}

void happyKU()
{
	system("cls");
	gotoxy(0, 9);
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t            ■  ■    ■■■■■    ■  ■\n");
	printf("\t\t\t\t            ■    ■■          ■■    ■\n");
	printf("\t\t\t\t            ■  ■■              ■■  ■\n");
	printf("\t\t\t\t        ■■■■        ■    ■      ■■■■\n");
	printf("\t\t\t\t    ■■  ■            ■    ■          ■  ■■\n");
	printf("\t\t\t\t  ■      ■      ■      ■  ■  ■      ■      ■\n");
	printf("\t\t\t\t■      ■      ■          ■      ■      ■      ■\n");
	printf("\t\t\t\t■      ■                                  ■      ■\n");
	printf("\t\t\t\t  ■■■          ■              ■            ■■■\n");
	printf("\t\t\t\t      ■        ■  ■          ■  ■        ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t    ■                  ■  ■                  ■\n");
	printf("\t\t\t\t    ■            ■■■■■■■■■            ■\n");
	printf("\t\t\t\t    ■        ■■■              ■■■        ■\n");
	printf("\t\t\t\t    ■    ■■        ■      ■        ■■    ■\n");
	printf("\t\t\t\t    ■  ■              ■■■              ■  ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t        ■                                  ■\n");
	printf("\t\t\t\t        ■■                              ■■\n");
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t              ■■                  ■■\n");
	printf("\t\t\t\t                  ■■■■■■■■■\n");
	Sleep(2000);
	system("cls");
}

//나중에 필요할 수도 있을것 같아 주석처리하고 일단은 두었습니다.
/*
int Scorecard(int level, int Q_solved, int Q_correct)
{
	extern char name[];
	extern int life;
	extern int e_total_score, e_correct_score, e_time_bonus, e_combo_bonus;
	extern int eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus;

	char ch, school[10], next[10];
	int go;
	int t1 = 0, t2 = 0;

	drawline();
	drawitem();
	drawmenu();

	switch (level)
	{
	case ELEMENTARY:
		strcpy(school, "초등");
		strcpy(next, "중");
		break;
	case MIDDLE:
		strcpy(school, "중");
		strcpy(next, "고등");
		break;
	case HIGH:
		strcpy(school, "고등");
		break;
	}

	if (life)
	{
		happyKU();
		drawline();
		gotoxy(45, 12);
		printf("! %s학교 졸업을 축하합니다 ! \n\n", school);
	}
	else
	{
		sadKU();
		drawline();
		gotoxy(45, 12);
		printf(" --  조금 더 연습해보아요!  --");
	}


	gotoxy(75, 14);
	printf("이름: %s\n", name);//이름 출력
	gotoxy(48, 16);
	printf("%d 문제중 %d 문제 정답!", Q_solved, Q_correct);
	gotoxy(48, 18);
	printf("획득한 점수  :  %5d 점", e_correct_score);
	gotoxy(48, 20);
	printf("시간추가 점수:  %5d 점", e_time_bonus);
	gotoxy(48, 22);
	printf("콤보점수     :  %5d 점 (%d COMBO)",e_combo_bonus , e_combo_bonus / BonusPerCombo);
	gotoxy(48, 24);
	printf("보스점수     :  %5d 점", eboss_total_score);
	gotoxy(34, 26);
	printf("----------------------------------------------------");
	gotoxy(48, 28);
	printf("총점         :  %5d 점", e_total_score+eboss_total_score);


	system("pause");/// 임시****

	gotoxy(25, 31);
	if (level != HIGH && life != 0) {
		printf("[ %s학교로 진행하려면 g, 메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.]", next);
		gotoxy(25, 32);
		printf(" 아무키도 누르지 않으면 자동으로 %s학교로 입학합니다. [8초]", next);
		t1 = clock(0);
	}
	else
		printf("[ 메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.]");

	while (1)
	{
		do {	// **********************************5/23 민영 시간 8초 지나면 자동 이동 기능
			t2 = clock(0);
			if (difftime(t2, t1) > 8000) {
				return 1;
				break;
			}
		} while (!_kbhit());
		ch = _getch();
		if (ch == ESC)
		{
			go = 0;
			//score_reset();
			break;
		}
		if (ch == 'g')
		{
			go = 1;
			break;
		}
	}
	system("cls");
	return go;
}*/