#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
class Owner{
    private:
        string name;
        string petname;
        string adress;
        string email;
        string phone;
        int age;

    public:
    void create();
    void read();
    void update();
    void deleteOwner();
};