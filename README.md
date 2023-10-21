# Projet C++ A2 - 2020

## Dossier du projet orienté objet

### Présentation du projet

### Présentation de l'équipe
- atleticoporlavida -> Djayan
- kenftt -> Ken
- vraggioli -> Valentin

### Guide d’installation utilisateur : accès à WinForms

1.	Pour commencer téléchargez Visual Studio via ce lien (Attention ! VisualStudio Code incompatible) :
https://visualstudio.microsoft.com/fr/downloads/

2.	Au préalable avant de d’utiliser ce logiciel téléchargez ce composant individuel à partir de VisualStudio Installer (téléchargez une version ultérieure si disponible)
<a href="https://zupimages.net/viewer.php?id=20/49/um96.png"><img src="https://zupimages.net/up/20/49/um96.png" alt="" /></a>

3.	Lancer VisualStudio 
                       <a href="https://zupimages.net/viewer.php?id=20/49/mqvg.png"><img src="https://zupimages.net/up/20/49/mqvg.png" alt="" /></a>              


4.	Cliquer sur      <a href="https://zupimages.net/viewer.php?id=20/49/om0v.png"><img src="https://zupimages.net/up/20/49/om0v.png" alt="" /></a>


5.	Lancer ce type de projet      <a href="https://zupimages.net/viewer.php?id=20/49/u3yl.png"><img src="https://zupimages.net/up/20/49/u3yl.png" alt="" /></a>


 
6	.	Nommer votre projet sans espace attention ! (modifiez son emplacement si besoin) et cliquez sur « créer »
<a href="https://zupimages.net/viewer.php?id=20/49/ba93.png"><img src="https://zupimages.net/up/20/49/ba93.png" alt="" /></a>
  

7	Dans l’explorateur de solution :
 <a href="https://zupimages.net/viewer.php?id=20/49/k8en.png"><img src="https://zupimages.net/up/20/49/k8en.png" alt="" /></a>

Faites un clic droit sur « Références » puis cliquez sur « Ajouter une référence ». Une fenêtre semblable à celle-ci devrait s’ouvrir :
<a href="https://zupimages.net/viewer.php?id=20/49/1r2g.png"><img src="https://zupimages.net/up/20/49/1r2g.png" alt="" /></a>
 
 
8	.Dans « Framework » dans « Assemblys » sélectionnez puis cocher :
<a href="https://zupimages.net/viewer.php?id=20/49/suzj.png"><img src="https://zupimages.net/up/20/49/suzj.png" alt="" /></a>
Appuyez ensuite sur « ok »


9.	Faites un clic droit sur « fichier d’en-tête » situé dans encore une fois dans l’ « explorateur de solution » puis cliquez sur « ajouter » puis sur « nouvel élément ».
Une fenêtre semblable à celle-ci devrait s’ouvrir :
<a href="https://zupimages.net/viewer.php?id=20/49/s5mm.png"><img src="https://zupimages.net/up/20/49/s5mm.png" alt="" /></a>



10.Dans « Visual C++ » cliquez sur « CLR » puis sur « Windows Form » et enfin sur « Ajouter » (renommez le si besoin)
<a href="https://zupimages.net/viewer.php?id=20/49/exsy.png"><img src="https://zupimages.net/up/20/49/exsy.png" alt="" /></a>



11. Pas de crainte à avoir en ayant ce message d’erreur c’est tout à fait normal (c’est même la preuve que vous avez correctement suivi les étapes) : 
<a href="https://zupimages.net/viewer.php?id=20/49/kap7.png"><img src="https://zupimages.net/up/20/49/kap7.png" alt="" /></a>



Il vous faut juste le fermer en fermant votre fenêtre.h [Design].

12. Dans l’ « explorateur de solutions » déplacez le fichier.cpp dans « Fichiers sources »
<a href="https://zupimages.net/viewer.php?id=20/49/e0nr.png"><img src="https://zupimages.net/up/20/49/e0nr.png" alt="" /></a>


