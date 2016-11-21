#include <time.h>

/**
* É criado um novo tipo de váriavel
* chamada Carro, através da palavra
* reservada typedef.
*/
typedef struct Carro {

  //Atributos do Carro
  char posicao[3], placa[9], modelo[14], cor[15], data[6], hora[6];
  time_t entrada;
} Carro;
