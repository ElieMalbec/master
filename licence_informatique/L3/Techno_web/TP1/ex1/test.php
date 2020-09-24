<?php

//1
for ($i = 1234; $i < 5679; $i++){
    echo $i . "\n";
}


//2
$tab = array();
for ($i = 0; $i < 100; $i++){
    $tab[] = 3*$i+2;
}
for ($i = 0; $i < 100; $i++){
    echo $tab[$i] . "\n";
}

//3
foreach ($tab as &$value){
    echo $value . "\n";
}



function moyenne($tab){
    $sum = 0;
    $cpt = 0;
    foreach ($tab as &$value){
        $sum += $value;
        $cpt++;
    }
    $sum = $sum / $cpt;
    return $sum;
    // array_sum($tab) / count($tab);
}

echo moyenne($tab) . "\n";
