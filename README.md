# ProjetInformatique
## 📌 Description

Ce projet est un petit jeu en C mettant en scène **deux équipes de trois personnages** s'affrontant dans un système de **combat au tour par tour**, basé sur la **vitesse d'action (vitact)**.

Chaque personnage possède des statistiques personnalisées.

Le système de tour est inspiré du jeu raid  : plus un personnage est rapide, plus il agit souvent.

## 🛠️ Fonctionnalités principales

- Calcul dynamique du prochain attaquant selon la vitesse accumulée.
- Gestion de deux équipes (`Equipe`), chacune composée de trois personnages (`Perso`).
- Système de mise à jour de la vitesse à chaque tour.

## 📁 Structure des fichiers

- `main.c` — point d'entrée du programme, logique principale de la boucle de combat.
- `foncions.c` — contient la logique de calcul de la vitesse et du choix de l’attaquant.
- `modes.c` — boucles permettant de faire fonctionner le mode solo.
- `capacites.c` — contient la logique des différentes capacités des personnages.
- `structures.h` — contient les structures du programme.

## ▶️ Compilation

Utilise `gcc` pour compiler le projet :

```bash
gcc -o combat main.c combat.c -lm
