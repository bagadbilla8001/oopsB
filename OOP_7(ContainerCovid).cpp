#include<bits/stdc++.h>
using namespace std;

void menu(){
    cout<<"______welcome______"<<endl;
    cout<<"Enter 1 to add details "<<endl;
    cout<<"Enter 2 to find details "<<endl;
    cout<<"Enter 3 to see details "<<endl;
    cout<<"Enter 0 to exit "<<endl;
}

void add_details(map<string,int> &maps){
    cout<<"Enter state : ";
    cin.ignore();
    string state;
    getline(cin,state);

    int population;
    cout<<"Enter population : ";
    cin>>population;

    auto it = maps.find(state);
    if(it!=maps.end()){
        it->second+=population;
    }else{
        maps[state]=population;
    }

    cout<<"Details added successfully"<<endl;
}

void findPopulation(map<string,int> maps){
    cout<<"Enter state"<<endl;
    string state;
    cin.ignore();
    getline(cin,state);

    auto it = maps.find(state);
    if(it!=maps.end()){
        cout << state <<" population is "<< it->second << endl;
    }else{
        cout << "Not found "<<endl;
    }
}

void display(map<string,int> maps){
    for(auto i : maps){
        cout<<"Population : "<<i.second <<" of State : "<<i.first<<endl;
    }
}

int main(){
    map<string,int> maps;

    bool flag = true;
    while(flag){
        menu();
        cout<<"Enter choice : ";
        int choice;
        cin>>choice;
        if(choice == 1){
            add_details(maps);
        }else if (choice == 2){
            findPopulation(maps);
        }else if (choice == 3){
            display(maps);
        }else if (choice == 0){
            flag = false;
        }else{
            cout<<"Enter right choice "<<endl;
        }
    }

    cout<<"Bie bie"<<endl;


}