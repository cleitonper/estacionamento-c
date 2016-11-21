#include "ui.h"


int main(){
  /**
  * É criado um vetor do tipo Carro
  * chamado carro com capacidade
  * definida pela constante CAPACIDADE_MAX
  */
  Carro carro[CAPACIDADE_MAX];



  /**
  * A variavel opção armazena a opção
  * escolhida pelo usuário no menu
  * e é manipulada em uma estrutura switch
  **/
  int opcao = 0;



  /**
  * Todos os carros tem seus atributos
  * inicializados com a string "vazio"
  */
  for(int i = 0; i < CAPACIDADE_MAX; ++i){
    cadastrarCarro(&carro[i], i+1, "-----", "-----", "-----");
  }


  mostrarMenuPrincipal(&opcao);

  limpar();

  while(opcao != 0){
    switch(opcao){
      case 1:
        limpar();
        desenharUI(carro, CAPACIDADE_MAX);
        break;
      case 2:
        limpar();
        mostrarPrecos();
        break;
      case 3:
        limpar();
        mostrarMenuCadastro(carro);
        break;
      case 4:
        mostrarMenuRemocao(carro);
        break;
      case 8:
        mostrarManual();
        break;
      default:
        printf("Opção invalida\n\n");
        break;
    }
    mostrarMenuPrincipal(&opcao);
  }

  printf("\033[22;32m <Feche a janela para encerrar>\n\n");
  return 0;
}
