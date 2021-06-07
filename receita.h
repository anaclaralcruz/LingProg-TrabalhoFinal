// Autoras:
//    Ana Clara Loureiro Cruz
//    Maria Clara Gonçalves Baptista
// Data: 06-06-2021

/*  TRABALHO FINAL - LING PROG  */
    // Criar um banco para gerir receitas

/* "receita.h" ------------------------------------------------- */
/* Inicializa a classe receita */

#include <string>
#include <vector>

using namespace std;

class Receita{
  public:
    void setNome(string);
    void setModoDePreparo(string);
    void setRendimento(string);
    void setTipo(string);
    void setNota(string);
    void setTempo(string);
    void setIngrediente(string);

    void imprime();

  private:
    string nome, modoDePreparo, tipo;
    int rendimento, tempo, nota;
    vector<string> ingredientes;
};