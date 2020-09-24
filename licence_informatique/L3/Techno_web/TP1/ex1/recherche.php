
<?php
function contient_toto($tab) {
    if (array_search('toto', $tab) == false) {
        echo "Le tableau ne contient pas toto\n";
    } else {
        echo "Le tableau contient toto !!\n";
    }
}

$x = [ 'titi', 'toto', 'tutu' ];
contient_toto($x);
$y = [ 'tutu', 'titi', 'tete' ];
contient_toto($y);
$z = [ 'toto', 'titi', 'tutu' ];
contient_toto($z);
$t = [ 'titi', 'tutu', 0  ];
contient_toto($t);