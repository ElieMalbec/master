<?php

$frgHTML = file_get_contents('fragmentHTML.txt');
var_export($frgHTML);


include 'fragmentPHP.txt';
ob_start();
//$frgPHP = file_get_contents('fragmentPHP.txt');
//var_export($frgPHP);
$var = ob_get_clean();
echo "-------------var : " . $var;