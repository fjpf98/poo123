#include "Passagem.h"

Passagem::Passagem(int i, bool para, int lin, Estacao* e, Comboio* c)
{

	id = i;
	comParagem = para;
	linha = lin;
	TDataHora datahora = datahora.hoje_agora();

	estacao = e;
	comboio = c;

	cout << "\nPassagem " << id << endl;
	cout << "A passar o comboio " << comboio->getSigla() << " pela estacao " << estacao->getSigla() << endl;
	cout << "\n \t\t..." << endl;
	cout << "\t\t..." << endl;
	cout << "\t\t...\n" << endl;

	c->setEstAnterior(estacao->getSigla());

	if (comParagem == true)
	{
		if(c->guardaParagem(this));
		cout << "O comboio " << comboio->getSigla() << " parou na estacao " << estacao->getSigla() << "  \t" << datahora << endl;
	}
	else
	{
		cout << "O comboio " << comboio->getSigla() << " passou na estacao " << estacao->getSigla() << " sem parar \t" << datahora << endl;
	}
	addPassagem(this);

}

Passagem::Passagem(bool para, int lin, Estacao* e, Comboio* c)
{
	int i = getID();
	Passagem p(i, para, lin, e, c);
}

Passagem::Passagem(Passagem* p)
{
	id = p->id;
	linha = p->linha;
	comParagem = p->comParagem;

	comboio = p->comboio;
	estacao = p->estacao;
}


bool Passagem::operator<(const Passagem& p) const
{
	return id < p.id;
}

bool Passagem::operator==(const Passagem& p) const
{
	return id == p.id;
}

void Passagem::print() const
{
	cout << "Na estacao -> " << estacao->getSigla() << "\t no dia " << datahora.getHora()<< " as "<< datahora.getHora() << endl;	
}

int Passagem::getID()
{
	id = Passagem::i++;
	return id;
}

void Passagem::setID()
{
	id = getID();
}

int Passagem::getLinha() const
{
	return linha;
}

bool Passagem::getcomParagem() const
{
	return comParagem;
}

string Passagem::getEstacao() const
{
	return estacao->getSigla();
}

string Passagem::getComboio() const
{
	return comboio->getSigla();
}

TDataHora Passagem::getHora() const
{
	return datahora;
}


bool Passagem::addPassagem(Passagem* p)
{
	return passagens.insert(p);
}
