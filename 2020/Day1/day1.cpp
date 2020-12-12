#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    fstream myfile("input.txt");
    string str;
    vector<int> myvec;

    while(getline(myfile,str)){

        myvec.push_back(stoi(str));

    }

    //cout << myvec.size() << endl;

    for(int iter = 0; iter < myvec.size(); iter++){

        int diff = 2020 - myvec[iter];

        vector<int>::iterator it = find(myvec.begin(),myvec.end(),diff);

        if(it != myvec.end()){
            cout << myvec[iter]*diff << endl;
        }

        for(int iter2 = iter; iter2 < myvec.size(); iter2++){

            int diff2 = diff - myvec[iter2];

            vector<int>::iterator it2 = find(myvec.begin()+iter,myvec.end(),diff2);

            if(it2 != myvec.end()){
                cout << diff2*myvec[iter2]*myvec[iter] << endl;
            }
        }
    }
}