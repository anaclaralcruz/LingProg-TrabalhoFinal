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

using namespace std;

class Banco{
  public:
    Banco(const char*);

    void buscaReceita(const char*);
   

  private:

    sqlite3* db;
    sqlite3_stmt *stmt;
  //  char* errmsg ;
};