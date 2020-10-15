<?php
session_start();
include "comptes.php";
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

<?php


if (isset($_SESSION["user"]) && ($_SESSION["user"]["status"] === "admin")){
    echo "<h1>Bienvenue dans my admin, " . $_SESSION["user"]["name"] . "<h1>";
}
else {
    echo "<h1>You are not root, admin page not for your eyes<h1>";
}
?>

<a href="index.php">Accueil</a>
</body>
</html>