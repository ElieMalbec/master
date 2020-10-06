<?php 
setcookie('id', 'Jean-luc', time()+30);
setcookie('date', date('l jS \of F Y h:i:s A'), time() + 30);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .cookie {
            border : solid 1px grey;
            border-radius : 10%;
            
        }
    </style>
</head>
<body>

<?php
    
    if (key_exists('id', $_COOKIE)){
        ?>
        <div class=cookie> 
        <h1>Cookie</h1>
        <?php
        echo "<p>" . date('l jS \of F Y h:i:s A') . "</p>" . "<br/>";
        echo "<p>" . htmlspecialchars($_COOKIE['id']) . " " . htmlspecialchars($_COOKIE['date']) . "</p>"; //html special pour éviter script dans les cookies

        ?>
        </div>
        <?php
    }
    else {
        echo date('l jS \of F Y h:i:s A') . "<br/>";
    }
?>

</body>
</html>