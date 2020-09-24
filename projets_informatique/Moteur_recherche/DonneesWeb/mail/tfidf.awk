BEGIN {
	# On enlève un argument du tableau des arguments en décrémentant le nombre d'arguments reçus en ligne de commande
	fileDF = ARGV[--ARGC]
	# Parcours de chaque ligne du fichier des df
	while ((getline < fileDF) > 0)
		df[$2] = $1
}
{
	# Tfidf(word, doc) = tf(word,doc) * log(nDoc/DF(word))
	print $1, $2 * log (3655 / df[$1])
}
