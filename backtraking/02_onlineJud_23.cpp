#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void rev(int a[], int i, int j) {
    int temp;
    while(i < j) { swap(a[i], a[j]); i++; j--; }
}
void LR(int a[], int i, int j) {
    rev(a, i, j); rev(a, i+1, j);
}
void RR(int a[], int i, int j) {
    rev(a, i, j); rev(a, i, j-1);
}
bool isFind = false;
bool find(vector<int> &temp, int count, int current) {
    if(isFind) return isFind;
    if(count == (temp.size())) {
        if(current == 23) {
            return true;
        }
        return false;
    }
    isFind = find(temp, count + 1, current + temp[count]);
    isFind = find(temp, count + 1, current * temp[count]);
    isFind = find(temp, count + 1, current - temp[count]);
    return isFind;
}
void permutation(int a[], int size, int index , int temp[]) {
    if(isFind) return;
    if(index == (size)) {
        vector<int> temp(a, a+size);
        find(temp,1,temp[0]);
        return;
    }

    for(int i = index; i < size; i++) {
        LR(a, index, i);
        temp[index] = a[index];
        permutation(a, size, index+1, temp);
        RR(a, index, i);
    }
}
int main() {
    int c_z = 0, num[5];
    while(c_z != 5) {
        for(int i = 0; i <5; i++) {
            cin>>num[i];
            if(num[i] == 0) c_z++;
        }
        if(c_z == 5) continue;
        permutation(num, 5, 0, num);
        if(isFind) {
            cout<<"Possible"<<endl;
        } else {
            cout<<"Impossible"<<endl;
        }
        isFind = false;
    }
}