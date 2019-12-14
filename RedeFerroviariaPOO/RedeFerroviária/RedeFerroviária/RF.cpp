#include "RF.h"

int Passagem::i = 1;

bool RF::addComboio(string sgl)
{
	Comboio* comb = findComboio(sgl);
	if (comb != NULL)
	{
		cout << "Comboio com a sigla: " << sgl << "ja existe !" << endl;
	}
	else
	{
		Comboio c(sgl);
		cout << "Comboio criado com a sigla " << sgl << " ! " << endl;

		return comboios.insert(c);
	}
}

bool RF::addEstacao(string sgl, string loc)
{
	Estacao* est = findEstacao(sgl);
	if (est != NULL)
	{
		cout << "Estacao ja existe com a sigla: " << sgl << endl;
	}
	else
	{
		Estacao e(sgl, loc);
		cout << "Estacao criada com a sigla " << sgl << " e local  " << loc << " ! " << endl;

		return estacoes.insert(e);
	}
}

bool RF::addLigacaoAEstacao(string est, string estDeDestino)
{
	Estacao* fe = findEstacao(est);
	if (fe != NULL)
	{
		Estacao* fed = findEstacao(estDeDestino);
		if (fed != NULL) {
			fe->guardaLigacao(fed); fed->guardaLigacao(fe);
			cout << "\nA estacao " << fe->getSigla() << " tem agora ligacao com " << fed->getSigla() << endl;
			return true;
		}
		else cout << "\nEstacao " << estDeDestino << " nao existe  " << endl;
	}
	else cout << "\nEstacao " << est << " nao exite" << endl;
	return false;
}

bool RF::passarComboioPorEstacao(string comb, string est, int lin, bool para)
{

	Comboio c = findComboio(comb);
	Estacao e = findEstacao(est);


	if (c.getEstacaoAnterior() == "")						//em caso de ser a 1ª estaçao do comboio
	{
		Passagem p(para, lin, &e, &c);
	}
	else													//caso nao seja a 1ª estaçao do comboio
	{
		if (c.getEstacaoAnterior() == e.getSigla())
		{
			cout << "ERRO ! " << endl;
			cout << "Comboio ja passou aqui!! " << endl;
			return false;
		}
		else
		{
			Estacao* eAnt = findEstacao(c.getEstacaoAnterior());
			if ((eAnt->verificaLigacao(findEstacao(est))) == true)
			{
				Passagem p(para, lin, &e, &c);
			}
			else
			{
				cout << "Estacao sem ligacao!! " << endl;
				return false;
			}
		}

	}
	return true;
}

/*void RF::printLigacoesEst(string sgl)        não e pedido no enunciado
{
	Estacao* fe = findEstacao(sgl);
	if (fe) fe->printLigacoes();
	else cout << "Estacao " << sgl << " nao existe.\n";
}

*/

/*bool RF::mostrarPassagensEstacao(string sgl)
{



}
*/

bool RF::mostrarParagensComboio(string sgl)
{
	cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl
		<< "\t O comboio " << sgl << " parou :" << endl
		<< ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl
		<< "\n" << endl
		<< "\n" << endl;
	findComboio(sgl)->printParagens();
	return true;
}


Estacao* RF::findEstacao(string sgl)
{
	Estacao e(sgl, "");
	return estacoes.find(e);
}

Comboio* RF::findComboio(string sgl)
{
	Comboio c(sgl);
	return comboios.find(c);
}