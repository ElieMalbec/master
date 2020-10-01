<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
    td{
        border:1px solid red;
    }
    tr:nth-child(odd) td:nth-child(odd){
        background-color: darksalmon;
    }
    tr:nth-child(odd) td:nth-child(even){
        background-color: yellow;
    }
    tr:nth-child(even) td:nth-child(odd){
        background-color: yellow;
    }
    tr:nth-child(even) td:nth-child(even){
        background-color: darksalmon;
    }
    </style>
</head>
<body>

<?php
function print_table($borne_sup){
    echo "<table>";

    for ($row = 1; $row <= $borne_sup; $row++){
        echo "<tr >";
        for ($col = 1; $col <= $borne_sup; $col++){
            echo "<td>";
            echo $col * $row;
            echo "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
}


if (isset($_GET['borne'])){
    $borne = intval($_GET['borne']);
    if ($borne <= 0){
        echo "Erreur : borne nulle";
    }
    else {
        if ($borne >= 101){
            echo "Erreur : borne trop grande";
        }
        else {
            print_table(intval($borne));
        }
        
    }
}
else {
    echo "Erreur : borne vide";
    //print_table(15);
}

?>

</body>
</html>