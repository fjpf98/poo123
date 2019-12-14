#pragma once
#include<iostream>
#include "Comboio.h"
#include "Estacao.h"
#include "Passagem.h"
#include "TData.h"
#include "TDataHora.h"
#include "THora.h"
#include "Colecao.h"

using namespace std;

class Estacao;
class Comboio;
class Passagem;

class RF
{
private:
	Colecao <Estacao> estacoes;
	Colecao <Comboio> comboios;

	Estacao* findEstacao(string sgl);
	Comboio* findComboio(string sgl);

public:
	bool addComboio(string sgl);
	bool addEstacao(string sgl, string loc);
	bool addLigacaoAEstacao(string est, string estDeDestino);
	//void printLigacoesEst(string sgl);
	bool passarComboioPorEstacao(string comb, string est, int lin, bool para);
	//bool mostrarPassagensEstacao(string sgl);
	bool mostrarParagensComboio(string sgl);


};

