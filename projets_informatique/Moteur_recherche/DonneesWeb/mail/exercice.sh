
cd content
# Parcours de tous les fichies .tf
# Chaque mot du tf possède un nombre d'occurences dans le document,
# mais il est remplacé par le nom du document dans lequel il est.
for i in $(seq 3655); do cat $i.tf | sed "s/ .*/ $i/"; done |
	# Tri du résultat par mot puis par nom du document dans lequel il est
	sort -k1,1 -k2,2n |
	# Pour chaque ligne de la forme : mot nomDoc
	# On donne pour chaque mot l'ensemble des documents dans lequel on le trouve
	awk '{if ($1 != last){if (last!="")print last, tab[last]; last = $1; tab[last] = $2} else tab[last] = tab[last] " " $2}END{print last, tab[last]}' > index


# Pour chaque mot de notre requete
for i in $(cat ../query); do
	# Récupération de la ligne qui contient le mot dans l'index avec tous les documents dans lesquels on trouve ce mot
	grep "^$i " index |
		# Puis premier sed pour retirer le mot
		# Second sed pour mettre un nom de document par ligne
		# Et enfin tri puis redirection dans fichier mot.index
		sed 's/[^ ]* //; s/ /\n/g' | sort > $i.index;
done;
# Premier mot de la requete, mot.index copié en fichier answer
cp $(head -1 ../query).index answer;
# Pour tous les autres mots de la requete
# comm = compare two sorted files line by line
# comm -1 -2 : show lines that appear in both files
# Comparaison des lignes (documents de la requete du premier mot) avec ceux des mots suivant
# Les documents trouvés dans les deux sont placés dans un fichier tmp, et tmp devient answer la réponse
for i in $(sed 1d ../query); do comm -1 -2 answer $i.index > tmp; mv tmp answer; done;


# Pour tous les mots de la requete
# On récupère le df du mot dans le fichier df.txt
# Puis le awk affiche pour chaque mot le tfidf de ce dernier
# Puis le awk affiche uniquement les valeurs des tfidf redirigé dans le fichier query.tfidf
for i in $(cat ../query); do grep " $i$" ../df.txt; done | awk '{print $2, log(3655/$1)}' | awk '{print $2}' > query.tfidf


# Pour chaque document de la réponse
# On met avec son nom:
for i in $(sort answer); do
	echo -n "$i ";
	# Pour chaque mot de la requete, on récupère la valeur du tfidf du mot dans chaque document de la réponse, et on imprime uniquement la valeur
	for j in $(cat ../query); do
		grep "^$j " $i.tfidf | awk '{print $2}';
	# Le tout est mis dans le fichier doc.pert pour pertinence
	done > $i.pert;

	# paste -d" " : merge lines of files with separator " "
	# Paste colle le contenu de chaque ligne de query.tfidf avec la pertinence des mots dans le doc i
	# Le awk permet de faire les normes des vecteurs de pertinence de mots
	# Le print final donne le document et la pertinence qu'il à avec la requete : 1 très forte
	paste -d" " query.tfidf $i.pert | awk '{sum+=$1*$2;norm1+=$1*$1;norm2+=$2*$2}END{print sum/sqrt(norm1)/sqrt(norm2)}';
	rm -f $i.pert;
done
cd ..
