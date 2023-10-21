// CLS_Perso.cpp
// Couche "service" de la gestion du personnel

#include "CLS_Perso.h"

namespace NS_Svc
{
	CLS_Perso::CLS_Perso(void)
	{
		this->cad = gcnew NS_Composants::CLC_Sql();
		this->personnel = gcnew NS_Composants::CLC_Perso();
		this->ds = gcnew Data::DataSet();
	}
	DataSet^ CLS_Perso::listePersonnes(String^ dataTableName)
	{
		this->ds->Clear();
		this->ds = this->cad->getRows(this->personnel->SELECT(), dataTableName);
		return this->ds;
	}
	int CLS_Perso::ajouter(String^ nom, String^ prenom, String^ dateE, String^ adresse)
	{
		int id_personne;
		this->personnel->setNom(nom);
		this->personnel->setPrenom(prenom);
		this->personnel->setDateE(dateE);
		this->personnel->setAdresse(adresse);
		id_personne = this->cad->actionRowsID(this->personnel->INSERT());
		return id_personne;
	}
	void CLS_Perso::modifier(int id_personne, String^ nom, String^ prenom, String^ dateE, String^ adresse)
	{
		this->personnel->setID(id_personne);
		this->personnel->setNom(nom);
		this->personnel->setPrenom(prenom);
		this->personnel->setDateE(dateE);
		this->personnel->setAdresse(adresse);
		this->cad->actionRows(this->personnel->UPDATE());
	}
	void CLS_Perso::supprimer(int id_personne)
	{
		this->personnel->setID(id_personne);
		this->cad->actionRows(this->personnel->DELETE());
	}
}
