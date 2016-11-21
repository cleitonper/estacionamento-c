#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "constantes.h"

void formatarAtributos(Carro *carro, int posicao, const char *placa, const char *modelo, const char *cor);
void cadastrarCarro(Carro *carro, int posicao, const char *placa, const char *modelo, const char *cor);


/** ~ Vagas
* As funções desenharCabecalho,
* desenharPosicao e desenharRodape
* compõem o layout da visualização
* de vagas disponiveis
*/
void desenharCabecalho(){
  printf("╔══════════════╦═════╦════════════╦═════╦══════════╦═════╦════════════════════╗\n");
  printf("║ Capacidade   ║ 50  ║ Ocupados   ║ 30  ║ Restam   ║ 20  ║ Mat: 2016200618    ║\n");
  printf("╠══════════════╩═════╩════════════╩═════╩══════════╩═════╩════════════════════╣\n");
  printf("╠═══════╦══════════╦═══════════════╦════════════════╦════════════╦════════════╣\n");
  printf("║ Lugar ║ Placa    ║ Modelo        ║ Cor            ║ Data       ║ Entrada    ║\n");
  printf("╠═══════╬══════════╬═══════════════╬════════════════╬════════════╬════════════╣\n");

}



void desenharPosicao(Carro *carro){

  printf("║  %s   ║ %s ║ %s ║ %s ║ %s      ║ %s      ║\n", carro->posicao, carro->placa, carro->modelo, carro->cor, carro->data, carro->hora);
  printf("╠═══════╬══════════╬═══════════════╬════════════════╬════════════╬════════════╣\n");
}



void desenharRodape(){
  printf("╠═══════╩══════════╩═══════════════╩════════════════╩════════════╩════════════╣\n");
  printf("╠═══════╦══════════════════╦════════╦══════╦════════════╦═════════════════════╣\n");
  printf("║ Nome  ║ Cleiton Pereira  ║ Turma  ║ 823  ║ Semestre   ║ 2016/2 - Unicarioca ║\n");
  printf("╚═══════╩══════════════════╩════════╩══════╩════════════╩═════════════════════╝\n\n\n");
}
/** ~ FIM Vagas **/


//===============================================================================================================================================//


/* ~ limpar
* A função system ultiliza comandos
* do sistema operacional.
* cls é usado no Windows para limpar o console,
* já clear é usado sistemas Linux.
* Com o uso do operador lógico || (ou) é
* possivel criar uma função portável.
*/
void limpar(){
  system("cls || clear");
}
/** ~ FIM limpar */


//===============================================================================================================================================//


/** ~ mostrarMenuPrincipal
* Mostra o menu principal
*/
void mostrarMenuPrincipal(int *opcao){
  printf("<Pressione ENTER para ir ao Menu>\n\n");

  getchar();

  limpar();


  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                            Menu Principal                                   ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                        PRESSIONE 0 PARA SAIR                                ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                    PRESSIONE 8 PARA VER O MANUAL                            ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n\n");


  printf("1 - Ver vagas\n");
  printf("2 - Ver tabela de precos\n");
  printf("3 - Cadastrar veiculo\n");
  printf("4 - Retirar veiculo\n\n");
  printf("Informe uma das opções: ");
  scanf("%d", opcao);

  getchar();

  limpar();
}
/** ~ FIM mostrarMenuPrincipal **/


//===============================================================================================================================================//


