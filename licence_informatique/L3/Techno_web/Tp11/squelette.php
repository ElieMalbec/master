<?php 
    //session_start();
    //include "./poemes/donnees.php"
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title></title>
    <style>
        .title {
            border : 2px solid grey;
            text-align : center;
            margin-bottom : 2px;
        }
    
    </style>
</head>
<body>
    <?php
        function printNothing(){
            ?>
                <p>Error in the URL</p>
                "AHAHAHAHA";
                <?php
        }

        function printNamePoeme($donnees){
        ?>
        <div class=title>
        <h1 class=titleH1>No poeme for you !</h1>
            <ul>
            <?php
            foreach($donnees as $key => $value){
                ?>
                <li><a href="index.php?poeme=<?= $key?>"><?=  $value["titre"]?></a></li>    
                <?php
            }
            ?>
            </ul>
        </div>
        <?php
        }

        function printAllInfos($key, $donnees){
            ?>
                <div class=title>
                    <h1 class=titleH1><?= $donnees[$key]["titre"] ?></h1>
                    <?php 
                        $name = $donnees[$key]["fragment"] . ".frg.html";
                        $file = file_get_contents("./poemes/textes/" . $name);
                        echo $file;
                    ?>
                <h2 class=titleH2><?= $donnees[$key]["auteur"] ?></h2>
                    <div>
                    <img src=<?= "./poemes/images/" . $donnees[$key]["image"]?> alt=<?= $donnees[$key]["auteur"]?>>
                    </div>
                </div>
            <?php
        } 
        
        function printNothingResearch(){
            ?>
                <div>
                    <p>
                        <a href=index.php?po>
                        Aucun poème ne correspond à votre recherche
                        </a>
                    </p>
                </div>
            <?php
        }

        function  printResearch($research, $donnees){
            foreach ($donnees as $key => $value){
                $name = $donnees[$key]["fragment"] . ".frg.html";
                $file = file_get_contents("./poemes/textes/" . $name);
                $find = strpos($file, $research);
                if ($find != false){
                    ?>
                        <div>
                            <p>
                                <a href="index.php?poeme=<?= $key?>"><?=  $value["titre"]?></a>
                            </p>
                        </div>
                    <?php
                }
            }
        }
    ?>
</body>
</html>