#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<vector<int>,int> get_nearbyactive(map<vector<int>,bool> mymap,int i,int linenumber){
    map<vector<int>,int> to_ret;

    for(map<vector<int>,bool>::iterator it=mymap.begin();it!=mymap.end();it++){
        vector<int> coord = it->first;
        int x = coord[0];
        int y = coord[1];
        int z = coord[2];
        int w = coord[3];

        if(it->second){
            for(int xsearch = x-1;xsearch<x+2;xsearch++){
                if(xsearch < -i-1 || xsearch > linenumber+1){
                    continue;
                }
                for(int ysearch = y-1;ysearch < y+2;ysearch++){
                    if(ysearch < -i-1 || ysearch > linenumber+1){
                        continue;
                    }
                    for(int zsearch = z-1;zsearch < z+2;zsearch++){
                        if(zsearch < -i-1 || zsearch > i+1){
                            continue;
                        }
                        for(int wsearch = w-1;wsearch < w+2;wsearch++){
                            if(wsearch < -i-1 || wsearch > i+1){
                                continue;
                            }
                            if(xsearch == x && ysearch == y && zsearch == z && wsearch == w){
                                continue;
                            }
                            vector<int> searching{xsearch,ysearch,zsearch,wsearch};
                            if(to_ret.find(searching) == to_ret.end()){
                                to_ret[searching] = 1;
                            }
                            else{
                                to_ret[searching] = to_ret[searching]+1;
                            }
                        }
                    }
                }
            }
        }
    }

    return to_ret;

}

int main(){

    fstream myfile("input.txt");
    //fstream myfile("input2.txt");
    string myline;

    map<vector<int>,bool> cube;

    int linenumber = 0;
    while(getline(myfile,myline)){
        for(int i=0;i<myline.size();i++){
            vector<int> coordinate{linenumber,i,0,0};
            if(myline[i] == '.'){
                cube[coordinate] = false;
            }
            else{
                cube[coordinate] = true;
            }
        }
        linenumber++;
    }

    map<vector<int>,int> count_nearby = get_nearbyactive(cube,0,linenumber-1);

    int totalactive;
    for(int i=0;i<6;i++){
        map<vector<int>,bool> nextcycle;

        totalactive = 0;

        cout << "i = " << i << endl;

        for(int w=-i-1;w<=i+1;w++){
            for(int z=-i-1;z<=i+1;z++){
                for(int y = -i-1;y<linenumber+1;y++){
                    for(int x=-i-1;x<linenumber+1;x++){
                        vector<int> mycoord{x,y,z,w};

                        if(cube.find(mycoord) == cube.end()){
                            cube[mycoord] = false;
                        }
                        if(count_nearby.find(mycoord) == count_nearby.end()){
                            count_nearby[mycoord] = 0;
                        }

                        if(cube[mycoord]){
                            if(count_nearby[mycoord] == 3 || count_nearby[mycoord] == 2){
                                nextcycle[mycoord] = true;
                                totalactive++;
                            }
                            else{
                                nextcycle[mycoord] = false;
                            }
                        }
                        else{
                            if(count_nearby[mycoord] == 3){
                                nextcycle[mycoord] = true;
                                totalactive++;
                            }
                            else{
                                nextcycle[mycoord] = false;
                            }
                        }
                    }
                }
            }
        }  
        linenumber++;
        cube = nextcycle;
        if(i!=5){
            count_nearby = get_nearbyactive(cube,i+1,linenumber-1);
        }
    }
    cout << totalactive << endl;
}