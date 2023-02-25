#include<iostream>

using namespace std;
int temp[18];
void bubbleSort(int list[], int len){
	for(int i = 0;i<len-1;i++){
		for(int j = 0;j<len-1-i;j++){
		  	if(list[j] > list[j+1])
			  swap(list[j],list[j+1]);	
		}
	}
}

void insertSort(int list[],int len){
	for(int i = 1;i<len;i++){
		int k = list[i];
		int j = i-1;
		while((j>=0) && (k < list[j])){
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = k;
	}
}

void merge(int list[], int l,int r,int mid){
    int i,j,k;

    i=l;j=mid;k=l;
    while(i<mid && j<=r){
        if(list[i] < list[j])
            temp[k++] = list[i++];
        else
            temp[k++] = list[j++];
    }

    while(i<mid)
        temp[k++] = list[i++];

    while(j<=r)
        temp[k++] = list[j++];

    k=l;i=l;
    while(k<=r){
        list[i++] = temp[k++];
    }
}

void mergeSort(int list[],int l,int r){
    if(l<r){
    int mid = (l+r) / 2;

    mergeSort(list,l,mid);
    mergeSort(list,mid+1,r);
    merge(list,l,r,mid+1);
}
}


int main(){
	cout << "Input" << endl;
	
	int a[18] = { 0 },n = 0;
	for(int i = 0;i<18;i++){
		cin >> a[i];
		if(a[i] == 0)
		  break;
		n++;
	}
	
	int flag;
	cout << "1-Bubble Sort,2-Insert Sort,3-Merge Sort" << endl;
	cin >> flag;
	cout << "Output" << endl;
	switch(flag){
		case 1 :
			bubbleSort(a,n);
            cout << "Bubble Sort" << endl;
			break;
        case 2 :
            insertSort(a,n);
            cout << "Insert Sort" << endl; 
            break;
        case 3:
            mergeSort(a,0,n-1);
            cout << "Merge Sort" << endl;
            break;   
	} 
    
    for(int i = 0;i<n;i++)
    {
        if(i==n-1)
        {
            cout << a[i] << endl;
            break;
        }
        cout << a[i] << ',';
            }

    cout << "End0" << endl;
    return 0;
}