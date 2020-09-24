<?php

$tab = array(3,12,15,25,29);
$persos = array(3,12,15,25,29);

print_r($tab);
var_dump($tab);
var_export($tab);

echo "print_r()\n";
print_r($persos);
echo "var_dump()\n";
var_dump($persos);
echo "var_export()\n";
var_export($persos);

echo "\n\n\n";

echo "\nasort: \n";
asort($persos);
var_export($persos);

echo "\narsort: \n";
arsort($persos);
var_export($persos);

echo "\nksort: \n";
ksort($persos);
var_export($persos);

echo "\nkrsort: \n";
krsort($persos);
var_export($persos);

echo "\nsort: \n";
sort($persos);
var_export($persos);

echo "\nrsort: \n";
rsort($persos);
var_export($persos);

echo "\nshuffle: \n";
shuffle($persos);
var_export($persos);

