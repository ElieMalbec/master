i=$(ls content | grep -v '\..*$' | wc -w)
echo "[INFO] Nombre de fichiers : $i"
echo "[INFO] Génération des tf"

for j in $(seq $i);
	do cat content/$j | tr [:upper:] [:lower:] | sed 's/[^a-z]/ /g' | sed 's/ /\n/g' | grep -v '^$' | sort | awk 'NR == 1 {mot = $1}{if (mot == $1) tf++; else {print mot, tf; mot = $1; tf = 1}} END {print mot, tf}' | sed 1d > content/$j.tf
done
