// CLC_Sql.cpp
// Ce fichier permet de lier la BDD a l'application, et de convertir les dates

#include "CLC_Sql.h"
#include <ctime>

namespace NS_Composants
{
	CLC_Sql::CLC_Sql(void)
	{
		this->rq_sql = "null";
		this->constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=bddca";
		this->con = gcnew MySqlConnection(this->constr);
		this->cmd = gcnew MySqlCommand(this->rq_sql, this->con);
		this->cmd->CommandType = CommandType::Text;
	}
	int CLC_Sql::actionRowsID(String^ rq_sql)
	{
		int id;
		this->setSQL(rq_sql);
		this->cmd->CommandText = this->rq_sql;
		this->con->Open();
		id = Convert::ToInt32(this->cmd->ExecuteScalar());
		this->con->Close();
		return id;
	}
	void CLC_Sql::actionRows(String^ rq_sql)
	{
		this->setSQL(rq_sql);
		this->cmd->CommandText = this->rq_sql;
		this->con->Open();
		this->cmd->ExecuteNonQuery();
		this->con->Close();
	}
	DataSet^ CLC_Sql::getRows(String^ rq_sql, String^ dataTableName)
	{
		this->setSQL(rq_sql);
		this->sda = gcnew MySqlDataAdapter(this->cmd);
		this->cmd->CommandText = this->rq_sql;
		this->ds = gcnew DataSet();
		this->sda->Fill(this->ds, dataTableName);
		return this->ds;
	}
	void CLC_Sql::setSQL(String^ rq_sql)
	{
		if (rq_sql == "" || rq_sql == "RIEN")
		{
			this->rq_sql = "RIEN";
		}
		else
		{
			this->rq_sql = rq_sql;
		}
	}
}
