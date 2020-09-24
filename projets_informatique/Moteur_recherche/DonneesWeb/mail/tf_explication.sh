#!/bin/bash

# Lecture du fichier
cat 1.txt

# Mise en forme des majuscules en minuscules
tr [:upper:] [:lower:]

# Substitution de tous les caractères qui ne sont pas des lettres par des espaces
sed 's/[^a-z]/ /g'

# Substitution des espaces par des sauts de ligne
sed 's/ /\n/g'

# On retire les lignes vides
grep -v '^$'
sed '/^$/d'
awk 'NF!=0{print}'

# On tri les entrées de mots
sort

# On trouve tous les mots uniques
uniq
# uniq -c donne le nombre d'occurences de chaque mot
# Mais avec un programme awk c'est :

# Permet de compter le nombre d'occurences de chaque mot dans une entrée triée
awk 'NR ==1 {mot = $1}{if (mot == $1) tf++; else {print mot, tf; mot = $1; tf = 1}} END {print mot, tf}'

# Aussi équivalent à
awk '{if (mot == $1) tf++; else {print mot, tf; mot = $1; tf = 1}} END {print mot, tf}' | sed 1d

# Commande complète pour calculer le tf des mots dans un document
cat 1.txt | tr [:upper:] [:lower:] | sed 's/[^a-z]/ /g' | sed 's/ /\n/g' | grep -v '^$' | sort | uniq | awk 'NR ==1 {mot = $1}{if (mot == $1) tf++; else {print mot, tf; mot = $1; tf = 1}} END {print mot, tf}' > 1.tf

# Boucle sur tous les fichiers pour générer les tf
time for i in $(seq 3650); do cat $i | tr [:upper:] [:lower:] | sed 's/[^a-z]/ /g' | sed 's/ /\n/g' | grep -v '^$' | sort | awk '{if (mot == $1) tf++; else {print mot, tf; mot = $1; tf = 1}} END {print mot, tf}' | sed 1d > $i.tf ; done
