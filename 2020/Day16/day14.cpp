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

    /*int solved = 0;
    int iter2 = 0;
    int iter3 = 0;
    while(solved < categories.size()){
        iter3 = iter2%categories.size();
        if(iter3==0){
            solved = 0;

            for(int i=0;i<categories.size();i++){

                cout << "i = " << i << "; " << solving[i].size() << endl;
                vector<string> temp = solving[i];
                for(int j=0;j<temp.size();j++){
                    cout << temp[j] << endl;
                }
            }
           
        }
        vector<string> temp = solving[iter3];

        if(temp.size() == 1){
            solved++;
            vector<string> myhold;
            for(int i=0;i<categories.size();i++){
                if(i==iter3){
                    continue;
                }
                vector<string> omg = solving[i];
                for(int j=0;j<omg.size();j++){
                    if(omg[j]!= temp[0]){
                        myhold.push_back(omg[j]);
                    }
                }
                solving[i] = myhold;
            }
        }
    }*/

    for(int i=0;i<categories.size();i++){

        cout << "i = " << i << "; " << solving[i].size() << endl;
        vector<string> temp = solving[i];
        for(int j=0;j<temp.size();j++){
            cout << temp[j] << endl;
        }
    }

    solving[0] = {"arrival track"};
    solving[1] = {"duration"};
    solving[2] = {"type"};
    solving[3] = {"arrival location"};
    solving[4] = {"price"};
    solving[5] = {"wagon"};
    solving[6] = {"arrival station"};
    solving[7] = {"train"};
    solving[8] = {"departure time"};
    solving[9] = {"route"};
    solving[10] = {"departure station"};
    solving[11] = {"arrival platform"};
    solving[12] = {"departure platform"};
    solving[13] = {"departure track"};
    solving[14] = {"departure date"};
    solving[15] = {"seat"};
    solving[16] = {"departure location"};
    solving[17] = {"zone"};
    solving[18] = {"class"};
    solving[19] = {"row"};
}