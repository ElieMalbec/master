<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

<?php

function print_infos($infos){
    ?>
    <div>
    <?php
        foreach($infos as $k => $v) {
            ?>
            <p><b><?= $k?></b> : <?= $v?></p>
            <?php
        }
    ?>
        <a href="galerie.php"><img src="<?php echo $infos['thumb_url']?>" alt=""></a>

    
    </div>
    <?php
}

require_once 'co.php';
$my_id = isset($_GET['id']) ? intval($_GET['id']) : -1;
if ($my_id != -1 && $my_id <= 108){
    $request = 'SELECT * FROM images WHERE ID = :id';
    $q = $bd->prepare($request);
    $q->execute(["id" => $my_id]); 
    $q->setFetchMode(PDO::FETCH_ASSOC);
    /*if (empty($q->fetch())){
        die("DIEEEEEEEEE");
    }*/
    
    print_infos($q->fetch());
}
else {
    echo "WHY DELETE THE ID IN THE URL MATE !!!";
}

/*
$count_request = 'SELECT * FROM images';
$query_count_request = $bd->query($count_request);
while ($ligne = $query_count_request->fetch()){
    print_infos($ligne);
}
*/
?>

</body>
</html>


