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
#include "banco.h"

using namespace std ;

int main (){
    int opcaoMenu;

    Banco banco (ARQUIVO_LIVRO_RECEITAS);

    // Menu de entrada:
    cout << endl;
    cout << " ______________________________________________________" << endl;
    cout << "| 1 | Buscar receita                                  |" << endl;
    cout << "| 2 | Adicionar receita                               |" << endl;
    cout << "| 3 | Atualizar uma nota (numero inteiro)             |" << endl;
    cout << "| 4 | Exibir ranking pela nota                        |" << endl;
    cout << "| 5 | Exibir todas as receitas                        |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "O que deseja? (digite o numero) -> ";
    cin >> opcaoMenu ;
    cin.ignore();
    cout << endl;

    if (opcaoMenu == 1){
        string nome;
        cout << "Qual receita deseja buscar?";
        getline(cin, nome);
        banco.buscaReceita(nome.c_str());
        main ();
    }
    
    else if (opcaoMenu == 2){
        Receita receita;
        string nome, modo_preparo, tipo, rendimento, tempo, nota, ingrediente, sn;

        cout << "Entre com o nome: ";
        getline(cin, nome);
        cout << nome << endl;
        receita.setNome(nome);
        
        cout << "Entre com o modo de preparo: ";
        getline(cin, modo_preparo);
        cout << modo_preparo << endl ;
        receita.setModoDePreparo(modo_preparo);

        cout << "Entre com o tipo: ";
        getline(cin, tipo);
        cout << tipo << endl;
        receita.setTipo(tipo);

        cout << "Entre com o rendimento: ";
        getline(cin, rendimento);
        cout << rendimento << endl;
        receita.setRendimento(rendimento);

        cout << "Entre com o tempo: ";
        getline(cin, tempo);
        cout << tempo << endl;
        receita.setTempo(tempo);

        cout << "Entre com a nota: ";
        getline(cin, nota);
        cout << nota << endl;
        receita.setNota(nota);

        int i = 1;
        while (i != 0){
            cout << "Entre com um ingrediente: ";
            getline(cin, ingrediente);
            receita.setIngrediente(ingrediente);
            ingrediente.clear();
            cout<< "Parar de adicionar ingredientes? {s/n}: ";
            getline(cin, sn);
            if (sn == "s")
                i=0;
        }
        banco.adicionarReceita(receita);
    }

    else if (opcaoMenu == 3){
        string nome,nota;
        cout << "Entre com a receita que deseja alterar a nota: ";
        getline(cin, nome);
        cout << "Entre com a nova nota: ";
        getline(cin, nota);
        banco.atualizarNota(nome.c_str(), stoi(nota));
    }

    else if (opcaoMenu == 4){
       banco.ranking();
        main ();
    }

    else if (opcaoMenu == 5){
        banco.exibirReceitas();
         main ();
    }

    else {
        cout << "ENTRADA INVALIDA escolha um numero de 1 a 8 !!" << endl;
        main ();
    }

    
    cout << endl;
    return 0;
}