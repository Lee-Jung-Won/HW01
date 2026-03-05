#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>

void usePotion(int count, int* p_HPPotion, int* p_MPPotion);
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void RefillPotion(int count, int* p_HPPotion, int* p_MPPotion);
void Upabil(int a, struct info* infop);
int Startsystem(struct info* infop);

typedef struct info
{
	int cinfo[5]; // 필수 구현 기능 1.HP 2.MP 3.공 4.방 5.렙
	int cabil[4]; // 도전 기능 확장 1. str 2. dex 3. int 4. luk
	int cinven[2]; // hp포션 mp포션

} info_t;

int main(void)
{
	int Ccount, Cinto, i, j, CChange, CChange1 = 0;
	printf("만들 캐릭터 갯수를 숫자로 적어주세요: ");
	scanf_s("%d", &Ccount);
	printf("몇번째 캐릭터로 들어갈까요?(1~만든갯수) : ");
	scanf_s("%d", &Cinto);
	info_t* infop = (info_t*)malloc(Ccount * sizeof(info_t));
	// 캐릭터 스텟 초기화 > 구조체에서 초기화되지않음.
	for (i = 0; i < Ccount; i++)
	{
		for (j = 0; j < 5; j++)
		{
			(infop + i)->cinfo[j] = 0;
			if (j <= 3)
			{
				(infop + i)->cabil[j] = 5;
			}
		}
	}
	// n번째 캐릭터 성장시작
	do
	{
		CChange = Startsystem(infop + (Cinto - 1));
		Cinto = CChange;
	} while (CChange != 0);

	printf("프로그램을 종료합니다.\n");
	return 0;
}


int Startsystem(struct info* infop) //캐릭성장함수
{
	int Num, Cnum, abilplus;
	srand((unsigned)time(NULL));

	if (infop->cinfo[0] == 0) //초기입력여부
	{
		do
		{
			printf("HP와 MP를 입력해주세요: "); //  필수 구현 기능 2-1
			scanf_s("%d %d", &(infop->cinfo[0]), &(infop->cinfo[1]));
			if (infop->cinfo[0] <= 50 || infop->cinfo[1] <= 50) // 필수 구현 기능 2-2
			{
				printf("HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n");
			}
			
		} while (infop->cinfo[0] <= 50 || infop->cinfo[1] <= 50);

		do
		{
			printf("공격력과 방어력을 입력해주세요: "); // 필수 구현 기능 2-1
			scanf_s("%d %d", &(infop->cinfo[2]), &(infop->cinfo[3]));
			if (infop->cinfo[2] <= 0 || infop->cinfo[3] <= 0) // 필수 구현 기능 2-3
			{
				printf("공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n");
			}

		} while (infop->cinfo[2] <= 0 || infop->cinfo[3] <= 0);


		infop->cinfo[4] = 1;
		
		printf("* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n");
		setPotion(5, &(infop->cinven[0]), &(infop->cinven[1])); // 뭐지 배열은 특이하게 취급하나
	}

	printf("=============================================\n");

	printf("<스탯  관리 시스템>\n");
	printf("1. HP UP\n2. MP UP\n3. 공격력 UP\n4. 방어력 UP\n5. 현재 능력치\n6. Level UP\n7. 캐릭터 선택\n0. 나가기\n");

	do // 필수 구현 기능 3
	{
		printf("스탯관리 번호를 선택해주세요: ");
		scanf_s("%d", &Num);


		switch (Num) // 필수 구현 기능 4-2 : 스탯증가
		{
		case 1:        //hp 증가
			if (infop->cinven[0] > 0) //hp포션의 유무
			{
				infop->cinfo[0] = infop->cinfo[0] + 20;

				usePotion(1, &(infop->cinven[0]), &(infop->cinven[1])); // count = 1 > hp
				printf("* HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n현재 HP: %d\n남은 포션 수: %d\n", infop->cinfo[0], infop->cinven[0]);
			}
			else
			{
				printf("HP포션이 부족합니다.\nHP포션을 3개 충전합니다.\n");
				RefillPotion(1, &(infop->cinven[0]), &(infop->cinven[1]));
				printf("* 현재 HP포션 : %d - MP포션 : %d\n", infop->cinven[0], infop->cinven[1]);
			}
			break;
		case 2:        //mp 증가
			if (infop->cinven[1] > 0) //mp포션의 유무
			{
				infop->cinfo[1] = infop->cinfo[1] + 20;

				usePotion(2, &(infop->cinven[0]), &(infop->cinven[1])); // count = 2 > mp
				printf("* MP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n현재 HP: %d\n남은 포션 수: %d\n", infop->cinfo[1], infop->cinven[1]);
			}
			else
			{
				printf("MP포션이 부족합니다.\nMP포션을 3개 충전합니다.\n");
				RefillPotion(2, &(infop->cinven[0]), &(infop->cinven[1]));
				printf("* 현재 HP포션 : %d - MP포션 : %d\n", infop->cinven[0], infop->cinven[1]);
			}
			break;
		case 3:        //공 증가
			infop->cinfo[2] = infop->cinfo[2] * 2;
			printf("* 공격력이 2배로 증가되었습니다.\n현재 공격력: %d\n", infop->cinfo[2]);
			break;
		case 4:        //방 증가
			infop->cinfo[3] = infop->cinfo[3] * 2;
			printf("* 방어력이 2배로 증가되었습니다.\n현재 방어력: %d\n", infop->cinfo[3]);
			break;
		case 5:        //능력치 // 도전 구현 기능 3-4
			printf("* HP : %d, MP : %d, 공격력 : %d, 방어력 : %d, LEVEL : %d\n", infop->cinfo[0], infop->cinfo[1], infop->cinfo[2], infop->cinfo[3], infop->cinfo[4]);
			printf("남은 포션 > HP포션 : %d, MP포션 : %d\n", infop->cinven[0], infop->cinven[1]);
			break;
		case 6:        //lv 증가 // 고전 구현 기능 1

			usePotion(3, &(infop->cinven[0]), &(infop->cinven[1])); //포션증가 각 +1
			infop->cinfo[4]++; // 레벨증가
			printf("* 레벨업! 현재 : %d - HP/MP 포션이 지급됩니다.\n남은 HP/MP 포션 수 : %d/%d\n", infop->cinfo[4], infop->cinven[0], infop->cinven[1]);
			printf("=================================================\n");
			printf("상승시킬 능력치를 고르세요.\n* 1. STR 2. DEX 3. INT 4. LUK\n");
			scanf_s("%d", &abilplus);

			Upabil(abilplus, infop);

			break;
		}
	} while (Num >= 1 && Num <= 6);

	Cnum = Num;
	if (Cnum == 7)
	{
		printf("몇번째 캐릭터로 이동하시겠습니까? : ");
		scanf_s("%d", &Cnum);
	}
	return Cnum;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) // 필수 구현 기능 4-1
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}


