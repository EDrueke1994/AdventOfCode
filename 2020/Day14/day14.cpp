#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

string convert_to_binary(unsigned long long int mynum){

    vector<int> myvec;

    int iter=0;
    while(mynum!=0){
        myvec.push_back(mynum%2);
        mynum = mynum/2;
        iter++;
    }

    while(myvec.size() < 36){
        myvec.push_back(0);
    }
    
    reverse(myvec.begin(),myvec.end());

    string to_ret;
    for(int i=0;i<myvec.size();i++){
        to_ret = to_ret + to_string(myvec[i]);
    }

    return to_ret;
}

string apply_mask(string mem,string mask){

    string to_ret;
    for(int i=0;i<mask.size();i++){
        if(mask[i]=='X'){
            to_ret.push_back(mem[i]);
        }
        else{
            to_ret.push_back(mask[i]);
        }
    }

    return to_ret;
}

vector<string> apply_mask2(string mem,string mask){

    vector<string> to_ret;
    
    for(int i=0;i<mask.size();i++){

        //cout << "size: " << to_ret.size() << endl;

        if(mask[i]=='0'){
            if(i==0){
                string mystr;
                mystr.push_back(mem[i]);
                to_ret.push_back(mystr);
            }
            else{
                for(int j=0;j<to_ret.size();j++){
                    to_ret[j].push_back(mem[i]);
                }
            }
        }
        else if(mask[i] == '1'){
            if(i==0){
               to_ret.push_back("1");
            }
            else{
                for(int j=0;j<to_ret.size();j++){
                    to_ret[j].push_back('1');
                }
            }
        }
        else{
            if(i==0){
                to_ret.push_back("0");
                to_ret.push_back("1");
            }
            else{
                vector<string> temp;
                temp = to_ret;
                for(int j=0;j<to_ret.size();j++){
                    temp[j].push_back('1');
                    to_ret[j].push_back('0');
                }
                //cout << "size2: " << to_ret.size() << endl;
                for(int j=0;j<temp.size();j++){
                    to_ret.push_back(temp[j]);
                    //cout << "temp: " << temp[j] << endl;
                }
            }
        }

        //cout << "toret: " << to_ret[0] << endl;
     }

    return to_ret;
}

unsigned long long int part1(){

    fstream myfile("input.txt");
    //fstream myfile("example_input.txt");

    string myline;

    map<unsigned long long int,string> mem;
    string cur_mask;

    while(getline(myfile,myline)){

        if(myline[1] == 'a'){
            cur_mask = myline.substr(7,36);
        }
        else{
            string cur_mem;
            int cur_pos = myline.find('[')+1;
            while(myline[cur_pos]!=']'){
                cur_mem.push_back(myline[cur_pos]);
                cur_pos++;
            }

            cur_pos = myline.find(' ')+3;
            string to_save;
            while(cur_pos<myline.length()){
                to_save.push_back(myline[cur_pos]);
                cur_pos++;
            }

            string bin = convert_to_binary(stoull(to_save));

            mem[stoull(cur_mem)] = apply_mask(bin,cur_mask);

        }
    }

    unsigned long long int mysum = 0;
    for(map<unsigned long long int,string>::iterator it = mem.begin();it!=mem.end();it++){
        unsigned long long int mynum = stoull(it->second,nullptr,2);
        mysum += mynum;
    }

    return mysum;

}

unsigned long long int part2(){

    fstream myfile("input.txt");
    //fstream myfile("example_input2.txt");

    string myline;

    map<unsigned long long int,unsigned long long int> mem;
    string cur_mask;

    while(getline(myfile,myline)){

        if(myline[1] == 'a'){
            cur_mask = myline.substr(7,36);
        }
        else{
            string cur_mem;
            int cur_pos = myline.find('[')+1;
            while(myline[cur_pos]!=']'){
                cur_mem.push_back(myline[cur_pos]);
                cur_pos++;
            }

            cur_pos = myline.find(' ')+3;
            string to_save;
            while(cur_pos<myline.length()){
                to_save.push_back(myline[cur_pos]);
                cur_pos++;
            }

            unsigned long long int to_save_int = stoull(to_save);

            //Convert the memory location
            string cur_mem_bin = convert_to_binary(stoull(cur_mem));

            vector<string> all_mem = apply_mask2(cur_mem_bin,cur_mask);
            for(int i=0;i<all_mem.size();i++){
                mem[stoull(all_mem[i],nullptr,2)] = to_save_int;
            }
        }
    }

    unsigned long long int mysum = 0;
    for(map<unsigned long long int, unsigned long long int>::iterator it = mem.begin();it!=mem.end();it++){
        mysum += it->second;
    }

    return mysum;

}

int main(){
 
    cout << part1() << endl;
    cout << part2() << endl;

}