// CLC_Sql.cpp
// Ce fichier permet de lier la BDD a l'application, et de convertir les dates

#pragma once

using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_Composants
{
	ref class CLC_Sql
	{
	private:
		String^ constr;
		String^ rq_sql;
		MySqlConnection^ con;
		MySqlCommand^ cmd;
		MySqlDataAdapter^ sda;
		DataSet^ ds;
		void setSQL(String^);
	public:
		CLC_Sql(void);
		int actionRowsID(String^);
		void actionRows(String^);
		DataSet^ getRows(String^, String^);
		// void sDate(String^);
	};
}