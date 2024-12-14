#include "../Controller/PetsController.cpp"
#include "../Controller/OwnersController.cpp"
int main (){
    int opcion;
    bool continuar = true;
    cout << "Que desea hacer?" << endl;
    cout << "1. Manejar las Mascotas" << endl;
    cout << "2. Manejar loss Duenios" << endl;\
    cout << "3. Salir" << endl;
    cin >> opcion;
    if(opcion == 1){
        Pets p;
        while(continuar){
            cout << "Que desea hacer?" << endl;
            cout << "1. Agregar Mascota" << endl;
            cout << "2. Leer Mascota" << endl;
            cout << "3. Modificar Mascota" << endl;
            cout << "4. Eliminar Mascota" << endl;
            cout << "5. Salir" << endl;
            cin >> opcion;
            if(opcion == 1){
                p.create();
            }else if(opcion == 2){
                p.read();
            }else if(opcion == 3){
                p.update();
            }else if(opcion == 4){
                p.deletePet();
            }
            else if(opcion == 5){
                continuar = false;
            }
        }
    }
    else if(opcion == 2){
        Owner o;
        while(continuar){
            cout << "Que desea hacer?" << endl;
            cout << "1. Agregar Duenio" << endl;
            cout << "2. Leer Duenio" << endl;
            cout << "3. Modificar Duenio" << endl;
            cout << "4. Eliminar Duenio" << endl;
            cout << "5. Salir" << endl;
            cin >> opcion;
            if(opcion == 1){
                o.create();
            }else if(opcion == 2){
                o.read();
            }else if(opcion == 3){
                o.update();
            }else if(opcion == 4){
                o.deleteOwner();
            }
            else if(opcion == 5){
                continuar = false;
            }
        }
    }
    cout << "Cerrando programa.." << endl;
  }