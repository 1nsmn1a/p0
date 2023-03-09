﻿#include <iostream>

using namespace std;
struct node {
    int data;
    struct node* next;
};
struct node* myHead;
int countItem = 0;

void addItem(int data) //Добавляет элемент в начало.
{
    struct node* newItem = new node();
    newItem->data = data;
    if (countItem == 0) {
        newItem->next = NULL;    
    }
    else
    {
        newItem->next = myHead;
    }
    myHead = newItem;
    countItem++;
}
void insertItem(int index, int data) {
    if (not (index >= 0 and index <= countItem and countItem>0))
        return;
    if (index==0){
        addItem(data);
    }
    else {
        struct node* current = myHead;
        for (int i = 0; i < index-1; i++) {
            current = current->next;
        }
        struct node* newItem = new node();
        newItem->data = data;
        newItem->next = current->next;
        current->next = newItem;
    }
}
void editItem(int index, int data) {
    if (index >= 0 and index < countItem and countItem>0) {
        struct node* current = myHead;
        for (int i = 0; i < index;  i++) {
            current = current->next;
            //cout << "+" << current->data;
        }
        current->data = data;
    }
    else {
        cout << endl <<"Ошибка индекс не в диапазоне";
    }
}
/// <summary>
/// Функция для удаления элемента из динамического списка
/// </summary>
/// <param name="index">индекс удаляемого элемента</param>
void deleteItem(int index) {
    if (index >= 0 and index < countItem and countItem>0) {
        struct node* current = myHead;
        struct node* old;
        if (index == 0) {
            old = myHead;
            myHead = current->next;
            delete old;
            countItem--;
        }
        else {
            int i = 0;
            while (current) {
                if (i == index-1) {
                    old = current->next->next;
                    delete current->next;
                    current->next = old;
                    countItem--;
                    break;
                }
                i++;
                current = current->next;
            }
        }
    }

}
void printMyList() {
    struct node* current = myHead;
    cout << endl;
    while (current) {
        cout << " " << current->data;
        current = current->next;
    }
}

int main()
{
    cout << "myList\n";
    addItem(1);
    addItem(2);
    addItem(3);
    addItem(4); 
    printMyList();
    cout << endl << "Count item: " << countItem << endl;
    //editItem(2, 8);
    //deleteItem(3);
    insertItem(4, 8);
    printMyList();
}