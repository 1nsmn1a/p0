#pragma once
#include "EzhStandart.h"
class EzhBattle :
    public EzhStandart
{
private:
    string weapon;
    int damage;
    int health;
public:
    int atack(int d) {
        health -= d;
        cout << "��� ����� �� �����: " << this->getName() << "�������� ��������: " << health;
        return health;

    }
    void display() {
        cout << "";
    }
    EzhBattle() {
        weapon = "������";
        damage = 1;
        health = 10;
    }
};

