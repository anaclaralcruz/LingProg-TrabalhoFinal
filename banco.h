// Autoras:
//    Ana Clara Loureiro Cruz
//    Maria Clara Gonçalves Baptista
// Data: 06-06-2021

/*  TRABALHO FINAL - LING PROG  */
    // Criar um banco para gerir receitas

/* "banco.h" ------------------------------------------------- */
/* Inicializa a classe banco */

#include <cstring>
#include <sqlite3.h>
#include <vector>
#include <string>
#include "receita.h"
using namespace std;

class Banco{
  public:
    Banco(const char*);

    void buscaReceita(const char*);
    void atualizarNota(const char*, int);
    void adicionarReceita(Receita);
    void ranking();
    void exibirReceitas();
   

  private:
    int getIngredienteId();
    int getReceitaId();

    sqlite3* db;
    sqlite3_stmt *stmt;
    sqlite3_stmt *stmt2;
    sqlite3_stmt *stmt3;
};