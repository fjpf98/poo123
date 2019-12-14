#pragma once
#include<iostream>
#include"Comboio.h"
#include"RF.h"
#include"TDataHora.h"
#include"TData.h"
#include"THora.h"
#include"Colecao.h"


using namespace std;

class RF;
class Comboio;

class Estacao
{
private:
	string sigla;
	string local;
	
	Colecao <Estacao> ligacoes;
	Colecao <Comboio> combParou; // comboios que param na estaçao

public:

	Estacao(string sgl, string loc);
	Estacao(Estacao* e);
	bool operator<(const Estacao& e) const;
	bool guardaLigacao(Estacao* e);
	void printLigacoes();
	bool verificaLigacao(Estacao* eProxima);

	string getSigla() const;
	string getLocal() const;

	void setSigla(string sgl);



};
