#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string input;
    int hori = 0, depth = 0, hori2 = 0, depth2 = 0, aim = 0;
    ifstream InFile("input.txt");

    while (getline(InFile, input)){
        int number = input.back() - '0';
        switch (input.front()){
            case 'f':
                hori += number;
                hori2 += number;
                depth2 += aim * number;
                break;
            case 'd':
                depth += number;
                aim += number;
                break;
            case 'u':
                depth -= number;
                aim -= number;
                break;
        }
    }

    cout << hori << ' ' << depth << ' ' << hori*depth << '\n';
    cout << hori2 << ' ' << depth2 << ' ' << hori2*depth2 << '\n';
}