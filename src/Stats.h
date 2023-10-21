// Stats.h
// Gestion des statistiques

#pragma once
#include "CLC_Sql.h"

namespace PooProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm2
	/// </summary>
	public ref class Stats : public System::Windows::Forms::Form
	{
	public:
		Stats(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Stats()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ txt_msg;
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::ComponentModel::IContainer^ components;
	private: Data::DataSet^ ds;
	private: int index;
	private: String^ mode;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->txt_msg = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(210, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Panier moyen (après remise)";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1013, 520);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(210, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Réaliser des simulations";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(155)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->button3->Location = System::Drawing::Point(12, 282);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(210, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Valeur d\'achat du stock";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(155)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->button4->Location = System::Drawing::Point(12, 227);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(210, 30);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Valeur commerciale du stock";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->button5->Location = System::Drawing::Point(12, 338);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(246, 30);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Les 10 articles les moins vendus";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->button6->Location = System::Drawing::Point(12, 396);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(210, 30);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Les 10 articles les plus vendus";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 168);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(276, 30);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Montant total d\'achat pour 1 client";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(12, 113);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(386, 30);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Produits inférieurs au seuil de réapprivisionnement";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(12, 59);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(210, 30);
			this->button9->TabIndex = 8;
			this->button9->Text = L"Chiffre d\'affaires (mois)";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// txt_msg
			// 
			this->txt_msg->Location = System::Drawing::Point(549, 57);
			this->txt_msg->Multiline = true;
			this->txt_msg->Name = L"txt_msg";
			this->txt_msg->Size = System::Drawing::Size(507, 200);
			this->txt_msg->TabIndex = 9;
			// 
			// Stats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1255, 572);
			this->Controls->Add(this->txt_msg);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Stats";
			this->Text = L"Relevé de statistiques";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
};
}