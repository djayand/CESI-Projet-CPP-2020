-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le : jeu. 03 déc. 2020 à 14:01
-- Version du serveur :  8.0.21
-- Version de PHP : 7.3.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `bddc`
--

-- --------------------------------------------------------

--
-- Structure de la table `adresse`
--

DROP TABLE IF EXISTS `adresse`;
CREATE TABLE IF NOT EXISTS `adresse` (
  `ID_Adresse` int NOT NULL AUTO_INCREMENT,
  `Code_postal` int NOT NULL,
  `Rue` varchar(255) NOT NULL,
  `N_` int NOT NULL,
  `Ville` varchar(32) NOT NULL,
  `FonctionAdresse` int NOT NULL,
  `ID_Client` int NOT NULL,
  PRIMARY KEY (`ID_Adresse`),
  KEY `Adresse_Client0_FK` (`ID_Client`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `adresse`
--

INSERT INTO `adresse` (`ID_Adresse`, `Code_postal`, `Rue`, `N_`, `Ville`, `FonctionAdresse`, `ID_Client`) VALUES
(1, 88500, 'Mirecourt la cité', 158, 'Mirecourt', 1, 5),
(2, 88500, 'bvd', 178, 'Nancy', 1, 2),
(3, 88500, 'avenue', 48, 'Nancy', 1, 3),
(4, 88500, 'rue', 45, 'Nancy', 1, 4),
(5, 88500, 'Azerty', 19, 'Nancy', 1, 5);

-- --------------------------------------------------------

--
-- Structure de la table `article`
--

DROP TABLE IF EXISTS `article`;
CREATE TABLE IF NOT EXISTS `article` (
  `ID_Article` int NOT NULL AUTO_INCREMENT,
  `Nom_Article` varchar(64) NOT NULL,
  `Couleur_Article` varchar(64) NOT NULL,
  `Nature_Article` varchar(64) NOT NULL,
  `Prix_Unitaire_HT` float NOT NULL,
  `Prix_Unitaire_TTC` float NOT NULL,
  `Prix_Unitaire_Achat` float NOT NULL,
  `Montant_TVA_Unitaire` float NOT NULL,
  `Qte_Stock` int NOT NULL,
  `Seuil` int NOT NULL,
  PRIMARY KEY (`ID_Article`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `article`
--

INSERT INTO `article` (`ID_Article`, `Nom_Article`, `Couleur_Article`, `Nature_Article`, `Prix_Unitaire_HT`, `Prix_Unitaire_TTC`, `Prix_Unitaire_Achat`, `Montant_TVA_Unitaire`, `Qte_Stock`, `Seuil`) VALUES
(1, 'Processeur', 'Rouge', 'Info', 999.99, 1199.98, 600, 0.2, 1800, 10),
(2, 'Processeur', 'Bleu', 'Info', 899.99, 1079.98, 600, 0.2, 1800, 10),
(3, 'Carte Graphique', 'Rouge', 'Info', 199.99, 239.98, 100, 0.2, 1500, 5),
(4, 'Carte Graphique', 'Verte', 'Info', 299.99, 359.98, 100, 0.2, 178, 5),
(5, 'Carte Graphique', 'Or', 'Info', 4999.99, 5999.98, 3000, 0.2, 4, 1),
(6, 'Disque dur', 'Rouge', 'Info', 59.99, 71.98, 40, 0.2, 180, 15),
(7, 'Disque dur', 'Bleu', 'Info', 109.99, 131.98, 40, 0.2, 160, 15),
(8, 'Watercooling', 'Bleu', 'Info', 699.99, 839.98, 450, 0.2, 160, 10),
(9, 'Watercooling', 'Rouge et blanc', 'Info', 799.99, 959.98, 460, 0.2, 10, 1);

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

DROP TABLE IF EXISTS `client`;
CREATE TABLE IF NOT EXISTS `client` (
  `ID_Client` int NOT NULL AUTO_INCREMENT,
  `Nom_Client` varchar(64) NOT NULL,
  `Prenom_Client` varchar(64) NOT NULL,
  `Date_Naissance_Client` varchar(11) NOT NULL,
  `Date_1e_Commande` varchar(11) NOT NULL,
  `ID_Remise` int NOT NULL,
  PRIMARY KEY (`ID_Client`),
  KEY `Client_TauxRemise0_FK` (`ID_Remise`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `client`
--

INSERT INTO `client` (`ID_Client`, `Nom_Client`, `Prenom_Client`, `Date_Naissance_Client`, `Date_1e_Commande`, `ID_Remise`) VALUES
(1, 'Fetet', 'Ken', '09/05/1998', '05/11/2020', 1),
(2, 'Raggioli', 'Valentin', '09/05/1999', '04/11/2020', 2),
(3, 'remy', 'Emmanuel', '09/05/2000', '04/11/2020', 2),
(4, 'Félix', 'Joao', '09/05/1999', '05/11/2020', 3),
(5, 'Demaison', 'Djayan', '09/05/2002', '05/11/2020', 1);

-- --------------------------------------------------------

--
-- Structure de la table `commande`
--

DROP TABLE IF EXISTS `commande`;
CREATE TABLE IF NOT EXISTS `commande` (
  `ID_Commande` int NOT NULL AUTO_INCREMENT,
  `ID_Client` int NOT NULL,
  `Date_livraison_prevue` varchar(11) NOT NULL,
  `Date_emission_facture` varchar(11) NOT NULL,
  `Moyen_Paiement` varchar(32) NOT NULL,
  `Date_Paiement` varchar(11) NOT NULL,
  `Date_Reglement` varchar(11) NOT NULL,
  `Solde_Reglement` float NOT NULL,
  `Nombre_Total_Articles` int NOT NULL,
  `Montant_Remise` float NOT NULL,
  `Montant_TVA_Total` float NOT NULL,
  `Prix_Commande_HT` float NOT NULL,
  `Prix_Commande_TTC` float NOT NULL,
  `ID_Facture` int NOT NULL,
  PRIMARY KEY (`ID_Commande`),
  UNIQUE KEY `Commande_Facture0_AK` (`ID_Facture`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `commander`
--

DROP TABLE IF EXISTS `commander`;
CREATE TABLE IF NOT EXISTS `commander` (
  `ID_Client` int NOT NULL,
  `ID_Commande` int NOT NULL,
  PRIMARY KEY (`ID_Client`,`ID_Commande`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `facture`
--

DROP TABLE IF EXISTS `facture`;
CREATE TABLE IF NOT EXISTS `facture` (
  `ID_Facture` int NOT NULL AUTO_INCREMENT,
  `ID_Commande` varchar(18) NOT NULL,
  `Nom_Societe` varchar(32) NOT NULL,
  `Adresse_Societe` varchar(255) NOT NULL,
  `Numero_Service_Client` int NOT NULL,
  `ID_Commande_Emettre` int NOT NULL,
  `ID_Adresse` int NOT NULL,
  `ID_Adresse_2` int NOT NULL,
  PRIMARY KEY (`ID_Facture`),
  KEY `Facture_Commande0_FK` (`ID_Commande_Emettre`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `former_une_commandeligne`
--

DROP TABLE IF EXISTS `former_une_commandeligne`;
CREATE TABLE IF NOT EXISTS `former_une_commandeligne` (
  `ID_Commande` int NOT NULL,
  `ID_Article` int NOT NULL,
  `Quantite` int NOT NULL,
  PRIMARY KEY (`ID_Commande`,`ID_Article`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `gerer`
--

DROP TABLE IF EXISTS `gerer`;
CREATE TABLE IF NOT EXISTS `gerer` (
  `ID_Commande` int NOT NULL,
  `ID_Personnel` int NOT NULL,
  PRIMARY KEY (`ID_Commande`,`ID_Personnel`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `personnel`
--

DROP TABLE IF EXISTS `personnel`;
CREATE TABLE IF NOT EXISTS `personnel` (
  `ID_Personnel` int NOT NULL AUTO_INCREMENT,
  `Nom_Personnel` varchar(64) NOT NULL,
  `Prenom_Personnel` varchar(64) NOT NULL,
  `Date_Embauche` varchar(11) NOT NULL,
  `Adresse_Personnel` varchar(255) NOT NULL,
  PRIMARY KEY (`ID_Personnel`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `personnel`
--

INSERT INTO `personnel` (`ID_Personnel`, `Nom_Personnel`, `Prenom_Personnel`, `Date_Embauche`, `Adresse_Personnel`) VALUES
(1, 'Morata', 'Alvaro', '01/15/2020', 'Juve'),
(2, 'Llorente', 'Marcos', '11/03/2020', 'Anfield');

-- --------------------------------------------------------

--
-- Structure de la table `possedersuperieur`
--

DROP TABLE IF EXISTS `possedersuperieur`;
CREATE TABLE IF NOT EXISTS `possedersuperieur` (
  `ID_Personnel` int NOT NULL,
  `ID_Personnel_PossederSuperieur` int NOT NULL,
  PRIMARY KEY (`ID_Personnel`,`ID_Personnel_PossederSuperieur`),
  KEY `PossederSuperieur_Personnel1_FK` (`ID_Personnel_PossederSuperieur`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `possedersuperieur`
--

INSERT INTO `possedersuperieur` (`ID_Personnel`, `ID_Personnel_PossederSuperieur`) VALUES
(2, 1);

-- --------------------------------------------------------

--
-- Structure de la table `tauxremise`
--

DROP TABLE IF EXISTS `tauxremise`;
CREATE TABLE IF NOT EXISTS `tauxremise` (
  `ID_Remise` int NOT NULL AUTO_INCREMENT,
  `Taux_Remise` int NOT NULL,
  PRIMARY KEY (`ID_Remise`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `tauxremise`
--

INSERT INTO `tauxremise` (`ID_Remise`, `Taux_Remise`) VALUES
(1, 0),
(2, 5),
(3, 10),
(4, 15);

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `adresse`
--
ALTER TABLE `adresse`
  ADD CONSTRAINT `Adresse_Client0_FK` FOREIGN KEY (`ID_Client`) REFERENCES `client` (`ID_Client`);

--
-- Contraintes pour la table `client`
--
ALTER TABLE `client`
  ADD CONSTRAINT `Client_TauxRemise0_FK` FOREIGN KEY (`ID_Remise`) REFERENCES `tauxremise` (`ID_Remise`);

--
-- Contraintes pour la table `commande`
--
ALTER TABLE `commande`
  ADD CONSTRAINT `Commande_Facture0_FK` FOREIGN KEY (`ID_Facture`) REFERENCES `facture` (`ID_Facture`);

--
-- Contraintes pour la table `facture`
--
ALTER TABLE `facture`
  ADD CONSTRAINT `Facture_Commande0_FK` FOREIGN KEY (`ID_Commande_Emettre`) REFERENCES `commande` (`ID_Commande`);

--
-- Contraintes pour la table `possedersuperieur`
--
ALTER TABLE `possedersuperieur`
  ADD CONSTRAINT `PossederSuperieur_Personnel0_FK` FOREIGN KEY (`ID_Personnel`) REFERENCES `personnel` (`ID_Personnel`),
  ADD CONSTRAINT `PossederSuperieur_Personnel1_FK` FOREIGN KEY (`ID_Personnel_PossederSuperieur`) REFERENCES `personnel` (`ID_Personnel`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
