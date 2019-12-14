#include<iostream>
#include"RF.h"
#include"Comboio.h"
#include"Estacao.h"
#include"Passagem.h"




class RF;
class Estacao;
class Comboio;
class Passagem;

void main() {

	RF RF1;

	RF1.addComboio("PortoAveiro");
	RF1.addComboio("PortoLisb");
	RF1.addComboio("AveiroLisb");

	RF1.addEstacao("PORTO", "Porto");
	RF1.addEstacao("LISBOA", "Lisboa");
	RF1.addEstacao("AVEIRO", "Aveiro");

	RF1.addLigacaoAEstacao("PORTO", "AVEIRO");
	RF1.addLigacaoAEstacao("AVEIRO", "LISBOA");
	RF1.addLigacaoAEstacao("PORTO", "LISBOA");

	//RF1.printLigacoesEst("LISBOA");    não e pedido no enunciado

	RF1.passarComboioPorEstacao("PortoAveiro", "PORTO", 3, true);       
	RF1.passarComboioPorEstacao("PortoLisb", "PORTO", 5, false);
	RF1.passarComboioPorEstacao("PortoAveiro", "AVEIRO", 3, false);
	RF1.passarComboioPorEstacao("PortoLisb", "LISBOA", 5, true);



	RF1.mostrarParagensComboio("PortoAveiro");

}