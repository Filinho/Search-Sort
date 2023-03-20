#include <iostream>

using namespace std;
string  rand_name(){

  string names[30];
  names[0] = "Flavio";
  names[1] = "Jose";
  names[2] = "Tadeu";
  names[3] = "Alberto";
  names[4] = "Breno";
  names[5] = "Pedro";
  names[6] = "Maicon";
  names[7] = "Ivanderlei";
  names[8] = "Alexandre";
  names[9] = "Tatiane";
  names[10] = "Marcos";
  names[11] = "Laercio";
  names[12] = "Vinicus";
  names[13] = "PDF";
  names[14] = "Gabriel";
  names[15] = "Rafael";
  names[16] = "Caribe";
  names[17] = "Alberto M.";
  names[18] = "Lucio";
  names[19] = "Luciana";
  names[20] = "Aline";
  names[21] = "Josias";
  names[22] = "Ana Luiza";
  names[23] = "Florzinha";
  names[24] = "LEAL";
  names[25] = "Genivaldo";
  names[26] = "Jubileu";
  names[27] = "Knight of Ni";
  names[28] = "Gandalfo";
  names[29] = "Bilbo";

  return names[rand()%30];
}