void usePotion(int count, int* p_HPPotion, int* p_MPPotion) 
{
	switch (count) {
	case 1:
		(*p_HPPotion)--;
		break;
	case 2:
		(*p_MPPotion)--;
		break;
	case 3:
		(*p_HPPotion)++;
		(*p_MPPotion)++;
		break;
	}
}

void RefillPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	switch (count)
	{
	case 1:
		(*p_HPPotion) = 3;
		break;
	case 2:
		(*p_MPPotion) = 3;
		break;
	}
}

void Upabil(int a, struct info* infop)
{

	int r = rand() % 3 + 1;

	infop->cabil[a - 1]++;				// 1. str 2. dex 3. int 4. luk 배열index0~3

	switch (a)						//힘민지럭에 대해 공증방증 값 증가
	{
	case 1:
		infop->cinfo[2] = infop->cinfo[2] + 2; //힘 = 공+2
		printf("* 공격력 2증가 !!! > 현재 공격력 : %d\n\n", infop->cinfo[2]);
		break;
	case 2:
		infop->cinfo[2] = infop->cinfo[2] + 1; //덱 = 공+1방+1
		infop->cinfo[3] = infop->cinfo[3] + 1;
		printf("* 공방 1증가 !!! > 현재 공방 : %d - 방어력 : %d\n\n", infop->cinfo[2], infop->cinfo[3]);
		break;
	case 3:
		infop->cinfo[3] = infop->cinfo[3] + 2; //인 = 방+2
		printf("* 방어력 2증가 !!! > 현재 방어력 : %d\n\n", infop->cinfo[3]);
		break;
	case 4:
		switch (r)  // r = 1~3 랜덤인수 > 럭 = 꽝 or 공or방 랜덤 + 3
		{
		case 1: //꽝
			printf("* 꽝 !!! 변화없음 !!! > 현재 공격력 : %d - 방어력 : %d", infop->cinfo[2], infop->cinfo[3]);
			break;
		case 2:	//공+3									
			infop->cinfo[r] = infop->cinfo[r] + 3;
			printf("* 공격력 3증가 !!! > 현재 공격력 : %d\n\n", infop->cinfo[r]);
			break;
		case 3: //방+3
			infop->cinfo[r] = infop->cinfo[r] + 3;
			printf("* 방어력 3증가 !!! > 현재 방어력 : %d\n\n", infop->cinfo[r]);
			break;
		}

		break;
	default: //힘민지럭 그외 값 입력시
		printf("능력치를 향상시키지 못했습니다.\n");
		break;
	}
}
