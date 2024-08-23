#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<chrono>
#include<algorithm>
using namespace std;

int isok(vector<int> arr);
void quick(vector<int> &arr);

int main() {
    string data;
    ifstream file("LrandomArr.txt");
    if(file.is_open()) {
        getline(file, data);
    }
    istringstream stream(data);
    vector<int> arr = {};
    int n, i = 0;
    
    while (stream >> n && i < 1000000) {
        arr.push_back(n);
        i++;
    }
    int temp[1000000];
    for (int i = 0; i < 1000000; i++) {
        temp[i] = arr[i];
    }

    // heap
    vector<int> t = {};
    for (int i = 0; i < 1000000; i++) {
        t.push_back(arr[i]);
    }
    auto start = chrono::high_resolution_clock::now();
    make_heap(t.begin(), t.end());
    sort_heap(t.begin(), t.end());
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> res = end - start;
    cout << "heap : " << res.count() << endl;

    // quick
    

    return 0;
}

int isok(vector<int> arr) {
    for (int i = 0; i < 10000; i++) {
        if (arr[i] != i + 1) {
            return 0;
        }
    }
    return 1;
}

void quick(vector<int> &arr, int l, int r) {
    int p = arr[0];
    while (l+1 <= r) {
        while(l+1 <= r && arr[l+1] <= p){
            l++;
        }
        while(r >= l+1 && arr[r] > p) {
            r--
        }
        if (l < r) {
            swap(arr[l+1],arr[r]);
        } 
    }
    swap(arr[l+1], arr[r]);
    quick(arr, l+1, r-1);
    quick(arr, r+1, )
}