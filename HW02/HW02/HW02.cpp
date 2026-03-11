#include <iostream>
#include "Player.h"
#include "Warrior.h" 
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;
    Monster* monster = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    do {
        cout << "선택: " << endl;
        cin >> job_choice;

        switch (job_choice) {
        case 1:
            player = new Warrior(nickname);
            player->setHP(120);
            break;
        case 2:
            player = new Magician(nickname);
            player->setMP(120);
            break;
        case 3:
            player = new Thief(nickname);
            player->setSpeed(20);
            break;
        case 4:
            player = new Archer(nickname);
            player->setAccuracy(15);
            break;
        default:
            cout << "잘못된 입력입니다." << endl;
            //break;
            return 1;
        }
    } while ((job_choice < 1) || (job_choice > 4));

    player->attack();

    cout << "* 몬스터이름을 입력해주세요: ";
    cin >> nickname;
    monster = new Monster(nickname);

    cout << endl;
    cout <<"Mon: " << monster->M_getname() << " VS User: " << player->getNickname() << "의 대결 !" << endl;

    monster->M_sethp(30);
    player->printPlayerStatus();

    int iswinp = player->attack(monster);
    int iswinm = monster->attack(player);
    do
    {
        iswinp = player->attack(monster);
        if (iswinp * iswinm)
        {
        }
        else
        {
            break;
        }
        iswinm = monster->attack(player);
    } while ( iswinp * iswinm );

    if (player != nullptr)
    {
        delete player;
        delete monster;
    }
    return 0;
}