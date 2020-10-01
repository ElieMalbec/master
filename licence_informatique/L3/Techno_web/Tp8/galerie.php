<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .images{
            width: 200px;
            border: 1px dashed black;
            text-align: center;
            padding-top: 15px;
            background-color : lightblue;
        }
        .images img{
            display : block;
            margin: 0 auto;

        }
        body {
            display: flex;
            flex-wrap : wrap;
            gap: 5px;
            background-color : azure;
        }
    </style>
</head>
<body>
    
<?php

function print_titles($query){
    ?>
    <div class="images">
        <p><?php echo $query['title'];?></p>
        <a href="image.php?id=<?php echo $query['id']?>">
            <img src="<?php echo $query['thumb_url'];?>" alt="">
        </a>
    </div>
        
    <?php
}

require_once 'co.php';
$var = 'SELECT * FROM images';
$data = [];

if (isset($_GET['order']) && $_GET['order'] === 'chrono'){
    $var .= " ORDER BY creation_date ASC";
}
else if (isset($_GET['order']) && $_GET['order'] === '!chrono'){
    $var .= " ORDER BY creation_date DESC";
}

if (isset($_GET['order']) && $_GET['order'] === 'alpha'){
    $var .= " ORDER BY title ASC";
}

if (isset($_GET['order']) && $_GET['order'] === 'auteur'){
    $var .= " ORDER BY author_name";
}

if (isset($_GET['size']) && intval($_GET['size']) > 0){
    $var.= ' LIMIT :size';
    $data['size'] = intval($_GET['size']); 
}


$query = $bd->prepare($var);
$query->execute($data);
while ($ligne = $query->fetch()){
    print_titles($ligne);
}


?>


</body>
</html>





