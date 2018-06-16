// twst.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

struct ListNode 
{
    ListNode* next;
    int var;
    ListNode() : next(nullptr), var(0) {}
    ListNode(int _var) : next(nullptr), var(_var) {}
};

//创建了一个没有头结点的单向链表
ListNode* MakeList(vector<int>& vec)
{
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for (auto& i : vec)
    {
        ListNode* tmp = new ListNode(i);
        cur->next = tmp;
        cur = tmp;
    }
    return head->next;
    //return head  //返回带头结点的链表
}

void PrintfList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->var << '\t';
        head = head->next;
    }
    cout << endl;
}

ListNode* RevertList(ListNode* head)
{
    if (head == nullptr && head->next == nullptr)	return head;

    ListNode* newList = nullptr;
    while (head != nullptr)
    {
        ListNode* tmp = head;
        head = head->next;
        tmp->next = newList;
        newList = tmp;
    }
    return newList;
}

ListNode* GetLastKthNode(ListNode* head, unsigned int k)
{
    if (head == nullptr)	return head;
    ListNode* last = head;
    for (unsigned int i=0;i<k;i++)
    {
        last = last->next;
        if (last == nullptr)
        {
            cout << "unexpected k value!" << endl;
            return nullptr;
        }
    }
    while (last != nullptr)
    {
        head = head->next;
        last = last->next;
    }
    return head;
}


int main()
{
    vector<int> vec = { 1,2,3,4,5,6 };
    ListNode* head = MakeList(vec);
    PrintfList(head);
    
    //PrintfList(RevertList(head);

    cout << GetLastKthNode(head, 1)->var << endl;


}
