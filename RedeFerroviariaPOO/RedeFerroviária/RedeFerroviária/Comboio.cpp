#include "Comboio.h"

Comboio::Comboio(string sgl)
{
	sigla = sgl;
	estAnterior = new Estacao("", "");
}

Comboio::Comboio(Comboio* c)
{
	sigla = c->getSigla();
	estAnterior = c->estAnterior;

}

bool Comboio::operator<(const Comboio& c) const
{
	return sigla < c.sigla;
}

string Comboio::getSigla() const
{
	return sigla;
}

string Comboio::getEstacaoAnterior()
{
	return estAnterior->getSigla();
}

bool Comboio::guardaParagem(Passagem *p)
{
	return combParou.insert(*p);
}

void Comboio::setEstAnterior(string sgl)
{
	estAnterior->setSigla(sgl);
}

void Comboio::printParagens()
{
	cout << combParou.size() << endl;
	for (it = combParou.begin(); it != combParou.end(); it++)
	{
			it->print();
	}
	
}

