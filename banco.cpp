// Autoras:
//    Ana Clara Loureiro Cruz
//    Maria Clara Gonçalves Baptista
// Data: 06-06-2021

/*  TRABALHO FINAL - LING PROG  */
    // Criar um banco para gerir receitas

/* "banco.cpp" ------------------------------------------------- */
/* Contem os metodos referentes a classe banco */

#include <iostream>

#include "banco.h"
#include "receita.h"

Banco::Banco(const char* nome_do_arquivo) {
    if (sqlite3_open(nome_do_arquivo, &db) == SQLITE_OK)
        cout << "Banco aberto com sucesso!\n";
    else
        cout << "Houve um problema ao abrir o banco. Cheque o nome do arquivo.\n";
}

void Banco::buscaReceita (const char* nome_da_receita) {
    sqlite3_prepare_v2(db, 
        "SELECT * FROM receitas WHERE nome = ?"
        , -1, &stmt, 0);

    sqlite3_bind_text(stmt, 1, nome_da_receita, strlen(nome_da_receita),SQLITE_STATIC);

    int rc = sqlite3_step(stmt);

    if (rc == SQLITE_DONE) {
        cout << "Receita nao encontrada! Verifique o nome e tente novamente :(" << endl ;
    }

    Receita receita;
    receita.setNome(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))));
    receita.setModoDePreparo(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))));
    receita.setTempo(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))));
    receita.setRendimento(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4))));
    receita.setTipo(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))));
    receita.setNota(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))));

    sqlite3_prepare_v2(db, 
        "SELECT ingredientes.ingrediente_nome FROM receitas JOIN receitas_ingredientes ON (receitas_ingredientes.receita_id = receitas.receita_id) JOIN ingredientes ON (ingredientes.ingrediente_id = receitas_ingredientes.ingrediente_id) WHERE receitas.nome = ?"
        , -1, &stmt, 0);

    sqlite3_bind_text(stmt, 1, nome_da_receita, strlen(nome_da_receita),SQLITE_STATIC);
    while (sqlite3_step(stmt) != SQLITE_DONE)
        receita.setIngrediente(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));

    sqlite3_finalize(stmt);
    receita.imprime();
}

