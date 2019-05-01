//Merge Sort

#include <iostream> 
#include <vector>
using namespace std;
const int Max = 1000;
void Merge(vector<int> &Array, int start, int mid, int end){
    vector<int> LeftSub(Array.begin()+start,Array.begin()+mid+1);
    vector<int> RightSub(Array.begin()+mid+1,Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(),Max);  //Set there is a infinity number at the end of the array to compare with the elements in the RightSub.
    RightSub.insert(RightSub.end(),Max); //Set there is a infinity number at the end of the array to compare with the elements in the LeftSub.

    int idxLeft = 0;
    int idxRight = 0; 

    for (int i = start; i <= end; i++){
        if (LeftSub[idxLeft] <= RightSub[idxRight]){
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{   //If LeftSub[idxLeft] > RightSub[idxRight]
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &array, int start, int end){
    if (start < end){
        int mid = (start+end)/2;
        MergeSort(array, start, mid); //Divide and Recursive to the Left
        MergeSort(array, mid+1, end); //Divide and Recursive to the Right
        Merge(array,start,mid,end); 
    }
}
void PrintArray(vector<int> &arr){
    for (int i = 0; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5,3,8,6,2,7,1,4};
    vector<int> array(arr,arr+sizeof(arr)/sizeof(int));
    PrintArray(array);
    MergeSort(array,0,7);
    PrintArray(array);

    return 0;   
}

