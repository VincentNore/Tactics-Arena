Projet en C : Tactics Arena

by EL KANDOUSSI Adnan
   COLIN Kévin
   NORE Vincent
   JOLLIET Corentin

Rapide description:

Tactics Arena  est un jeu de stratégie tour par tour virtuel ou l'on joue en duel programmé en C. Son concept est proche de celui des échecs, mais il incorpore une certaine variété de pièces, ainsi qu'une part de hasard (ex: blocage de coup, les pièces disposent d'un certain nombre de vie, attaque, armure, blocage).

Règles du jeu:

Le jeu se joue avec 2 joueurs (Réels ou un joueur Réel et une IA) sur un plateau de jeu carrée de dimension NxN (N valant 11 par défaut).
Chaque joueur possède sa propre armée de n pions et chaque pion possède ses propres caractéristiques.
Les joueurs peuvent déplacer leurs pions, réfléchir à leur stratégie, restaurer la santé et/l'énergie de leurs pions et/attaquer les pions adverses à leur portée.

Les attaques sont divisées en 2 catégories relativement simples :
-Les attaques physiques reposant sur la force du pion attaquant.
-Les attaques magiques reposant sur l'énergie magique (ici mana) du pion attaquant.

Les déplacements sont linéaires avec possibilité de changer de direction mais il leur est impossible de revenir en arrière.
