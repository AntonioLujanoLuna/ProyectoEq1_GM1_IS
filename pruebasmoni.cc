// Pruebas Unittest Clase Monitor
//Proyecto IS


#include <string>
#include <fstream>
#include <list>
#include "monitor.h"
#include "gtest/gtest.h"


using namespace std;

TEST(monitor, gurdarDatos) {
  string dni = "03524931X";
  string nombre = "Valentin Avram";
  string telefono = "675000444";
  string fechaNacimiento = "01/11/1990";
  string condicion = "Ninguna condicion especial a tener en cuenta";
  bool disponibilidad = true;

  Monitor m(dni, email, telefono, fechaNacimiento, condicion, disponibilidad);

  EXPECT_EQ(dni, m.getDNI());
  EXPECT_EQ(nombre, m.getCodigo());
  EXPECT_EQ(telefono, m.getNombre());
  EXPECT_EQ(fechaNacimiento, m.getApellidos());
  EXPECT_EQ(condicion, m.getDireccion());
  EXPECT_EQ(disponibilidad, m.getLocalidad());
  EXPECT_FALSE(3, m.getDisponibilidad());
 }


  int main(int argc, char ∗∗argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }


}
