#include <iostream>

using namespace std;

void setStatus(int status[]);

void setPotion(int count, int* m_HPPotion, int* m_MPPotion);

void printMainMenu();

void usePotion(const char* statusName, int& status, int* m_Potion);

void multipleStat(const char* statusName, int& status, int mul);

void activateSkill(int skillType, int& MP);

int main()
{
    int status[4] = { 0, };
    int HPPotion, MPPotion;
    int choice;

    setStatus(status);
    setPotion(5, &HPPotion, &MPPotion);
    printMainMenu();

    do
    {
        cout << "번호를 선택해주세요: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            usePotion("HP", status[0], &HPPotion);
            break;
        case 2:
            usePotion("MP", status[1], &MPPotion);
            break;
        case 3:
            multipleStat("HP", status[0], 2);
            break;
        case 4:
            multipleStat("MP", status[1], 2);
            break;
        case 5:
            activateSkill(0, status[1]);
            break;
        case 6:
            activateSkill(1, status[1]);
            break;
        case 7:
            cout << "게임을 종료합니다." << endl;
            break;
        default:
            cout << "잘못된 선택입니다. 다시 입력해주세요." << endl;
            break;
        }

    } while (choice != 7);

    return 0;
}

void setStatus(int status[])
{
    do
    {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];

        if (status[0] <= 50 || status[1] <= 50)
        {
            cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
            continue;
        }
        else
            break;
    } while (true);

    do
    {
        cout << "공격력와 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];

        if (status[2] < 1 || status[3] < 1)
        {
            cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
            continue;
        }
        else
            break;
    } while (true);

    return;
}

void setPotion(int count, int* m_HPPotion, int* m_MPPotion)
{
    *m_HPPotion = count;
    *m_MPPotion = count;
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)" << endl;

    return;
}

void printMainMenu()
{
    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    cout << "1. HP 회복" << endl;
    cout << "2. MP 회복" << endl;
    cout << "3. HP 강화" << endl;
    cout << "4. MP 강화" << endl;
    cout << "5. 공격 스킬 사용" << endl;
    cout << "6. 필살기 사용" << endl;
    cout << "7. 나가기" << endl;

    return;
}

void usePotion(const char* statusName, int& status, int* m_Potion)
{
    if (*m_Potion > 0)
    {
        *m_Potion -= 1;
        status += 20;
        cout << "* " << statusName << "가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
        cout << "현재 " << statusName << ": " << status << endl;
        cout << "남은 포션 수: " << *m_Potion << endl;
    }
    else
    {
        cout << "* 포션이 부족합니다." << endl;
    }

    return;
}

void multipleStat(const char* statusName, int& status, int mul)
{
    status *= mul;
    cout << "* " << statusName << "가 " << mul << "배로 증가되었습니다." << endl;
    cout << "현재 " << statusName << ": " << status << endl;
}

void activateSkill(int skillType, int& MP)
{
    switch (skillType)
    {
    case 0:
        if (MP < 50)
        {
            cout << "마나가 부족합니다." << endl;
            return;
        }
        else
        {
            MP -= 50;
            cout << "* 스킬을 사용하여 MP가 50 소모되었습니다." << endl;
            break;
        }
    case 1:
        if (MP < 2)
        {
            cout << "마나가 부족합니다." << endl;
            return;
        }
        else 
        {
            MP /= 2;
            cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다." << endl;
            break;
        }
    default:
        cout << "* 잘못된 스킬 타입 입니다." << endl;
        return;
    }

    cout << "현재 MP: " << MP << endl;
    return;
}