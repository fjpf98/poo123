#pragma once
#include<iostream>
#include "Estacao.h"
#include "Passagem.h"
#include "Colecao.h"
#include "TData.h"
#include "TDataHora.h"
#include "THora.h"

using namespace std;

class Passagem;

class Comboio{
private:
	string sigla;

	Estacao* estAnterior;

	Colecao <Passagem> combParou;
	Colecao<Passagem>::iterator it;

public:


	Comboio(string sgl);
	Comboio(Comboio* c);

	bool operator<(const Comboio& c) const;

	string getSigla() const;
	string getEstacaoAnterior();

	bool guardaParagem(Passagem *p);

	void setEstAnterior(string sgl);

	void printParagens();

};

