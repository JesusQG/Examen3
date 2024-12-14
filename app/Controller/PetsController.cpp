#include"../module/Pets/Pets.h"


void Pets::create(){
    ifstream input("module/Pets/Pets.csv", ios::app);
    ofstream output("module/Pets/tempPets.csv", ios::app);
    string linea;
    Pets pet_actual;
    cout << "AGREGAR NUEVA MASCOTA" << endl;
    cout << "Ingrese el nombre: "; cin>>Pets::name;
    cout << "Ingrese la edad: "; cin >> Pets::age;
    cout << "Ingrese el tipo de animal: "; cin>>Pets::type;
    cout << "Ingrese la raza: "; cin>>Pets::breed;
    cout << "Ingrese el peso: "; cin>>Pets::weight;

    while(getline(input,linea)){
        output << linea << endl;
    }
    output << Pets::type +',' << Pets::name + ',' << Pets::age <<',' << Pets::breed + ',' << Pets::weight;
    input.close();
    output.close();
    remove("module/Pets/Pets.csv");
    rename("module/Pets/tempPets.csv","module/Pets/Pets.csv");
}

void Pets::read(){
    ifstream input("module/Pets/Pets.csv");
    string linea;
    string pet_name;
    cout << "Ingrese el nombre de la mascota: "; cin >> pet_name;
    while(getline(input,linea)){
        stringstream ss(linea);
        string token;
        while(getline(ss,token,',')){
            if(token == pet_name){
                getline(ss,token,',');
                cout << "Tipo: " << token << endl;
                getline(ss,token,',');
                cout << "Edad: " << token << endl;
                getline(ss,token,',');
                cout << "Raza: " << token << endl;
                getline(ss,token,',');
                cout << "Peso: " << token << endl;

            }
        }
    }
}

void Pets::update(){
    ifstream input("module/Pets/Pets.csv");
    ofstream output("module/Pets/tempPets.csv");
    string linea;
    string pet_name;
    cout << "Ingrese el nombre de la mascota a modificar: "; cin >> pet_name;
    while(getline(input,linea)){
        stringstream ss(linea);
        string token;
        getline(ss, token, ',');
        if(token == pet_name){
            cout << "Ingrese el nuevo nombre: "; cin >> Pets::name;
            cout << "Ingrese la nueva edad: "; cin >> Pets::age;
            cout << "Ingrese el nuevo tipo de animal: "; cin >> Pets::type;
            cout << "Ingrese la nueva raza: "; cin >> Pets::breed;
            cout << "Ingrese el nuevo peso: "; cin >> Pets::weight;
            output << Pets:: type << "," << Pets::name << "," << Pets::age << "," << Pets::breed << "," << Pets::weight << endl;
        }
        else{
            output << linea << endl;
        }
    }
    input.close();
    output.close();
    remove("module/Pets/Pets.csv");
    rename("module/Pets/tempPets.csv","module/Pets/Pets.csv");
}

void Pets::deletePet(){
    ifstream input("module/Pets/Pets.csv");
    ofstream output("module/Pets/tempPets.csv");
    string linea;
    string pet_name;
    cout << "Ingrese el nombre de la mascota a eliminar: "; cin >> pet_name;
    while(getline(input,linea)){
        stringstream ss(linea);
        string token;
        getline(ss, token, ',');
        if(token != pet_name){
            output << linea << endl;
        }
    }
    input.close();
    output.close();
    remove("module/Pets/Pets.csv");
    rename("module/Pets/tempPets.csv","module/Pets/Pets.csv");
}

