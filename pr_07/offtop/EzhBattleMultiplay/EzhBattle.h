#pragma once
#include "EzhStandart.h"
#include <windows.h> 
class EzhBattle :
    public EzhStandart
{
private:
    string weapon;
    int damage;
    int health;
public:
    int atack(int d) {
        if (health>0){
           health -= d;
           cout << "��� ����� �� �����: " << this->getName() << " �������� ��������: " << health <<endl;
        }
        else
        {
            cout << "����: " << this->getName() << " GameOver" << endl;
            Beep(1000, 3000);
        }
        return health;

    }
    int getDamage() {
        return damage;
    }
    void display() {
        cout << "";
    }
    EzhBattle() {
        weapon = "������";
        damage = 15;
        health = 145;
    }
};

