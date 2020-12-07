//menus.cc
//proyecto IS

#include "menus.h"

int menuAdmin(){
    int opc;
      cout<<"--- Contraseña correcta. Bienvenido al sistema. ---\n";
      cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
      cout<<"--- 0) Gestion de Parques Naturales. ---\n";
      cout<<"--- 1) Gestion de Senderos. ---\n";
      cout<<"--- 2) Gestion de Visitantes. ---\n";
      cout<<"--- 3) Gestion de Monitores. ---\n";
      cout<<"--- 4) Salir del menu. ---\n";
      cin<<opc;

      while(opc<0||opc>4){
        cout<<" Opcion invalida. Por favor, seleccione una opcion valida. \n";
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

      case 4:
        menuPrincipal();
        break;
}

int menuMonitor(){
  int seleccion;
  cout<<"--- DNI correcto. Bienvenido al sistema. ---\n";
  cout<<"--- Por favor, seleccione a que gestion desea acceder. ---\n";
  cout<<"--- 0) Gestion de Rutas. ---\n";
  cout<<"--- 1) Salir del menu ---\n";
  cin<<seleccion;

    switch(seleccion){
      while(seleccion<0||seleccion>1){
        cout<<"Opcion invalida. Por favor seleccione una opcion valida \n";
        cin<<seleccion;
      }

    case 0:
      menuRutas();
      break;

    case 1:
      menuPrincipal;
      break;
  }
}

bool comprobarAdmin(){
  string password;
  for (int i = 0; i<3; i++){
    cout<<" Por favor, introduzca su contraseña.\n";
    cin>>password;
    if (password == admingestionJA){
        cout<<"Contraseña correcta\n";
        return true;
    }
    else {
        cout<<" Contraseña incorrecta.";
        printf("Quedan %d intentos", 3-i);
    }
  }
  cout<<"Maximo numero de intentos permitido alcanzado\n"
  return false;
}

bool comprobarMonitor(bool es_Monitor){
  es_Monitor=false;
  string dni;
    cout<<" Por favor, introduzca su DNI.\n";
    cin>>DNI;
    //Funcion comprobacion DNI
    //
    //
return es_Monitor;
}

int menuParques(){
  int i;
  cout<<"   --- Gestion de Parques --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir un nuevo Parque Natural. --- \n";
  cout<<"--- 1) Modificar los datos de un Parque Natural ya introducido. --- \n";
  cout<<"--- 2) Cambiar la disponibilidad de un Parque Natural. --- \n";
  cout<<"--- 3) Eliminar un Parque Natural. --- \n";
  cout<<"--- 4) Mostrar los datos de un Parque Natural ya introducido. --- \n";
  cout<<"--- 5) Salir del programa. --- \n";
  cin<<i;

  while(i<0||i>5){
    cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
    cin<<i;
  }

  case 0:
  //
  //
  //
  break;

  case 1:
  //
  //
  //
  break;

  case 2:
  //
  //
  //
  break;

  case 3:
  //
  //
  //
  break;

  case 4:
  //
  //
  //
  break;

  case 5:
    return 0;
  break;
}

int menuSenderos(){
  int i;

  cout<<"   --- Gestion de Senderos --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir un nuevo Sendero. --- \n";
  cout<<"--- 1) Modificar los datos de un Sendero ya introducido. --- \n";
  cout<<"--- 2) Cambiar la disponibilidad de un Sendero. --- \n";
  cout<<"--- 3) Eliminar un Sendero. --- \n";
  cout<<"--- 4) Mostrar los datos de un Sendero ya introducido. --- \n";
  cout<<"--- 5) Salir del programa. --- \n";

  cin<<i;

  while(i<0||i>5){
  cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
  cin<<i;
  }


case 0:
//
//
//
break;

case 1:
//
//
//
break;

case 2:
//
//
//
break;

case 3:
//
//
//
break;

case 4:
//
//
//
break;

case 5:
  return 0;
break;

}

int menuVisitantes(){
  int i;

  cout<<"   --- Gestion de Visitantes --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir un nuevo visitante. --- \n";
  cout<<"--- 1) Modificar los datos de un visitante ya introducido. --- \n";
  cout<<"--- 2) Cancelar la visita asociada a un visitante concreto. --- \n";
  cout<<"--- 3) Eliminar un visitante. --- \n";
  cout<<"--- 4) Mostrar los datos de un visitante ya introducido. --- \n";
  cout<<"--- 5) Salir del programa. --- \n";

  cin<<i;

  while(i<0||i>5){
  cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
  cin<<i;
  }


case 0:
//
//
//
break;

case 1:
//
//
//
break;

case 2:
//
//
//
break;

case 3:
//
//
//
break;

case 4:
//
//
//
break;

case 5:
  return 0;
break;

}

int menuMonitores(){
  int i;

  cout<<"   --- Gestion de Monitores --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir un nuevo monitor. --- \n";
  cout<<"--- 1) Modificar los datos de un monitor ya introducido. --- \n";
  cout<<"--- 2) Cambiar la disponibilidad de un monitor. --- \n";
  cout<<"--- 3) Eliminar los datos de un monitor. --- \n";
  cout<<"--- 4) Mostrar los datos de un monitor ya introducido. --- \n";
  cout<<"--- 5) Salir del programa. --- \n";

  cin<<i;

  while(i<0||i>5){
  cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
  cin<<i;
  }


  case 0:
  //
  //
  //
  break;

  case 1:
  //
  //
  //
  break;

  case 2:
  //
  //
  //
  break;

  case 3:
  //
  //
  //
  break;

  case 4:
  //
  //
  //
  break;

  case 5:
  return 0;
  break;

}

int menuRutas(){
  int i;

  cout<<"   --- Gestion de Rutas --- \n";
  cout<<"--- Seleccione la opcion a la que desee acceder. --- \n";
  cout<<"--- 0) Añadir una nueva ruta. --- \n";
  cout<<"--- 1) Modificar los datos de una ruta ya introducida. --- \n";
  cout<<"--- 2) Cambiar la disponibilidad de una ruta. --- \n";
  cout<<"--- 3) Eliminar una ruta. --- \n";
  cout<<"--- 4) Mostrar los datos de un ruta ya programada. --- \n";
  cout<<"--- 5) Salir del programa. --- \n";

  cin<<i;

  while(i<0||i>5){
  cout<<" Opcion invalida. Por favor, seleccione una opcion valida.\n";
  cin<<i;
  }


  case 0:
  //
  //
  //
  break;

  case 1:
  //
  //
  //
  break;

  case 2:
  //
  //
  //
  break;

  case 3:
  //
  //
  //
  break;

  case 4:
  //
  //
  //
  break;

  case 5:
  return 0;
  break;

}
