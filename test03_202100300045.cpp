#include <iostream>
#include<algorithm>

using namespace std;

struct ListNode{
    int data;
    struct ListNode* next;
    ListNode(int x) :
        data(x),next(NULL){}
    ListNode() :
        data(0),next(NULL){}
};

void remake(ListNode* & head, int count){
    ListNode* m = head;
    if(head->data == 0) return;
    int * copy = new int [count];

    for(int i = 0;i<count;i++){
        copy[i] = m->data;
        m = m->next;
    }

    sort( copy, copy+count);
    m = head;

    for(int i = 0;i<count;i++){
        m->data = copy[i];
        m = m->next;
    }
}

void output(ListNode* head){
    ListNode *m = head;
    while(m!= nullptr){
        if(m->next == nullptr){
            cout << m->data << endl;
            break;
        }
        cout << m->data << ",";
        m = m->next;
    }
}

ListNode* insertNode(ListNode* & head, int data){
    ListNode* newNode = new ListNode(data);
    ListNode* p = head;
    if(p == nullptr){
        head = newNode;
    }
    else{
        if(head->data > newNode->data){
            newNode->next = head;
            head = newNode;
            return head;
        }
            
        while(p->next != nullptr && p->next->data < newNode->data){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    return head;
}

int indexOf(ListNode* head, int& element){
    ListNode* p = head;
    int count = 0;
    while(p->next != nullptr){
        count++;
        if(p->data == element)
            return count;
        p = p->next;
    }
    if(element == p->data)
        return count+1;
    return 0;
}

ListNode*  merge(ListNode* a,ListNode* b){
    if(a == nullptr)
        return b;
    if(b == nullptr)
        return a;
    ListNode* head, *p1, *p2;
    if(a->data < b->data){
        head = a;
        p1 = a->next;
        p2 = b;
    }
    else
    {
        head = b;
        p1 = a;
        p2 =  b->next;
    }
    ListNode* m = head;
    while(p1 && p2){
        if(p1->data <= p2->data){
            m->next = p1;
            m = p1;
            p1 = p1->next;
        }
        else if(p1->data > p2->data){
            m->next = p2;
            m = p2;
            p2 = p2->next;
        }
    }
    if(p1)
        m->next = p1;
    if(p2)
        m->next = p2;
    return head;
}

int main(){
    int num,count = 1;
    cout << "Input1" << endl;
    cin >> num;
    ListNode* head = new ListNode(num);
    ListNode* p = head;

    while(cin >> num){
        if(num == 0)
            break;
        ListNode *q = new ListNode(num);
        p->next =q;
        p = p->next;
        count++;
    }
    remake(head,count);

    cout << "Output1" << endl;
    output(head);

    cout << "Input2" << endl; //insert,output有序插入
    cin >> num;
    insertNode(head,num);
    cout << "Output2" << endl;
    output(head);


    cout << "Input3" << endl;   //indexOf
    cin >> num;
    cout << "Output3" << endl;  
    cout << indexOf(head,num) << endl;

    cout << "Input4" << endl;   //indexOf
    cin >> num;
    cout << "Output4" << endl; 
    cout << indexOf(head,num) << endl;


    cout << "Input5" << endl;   //newlist,output
    cin >> num;
    ListNode* head2 = new ListNode(num);
    ListNode* p2 = head2;
    int count2 = 1;
    while(cin >> num){
        if(num == 0)
            break;        
        ListNode* q2 = new ListNode(num);
        p2->next = q2;
        p2 = p2->next;
        count2++;
    }
    remake(head2,count2);
    cout << "Output5" << endl; 
    output(head2);

    output(merge(head,head2));

    cout << "End" << endl;
    system("pause");
    return 0;
}