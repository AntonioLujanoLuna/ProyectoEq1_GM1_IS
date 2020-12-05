//main.cc
//proyecto IS
#include <parques.h>
#include <senderos.h>
using namespace std;

void main(){
  int login;

  cout<<"--- Bienvenido al Sistema de Gestión de Parques Naturales de la Junta de Andalucia. ---\n";
  cout<<"--- Por favor, inicie sesión, seleccionado la opción 0 o 1. ---\n";
  cout<<"--- 0) Entrar al Sistema como Administrador. ---\n";
  cout<<"--- 1) Entrar al Sistema como Monitor. ---\n";
  cin<<login;

  switch(login){

  case 0:
    int opc;
    char password;
      cout<<" Por favor, introduzca su contraseña.\n";
      cin>>password;
      while(password!=admingestionJA){
        cout<<" Contraseña incorrecta. Por favor, introduzca su contraseña.\n";
        cin>>password;
      }
      cout<<" Contraseña correcta. Bienvenido al sistema. \n";
      cout<<" Por favor, seleccione a que gestión desea acceder. \n";
      cout<<"--- 0) Gestión de Parques Naturales. ---\n";
      cout<<"--- 1) Gestión de Senderos. ---\n";
      cout<<"--- 2) Gestión de Visitantes. ---\n";
      cout<<"--- 3) Gestión de Monitores. ---\n";
      cin<<opc;
      while(opc<0||opc>3){
        cout<<" Opción invalida. Por favor, seleccione una opcion válida. \n";
        cin<<opc;
      }
      case 0:
        menuParques();
        break;

      case 1:
        menuSenderos();
        break;

      case 2:
        menuVisitantes();
        break;

      case 3:
        menuMonitores();
        break;
    break;

  case 1:

  int seleccion;
  char dni;
    cout<<" Por favor, introduzca su DNI.\n";
    cin>>password;
    while(password!=admingestionJA){
      cout<<" DNI incorrecta. Por favor, introduzca su contraseña.\n";
      cin>>dni;
    }
    cout<<" Contraseña correcta. Bienvenido al sistema. \n";
    cout<<" Por favor, seleccione a que gestión desea acceder. \n";
    cout<<"--- 0) Gestión de Parques Naturales. ---\n";
  }
}
