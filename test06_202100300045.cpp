#include <iostream>
#include <algorithm>


using namespace std;
string a,pre,mid;
typedef struct Node{
    char filed;
    struct Node * lchild = nullptr,* rchild = nullptr;
}*BiTree,BiNode;//声明结构体类型BiTNode=struct Node，BiTree=struct Node*

struct queue
{
    Node *data[100];
    int front,rear;
};

void creatQueue(queue &q){
    q.front = q.rear = 0;
}

void enqueue(queue &q, BiTree &T){
    if( (q.rear+1) % 100 == q.front){
        return;
    }
    q.rear = (q.rear+1) % 100;
    q.data[q.rear] = T;
}

BiTree dequeue(queue &q){
    BiTree T;
    q.front = (q.front+1) % 100;
    T = q.data[q.front];
    return T;
}

bool isEmpty(queue &q){
    return (q.front == q.rear);
}

// int ct = 0;
void CreateBiTree(BiTree &T,string a){
    queue Q;
    creatQueue(Q);

    int i = 1,n = a.length();

    T->filed = a[0];
    enqueue(Q,T);

    while( i<n && !isEmpty(Q) ){
        BiTree p = dequeue(Q);
        if(i < n ){
            p->lchild = new BiNode;
            p->lchild->filed = a[i];
            enqueue(Q,p->lchild);  
        }
        i++;
        if(i < n){
            p->rchild = new BiNode;
            p->rchild->filed = a[i];
            enqueue(Q,p->rchild);    
        }
        i++;

    }


}

void PreOrderTraverse(BiTree T){
    if(T){
        if(T->filed == a[a.length()-1])
            cout << T->filed;
        else
            cout << T->filed << ",";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        if(T->filed == a[a.length()-1])
            cout << T->filed;
        else
            cout << T->filed << ",";
        InOrderTraverse(T->rchild);
    }
}

void levelOrederTraverse(BiTree T){
    queue q;
    creatQueue(q);
    BiTree t = new BiNode;

    if(T->lchild == nullptr){
        cout << T->filed;
        return;
    }

    enqueue(q,T);
    while( !isEmpty(q) ){
        t = dequeue(q);
        if( isEmpty(q) && t->filed!='A')
            cout << t->filed;
        else
            cout << t->filed << ",";

        if(t->lchild)
            enqueue(q,t->lchild);
        if(t->rchild)
            enqueue(q,t->rchild);
    }
}

void PostOrderTraverse(BiTree T)
{
    if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        if(T->filed == a[0])
            cout << T->filed;
        else
            cout << T->filed << ",";
    }
}
int NodeCount(BiTree T){
    if(T==nullptr)
        return 0;
    return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int Hight(BiTree T){
    if(T == nullptr)
        return 0;
    int i = Hight(T->lchild);
    int j = Hight(T->rchild);
    return i > j ? i+1 : j+1; 
}

BiTree getPreInBiTree(string pre, string in,int size){
    if(size <= 0) return NULL;
    int i;
    for(i = 0;i<mid.length();i++){
        if(in[i] == pre[0])
            break;
    }
    BiTree t = new BiNode;
    t->filed = pre[0];
    t->lchild = getPreInBiTree(pre.substr(1),in,i);
    t->rchild = getPreInBiTree(pre.substr(i+1),in.substr(i+1),size-1-i);
    return t;
}



int main(){
    cout << "Input1" << endl;
    BiTree T = new BiNode;

    cin >> a;
    CreateBiTree(T,a);
    cout << "Output" << endl;   
    PreOrderTraverse(T);
    cout << endl;
    InOrderTraverse(T);
    cout << endl;
    PostOrderTraverse(T);
    cout << endl;
    cout << NodeCount(T);
    cout << endl;
    cout << Hight(T);
    cout << endl;

    cout << "Input2" << endl;
    BiTree T2 = new BiNode;
    cin >> pre;
    cin >> mid;
    T2 = getPreInBiTree(pre,mid,pre.length());

    cout << "Output2" << endl;
    PostOrderTraverse(T2);
    cout << endl;
    levelOrederTraverse(T2);
    cout << endl;
    cout << "End";
    system("pause");
    return 0;
}