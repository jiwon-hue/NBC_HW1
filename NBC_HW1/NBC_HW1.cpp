#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main(void)
{
	int status[4] = { 0, }; //HP, MP, 공격력, 방어럭
	int* p_HPPotion = (int*)malloc(sizeof(int));
	int* p_MPPotion = (int*)malloc(sizeof(int));
	int condition = 1;

	//2-1. HP, MP 입력
	do
	{
		printf(">> HP와 MP를 입력해주세요: ");
		scanf("%d %d", &status[0], &status[1]);
		if (status[0] > 50 && status[1] > 50)
		{
			break;
		}
		printf("HP나 MP의 값이 너무 작습니다. 다시 입력해주세요. (50 초과한 수를 적을 것)\n");
	} while (true);

	//2-2. 공격력, 방어력 입력
	do
	{
		printf(">> 공격력과 방어력을 입력해주세요: ");
		scanf("%d %d", &status[2], &status[3]);

		if (status[2] > 0 && status[3] > 0)
		{
			break;
		}
		printf("공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요. (0 초과한 수를 적을 것)\n");
	} while (true);

	//3. 스탯관리 시스템

	setPotion(5, p_HPPotion, p_MPPotion);

	printf("\n1.HP UP\n");
	printf("2.MP UP\n");
	printf("3.공격력 UP\n");
	printf("4.방어력 UP\n");
	printf("5.현재 능력치\n");
	printf("6.Level Up\n");
	printf("0.나가기\n\n");

	do
	{
		int num;

		printf(">> 번호를 선택해주세요: ");
		scanf("%d", &num);

		switch (num) {
		case 0: 
			condition = 0;
			printf("프로그램을 종료합니다.\n");
			break;
		case 1:
			if (*p_HPPotion > 0)
			{
				status[0] += 20;
				--*p_HPPotion;
				printf("* HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n");
				printf("현재 HP: %d\n", status[0]);
				printf("남은 포션 수: %d\n", *p_HPPotion);
			}
			else
			{
				printf("포션이 부족합니다.\n");
			}
			break;
		case 2:
			if (*p_MPPotion > 0)
			{
				status[1] += 20;
				--*p_MPPotion;
				printf("* MP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n");
				printf("현재 HP: %d\n", status[1]);
				printf("남은 포션 수: %d\n", *p_MPPotion);
			}
			else
			{
				printf("포션이 부족합니다.\n");
			}
			break;
		case 3:
			status[2] *= 2;
			printf("* 공격력이 2배로 증가되었습니다.\n", status[2]);
			printf("현재 공격력: %d\n", status[2]);
			break;
		case 4:
			status[3] *= 2;
			printf("* 방어력이 2배로 증가되었습니다.\n", status[3]);
			printf("현재 방어력: %d\n", status[3]);
			break;
		case 5:
			printf("* HP : %d, MP : %d, 공격력 : %d, 방어력 : %d\n", status[0], status[1], status[2], status[3]);
			break;
		case 6:
			++ *p_HPPotion;
			++ *p_MPPotion;
			printf("* 레벨업! HP/MP 포션이 지급됩니다.\n");
			printf("남은 HP/MP 포션 수 : %d/%d\n", *p_HPPotion, *p_MPPotion);
			break;
		}

	} while (condition);

	free(p_HPPotion), free(p_MPPotion);
	return 0;
}

//4. 포션시스템
void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
	printf("* 포션이 지급되었습니다. (HP, MP 포션 각 %d개)", count);

	return;
}