#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType myarr[], int size) {
    for(int i=0;i<size;i++){
        cout<<myarr[i]<<" ";
    }
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    for(int i=start;i<=end;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    if(n<=0){
        return false;
    }
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){return true;}
        else if(arr[mid]<target){start=mid+1;}
        else{end=mid-1;}
    }
    return false;
}	


// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    // base case
    if(n<=0){
        return false;
    }
    //general case
    else{
        int mid=n/2;
            if(charray[mid]==target){return true;}
            else if(charray[mid]<target){return binSearchR(target, charray+mid+1, n-mid-1);}
            else{return binSearchR(target, charray, mid);}
        }
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int a, int b) {
    double temp=darray[a];
    darray[a]=darray[b];
    darray[b]=temp;
}

int minFind(double darray[], int size) {
    int minIndex=0;
    for(int i=0;i<size;i++){
        if(darray[i]<darray[minIndex]){
            minIndex=i;
        }
    }
    return minIndex;
}

void newSort(double darray[], int size) {
    if(size<=1){
        return;
    }
    int smallest=minFind(darray,size);
    swap(darray,smallest,0);
    newSort(darray+1,size-1);
}
