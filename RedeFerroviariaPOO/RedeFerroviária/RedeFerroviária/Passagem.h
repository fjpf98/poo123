#pragma once
#include<iostream>
#include "Comboio.h"
#include "Estacao.h"
#include "Passagem.h"
#include "Colecao.h"
#include "TData.h"
#include "TDataHora.h"
#include "THora.h"

using namespace std;

class Comboio;
class Estacao;
class RF;

class Passagem
{
private:
	int id;
	int linha;
	bool comParagem;
	TDataHora datahora;

	Estacao* estacao;
	Comboio* comboio;

	Colecao <Passagem> passagens;

public:
	static int i;
	Passagem(int id, bool para, int lin, Estacao* e, Comboio* c);
	Passagem(bool para, int lin, Estacao* e, Comboio* c);
	Passagem(Passagem* p);
	bool operator<(const Passagem& p) const;
	bool operator==(const Passagem& p) const;
	void print() const;
	int getID();
	void setID();
	int getLinha() const;
	bool getcomParagem() const;
	string getEstacao() const;
	string getComboio() const;
	TDataHora getHora() const;

	bool addPassagem(Passagem* p);


};

