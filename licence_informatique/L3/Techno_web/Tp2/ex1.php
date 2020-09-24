<?php

//1 telecharger
//2 Comprendre comment le csv est organisé
//3 afficher ligne par ligne
$file = "./dpt2018.csv";

$data = [];
$fd = fopen($file, "r"); //open file in read only
$line = fgets($fd, 60); // get 60 char of the line
while ($line = fgets($fd, 60)){
    $split = explode(';', $line);//split the data
    $data[] = [
            "sexe" => $split [0],
            "prenom" => $split [1],
            "annee" => $split [2],
            "departement" => $split [3],
            "nombre" => $split [4],
    ];
}

//4
echo "nombre de lignes : " . count($data) . "\n";
//print_r($data); 
//5
$count_children = 0;
$count_children_14 = 0;
$david = 0;
$zeinab_2012 = 0;
foreach ($data as $line => $value){
    $count_children += (int)$value["nombre"];
    
    if ($value["departement"] === "14"){
        $count_children_14 += (int) $value["nombre"];
    }

    if ($value["prenom"] == "DAVID"){
        $david += (int) $value["nombre"];
    }

    if ($value["prenom"] == "ZEINAB" && $value["annee"] === "2012"){
        $zeinab_2012 += (int) $value["nombre"];
    }
}
echo "Children born in FRANCE : " . $count_children . "\n";
echo "Children born in Calvados : " . $count_children_14 . "\n";
echo "Children born with David : " . $david . "\n";
echo "Children born with Zeinab in 2012 : " . $zeinab_2012 . "\n";

$min = 0;
$name;
foreach ($data as $line => $value){
    if ($value["sexe"] === "2" && $value["departement"] === "50" && $value["annee"] === "1978"){
      if ($value["nombre"] > $min){
          $min = $value["nombre"];
          $name = $value["prenom"];
      }  
    }
}
echo "prénom féminin le plus fréquent dans la Manche (50) en 1978 : " . $min . " " . $name ."\n";


$min = 0;
$name;
foreach ($data as $line => $value){
    if ($value["sexe"] === "2" && $value["annee"] === "1996"){
      if ($value["nombre"] > $min){
          $min = $value["nombre"];
          $name = $value["prenom"];
      }  
    }
}
echo "prénom féminin le plus fréquent dans la France en 1996 : " . $min . " " . $name ."\n";


$min = 0;
$name;
foreach ($data as $line => $value){
    if ((int) $value["annee"] >= 1978 && (int) $value["annee"] <= 1996){
      if ($value["nombre"] > $min){
          $min = $value["nombre"];
          $name = $value["prenom"];
      }  
    }
}
echo "prénom le plus fréquent entre 1978 et 1996 : " . $min . " " . $name ."\n";

//5i
$min = 0;
$name;
foreach ($data as $line => $value){
    if ($value["prenom"][0] === "A"  && substr($value["prenom"], -1) === "Z"){
        $min += (int)$value["nombre"];
    }
}
echo "Nom A ou Z : " . $min ."\n";


//5k
$min = 0;
$arr_of_names = [];
foreach ($data as $line => $value){
    if (!(in_array($value["prenom"], $arr_of_names, true))){
       $arr_of_names [] = $value["prenom"];
       $min++;
    }
}
echo "prenom differents en France : " . $min ."\n";

//5j
$min = 0;
foreach ($data as $line => $value){
    if ((int) $value["annee"] >= 1978 && (int) $value["annee"] <= 1996 && $value["departement"] === "971"){
        $min += (int) $value["nombre"];
    }
}
echo "Naissance en 971 : " . $min ."\n";





fclose($fd);
