#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: Personnel
#------------------------------------------------------------

CREATE TABLE Personnel(
        ID_Personnel      Int  Auto_increment  NOT NULL ,
        Nom_Personnel     Varchar (64) NOT NULL ,
        Prenom_Personnel  Varchar (64) NOT NULL ,
        Date_Embauche     Date NOT NULL ,
        Adresse_Personnel Varchar (255) NOT NULL
	,CONSTRAINT Personnel_PK PRIMARY KEY (ID_Personnel)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: DesignationArticle
#------------------------------------------------------------

CREATE TABLE Designation_Article(
        Nom_Article         Varchar (64) NOT NULL ,
        Designation_Article Varchar (255) NOT NULL ,
        Nature_Article      Varchar (64) NOT NULL
	,CONSTRAINT DesignationArticle_PK PRIMARY KEY (Nom_Article)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Article
#------------------------------------------------------------

CREATE TABLE Article(
        ID_Article                     Int  Auto_increment  NOT NULL ,
        Couleur_Article                Varchar (64) NOT NULL ,
        Prix_Unitaire_HT               DECIMAL (15,3)  NOT NULL ,
        Prix_Unitaire_TTC              DECIMAL (15,3)  NOT NULL ,
        Montant_TVA_Unitaire           Float NOT NULL ,
        Qte_Stock                      Int NOT NULL ,
        Seuil_Reapprivosionement       Int NOT NULL ,
        Nom_Article                    Varchar (64) NOT NULL ,
        Nom_Article_DesignationArticle Varchar (64) NOT NULL
	,CONSTRAINT Article_AK UNIQUE (Nom_Article)
	,CONSTRAINT Article_PK PRIMARY KEY (ID_Article)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: TauxRemise
#------------------------------------------------------------

CREATE TABLE Taux_Remise(
        ID_Remise   Int  Auto_increment  NOT NULL ,
        Taux_Remise Int NOT NULL
	,CONSTRAINT TauxRemise_PK PRIMARY KEY (ID_Remise)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Client
#------------------------------------------------------------

CREATE TABLE Client(
        ID_Client             Int  Auto_increment  NOT NULL ,
        Nom_Client            Varchar (64) NOT NULL ,
        Prenom_Client         Varchar (64) NOT NULL ,
        Date_Naissance_Client Date NOT NULL ,
        Date_1e_Commande      Date NOT NULL ,
        ID_Remise             Int NOT NULL
	,CONSTRAINT Client_PK PRIMARY KEY (ID_Client)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Adresse
#------------------------------------------------------------

CREATE TABLE Adresse(
        ID_Adresse      Int  Auto_increment  NOT NULL ,
        Code_postal     Int NOT NULL ,
        Rue             Varchar (255) NOT NULL ,
        N_              Int NOT NULL ,
        Ville           Varchar (32) NOT NULL ,
        FonctionAdresse Int NOT NULL ,
        ID_Client       Int NOT NULL
	,CONSTRAINT Adresse_PK PRIMARY KEY (ID_Adresse)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Moyen Paiement
#------------------------------------------------------------

CREATE TABLE Moyen_Paiement(
        ID_MoyenPaiement Int  Auto_increment  NOT NULL ,
        Moyen_Paiement   Varchar (32) NOT NULL
	,CONSTRAINT Moyen_Paiement_PK PRIMARY KEY (ID_MoyenPaiement)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: PosséderSupérieur
#------------------------------------------------------------

CREATE TABLE Posseder_Superieur(
        ID_Personnel                   Int NOT NULL ,
        ID_Personnel_PossederSuperieur Int NOT NULL
	,CONSTRAINT PossederSuperieur_PK PRIMARY KEY (ID_Personnel,ID_Personnel_PossederSuperieur)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Payer avec
#------------------------------------------------------------

CREATE TABLE Payer_avec(
        ID_MoyenPaiement Int NOT NULL ,
        ID_Client        Int NOT NULL
	,CONSTRAINT Payer_avec_PK PRIMARY KEY (ID_MoyenPaiement,ID_Client)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Commande
#------------------------------------------------------------

CREATE TABLE Commande(
        ID_Commande           Varchar (18) NOT NULL ,
        Date_livraison_prevue Date NOT NULL ,
        Date_emission_facture Date NOT NULL ,
        Moyen_Paiement        Varchar (32) NOT NULL ,
        Date_Paiement         Date NOT NULL ,
        Date_Reglement        Date NOT NULL ,
        Solde_Reglement       Float NOT NULL ,
        Nombre_Total_Articles Int NOT NULL ,
        Montant_Remise        DECIMAL (15,3)  NOT NULL ,
        Montant_TVA_Total     Float NOT NULL ,
        Prix_Commande_HT      DECIMAL (15,3)  NOT NULL ,
        Prix_Commande_TTC     DECIMAL (15,3)  NOT NULL ,
        ID_Client             Int  Auto_increment  NOT NULL ,
        ID_Facture            Int NOT NULL
	,CONSTRAINT Commande_AK0 UNIQUE (ID_Client)
	,CONSTRAINT Commande_PK PRIMARY KEY (ID_Commande)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Facture
#------------------------------------------------------------

CREATE TABLE Facture(
        ID_Facture            Int  Auto_increment  NOT NULL ,
        Nom_Societe           Varchar (32) NOT NULL ,
        Adresse_Societe       Varchar (255) NOT NULL ,
        Numero_Service_Client Int NOT NULL ,
        ID_Commande           Varchar (18) NOT NULL ,
        ID_Commande_Emettre   Varchar (18) NOT NULL ,
        ID_Adresse            Int NOT NULL ,
        ID_Adresse_2          Int NOT NULL
	,CONSTRAINT Facture_AK0 UNIQUE (ID_Commande)
	,CONSTRAINT Facture_PK PRIMARY KEY (ID_Facture)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Former une CommandeLigne
#------------------------------------------------------------

CREATE TABLE Former_une_CommandeLigne(
        ID_Commande Varchar (18) NOT NULL ,
        ID_Article  Int NOT NULL ,
        Quantite    Int NOT NULL
	,CONSTRAINT Former_une_CommandeLigne_PK PRIMARY KEY (ID_Commande,ID_Article)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Gérer
#------------------------------------------------------------

CREATE TABLE Gerer(
        ID_Commande  Varchar (18) NOT NULL ,
        ID_Personnel Int NOT NULL
	,CONSTRAINT Gerer_PK PRIMARY KEY (ID_Commande,ID_Personnel)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Commander
#------------------------------------------------------------

CREATE TABLE Commander(
        ID_Client   Int NOT NULL ,
        ID_Commande Varchar (18) NOT NULL
	,CONSTRAINT Commander_PK PRIMARY KEY (ID_Client,ID_Commande)
)ENGINE=InnoDB;

ALTER TABLE Article
	ADD CONSTRAINT Article_DesignationArticle0_FK
	FOREIGN KEY (Nom_Article_DesignationArticle)
	REFERENCES DesignationArticle(Nom_Article);

ALTER TABLE Client
	ADD CONSTRAINT Client_TauxRemise0_FK
	FOREIGN KEY (ID_Remise)
	REFERENCES TauxRemise(ID_Remise);

ALTER TABLE Adresse
	ADD CONSTRAINT Adresse_Client0_FK
	FOREIGN KEY (ID_Client)
	REFERENCES Client(ID_Client);

ALTER TABLE PossederSuperieur
	ADD CONSTRAINT PossederSuperieur_Personnel0_FK
	FOREIGN KEY (ID_Personnel)
	REFERENCES Personnel(ID_Personnel);

ALTER TABLE PossederSuperieur
	ADD CONSTRAINT PossederSuperieur_Personnel1_FK
	FOREIGN KEY (ID_Personnel_PossederSuperieur)
	REFERENCES Personnel(ID_Personnel);

ALTER TABLE Payer_avec
	ADD CONSTRAINT Payer_avec_Moyen_Paiement0_FK
	FOREIGN KEY (ID_MoyenPaiement)
	REFERENCES Moyen_Paiement(ID_MoyenPaiement);

ALTER TABLE Payer_avec
	ADD CONSTRAINT Payer_avec_Client1_FK
	FOREIGN KEY (ID_Client)
	REFERENCES Client(ID_Client);

ALTER TABLE Commande
	ADD CONSTRAINT Commande_Facture0_FK
	FOREIGN KEY (ID_Facture)
	REFERENCES Facture(ID_Facture);

ALTER TABLE Commande 
	ADD CONSTRAINT Commande_Facture0_AK 
	UNIQUE (ID_Facture);

ALTER TABLE Facture
	ADD CONSTRAINT Facture_Commande0_FK
	FOREIGN KEY (ID_Commande_Emettre)
	REFERENCES Commande(ID_Commande);

ALTER TABLE Facture
	ADD CONSTRAINT Facture_Adresse1_FK
	FOREIGN KEY (ID_Adresse,ID_Adresse_2)
	REFERENCES Adresse(ID_Adresse,ID_Adresse);

ALTER TABLE Facture 
	ADD CONSTRAINT Facture_Commande0_AK 
	UNIQUE (ID_Commande_Emettre);

ALTER TABLE Former_une_CommandeLigne
	ADD CONSTRAINT Former_une_CommandeLigne_Commande0_FK
	FOREIGN KEY (ID_Commande)
	REFERENCES Commande(ID_Commande);

ALTER TABLE Former_une_CommandeLigne
	ADD CONSTRAINT Former_une_CommandeLigne_Article1_FK
	FOREIGN KEY (ID_Article)
	REFERENCES Article(ID_Article);

ALTER TABLE Gerer
	ADD CONSTRAINT Gerer_Commande0_FK
	FOREIGN KEY (ID_Commande)
	REFERENCES Commande(ID_Commande);

ALTER TABLE Gerer
	ADD CONSTRAINT Gerer_Personnel1_FK
	FOREIGN KEY (ID_Personnel)
	REFERENCES Personnel(ID_Personnel);

ALTER TABLE Commander
	ADD CONSTRAINT Commander_Client0_FK
	FOREIGN KEY (ID_Client)
	REFERENCES Client(ID_Client);

ALTER TABLE Commander
	ADD CONSTRAINT Commander_Commande1_FK
	FOREIGN KEY (ID_Commande)
	REFERENCES Commande(ID_Commande);
