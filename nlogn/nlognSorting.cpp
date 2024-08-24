#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<chrono>
#include<algorithm>
using namespace std;

int isok(vector<int> arr);
void quick(vector<int> &arr, int low, int high);

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
    start = chrono::high_resolution_clock::now();
    quick(arr, 0, 999999);
    end = chrono::high_resolution_clock::now();
    res = end - start;
    cout << "quick : " << res.count() << endl;

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

void quick(vector<int> &arr, int low, int high) {
    
    if (low > high) {
        return;
    }

    int pivot = arr[low];
    int l = low + 1;
    int r = high;

    while (l <= r) {

        while (l <= r && arr[l] <= pivot) {
            l++;
        }

        while (r >= l && arr[r] > pivot) {
            r--;
        }

        if (l < r) {
            swap(arr[l], arr[r]);
        }
    }

    swap(arr[low], arr[r]);

    quick(arr, low, r - 1);
    quick(arr, r + 1, high);
    
}