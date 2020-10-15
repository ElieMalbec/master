<?php
//session_name("exo-auth");
session_start();
include "comptes.php";
include "AuthenticationManager.php";


$am = new AuthenticationManager($comptes);
if ($am->isUserConnected()){
    
}

/*
if (isset($_POST["deco"])){
    session_destroy();
    header('Location: index.php');
    exit();
}
if (key_exists('login', $_POST) && key_exists('password', $_POST)){
    foreach ($comptes as $a => $b) {
        if (($_POST['login'] === $b["login"]) && (password_verify($_POST['password'], $b["password"]))) {
            //echo $b['login'] . " " . $b['password'];
            $_SESSION["user"] = $b;
            //var_dump($_SESSION);
        }
    }
}
*/
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
    <h1>Page de connexion/déconnexion</h1>
    <?= isset($_SESSION["user"]) ? $_SESSION["user"]["name"] : "";?>
    <?php
        if (isset($_SESSION["user"])){
            ?>
            <form method="POST">
                <input type="submit" value="se déconnecter" name="deco">
            </form>
            <?php
            
        } else {
    ?>
    <form action="" method="post">
        <label>Nom : <input type="text" name="login"></label>
        <label>Mot de passe : <input type="password" name="password" id=""></label>
        <input type="submit" value="se connecter">
    </form>
        <?php } ?>
    <ul>
        <li><a href="index.php">Page d'accueil</a></li>
        <li>Page de connexion/deconnexion</li>
        <li><a href="admin.php">Partie admin</a></li>
    </ul>
</body>
</html>