13.Copiez-collez ce code source dans votre fichier.cpp et renommez « testWin » par le nom de votre projet :
<!-- HTML generated using hilite.me --><div style="background: #ffffff; overflow:auto;width:auto;border:solid gray;border-width:.1em .1em .1em .8em;padding:.2em .6em;"><table><tr><td><pre style="margin: 0; line-height: 125%"> 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12</pre></td><td><pre style="margin: 0; line-height: 125%"><span style="color: #888888">//MyForm.cpp</span>
<span style="color: #557799">#include &quot;MyForm.h&quot;</span>
<span style="color: #008800; font-weight: bold">using</span> <span style="color: #008800; font-weight: bold">namespace</span> System;
<span style="color: #008800; font-weight: bold">using</span> <span style="color: #008800; font-weight: bold">namespace</span> System<span style="color: #333333">::</span>Windows<span style="color: #333333">::</span>Forms;
[STAThreadAttribute]
<span style="color: #333399; font-weight: bold">int</span> __clrcall WinMain(array<span style="color: #333333">&lt;</span>String<span style="color: #333333">^&gt;^</span> args )
{
Application<span style="color: #333333">::</span>EnableVisualStyles();
Application<span style="color: #333333">::</span>SetCompatibleTextRenderingDefault(<span style="color: #007020">false</span>);
testWin<span style="color: #333333">::</span>MyForm monFormulaire;<span style="color: #888888">//ATTENTION : ici testWin est le nom du projet. Vous devez l’adapter au nom de votre projet</span>
Application<span style="color: #333333">::</span>Run(<span style="color: #333333">%</span>monFormulaire);
}
</pre></td></tr></table></div>




14.Dans l « ’explorateur de solution », sélectionnez votre projet et ouvrez les propriétés du
projet en cliquant sur le pictogramme de la clé à molette, une fenêtre semblable à celle-ci va apparaître :
<a href="https://zupimages.net/viewer.php?id=20/49/erzo.png"><img src="https://zupimages.net/up/20/49/erzo.png" alt="" /></a>



15. Déroulez le menu « Editeur de lien » , cliquez sur avancé, renseignez « WinMain » dans « Point d’entrée ». 
Puis vérifiez que vous êtes en train de paramétrer le bon mode de compilation (debug ou release).
Enfin cliquez sur « Appliquer ».
<a href="https://zupimages.net/viewer.php?id=20/49/ixlk.png"><img src="https://zupimages.net/up/20/49/ixlk.png" alt="" /></a>
 
 
 
16.Cliquez sur « Système » toujours dans « éditeur de lien », dans « Sous-système » renseignez « Windows ». Puis vérifiez que vous êtes en train de paramétrer le bon mode de compilation (debug ou release). 
Enfin cliquez sur « Appliquer » puis sur « OK ».
<a href="https://zupimages.net/viewer.php?id=20/49/mq4o.png"><img src="https://zupimages.net/up/20/49/mq4o.png" alt="" /></a>



17.Enregistrez tout votre projet en cliquant sur  <a href="https://zupimages.net/viewer.php?id=20/49/d1lr.png"><img src="https://zupimages.net/up/20/49/d1lr.png" alt="" /></a>        dans la barre des tâches.



18.Fermez Visual Studio.
 
 
 
19.Lancez Visual Studio <a href="https://zupimages.net/viewer.php?id=20/49/mqvg.png"><img src="https://zupimages.net/up/20/49/mqvg.png" alt="" /></a>            puis ouvrez votre projet situé dans les « Eléments récents »
<a href="https://zupimages.net/viewer.php?id=20/49/5lrl.png"><img src="https://zupimages.net/up/20/49/5lrl.png" alt="" /></a>
 
 
20. Ouvrez le formulaire graphique en cliquant sur le fichier.h dans l’ « Explorateur de solutions » :
 <a href="https://zupimages.net/viewer.php?id=20/49/vqhw.png"><img src="https://zupimages.net/up/20/49/vqhw.png" alt="" /></a>



21. Faites des tests en glissant et en déposant par exemple une textBox et un button à partir de la boîte à outil (si elle n’apparait pas sur votre gauche saisissez CTRL + ALT + X) :
<a href="https://zupimages.net/viewer.php?id=20/49/794p.png"><img src="https://zupimages.net/up/20/49/794p.png" alt="" /></a>
 

22. Compilez et exécutez votre programme :
<a href="https://zupimages.net/viewer.php?id=20/49/9fw3.png"><img src="https://zupimages.net/up/20/49/9fw3.png" alt="" /></a>
Tout est bon !
