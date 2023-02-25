#include <iostream>
#include <algorithm>


using namespace std;

int arr[20], len;
int ctp,cti;

typedef struct TreeNode
{
    int data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}Node;

typedef struct tree{
    Node* root;
}Tree;

struct  heap {
    int a[20],size,capacity;
};

void createTree(Tree *tree,int val){
    Node* node = new Node;
    node->data = val;
    node->lchild = nullptr;
    node->rchild = nullptr;

    if(tree->root == nullptr)
        tree->root = node;

    else{
        Node* temp = tree->root;
        while(temp != nullptr){
            if(val < temp->data){
                if(temp->lchild == nullptr){
                    temp->lchild = node;
                    return;
                }
                else {
                    temp = temp->lchild;
                }
            }
            else {
                if(temp->rchild == nullptr){
                    temp->rchild = node;
                    return;
                }
                else {
                    temp = temp->rchild;
                }
            }
        }
    }
}

heap* createHeap() {
    heap* temp = new heap;
    temp->capacity = 20;
    temp->size = 0;
    temp->a[0] = INT_MAX;
    return temp;
}

heap* fillH(int arr[], int len){
    heap* h = new heap;
    h = createHeap();
    for(int i = 0;i<len;i++){
        h->a[++h->size] = arr[i];
    }
    return h;
}

void sortH(heap* h){
    for(int root = h->size / 2; root >=1;root--){
        int rootElement = h->a[root];

        int child = 2*root;
        while(child <= h->size){
            if(child < h->size && h->a[child] < h->a[child+1])
                child++;

            if(rootElement >= h->a[child])
                break;
            
            h->a[child / 2] = h->a[child];
            child *= 2;
        }
        h->a[child / 2] = rootElement;
    }
}

void pop(heap* h){
    int laste = h->a[h->size--];

    int currentNode = 1,child = 2;
    while(child <= h->size){
        if(child < h->size && h->a[child] < h->a[child+1])
            child++;
        if(laste >= h->a[child])
            break;
        
        h->a[currentNode] = h->a[child];
        currentNode = child;
        child*=2;
    }
    h->a[currentNode] = laste;
}

void PreOrderTraverse(Node *node){
    if(node!=nullptr){
        if(ctp == len-2)
            cout << node->data << endl;
        else{
            cout << node->data << ",";
            ctp++;
        }
        PreOrderTraverse(node->lchild);
        PreOrderTraverse(node->rchild);
    }
}

void InOrderTraverse(Node *node){
    if(node!=nullptr){
        InOrderTraverse(node->lchild);
        if(cti == len-2)
            cout << node->data << endl;
        else{
            cout << node->data << ",";
            cti++;
        }
        InOrderTraverse(node->rchild);
    }
}

int * quchong(int arr[]){
    int* t = new int[len-2];
    int in = 0;
    for(int i = 0;i<len-1;i++){
        int uniq = 1;
        for(int j = 0;j<len-2;j++){
            if(t[j] == arr[i]){
                uniq = 0;
                len--;
                break;
            }
        }
        if(uniq)
            t[in++] = arr[i];
    }

    return t;
}


int main(){
    cout << "Input" << endl;
    for(int i = 0;i < 20;i++){
        int t;
        cin >> t;
        if(t == 0){ 
        len = ++i;
        break;
        }
        arr[i] = t;
    }
    heap *h1 = new heap;
    h1 = fillH(arr,len);
    sortH(h1);
    //层序输出
    cout << "Output" << endl;
    for(int i = 1;i<len;i++){
        if(i == len-1){
            cout << h1->a[i] << endl;
            break; 
        }
        cout << h1->a[i] << ",";
    }
    // 堆排序
    int a[20];
    for(int i = 1;i<len;i++){
        a[i-1] = h1->a[1];
        pop(h1);
    }
    for(int i = len-2;i>=0;i--){
        if(i == 0){
            cout << a[i] << endl;
            break;
        }
        cout << a[i] << ",";
    }
    //创建二叉搜索树
    Tree tree;
    tree.root = nullptr;
    int* newarr = new int[len];
    newarr = quchong(arr);
    for(int i = 0;i<len-1;i++)
        createTree(&tree,newarr[i]);
    // for(int i = 0;i<len-1;i++)
    //     createTree(&tree, arr[i]);
    //遍历
    PreOrderTraverse(tree.root);
    InOrderTraverse(tree.root);


    cout << "End" << endl;
    system("pause");
    return 0;
}