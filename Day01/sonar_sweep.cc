#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string input;
    int prev = -1, curr = -1;
    list<int> prev_window, curr_window;
    ifstream InFile("input.txt");

    int increases = 0;
    int window_increases = 0;
    while (getline(InFile, input)){
        curr = stoi(input);
        curr_window.push_front(curr);
        if (prev != -1 && curr > prev){
            increases++;
        }

        if (curr_window.size() > 3){
            curr_window.pop_back();
        }
        if (prev_window.size() > 3){
            prev_window.pop_back();
        }
        if (prev_window.size() == 3){
            int curr_total = 0;
            for (auto val : curr_window){
                curr_total += val;
            }
            int prev_total = 0;
            for (auto val : prev_window){
                prev_total += val;
            }
            if (curr_total > prev_total){
                window_increases++;
            }
        }

        prev = curr;
        prev_window.push_front(curr);
    }
    cout << increases << '\n';
    cout << window_increases << '\n';
}