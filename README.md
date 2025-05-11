# ProjetInformatique
## 📌 Description

Ce projet est un petit jeu en C mettant en scène **deux équipes de trois personnages** s'affrontant dans un système de **combat au tour par tour**, basé sur la **vitesse d'action (vitact)**.

Chaque personnage possède :
- une vitesse de base (`vit`)
- une vitesse accumulée (`vitact`)
- des attaques ou capacités (à développer)

Le système de tour est inspiré de jeux comme Final Fantasy X ou Darkest Dungeon : plus un personnage est rapide, plus il agit souvent.

## 🛠️ Fonctionnalités principales

- Calcul dynamique du prochain attaquant selon la vitesse accumulée.
- Gestion de deux équipes (`Equipe`), chacune composée de trois personnages (`Perso`).
- Système de mise à jour de la vitesse à chaque tour.

## 📁 Structure des fichiers

- `main.c` — point d'entrée du programme, logique principale de la boucle de combat.
- `combat.c` — contient la logique de calcul de la vitesse et du choix de l’attaquant.
- `perso.h` — définitions des structures `Perso` et `Equipe`.
- `Makefile` — (optionnel) pour compiler facilement le programme.

## ▶️ Compilation

Utilise `gcc` pour compiler le projet :

```bash
gcc -o combat main.c combat.c
