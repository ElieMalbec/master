<!DOCTYPE html>
<html lang="fr">
<head>
	<title>Inclusion</title>
	<meta charset="UTF-8" />
	<style>blockquote { border: 3px outset #555; padding: .4em; }</style>
</head>
<body>

<h2>Inclusion du fragment HTML</h2>
<blockquote>
<?php
require_once 'fragmentHTML.txt';
?>
</blockquote>

<h2>Inclusion du fragment PHP</h2>
<blockquote>
<?php
require_once 'fragmentPHP.txt';
?>
</blockquote>

<h2>Inclusion d'un fragment inexistant</h2>
<blockquote>
<?php
//require_once 'fragment404.txt';
?>
</blockquote>

<h2>Conclusion</h2>
<p>Lorem ipsum dolor sit amet.</p>


</body>
</html>
