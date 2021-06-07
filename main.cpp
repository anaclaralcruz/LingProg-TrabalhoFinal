// Autoras:
//    Ana Clara Loureiro Cruz
//    Maria Clara Gonçalves Baptista
// Data: 06-06-2021

/*  TRABALHO FINAL - LING PROG  */
    // Criar um banco para gerir receitas

/* "main.cpp" ------------------------------------------------- */
/* Funcao principal que contem o menu do programa */

#define  ARQUIVO_LIVRO_RECEITAS  "Livro_de_receitas.db"

#include <iostream>
#include <string>
#include <sqlite3.h>

#include "banco.h"

using namespace std;

int main() {

   Banco banco (ARQUIVO_LIVRO_RECEITAS);
   banco.buscaReceita("Arroz");

}