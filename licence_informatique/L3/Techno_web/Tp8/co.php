<?php

try {
    $bd = new PDO("mysql:host=mysql.info.unicaen.fr;port=3306;dbname=21805304_dev;charset=utf8", "21805304", "leiNahro2Uyae5oh");
    $bd->setAttribute(PDO::ATTR_EMULATE_PREPARES, FALSE);
} catch (Exception $e){
    die("STOP, GROS CON ELLE EXISTE PAS ISSOU");
}
$bd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

?>
