<?php 

if (key_exists("theme", $_POST)){
    if ($_POST["theme"] === "clair"){
        setcookie("theme", "clair");
    }
    else {
        setcookie("theme", "sombre");
    }
}

if (key_exists("theme", $_COOKIE) && $_COOKIE["theme"] === "sombre"){
    $_POST["theme"] = "sombre";
    echo "AAAAAAA";
}
else if (key_exists("theme", $_COOKIE) && $_COOKIE["theme"] === "clair"){
    $_POST["theme"] = "clair";
    echo "BBBBBBB";
}

//var_dump($_POST);

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ex3</title>
    <link rel="stylesheet" href="<?php echo $_POST['theme']?>.css" type="text/css">
</head>
<body>
    <h1>Titre</h1>

    <form action="" method="post">
        <label for="">Clair </label>
        <input type="submit" name="theme" value="clair"> <br/>
        <label for="">Sombre</label>
        <input type="submit" name="theme" value="sombre">
    </form>
</body>
</html>

