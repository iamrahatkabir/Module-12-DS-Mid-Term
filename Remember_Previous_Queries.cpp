#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void delete_linked_list(Node* &head, Node* &tail, int idx, int size)
{
    // cout << "hello from delete list " << size << endl;

    Node* temp = head;
    for(int i = 0; i < idx-1; i++)
    {
        temp = temp->next;
        // cout << "Hello temp value" << temp->val << endl;
    }
    Node* deletenode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete deletenode;

}

void delete_at_head(Node* &head, Node* &tail)
{
    // cout << "Hello temp value" << head->val << endl;
    Node* deletenode = head;
    head = head->next;
    if(head == NULL)
    {
        tail = NULL;
    }
    else{
        head->prev = NULL;
    }
    delete deletenode;
}

void delete_at_tail(Node* &head, Node* &tail)
{
    Node* deletenode = tail;
    tail = tail->prev;
    tail->next = NULL;
    // cout << "tail value" << tail->val << endl;
    delete deletenode;
}

void print_doubly(Node *head, Node *tail)
{
    // cout << "tail value" << tail->val << endl;
    Node *temp = head;
    Node *temp_back = tail;

    cout << "L -> ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "R -> ";
    while (temp_back != NULL)
    {
        cout << temp_back->val << " ";
        temp_back = temp_back->prev;
    }
    cout << endl;
    // cout << "Print" << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;

    int cnt = 0;

    for (int i = 0; i < q; i++)
    {
        int idx, val;
        cin >> idx >> val;

        if (idx == 0)
        {
            cnt++;
            insert_at_head(head, tail, val);
            print_doubly(head, tail);
        }
        else if (idx == 1)
        {
            cnt++;
            insert_at_tail(head, tail, val);
            print_doubly(head, tail);
        }
        else if(idx == 2)
        {
            // cout << "hello from valid " << cnt << endl;
            if(val > cnt-1)
            {
                print_doubly(head, tail);
            }
            else{
                if(val == 0)
                {
                    // cout << "hello from valid " << cnt << endl;
                    delete_at_head(head, tail);
                    print_doubly(head, tail);
                    cnt--;
                }
                else if(val == cnt-1)
                {
                    delete_at_tail(head, tail);
                    print_doubly(head, tail);
                    cnt--;
                }
                else
                {
                    // cout << "hello from valid " << cnt << endl;
                    delete_linked_list(head, tail, val, cnt);
                    cnt--;
                    print_doubly(head, tail);
                }
                // cout << cnt << endl;
            }
        }
    }

    return 0;
}