/** ~ mostrarMenuCadastro
* Mostra o menu de cadastro
* de veiculos.
*/
void mostrarMenuCadastro(Carro *carro){

  /**
  * Atribus dos carros
  */
  int posicao = 1;
  char placa[9], modelo[14], cor[15];

  do {
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         Cadastrar Veiculo                                   ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║              PRESSIONE 0 EM POSICAO VOLTAR AO MENU                          ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n\n");


    printf("Informe a posicao que o carro ficará: ");
    scanf("%d", &posicao);

    getchar();

    if(posicao == 0) break;
    if(posicao > (CAPACIDADE_MAX)){
      printf("\33[31mVaga inexistente <ENTER>\033[0;0m ");
      getchar();
      limpar();
      break;
    }
    if(strncmp(carro[posicao - 1].placa, "-----", 5) != 0){
      printf("\33[31mPosicao ja ocupada <ENTER>\033[0;0m ");
      getchar();
      limpar();
      continue;
    }


    printf("Informe a placa: ");
    fgets(placa, 9, stdin);

    getchar();

    printf("Informe o modelo: ");
    fgets(modelo, 14, stdin);

    printf("Informe a cor: ");
    fgets(cor, 15, stdin);


    cadastrarCarro(&carro[posicao - 1], posicao, placa, modelo, cor);

    printf("\033[22;32mVeiculo cadastrado <ENTER>\33[0;0m ");

    getchar();
    limpar();
  } while(posicao != 0);

  limpar();
}
/** ~ FIM mostrarMenuCadastro **/


//===============================================================================================================================================//


/** ~ mostrarPrecos
* Exibe a tabela de preços
*/
void mostrarPrecos(){

    float diaria = PRIMEIRA_HORA + (FRACAO * (DIARIA - 1));


    printf("╔═════════════════════════════════════════════════════╗\n");
    printf("║                    Tabela de Precos                 ║\n");
    printf("╠═════════════════════════════════════════════════════╣\n");
    printf("╠═════════════╦═══════════════╦═══════════╦═══════════╣\n");
    printf("║ Desistencia ║ Primeira Hora ║  Fracao   ║  Diaria   ║\n");
    printf("╠═════════════╬═══════════════╬═══════════╬═══════════╣\n");
    printf("║   %d min.   ║   R$ %.2f     ║  R$ %.2f  ║  R$ %.2f  ║\n", DESISTENCIA, PRIMEIRA_HORA, FRACAO, diaria);
    printf("╚═════════════╩═══════════════╩═══════════╩═══════════╝\n\n\n");
}
/** ~ FIM mostrarPrecos **/


//===============================================================================================================================================//


/** ~ mostrarMenuRemocao
* mostra o menu de remoção
* de veiculos
*/
void mostrarMenuRemocao(Carro *carro){
  int posicao = 1;
  double tempodeuso = 0, fracao = 0, preco = 0;
  time_t saida;

  do{
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Remover Veiculo                                    ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║              PRESSIONE 0 EM POSICAO VOLTAR AO MENU                          ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n\n");

    printf("Informe a posicao em que o veiculo se encontra: ");
    scanf("%d", &posicao);
    time(&saida);

    getchar();

    if(posicao == 0) break;
    if(posicao > (CAPACIDADE_MAX)){
      printf("\33[31mVaga inexistente <ENTER> \033[0;0m ");
      getchar();
      limpar();
      break;
    }
    if(strncmp(carro[posicao - 1].placa, "-----", 5) == 0){
      printf("\33[31mNao existe veiculo nesta vaga <ENTER>\033[0;0m ");
      getchar();
      limpar();
      continue;
    }

    cadastrarCarro(&carro[posicao - 1], posicao, "-----", "-----", "-----");

    tempodeuso = (difftime(saida, carro[posicao - 1].entrada) / 1);

    if(tempodeuso <= DESISTENCIA){
      preco = 0;
    }
    else if(tempodeuso > DESISTENCIA && tempodeuso <= 60){
      preco = PRIMEIRA_HORA;
    }
    else{
      int hora, proxHora;
      preco = PRIMEIRA_HORA;
      fracao = 1;
      for(int i = 1; i < (DIARIA - 1); ++i, fracao += FRACAO){
        hora = i * 60;
        proxHora = ((i + 1) * 60);
        if(tempodeuso >= hora && tempodeuso < proxHora){
          preco += fracao;
        }
      }
    }

    printf("\033[22;32mVeiculo retirado\33[0;0m \n\n");
    printf("\033[22;32mVPreco: R$ %.2f\33[0;0m \n\n", preco);
    printf("\033[22;32mTempo de uso: %d segundos <ENTER>\33[0;0m ", (int)tempodeuso);

    getchar();
    limpar();

  } while(posicao != 0);

  limpar();
}
/** ~ FIM mostrarMenuRemocao **/


