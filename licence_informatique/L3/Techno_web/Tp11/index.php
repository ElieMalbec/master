<?php 
    session_start();
    include "./poemes/donnees.php";
    include "./squelette.php";

    if (isset($_GET["poeme"])){
        if (key_exists($_GET["poeme"], $donnees)){
            printAllInfos($_GET["poeme"], $donnees);
        }
        else {
            printNothing();
        }
    }
    else  {
        printNamePoeme($donnees);
    }

    if (isset($_GET["recherche"])){
        printResearch($_GET["recherche"], $donnees);
    }
    else {
        printNothingResearch();
    }
