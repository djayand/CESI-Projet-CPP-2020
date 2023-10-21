# Projet C++ A2 - 2020

## Dossier du projet orienté objet

### Présentation du projet

### Présentation de l'équipe
- **atleticoporlavida** -> Djayan
- **kenftt** -> Ken
- **vraggioli** -> Valentin

### Guide d’installation utilisateur : accès à WinForms

1. Pour commencer, téléchargez **Visual Studio** via ce [lien](https://visualstudio.microsoft.com/fr/downloads/). Attention ! VisualStudio Code est incompatible.

2. Au préalable, avant d’utiliser ce logiciel, téléchargez ce composant individuel à partir de VisualStudio Installer (téléchargez une version ultérieure si disponible):
   ![composant](https://zupimages.net/up/20/49/um96.png)

3. Lancez **VisualStudio**:
   ![VisualStudio](https://zupimages.net/up/20/49/mqvg.png)

4. Cliquez sur:
   ![etape4](https://zupimages.net/up/20/49/om0v.png)

5. Lancez ce type de projet:
   ![etape5](https://zupimages.net/up/20/49/u3yl.png)

6. Nommez votre projet sans espace (modifiez son emplacement si besoin) et cliquez sur « créer »:
   ![etape6](https://zupimages.net/up/20/49/ba93.png)

7. Dans l’explorateur de solution, faites un clic droit sur « Références » puis cliquez sur « Ajouter une référence »:
   ![etape7](https://zupimages.net/up/20/49/k8en.png)

   Une fenêtre semblable à celle-ci devrait s’ouvrir:
   ![fenêtre](https://zupimages.net/up/20/49/1r2g.png)

8. Dans « Framework » dans « Assemblys », sélectionnez puis cochez:
   ![etape8](https://zupimages.net/up/20/49/suzj.png)

   Appuyez ensuite sur « ok ».

9. Dans l’ « explorateur de solution », faites un clic droit sur « fichier d’en-tête » puis cliquez sur « ajouter » puis sur « nouvel élément »:
   ![etape9](https://zupimages.net/up/20/49/s5mm.png)

10. Dans « Visual C++ », cliquez sur « CLR » puis sur « Windows Form » et enfin sur « Ajouter »:
    ![etape10](https://zupimages.net/up/20/49/exsy.png)

11. Pas de crainte à avoir en voyant ce message d’erreur, c’est tout à fait normal:
    ![etape11](https://zupimages.net/up/20/49/kap7.png)

    Fermez simplement le fenêtre.h [Design].

12. Dans l’ « explorateur de solutions », déplacez le fichier.cpp dans « Fichiers sources »:
    ![etape12](https://zupimages.net/up/20/49/e0nr.png)

13. Copiez-collez ce code source dans votre fichier.cpp et renommez « testWin » par le nom de votre projet:

    ```cpp
    //MyForm.cpp
    #include "MyForm.h"
    using namespace System;
    using namespace System::Windows::Forms;

    [STAThreadAttribute]
    int __clrcall WinMain(array<String^>^ args )
    {
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);
        testWin::MyForm monFormulaire; //ATTENTION : ici testWin est le nom du projet. Vous devez l’adapter au nom de votre projet
        Application::Run(%monFormulaire);
    }
    ```

14. Dans l’ « explorateur de solutions », sélectionnez votre projet et ouvrez les propriétés avec le pictogramme de la clé à molette:
    ![etape14](https://zupimages.net/up/20/49/erzo.png)

15. Dans le menu « Editeur de lien », cliquez sur avancé, renseignez « WinMain » dans « Point d’entrée »:
    ![etape15](https://zupimages.net/up/20/49/ixlk.png)

16. Cliquez sur « Système » toujours dans « éditeur de lien », dans « Sous-système » renseignez « Windows »:
    ![etape16](https://zupimages.net/up/20/49/mq4o.png)

17. Enregistrez tout votre projet:
    ![etape17](https://zupimages.net/up/20/49/d1lr.png)

18. Fermez Visual Studio.

19. Lancez **Visual Studio** et ouvrez votre projet situé dans les « Eléments récents »:
    ![etape19a](https://zupimages.net/up/20/49/mqvg.png)
    ![etape19b](https://zupimages.net/up/20/49/5lrl.png)

20. Ouvrez le formulaire graphique en cliquant sur le fichier.h dans l’ « Explorateur de solutions »:
    ![etape20](https://zupimages.net/up/20/49/vqhw.png)

21. Testez en glissant et en déposant, par exemple, une textBox et un button à partir de la boîte à outils:
    ![etape21](https://zupimages.net/up/20/49/794p.png)

22. Compilez et exécutez votre programme:
    ![etape22](https://zupimages.net/up/20/49/9fw3.png)
