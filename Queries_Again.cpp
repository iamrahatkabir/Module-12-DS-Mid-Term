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
        Node* next;
        Node* prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void insert_at_head(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;

}

void insert_at_any(Node* &head, Node* &tail, int val, int idx)
{
    
    Node* newnode = new Node(val);
    Node* temp = head;
    // cout << "IDX " << idx << endl;
    for(int i = 0; i < idx-1; i++)
    {
        temp = temp->next;
    }
    temp->next->prev = newnode;
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    // cout << "Hi from any " << tail->prev->val << endl;
}

void print_doubly(Node* head, Node* tail)
{
    Node* temp = head;
    Node* temp_back = tail;

    cout << "L -> ";
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "R -> ";
    while(temp_back != NULL)
    {
        cout << temp_back->val << " ";
        temp_back = temp_back->prev;
    }
    cout << endl;
    // cout << "Print" << endl;

}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int q;
    cin >> q;

    int cnt = 0;

    for(int i = 0; i < q; i++)
    {
        int idx, val;
        cin >> idx >> val;


        // cout << "idx = " << idx << " cnt = " << cnt << endl;
        if(idx <= cnt)
        {
            if(idx == 0)
            {
                // cout << "call from head" << endl;
                cnt++;
                insert_at_head(head, tail, val);
                print_doubly(head, tail);
            }
            else if(idx == cnt)
            {
                cnt++;
                //Insert at tail;
                // cout << "call from tail" << endl;
                insert_at_tail(head, tail, val);
                print_doubly(head, tail);
            }
            else
            {
                cnt++;
                // cout << "Call from any " << endl;
                insert_at_any(head, tail, val, idx);
                print_doubly(head, tail);
                //Insert at any;
            }

            

        }
        else
        {
            cout << "Invalid" << endl;
        }


    }
 

    return 0;
}