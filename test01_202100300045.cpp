#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void Perm(int obj[] , int p, int q){
    if(p == q){
        for(int i = 0;i<=q;i++){
        if(i==q){	
          cout << obj[i] << endl;
          break;
      }
        cout << obj[i] << ",";
        }
    }
    else{
        for(int i = p;i<=q;i++){
            swap(obj[i],obj[p]);
            Perm(obj,p+1,q);
            swap(obj[i],obj[p]);
        }
    }
}

int main(){
    int list[21] = { 0 },count = 0;
    cout << "Input" << endl;
    
    for(int i = 0;i<20;i++){
        cin >> list[i];
        
        if(list[i] == 0)
          break;
		count++;
    }
    

    cout << "Output" << endl;

    Perm(list,0,count-1);

    cout << "End0" << endl;
    system("pause");
    return 0;
}