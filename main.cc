//main.cc
//proyecto IS
#include "parques.h"
#include "senderos.h"
#include "visitantes.h"
#include "monitores.h"
#include "rutas.h"

#include <iostream>

using namespace std;

int main(){
  menuPrincipal();
}

int menuPrincipal(){
  int login;

  cout<<"     --- Bienvenido al Sistema de Gestión de Parques Naturales de la Junta de Andalucia. ---\n";
  cout<<"--- Por favor, inicie sesion, seleccionado la opcion 0 o 1. ---\n";
  cout<<"--- 0) Entrar al Sistema como Administrador. ---\n";
  cout<<"--- 1) Entrar al Sistema como Monitor. ---\n";
  cout<<"--- 2) Salir del programa ---\n";
  cin<<login;

  switch(login){
    while(login<0||login>2){
      cout<<"Opcion invalida. Por favor, seleccione una opcion valida. \n";
      cin<<login;
    }

  case 0:
    if(!comprobarAdmin()){
      cout<<"No tiene autorizacion para entrar al sistema como administrador. \n";
    }
    else{
      menuAdmin();
    }
    break;

  case 1:
    if(!comprobarMonitor()){
      cout<<"No tiene autorizacion para entrar al sistema como monitor. \n";
      cout<<"Si es usted administrador del sistema, introduzca sus credenciales. \n";
      if(!comprobarAdmin()){
        cout<<"No tiene autorizacion para entrar al sistema como administrador. \n";
        return 0;
      }
      else{
        menuMonitor();
      }
    }
    break;

  case 2:
    return 0;
  break;
  }
}
