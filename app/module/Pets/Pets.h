#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector> 
using namespace std;

class Pets{
    private:
        string name;
        string type;
        string owner;
        string breed;
        float weight;
        int age;

    public:
    void create();
    void read();
    void update();
    void deletePet();
};




