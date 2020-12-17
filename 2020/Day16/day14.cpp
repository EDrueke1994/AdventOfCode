#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    map<string,vector<int>> high_ranges;
    map<string,vector<int>> low_ranges;
    vector<string> categories;

    string myticket;

    fstream myfile("input.txt");
    string myline;

    bool mytick = false;
    bool othertick = false;

    int invalid = 0;

    int iter = 0;

    vector<vector<int>> alltickets;

    while(getline(myfile,myline)){

        iter++;

        if(myline.size() < 2){
            continue;
        }

        if(othertick){

            string hold;
            vector<int> thisticket;

            for(int i=0;i<myline.size();i++){

                if(myline[i] == ','){
                    thisticket.push_back(stoi(hold));
                    hold = "";
                }
                else{
                    hold.push_back(myline[i]);
                }

            }

            thisticket.push_back(stoi(hold));

            bool foundallvalid = true;
            for(int i=0;i<thisticket.size();i++){
                int myval = thisticket[i];
                bool foundvalid = false;

                for(int j=0;j<categories.size();j++){
                    vector<int> range1 = low_ranges[categories[j]];
                    vector<int> range2 = high_ranges[categories[j]];

                    if(!foundvalid && ((range1[0] <= myval && myval <= range1[1]) || (range2[0] <= myval && myval <= range2[1]))){
                        foundvalid = true;
                    }
                }

                if(!foundvalid){
                    invalid += myval;
                    foundallvalid = false;
                }
            }
            if(foundallvalid){
                alltickets.push_back(thisticket);
            }
        }
        else if(myline == "nearby tickets:"){
            othertick = true;
        }
        else if(mytick){
            myticket = myline;
        }
        else if(myline == "your ticket:"){
            mytick = true;
        }
        else{

            string thiscat;
            vector<int> nums;
            string hold;

            bool colon = false;

            for(int i=0;i<myline.size();i++){

                if(colon){
                    if(myline[i] == ' ' || myline[i] == 'r'){
                        continue;
                    }
                    else if(myline[i] == '-' || myline[i] == 'o'){
                        nums.push_back(stoi(hold));
                        hold = "";
                    }
                    else{
                        hold.push_back(myline[i]);
                    }
                }
                else if(myline[i] == ':'){
                    colon = true;
                }
                else{
                    thiscat.push_back(myline[i]);
                }
            }

            nums.push_back(stoi(hold));
            vector<int> low{nums[0],nums[1]};
            vector<int> high{nums[2],nums[3]};
            low_ranges[thiscat] = low;
            high_ranges[thiscat] = high;
            categories.push_back(thiscat);

        }
    }

    cout << invalid << endl;

    vector<int> myticket_processed;
    string hold;
    for(int i=0;i<myticket.size();i++){
        if(myticket[i] == ','){
            myticket_processed.push_back(stoi(hold));
            hold = "";
        }
        else{
            hold.push_back(myticket[i]);
        }
    }
    myticket_processed.push_back(stoi(hold));
    alltickets.push_back(myticket_processed);

    map<int,vector<string>> solving;

    for(int i=0;i<categories.size();i++){
        solving[i] = categories;
    }

    for(int i=0;i<alltickets.size();i++){

        vector<int> current_ticket = alltickets[i];

        for(int j=0;j<current_ticket.size();j++){

            int myval = current_ticket[j];

            vector<string> tempcat = solving[j];
            vector<string> next;
            for(int k=0;k<tempcat.size();k++){
                string mycat = tempcat[k];
                vector<int> range1 = low_ranges[mycat];
                vector<int> range2 = high_ranges[mycat];

                if((range1[0] <= myval && myval <= range1[1]) || (range2[0] <= myval && myval <= range2[1])){
                    next.push_back(mycat);
                }
            }
            solving[j] = next;
            
        }
    }

    map<int,string> solved;
    int finished = 0;
    vector<string> found;
    while(finished < categories.size()){
        for(int i=0;i<categories.size();i++){
            vector<string> temp = solving[i];
            if(temp.size() == finished+1){
                for(int j=0;j<temp.size();j++){
                    if(find(found.begin(),found.end(),temp[j]) == found.end()){
                        found.push_back(temp[j]);
                        solved[i] = temp[j];
                        finished++;
                    }
                }
            }
        }
    }

    unsigned long long int to_ret = 1;
    for(int i=0;i<categories.size();i++){
        cout << "i = " << i << "; cat = " << solved[i] << endl;
        if(solved[i].substr(0,9) == "departure"){
            cout << "yes" << endl;
            to_ret = to_ret*myticket_processed[i];
        }
    }

    cout << to_ret << endl;

}