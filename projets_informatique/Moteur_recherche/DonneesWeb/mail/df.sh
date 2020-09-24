i=$(ls content | grep -v '\..*$' | wc -l)
echo "[INFO] Génération df.txt"
for j in $(seq $i); do
	cat content/$j | tr [:upper:] [:lower:] | sed 's/[^a-z]/ /g' | sed 's/ /\n/g' | sort | uniq | grep -v '^$' >> tmp.txt
done
cat tmp.txt | sort | uniq -c > df.txt
rm -f tmp.txt
