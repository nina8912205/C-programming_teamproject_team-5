#include "common.h"

int main(void)
{
	extern int end_game;
	extern int die;

	system("mode con: cols=120 lines=43"); // 콘솔창 크키 조정
	srand((unsigned)time(NULL));

	while (1)
	{
		system("cls");
		game_title();                 // 게임 타이틀

		while (1)
		{
			resetScore();
			game_start_menu();        // 게임 시작 및 진행
			if (die == 1)             //목숨 0 되어 죽었을 경우 - 타이틀 출력으로 돌아감.
			{
				die = 0;
				end_game = 0;
				break;
			}
			if (end_game)        //게임 종료 관련 - 메인 메뉴에서 게임 종료 선택시 게임 프로그램 종료//
				break;
		
		}
		if (end_game == 1) //만약 메인 메뉴에서 3. 게임종료 선택시, 게임 프로그램 완전히 
			break;
	}

	return 0;
}