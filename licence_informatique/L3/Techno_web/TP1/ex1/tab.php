<?php

//1
$persos = array("Jean-Luc" => 15.3, 
            "Michael Kork" => 12.7, 
            "JPP" => 7.9, 
            "Augustin le gustin" => 17.7);
//2
foreach ($persos as $key => $value){
    echo $key . " mesure " . $value . " cm\n";
}

//3
function minimum($tab){
    $min = 999999;
    foreach($tab as $key => $value){
        if ($value < $min){
            $min = $value;
        }
    }
    return $min;
    //min($tab)
}

echo "The min is : " . minimum($persos) . "\n";
//echo min($persos);

//4
function minimum2($tab , $tf=false){
    $min = 999999;
    $min_key;
    foreach($tab as $key => $value){
        if ($value < $min){
            $min = $value;
            $min_key = $key;
        }
    }
    if (!$tf){
        return $min;
    }
    else {
        return $min_key;
    }
    //array_search(min(array_values($tab)), $tab);
}

$b = true;
echo minimum2($persos, $b) . "\n";

//5
function min_and_max($tab){
    return $min_max = array(min($tab), max($tab));
}

foreach(min_and_max($persos) as $value){
    echo $value . "\n";
} 
 
