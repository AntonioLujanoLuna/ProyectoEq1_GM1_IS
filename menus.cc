//menus.cc
//proyecto IS

#include "menus.h"
#include "parques.h"
#include "senderos.h"
#include "rutas.h"
#include "monitores.h"
#include "visitantes.h"
#include "persona.h"
#include "fileIO.h"


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

bool comprobarMonitor(){
  string dni;
  for (int i = 0; i<3; i++){
    cout<<" Por favor, introduzca su DNI.\n";
    cin>>dni;
    if (){
        cout<<"DNI correcto\n";
        return true;
    }
    else {
        cout<<" DNI incorrecto.";
        printf("Quedan %d intentos", 3-i);
    }
  }
cout<<"Maximo numero de intentos permitido alcanzado\n"
return false;
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
  switch(i){
    string aux="";
    int tamano=0;
    parque p;
  case 0:
  //
  //FUNCION DE MOSTRAR LISTAS DE PARQUES
  cout<<"   --- Menu de Introduccion de Datos --- \n";

  cout<<"--- Por favor, introduzca el nombre del nuevo parque natural --- \n";
  cin>>aux;
  p.setNombre(aux);
  //Funcion que compruebe que el nombre del parque ya exista
  //Funcion que pida nuevo nombre en caso de que exista
  cout<<"--- Por favor, introduzca la fecha del nombramiento del parque natural --- \n";
  cin>>aux;
  p.setFechaNombramientoParque(aux);

  cout<<"--- Por favor, introduzca el tamaño del parque natural en kilometros cuadrados --- \n";
  cin>>tamano;
  p.setTamano(tamano);

  cout<<"--- Por favor, introduzca el nombre de los premios otorgados al parque natural, separado por comas --- \n";
  cin>>aux;
  p.setPremios(aux);

  cout<<"--- Por favor, introduzca una breve descripcion del nuevo parque natural --- \n";
  cin>>aux;
  p.setDescripcion(aux);

  guardarParque(p);

  p.imprimirParque();


  //
  break;

  case 1:
  //
  //FUNCION DE MOSTRAR LISTAS DE PARQUES
  cout<<"   --- Menu de Introduccion de Datos --- \n";

    //Funcion que compruebe que el nombre del parque ya exista
    //Funcion que pida nuevo nombre en caso de que exista
    //FUNCION MOSTRAR NOMBRES DE PARQUES.
  cout<<"--- Por favor, introduzca el nombre del parque natural --- \n";
  cin>>aux;
  p.setNombre(aux);

  cout<<"--- Por favor, introduzca la fecha del nombramiento del parque natural --- \n";
  cin>>aux;
  p.setFechaNombramientoParque(aux);

  cout<<"--- Por favor, introduzca el tamaño del parque natural en kilometros cuadrados --- \n";
  cin>>tamano;
  p.setTamano(tamano);

  cout<<"--- Por favor, introduzca el nombre de los premios otorgados al parque natural, separado por comas --- \n";
  cin>>aux;
  p.setPremios(aux);

  cout<<"--- Por favor, introduzca una breve descripcion del parque natural --- \n";
  cin>>aux;
  p.setDescripcion(aux);
  guardarParque(p);
  //Funcion que devuelva los senderos Asociados
  p.imprimirParque();
  //
  break;

  case 2:
  //
  cout<<"--- Por favor, introduzca la nueva disponibilidad del parque natural\n";
  setDisponibilidad(bool disponibilidad);
  getDisponibilidad();
  break;

  case 3:
  //
  //Funcion mostrar lista de PARQUES
  //Funcion de seleccion y eliminacion de parques
  cout<<"--- Esta seguro de que desea borrar el parque ---\n";
  cout<<"--- Escriba 1 si desea confirmarlo, 0 si no ---\n";
  int decis;
  cin<<decis;
  if(decis==0){
    //funcion de borrado de parque
    borrarParque(const parque &p);
  if(decis==1){
    //funcion que muestre la lista de parques
  }
  //
  break;

  case 4:
  //
  //Funcion mostrar lista de PARQUES
  //Funcion buscar parque concreto
  cout<<"--- A continuacion se mostrarán los datos del parque existente --- \n";
  getNombre();
  //Funcion que devuelva los senderos Asociados
  getSenderosParque(std::string nombre);
  getFechaNombramientoParque();
  getTamamo();
  getPremios();
  getDescripcion();
  //
  break;

  case 5:
    return 0;
  break;
}
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
cout<<"--- Por favor, seleccione el parque al que quiere añadir el sendero.. --- \n";
//MOSTRAR LISTA DE PARQUES
cout<<"   --- Menu de Introduccion de Datos --- \n";
// FUNCION QUE GUARDE EL PARQUE SELECCIONADO EN UNA VARIABLE (PARA NO TENER QUE VOLVER A PEDIRLA)
cout<<"--- Por favor, introduzca el nombre del nuevo sendero. --- \n";
setNombre(string nombre);
setParqueAsociado(string nombre); //AQUI IRIA LA VARIABLE GUARDADA POSTERIORMENTE
cout<<"--- Por favor, introduzca el nombre del nuevo sendero. --- \n";


//Funcion que compruebe que el nombre del sendero ya exista en ese parque.
//Funcion que pida nuevo nombre en caso de que exista (pueden ser ambos pasos en la misma funcion, una funcion recursiva)

//MOSTRAR LISTA DE SENDEROS ASOCIADOS AL PARQUE ELEGIDO
cout<<"SENDERO AÑADIDO CON EXITO. "<<endl;
break;

case 1:
cout<<"--- Por favor, seleccione el parque al que quiere añadir el sendero.. --- \n";
//MOSTRAR LISTA DE PARQUES


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
