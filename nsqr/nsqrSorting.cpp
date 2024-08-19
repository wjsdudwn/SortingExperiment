#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<chrono>
using namespace std;

int isok(int arr[]);

int main() {

    // set array ========
    string data;
    ifstream file("randomArr.txt");
    if(file.is_open()) {
        getline(file, data);
    }
    istringstream stream(data);
    int arr[10000];
    int n, i = 0;
    
    while (stream >> n && i < 10000) {
        arr[i] = n;
        i++;
    }
    int temp[10000];
    for (int i = 0; i < 10000; i++) {
        temp[i] = arr[i];
    }
    // ====================
    
    // bubble =============
    auto start = chrono::high_resolution_clock::now();
    int tmp;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 9999 - i; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> res = end - start;
    cout << "bubble : " << res.count() << endl;
    // ====================
    for (int i = 0; i < 10000; i++) {
        arr[i] = temp[i];
    }
    // selection ==========
    start = chrono::high_resolution_clock::now();

    int m = arr[0];
    int c = 0;
    for (int i = 0; i < 10000; i++) {
        m = arr[i];
        c = i;
        for (int j = i; j < 10000; j++) {
            if (m > arr[j]) {
                m = arr[j];
                c = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[c];
        arr[c] = tmp;
    }

    end = chrono::high_resolution_clock::now();
    res = end - start;
    
    cout << "selection : " << res.count() << endl;
    // ====================
    for (int i = 0; i < 10000; i++) {
        arr[i] = temp[i];
    }
    // insertion ==========
    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < 10000; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j-1] > arr[j]) {
                tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            } else {
                break;
            }
        }
    }
    end = chrono::high_resolution_clock::now();
    res = end - start;
    cout << "selection : " << res.count() << endl;

    // ====================


    return 0;    
}

int isok(int arr[]) {
    for (int i = 0; i < 10000; i++) {
        if (arr[i] != i + 1) {
            return 0;
        }
    }
    return 1;
}