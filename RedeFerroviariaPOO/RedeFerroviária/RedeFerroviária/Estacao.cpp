#include "Estacao.h"


Estacao::Estacao(string sgl, string loc) 
{
	sigla = sgl;
	local = loc;
}

Estacao::Estacao(Estacao* e)
{
	sigla = e->getSigla();
	local = e->getLocal();
}

bool Estacao::operator<(const Estacao& e) const
{
	return sigla < e.sigla;
}

bool Estacao::guardaLigacao(Estacao* e)
{
	string sgl = e->sigla;
	string loc = e->local;
	Estacao ed(sgl, loc);
	return ligacoes.insert(ed);
}

void Estacao::printLigacoes()
{
	cout << "\n ---------------------------------------------------- \n";
	cout << "Lista de ligacoes da estacao " << getSigla() << ":\n";
	Colecao<Estacao>::iterator it;
	for (it = ligacoes.begin(); it != ligacoes.end(); it++)
		cout << "\t -> " << it->getSigla() << "\t" << it->getLocal() << " \n";
	cout << "\n ---------------------------------------------------- \n\n";
}

bool Estacao::verificaLigacao(Estacao* eProxima)
{
	Colecao<Estacao>::iterator it;
	for (it = ligacoes.begin(); it != ligacoes.end(); it++) {
		if (it->getSigla() == eProxima->getSigla())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

string Estacao::getSigla() const
{
	return sigla;
}

string Estacao::getLocal() const
{
	return local;
}

void Estacao::setSigla(string sgl)
{
	sigla = sgl;
}
