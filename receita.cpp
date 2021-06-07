// Autoras:
//    Ana Clara Loureiro Cruz
//    Maria Clara Gonçalves Baptista
// Data: 06-06-2021

/*  TRABALHO FINAL - LING PROG  */
    // Criar um banco para gerir receitas

/* "receita.cpp" ------------------------------------------------- */
/* Contem os metodos referentes a classe receita */

#include <iostream>

#include "receita.h"

using namespace std;

void Receita::setNota(string novaNota){
    nota = stoi(novaNota);
}

void Receita::setRendimento (string novoRendimento) {
    rendimento = stoi(novoRendimento);
}

void Receita::setTempo (string novoTempo) {
    tempo = stoi(novoTempo);
}

void Receita::setTipo (string novoTipo) {
    tipo = novoTipo;
}

void Receita::setNome(string novoNome) {
    nome = novoNome;
}

void Receita::setModoDePreparo (string novoModo) {
    modoDePreparo = novoModo;
}

void Receita::setIngrediente (string novoIngrediente) {
    ingredientes.push_back (novoIngrediente);
}

void Receita::imprime(){
    cout << "Receita de " << nome << ": " << endl << endl;
    cout << "Ingredientes: " << endl;
    for (auto& ingrediente : ingredientes)
        cout << ingrediente << endl ;
    cout << endl << "Modo de preparo: " << modoDePreparo << endl << endl;
    cout << "Rende " << rendimento << " porcoes." << endl;
    cout << "Tempo de preparo: " << tempo << " minutos." << endl << endl;
    cout << "Aproveite! :)" << endl;
}