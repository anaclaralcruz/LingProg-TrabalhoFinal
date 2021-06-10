// Autoras:
//    Ana Clara Loureiro Cruz
//    Maria Clara Gonçalves Baptista
// Data: 06-06-2021

/*  TRABALHO FINAL - LING PROG  */
    // Criar um banco para gerir receitas

/* "receita.h" ------------------------------------------------- */
/* Inicializa a classe receita */

#ifndef RECEITA_H
#define RECEITA_H

#include <string>
#include <vector>

using namespace std;

class Receita{
  public:
    Receita();

    void setNome(string);
    void setModoDePreparo(string);
    void setRendimento(string);
    void setTipo(string);
    void setNota(string);
    void setTempo(string);
    void setIngrediente(string);

    const char* getNome();
    const char* getModoDePreparo();
    int getRendimento();
    const char* getTipo();
    int getNota();
    int getTempo();
    vector<const char*> getIngredientes();

    void imprime();

  private:
    string nome, modoDePreparo, tipo;
    int rendimento, tempo, nota;
    vector<string> ingredientes;
};

#endif