//===============================================================================================================================================//


/** ~ mostrarManual
* Exibe o manual de uso
*/
void mostrarManual(){
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                       MANUAL DE ULTILIZACAO                                 ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                  PRESSIONE <ENTER> VOLTAR AO MENU                           ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n\n\n");

  printf("1) A placa deve ser preenchida no modelo NNN-LLLL, onde: \n");
  printf(" * N é um algarismo Numerico \n");
  printf(" * L é uma Letra \n\n");

  printf("2) Sempre que ver o simbolo <ENTER> aperte ENTER para continuar\n\n\n\n\n");
}
/** ~FIM mostrarManual **/


//===============================================================================================================================================//


/** ~ desenharUI
* Exibe todas as vagas
* disponiveis e ocupadas
*/
void desenharUI(Carro *carro, int capacidade){
  /**
  * As funções desenharCabecalho,
  * desenharPosicao e desenharRodape
  * simulam uma interface grafica (ui)
  * no terminal com os dados do Estacionamento
  */
  desenharCabecalho();

  for(int i = 0; i < capacidade; ++i){
    desenharPosicao(&carro[i]);
  }

  desenharRodape();
  /** ~ Fim UI ~ **/
}
/** ~ FIM desenharUI **/


//===============================================================================================================================================//


/** ~ formatarAtributos
* Realiza a adequação das propriedades do carro
* à UI.
*/
void formatarAtributos(Carro *carro, int posicao, const char *placa, const char *modelo, const char *cor){

  int i, j;
  char posicaostr[3];

  // int to string
  sprintf(posicaostr, "%d", posicao);

  if(posicao <= 9){
    strcat(posicaostr, " ");
  }

  strcpy(carro->posicao, posicaostr);
  strcpy(carro->placa, placa);
  strcpy(carro->modelo, modelo);
  strcpy(carro->cor, cor);


  if(strncmp(carro->placa, "-----", 5) == 0){
    strcpy(carro->data, "--/--");
    strcpy(carro->hora, "--:--");
  }
  else{
    char data[6], hora[6];

    time(&carro->entrada);
    struct tm *momento;
    momento = localtime(&carro->entrada);
    strftime(data, 6, "%d/%m", momento);
    strftime(hora, 6, "%H:%M", momento);

    strcpy(carro->data, data);
    strcpy(carro->hora, hora);
  }


  for(i = 0; i < 14; ++i){

    if(carro->placa[i] == '\n') carro->placa[i] = ' ';
    if(carro->modelo[i] == '\n') carro->modelo[i] = ' ';
    if(carro->cor[i] == '\n') carro->cor[i] = ' ';

    if(carro->placa[i] == '\0' && i < 8){
      j = i;

      do{
        carro->placa[j] = ' ';
        ++j;
      } while(j < 8);
    }

    if(carro->modelo[i] == '\0' && i < 13){
      j = i;

      do{
        carro->modelo[j] = ' ';
        ++j;
      } while(j < 13);
    }

    if(carro->cor[i] == '\0' && i < 14){
      j = i;

      do{
        carro->cor[j] = ' ';
        ++j;
      } while(j < 14);
    }
  }



  carro->placa[8] = '\0';
  carro->modelo[13] = '\0';
  carro->cor[14] = '\0';
}
/** ~ FIM formatarAtributos **/


//===============================================================================================================================================//


/** ~ cadastrarCarro
* Função responsável por cadastrar os atributos
* em uma variável do tipo Carro, definida em struct.h
* É usada a função formatarAtributos para adequar os parametros
* passados a ui.h
*/
void cadastrarCarro(Carro *carro, int posicao, const char *placa, const char *modelo, const char *cor){
  formatarAtributos(carro, posicao, placa, modelo, cor);
}
