#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> parse_string(string str){

    string hold;
    vector<int> to_ret;

    for(int i=0;i<str.size();i++){
        if(str[i] == ','){
            if(hold == "x"){
                hold = "";
            }
            else{
                to_ret.push_back(stoi(hold));
                hold = "";
            }
        }
        else{
            hold.push_back(str[i]);
        }
    }

    if(hold != "x"){
        to_ret.push_back(stoi(hold));
    }

    return to_ret;
}

vector<int> parse_string2(string str){

    string hold;
    vector<int> to_ret;

    for(int i=0;i<str.size();i++){
        if(str[i] == ','){
            if(hold == "x"){
                to_ret.push_back(0);
                hold = "";
            }
            else{
                to_ret.push_back(stoi(hold));
                hold = "";
            }
        }
        else{
            hold.push_back(str[i]);
        }
    }

    if(hold != "x"){
        to_ret.push_back(stoi(hold));
    }
    else{
        to_ret.push_back(0);
    }

    return to_ret;
}

int gcd(int a, int b){
    if(b>a){
        int temp = a;
        a = b;
        b = temp;
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){

    fstream myfile("input.txt");
    string myline;
    string myline1, myline2;
    unsigned long long int iter = 0;

    while(getline(myfile,myline)){

        if(iter == 0){
            myline1 = myline;
        }
        else{
            myline2 = myline;
        }

        iter ++;

    }

    //Part 1
    int timestamp = stoi(myline1);
    vector<int> buses = parse_string(myline2);

    int minmod = timestamp*2;
    int minbus = 0;

    for(int i=0;i<buses.size();i++){

        int times = buses[i];
        while(times < timestamp){
            times += buses[i];
        }

        if(times - timestamp < minmod){
            minmod = times - timestamp;
            minbus = buses[i];
        }
 
    }
    //cout << minbus << "," << minmod << "," << minbus*minmod << endl;
    cout << minbus * minmod << endl;

    //Part 2
    //myline2 = "7,13,x,x,59,x,31,19";
    //buses = parse_string(myline2);
    vector<int> alltimes = parse_string2(myline2);

    //Almost brute force
    //Sort alltimes
    //vector<int> sorted_times = buses;
    //sort(sorted_times.begin(),sorted_times.end());

    vector<int> Ns;
    int j=0;
    for(int i=0;i<buses.size();i++){
        j=0;
        while(alltimes[j]!=buses[i]){
            j++;
        }
        Ns.push_back(j);
    }

    for(int i=0;i<buses.size();i++){
        cout << "time = "<<buses[i] << "; N = " << Ns[i] << endl;        
    }

    unsigned long long int time = Ns[0] * buses[0];
    unsigned long long int to_add = max(Ns[0]*buses[0],buses[0]);
    iter = 0;
    int nfound = 1;
    while(nfound != buses.size()){

        time = time + to_add;

        while(nfound != buses.size() && (time + Ns[nfound]) % buses[nfound] == 0){
            to_add *= buses[nfound];
            nfound++;
        }
        
        cout << "iter = " << iter << "; nfound = " << nfound << endl;

        iter++;
    }

    for(int i=0;i<buses.size();i++){
        if((time + Ns[i])%buses[i] != 0){
            cout << "Error: " << buses[i] << endl;
        }
    }

    //Brute force
    /*unsigned long long int time = alltimes[0];
    bool found_time = false;
    iter = 0;

    while(!found_time){

        if(iter%1000000==0){
            cout << "iter = " << iter << endl;
        }

        found_time = true;

        time = time + alltimes[0];

        for(int i=0;i<alltimes.size();i++){
            if(alltimes[i] == 0){
                continue;
            }
            if((time + i)%alltimes[i] != 0){
                found_time = false;
            }
        }

        iter ++;
    }*/

    cout << time << endl;

}