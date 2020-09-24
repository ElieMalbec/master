i=$(ls content | grep -v '\..*$' | wc -l)
[ -f content/1.tf ] && k=$(ls content/*.tf | wc -l) || k=0
test $i = $k || sh tf.sh
[ -f df.txt ] || sh df.sh

echo "[INFO] Génération des tfidf"
for j in $(seq $i); do
	awk -f tfidf.awk content/$j.tf df.txt  | sort -k 2,2nr > content/$j.tfidf
done
