#include<iostream>
#include<stdio.h>
#include<vector>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

int bubble();
int selection();
int insertion();

int main() {

    clock_t start, end;
    string data;
    ifstream file("randomArr.txt");
    if(file.is_open()) {
        while(getline(file, data)){
            cout << data << endl;
        }
    }

    start = clock();
    // for (int i = 0; i < n; i++) 

    return 0;    
}
