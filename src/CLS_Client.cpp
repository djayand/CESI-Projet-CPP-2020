// CLS_Client.cpp
// Couche "service" de la gestion des clients

#include "CLS_Client.h"

namespace NS_Svc
{
	CLS_Client::CLS_Client(void)
	{
		this->cad = gcnew NS_Composants::CLC_Sql();
		this->client = gcnew NS_Composants::CLC_Client();
		this->ds = gcnew Data::DataSet();
	}
	DataSet^ CLS_Client::listeClient(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->client->SELECT(), dataTableName);
		return this->ds;
	}
	int CLS_Client::ajouter(String^ nom, String^ prenom, String^ DateN, String^ DateC, int ID_Remise)
	{
		int ID_Client;
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->client->setDateN(DateN);
		this->client->setDateC(DateC);
		this->client->setID_Remise(ID_Remise);
		ID_Client = this->cad->actionRowsID(this->client->INSERT());
		return ID_Client;
	}
	void CLS_Client::modifier(int ID_Client, String^ nom, String^ prenom, String^ DateN, String^ DateC, int ID_Remise)
	{
		this->client->setID(ID_Client);
		this->client->setNom(nom);
		this->client->setPrenom(prenom);
		this->client->setDateN(DateN);
		this->client->setDateC(DateC);
		this->client->setID_Remise(ID_Remise);
		this->cad->actionRows(this->client->UPDATE());
	}
	void CLS_Client::supprimer(int ID_Client)
	{
		this->client->setID(ID_Client);
		this->cad->actionRows(this->client->DELETE());
	}
}