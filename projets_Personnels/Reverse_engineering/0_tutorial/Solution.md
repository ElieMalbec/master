Problem is this web page : https://medium.com/@jacob16682/reverse-engineering-with-radare2-part-2-83b71df7ffe4

we will use radare2 to reverse engineer that file


En utilisant ```rabin2 -I crackme``` nous pouvons voir que c'est un fichier ELF, écrit en C sous linux avec une architecture x86.

En faisant ```rabin2 -zqq crackme```, nous pouvons voir plusieurs chaînes de caractères  : *Quel est le mot de passe*, *quel est le second mot de passe*, *quel est el troisième mot de passe ?*,*Congratulations* et *You failed*.
Il va nous falloir toruver plusieurs mots de passe.

nous lancons radare2 : ```r2 crackme```.
Nous écrivons ```aaa```
Nous écrivons : ```s main``` pour trouver le main
puis nous lancons : ```VV``` pour visualiser le programme

1er mot de passe  = radare2
2ème mot de passe = utilise la fonction atoi-->donc doit etre un nombre , donc en regardant le cmp on voit ```0xf```, c'est surement notre nombre.
3ème mot de passe = pareil un autre atoi, donc ```0x539``` en regardant le cmp

Nous obtenons le flag ! 



