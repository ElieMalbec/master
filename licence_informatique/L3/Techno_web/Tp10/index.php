<?php
//session_name("exo-auth");
session_start();
include "comptes.php";

?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
<?php
if (isset($_SESSION["user"])){
    echo "<h1>Bienvenue, " . $_SESSION["user"]["name"] . "!</h1>";
}
else {
    echo "<h1>Bienvenue !</h1>";
}
?>
<p>Vous êtes sur la page d'accueil</p>
<ul>
    <li>Page d'accueil</li>
    <li><a href="connexion.php">Page de connexion/deconnexion</a></li>
    <li><a href="admin.php">Partie admin</a></li>
</ul>
</body>
</html>