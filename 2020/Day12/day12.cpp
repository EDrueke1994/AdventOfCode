#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int part1(){
    int x_pos = 0;
    int y_pos = 0;
    char facing = 'E';

    vector<char> orders{'N','E','S','W'};

    fstream myfile("input.txt");

    string myline;

    while(getline(myfile,myline)){

        char command = myline[0];
        int dist = stoi(myline.substr(1));

        vector<char>::iterator it;
        if(command == 'L' || command == 'R' || command == 'F'){
            it = find(orders.begin(),orders.end(),facing);
        }
        else{
            it = find(orders.begin(),orders.end(),command);
        } 
        int count = it - orders.begin();

        if(command == 'F'){
            command = facing;
        }

        if(command == 'R'){
            //cout << facing << "," << myline << endl;
            dist = dist/90;
            //cout << dist << "," << count << endl;
            count = (count + dist) % 4;
            facing = orders.at(count);
            //cout << count << "," << facing << endl;
        }
        else if(command == 'L'){
            //cout << facing << "," << myline << endl;
            dist = dist/90;
            //cout << dist << "," << count << endl;
            count = (count - dist + 4) % 4;
            facing = orders.at(count);
            //cout << count << "," << facing << endl;
        }
        else if(command == 'N'){
            y_pos = y_pos + dist;
        }
        else if(command == 'S'){
            y_pos = y_pos - dist;
        }
        else if(command == 'E'){
            x_pos = x_pos + dist;
        }
        else if(command == 'W'){
            x_pos = x_pos - dist;
        }
        else{
            cout << "Error" << endl;
        }

        //cout << command << "," << dist << "," << x_pos << "," << y_pos << endl;

    }

    //cout << abs(x_pos) + abs(y_pos) << endl;

    return abs(x_pos) + abs(y_pos);

}

int part2(){
    int x_pos = 0;
    int y_pos = 0;
    int wp_x = 10;
    int wp_y = 1;

    fstream myfile("input.txt");

    string myline;

    while(getline(myfile,myline)){

        char command = myline[0];
        int dist = stoi(myline.substr(1));

        if(command == 'F'){
            x_pos = x_pos + wp_x*dist;
            y_pos = y_pos + wp_y*dist;
        }
        else if(command == 'R'){
            dist = dist/90;
            for(int i = 0;i<dist;i++){
                int temp = wp_y;
                wp_y = -wp_x;
                wp_x = temp;
            }
        }
        else if(command == 'L'){
            dist = dist/90;
            for(int i=0;i<dist;i++){
                int temp = wp_y;
                wp_y = wp_x;
                wp_x = -temp;
            }
        }
        else if(command == 'N'){
            wp_y = wp_y + dist;
        }
        else if(command == 'S'){
            wp_y = wp_y - dist;
        }
        else if(command == 'E'){
            wp_x = wp_x + dist;
        }
        else if(command == 'W'){
            wp_x = wp_x - dist;
        }
        else{
            cout << "Error" << endl;
        }

        //cout << command << "," << dist << "," << x_pos << "," << y_pos << endl;

    }

    return abs(x_pos) + abs(y_pos);

}

int main(){
    cout << part1() << endl;
    cout << part2() << endl;
}