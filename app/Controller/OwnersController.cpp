#include "../module/Owners/Owners.h"

void Owner::create(){
    ifstream input("module/Owners/Owners.csv");
    ofstream output("module/Owners/tempOwner.csv");
    string linea;
    cout << "AGREGAR NUEVO DUENIO" << endl;
    cout << "Ingrese el nombre: "; cin>>Owner::name;
    cout << "Ingrese la edad: "; cin >> Owner::age;
    cout << "Ingrese el nombre de la mascota: "; cin>>Owner::petname;
    cout << "Ingrese el correo: "; cin>>Owner::email;
    cout << "Ingrese la direccion: "; cin>>Owner::adress;
    cout << "Ingrese el telefono: "; cin>>Owner::phone;

    while(getline(input,linea)){
        output << linea << endl;
    }
    output << Owner::name << "," << Owner::age << "," << Owner::petname << "," << Owner::email << "," << Owner::adress << "," << Owner::phone << endl; 
    input.close();
    output.close();
    remove("module/Owners/Owners.csv");
    rename("module/Owners/tempOwner.csv","module/Owners/Owners.csv");
}

void Owner::read(){
    ifstream input("module/Owners/Owners.csv");
    string linea;
    string owner_name;
    cin.ignore();
    cout << "Ingrese el nombre del duenio: "; getline(cin,owner_name);
    while(getline(input,linea)){
        stringstream ss(linea);
        string token;
        while(getline(ss,token,',')){
            if(token == owner_name){
                getline(ss,token,',');
                cout << "Edad: " << token << endl;
                getline(ss,token,',');
                cout << "Nombre de la mascota: " << token << endl;
                getline(ss,token,',');
                cout << "Correo: " << token << endl;
                getline(ss,token,',');
                cout << "Direccion: " << token << endl;
                getline(ss,token,',');
                cout << "Telefono: " << token << endl;
            }
        }
    }
}

void Owner::update(){
    ifstream input("module/Owners/Owners.csv");
    ofstream output("module/Owners/tempOwner.csv");
    string linea;
    string owner_name;
    cin.ignore();
    cout << "Ingrese el nombre del duenio a modificar: "; getline(cin,owner_name);
    while(getline(input,linea)){
        stringstream ss(linea);
        string token;
        getline(ss, token, ',');
        if(token == owner_name){
            string nombre;
            string apellido;
            cout << "Ingrese el nombre: "; cin >> nombre;
            cout << "Ingrese el apellido: "; cin >> apellido;
            cout << "Ingrese la edad: "; cin >> Owner::age;
            cout << "Ingrese el nombre de la mascota: "; cin>>Owner::petname;
            cout << "Ingrese el correo: "; cin>>Owner::email;
            cout << "Ingrese la direccion: "; cin>>Owner::adress;
            cout << "Ingrese el telefono: "; cin>>Owner::phone;
            output << nombre << " " << apellido << "," << Owner::age << "," << Owner::petname << "," << Owner::email << "," << Owner::adress << "," << Owner::phone << endl;
        }else{
            output << linea << endl;
        }
    }
    input.close();
    output.close();
    remove("module/Owners/Owners.csv");
    rename("module/Owners/tempOwner.csv","module/Owners/Owners.csv");
}

void Owner::deleteOwner(){
    ifstream input("module/Owners/Owners.csv");
    ofstream output("module/Owners/tempOwner.csv");
    string linea;
    string owner_name;
    cin.ignore();
    cout << "Ingrese el nombre del duenio a eliminar: "; getline(cin,owner_name);
    while(getline(input,linea)){
        stringstream ss(linea);
        string token;
        getline(ss, token, ',');
        if(token != owner_name){
            output << linea << endl;
        }
    }
    input.close();
    output.close();
    remove("module/Owners/Owners.csv");
    rename("module/Owners/tempOwner.csv","module/Owners/Owners.csv");
}