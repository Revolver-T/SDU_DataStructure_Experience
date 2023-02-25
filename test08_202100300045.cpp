#include <iostream>
#include <algorithm>


using namespace std;

int flag[10];//深度遍历标记
int vist[10];//广度遍历标记
int mark[10];//最短路径标记

typedef struct Queue{
    int data[10];
    int head;
    int tail;
}Queue;

void initialQueue(Queue *q){
    q->head = 0;
    q->tail = 0;
}

int isEmpty(Queue *q){
    if(q->head == q->tail)
        return 1;
    return 0;
}

void enQueue(Queue *q,int t){
    if( (q->tail+1) % 10 == q->head)
        return;
    else{
        q->data[q->tail] = t;
        q->tail = (q->tail+1) % 10;
    }
}

void deQueue(Queue *q,int *temp){
    if(q->tail == q->head)
        return;
    else{
        *temp = q->data[q->head];
        q->head = (q->head+1) % 10;
    }
}


typedef struct Matrix{
    int vertexn,edgen; //顶点数和边数
    int *node = new int[20];
    // int node[20];
    int weight[10][10];
}Matrix,*Matrixp;

typedef struct Edge{
    int v1,v2,weight;
}*Edgep;

void initialMatrix(Matrixp m, int numOfVertex,int numOfEdge){
    m->edgen = numOfEdge;
    m->vertexn = numOfVertex;

    int i,j;
    for(int i = 1;i<=numOfVertex;i++){
        for(int j = 1;j<=numOfVertex;j++){
            m->weight[i][j] = 999;
        }
    }
}

void insertWeight(Matrixp m,Edgep e){
    m->weight[e->v1][e->v2] = e->weight;
    m->weight[e->v2][e->v1] = e->weight;
}

int nodein;

void insertData(Matrixp m,int v1,int v2, int weight){
        Edgep E = new Edge;
        E->v1 = v1;
        E->v2 = v2;
        E->weight = weight;
        insertWeight(m,E);
        m->node[nodein] = v1;
        m->node[++nodein] = v2;
        nodein++;
}
int bfsct;
void BFS(Matrixp m,int numOfVertex){
    for(int i = 0;i<numOfVertex;i++)
        vist[m->node[i]] = 0;

    Queue Q;
    initialQueue(&Q);

    for(int i = 0;i<numOfVertex;i++){
        if(!vist[m->node[i]])
        {
            vist[m->node[i]] = 1;
            if(bfsct == numOfVertex-1)
            cout << m->node[i] << endl;
            else{
            cout << m->node[i] << ",";
            bfsct++;
            }
            enQueue(&Q,i);

            while(!isEmpty(&Q)){
                deQueue(&Q,&i);
                for(int j = 0;j<numOfVertex;j++){
                    if(!vist[m->node[j]] && m->weight[m->node[i]][m->node[j]] != 999){
                        vist[m->node[j]] = 1;
                        if(bfsct == numOfVertex-1)
                        cout << m->node[j] << endl;
                        else{
                        cout << m->node[j] << ",";
                        bfsct++;
                        }
                        enQueue(&Q,j);
                    }
                }
            }
        }
    }

}

int dfsct;
void DFS(Matrixp m,int node,int numOfVertex){
    flag[node] = 1;
    if(dfsct == numOfVertex -1)
    cout << node << endl;
    else{
    cout << node << ",";
    dfsct++;
    }

    for(int i = 0;i<numOfVertex;i++){
        if(!flag[m->node[i]] && m->weight[node][m->node[i]] !=999 ){
            DFS(m,m->node[i],numOfVertex);
        }
    }
    
}

void initialDFS(Matrixp m, int numOfVertex){
    for(int i = 0;i<numOfVertex;i++)
        flag[m->node[i]] = 0;
    
    for(int i = 0;i<numOfVertex;i++){
        if(!flag[m->node[i]])
            DFS(m,m->node[i],numOfVertex);
    }
}

int * quchong(int arr[],int &nodelen){
    int* t = new int[20];
    int in = 0;
    for(int i = 0;i<nodein;i++){
        int uniq = 1;
        for(int j = 0;j<nodein;j++){
            if(t[j] == arr[i]){
                uniq = 0;
                break;
            }
        }
        if(uniq)
            t[in++] = arr[i];
    }
    nodelen = in;
    return t;
}

void findShortestPath(Matrixp m,int numOfVertex,int v1,int vn){

    if(m->weight[v1][vn+1] == 999){
        cout << "0" << endl;
        return;
    }


    int dis[10];
    int min,u;

    for(int i = 1;i<=numOfVertex;i++){
        mark[i] = 0;
        dis[i] = m->weight[v1][i];
    }

    mark[v1] = 1;
    for(int k = 1;k<=numOfVertex;k++){
        min = 9999;

        for(int j = 1;j<=numOfVertex;j++){
            if(mark[j]==0 && min>dis[j]){
                min = dis[j];
                u = j;
            }
        }

        mark[u] = 1;
        for(int i = 1;i<=numOfVertex;i++){
            if(!mark[i] && dis[i] > dis[u] + m->weight[u][i]){
                dis[i] = dis[u] + m->weight[u][i];
            }
        }
    }

    cout << dis[vn] << endl;
}

int main(){
    cout << "Input" << endl;
    int n,m;
    scanf("%d,%d",&n,&m);
    Matrixp obj = new Matrix;
    initialMatrix(obj,n,m);

    for(int i = 0;i<m;i++){
        int v1,v2,weight;
        scanf("%d,%d,%d",&v1,&v2,&weight);
        insertData(obj,v1,v2,weight);
    }
    obj->node = quchong(obj->node,obj->vertexn);
    sort(obj->node,obj->node+obj->vertexn);    

    cout << "Output" << endl;
    BFS(obj,obj->vertexn);
    initialDFS(obj,obj->vertexn);

    // for(int i = 0;i<obj->vertexn;i++)
    //     cout << obj->node[i] << " ";
    
    findShortestPath(obj,n,obj->node[0],obj->node[obj->vertexn-1]);

    cout << "End" << endl;
    system("pause");
    return 0;
}
