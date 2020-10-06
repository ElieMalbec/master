<?php
    session_name("Jacques");
    session_start();
    $nb;
    
    if (key_exists("lol", $_POST)){
        session_destroy();
        header('Location: ' . basename(__FILE__)); // pour éviter de renvoyer les données
    }
    var_dump($_POST);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .beauty {
            background: rgb(250,42,217);
            background: linear-gradient(90deg, rgba(250,42,217,1) 0%, rgba(227,70,23,1) 48%, rgba(0,212,255,1) 91%);
            height : 250px;
        }
        .funny {
            text-align : center;
        }
        .fun {
            text-align : right;
            border : 5px dashed red;
        }
        .but {
            height : 50px;
            border-radius: 25%;
        }
    </style>
</head>
<body>
<?php
if (key_exists('nom', $_SESSION) && key_exists('nb', $_SESSION) && key_exists('date', $_SESSION)){
    $_SESSION['nb'] = intval($_SESSION['nb']) + 1;
        ?>

        <div class=beauty>
            <?php
                echo "<p class=\"funny\"> C'est la " . $_SESSION["nb"] . " fois que vous venez M. " . $_SESSION["nom"] . " a " . $_SESSION['date'] . "</p>";
            ?>
        </div>

        <?php
}
else {
    $nb = 1;
    
    $_SESSION['nb'] = $nb; //PHPSESSID nom de la session ainsi qu'une nouvelle valeur à chaque session
    $_SESSION['nom'] = "Jacques";
    $_SESSION['date'] = date('l jS \of F Y h:i:s A');
    
    echo "<p class=\"fun\"> C'est la " . $_SESSION["nb"] . " fois que vous venez M. " . $_SESSION["nom"] . " a " . $_SESSION['date'] . "</p>";
}


?>
<form method="post">
<input type="submit" name="lol">
</form>




</body>
</html>