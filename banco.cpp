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
        cout << " " << endl;
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
        return;
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

void Banco::atualizarNota (const char* nome_da_receita, int nota) {
    sqlite3_prepare_v2(db, 
        "SELECT * FROM receitas WHERE nome = ?"
        , -1, &stmt, 0);

    sqlite3_bind_text(stmt, 1, nome_da_receita, strlen(nome_da_receita),SQLITE_STATIC);

    int rc = sqlite3_step(stmt);

    if (rc == SQLITE_DONE) {
        cout << "Receita nao encontrada! Verifique o nome e tente novamente :(" << endl ;
        return;
    }
    sqlite3_finalize(stmt);

    sqlite3_prepare_v2(db, 
        "UPDATE receitas SET nota = ? WHERE nome = ?"
        , -1, &stmt, 0);

    sqlite3_bind_int(stmt, 1, nota);
    sqlite3_bind_text(stmt, 2, nome_da_receita, strlen(nome_da_receita),SQLITE_STATIC);
    rc = sqlite3_step(stmt);
    cout << "A nova nota da receita de " << string (nome_da_receita) << " eh " << nota << endl;

    sqlite3_finalize(stmt);
}

void Banco::adicionarReceita (Receita receita) {
    int receita_id = getReceitaId();
    int ingrediente_id = getIngredienteId();

    string sqlstatement = "INSERT INTO receitas (nome, modo_preparo, tempo_preparo, rendimento, tipo, nota) VALUES (\""
     + string (receita.getNome()) + "\"," 
     + "\"" + string (receita.getModoDePreparo()) + "\"," 
     + to_string (receita.getTempo()) + ","
     + to_string (receita.getRendimento()) + ","
     + '\"' + string (receita.getTipo()) + "\","
     + to_string (receita.getNota()) + ")" ;

    sqlite3_prepare( db, sqlstatement.c_str(), -1, &stmt, NULL );
    sqlite3_step( stmt );
    sqlite3_finalize(stmt);

    for (auto& ingrediente : receita.getIngredientes()) {
        sqlite3_prepare_v2(db, 
            "INSERT INTO ingredientes (ingrediente_nome) VALUES (?)"
            , -1, &stmt2, 0);
        sqlite3_bind_text(stmt2, 1, ingrediente, strlen(ingrediente), SQLITE_STATIC);
        sqlite3_step(stmt2);
        sqlite3_finalize(stmt2);

        sqlite3_prepare_v2(db, 
            "INSERT INTO receitas_ingredientes (receita_id, ingrediente_id) VALUES (?, ?)"
            , -1, &stmt3, 0);
        sqlite3_bind_int(stmt3, 1, receita_id);
        sqlite3_bind_int(stmt3, 2, ingrediente_id);
        sqlite3_step(stmt3);
        sqlite3_finalize(stmt3);
        ingrediente_id++;
    }

    cout << "Receita adicionada com sucesso!!" << endl;
}

int Banco::getReceitaId() {
    int i;
    sqlite3_prepare_v2(db, 
        "SELECT receita_id FROM receitas"
        , -1, &stmt, 0);

    while (sqlite3_step(stmt) != SQLITE_DONE)
        i = sqlite3_column_int (stmt, 0);

    sqlite3_finalize(stmt);

    return i + 1;
}

int Banco::getIngredienteId() {
    int i;
    sqlite3_prepare_v2(db, 
        "SELECT ingrediente_id FROM ingredientes"
        , -1, &stmt, 0);

    while (sqlite3_step(stmt) != SQLITE_DONE)
        i = sqlite3_column_int (stmt, 0);

    sqlite3_finalize(stmt);

    return i + 1;
}

void Banco::ranking () {

    sqlite3_prepare_v2(db, 
        "SELECT nome, nota FROM receitas ORDER BY nota"
        , -1, &stmt, 0);

    int i = 1;
    cout << "NOME" << "\t\t\t\t"<< "NOTA"<<endl;
    while (sqlite3_step(stmt) != SQLITE_DONE){
        cout<< string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))) <<"\t\t\t\t";
        cout << sqlite3_column_int (stmt, 1) << endl;
        i++;
    }
    
    sqlite3_finalize(stmt);
}

void Banco::exibirReceitas() {

    sqlite3_prepare_v2(db, 
        "SELECT nome, tipo FROM receitas ORDER BY nome"
        , -1, &stmt, 0);

    int i = 1;
    cout << "NOME\t\t\t\t" << "TIPO" << endl;
    while (sqlite3_step(stmt) != SQLITE_DONE){
        cout << i << ". ";
        cout<< string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))) << "\t\t\t\t";
        cout<< string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))) << endl;
        i++;
    }
    sqlite3_finalize(stmt);

}