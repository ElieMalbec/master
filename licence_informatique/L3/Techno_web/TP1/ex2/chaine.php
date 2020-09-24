<?php
//1
$nom = readline("Nom : ");
$prenom = readline("Prenom : ");

echo "une phrase de bienvenue personnalisée ! " . $nom . " " . $prenom . ".\n";
//2
echo strlen($prenom) . "\n";// compte pas les emojis
echo iconv_strlen($prenom) . "\n";

//3
if ($prenom . $nom == 'JeanValjean') {//comparaison avec + sur strings = 0
    echo "Surprise !\n";
}

//4
//echo substr($string, start, length);
$findme = 'a';
$pos = strpos(strtolower($nom), $findme);

if ($pos === false) {
    echo "La chaîne '$findme' ne se trouve pas dans la chaîne '$nom'\n";
} else {
    echo "La chaine '$findme' a été trouvée dans la chaîne '$nom'";
    echo " et débute à la position $pos\n";
}

//5 Decoupe une chaine suivant un délimiteur et renvoie les morceaux
$exp = explode(' ', $nom);
echo $exp[2] . "\n";

//6 Decoupe un tableau et renvoie la concat de ces chaines
$my_arr = array("Hello", "World");
$imp = implode('~', $my_arr);
echo $imp . "\n";


//------
$first_input = readline("first : ");
$second_input = readline("second : ");

$exp_first = explode(' ', $first_input);
$exp_second = explode(' ',$second_input);

$my_arr2 = array();
foreach($exp_first as $word){
    $my_arr2[] = $word;
}
foreach($exp_second as $word){
    $my_arr2[] = $word;
}


echo implode($my_arr2);