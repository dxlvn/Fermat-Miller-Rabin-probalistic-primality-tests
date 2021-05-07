########## Utilisation du Makefile #########

Par défaut, k = 40, n = 2^4423 - 1

Pour lancer le test de Fermat : make fermat

Pour lancer le test de Miller-Rabin: make miller

Pour supprimer les fichiers générés : make clean

Une fois les exécutables générés, vous pouvez choisir le nombre à tester et le nombre de répétitions.
Il suffit d'entrer dans le terminal: ./Fermat k n ou ./Miller_Rabin k n , avec k le nombre de répétitions et n le nombre à tester.