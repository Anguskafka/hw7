//
//  main.cpp
//  hw7
//
//  Created by Angus Tse on 10/24/16.
//  Copyright © 2016 Angus Tse. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"
using namespace std;
int main() {
    ofstream fout;
    fout.open("gamelog.txt");
    int count;
    
    srand(static_cast<int>(time(0)));
    int bet;
    string response;
    Player player1 = Player(100);
    while (player1.get_money() > 0 && player1.get_money()<1000)
    {
        cout << "You have: " << player1.get_money() << " ";
        cout << "bet:";
        cin >> bet;
        fout << setw(5) << " Game number:" << count << setw(10) << "money left: " << player1.get_money();
        fout << "Bet: "<< bet;
        

    }

    return 0;
}
