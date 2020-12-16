#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    //vector<int> spoken{0,3,6};
    vector<int> spoken{15,5,1,4,7,0};
    map<int,int> thegame;
    map<int,int> twices;

    for(int i=0;i<spoken.size();i++){
        thegame[spoken[i]] = i;;
    }

    int iter = spoken.size();

    //int previous_spoken = spoken[spoken.size() - 2];
    int last_spoken = spoken[spoken.size() - 1];

    while(iter != 30000000){//2020){

        if(iter%10000 == 0){
            cout << "iter = " << iter << endl;
        }

        map<int,int>::iterator found_twice = twices.find(last_spoken);

        if(found_twice == twices.end()){
            //cout << "A" << endl;
            last_spoken = 0;
            twices[0] = thegame[0];
            thegame[0] = iter;
        }
        else{
            int to_speak = iter - twices[last_spoken] - 1;
            if(thegame.find(to_speak) == thegame.end()){
                thegame[to_speak] = iter;
            }
            else{
                twices[to_speak] = thegame[to_speak];
                thegame[to_speak] = iter;
            }
            last_spoken = to_speak;
        }

        /*cout << "twices: " << endl;
        for(map<int,int>::iterator it = twices.begin();it!=twices.end();it++){
            cout << it->first << ":" << it->second << endl;
        }*/

        //cout << iter << ":" << last_spoken << endl;

        iter++;
    }

    cout << last_spoken << endl;
}