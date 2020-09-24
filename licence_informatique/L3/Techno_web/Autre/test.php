<?php

class Test {
	const constante = 'toto';

	public $x = 0;
	protected $y = 0;
	private $z = 0;

	protected static $cpt = 0;

	public function __construct($x, $y, $z) {
		$this->x = $x;
		$this->y = $y;
		$this->z = $z;

		//Acces aux attributs statiques
		self::$cpt++;
	}

	public function showConstante() {
		echo "La constante : " . self::constante . "\n";
	}

	public function instances() {
		echo "Nombre d'instances :". self::$cpt . "\n";
	}

	public function __destruct() {
		echo "Destruction de l'objet Test\n";
	}

	public function getZ() {
		return $this->z;
	}

	public function getY() {
		return $this->y;
	}

	public function showProp() {
		foreach ($this as $k => $v)
			echo "$k => $v\n";
	}

	public function __toString() {
		$this->showProp();
		return "ta mère en slip\n";
	}

	public static function statiqueMethod() {
		echo "Méthode statique \n";
	}
}

class Test2 extends Test {
	public function __construct() {
		echo "Je ne modifie pas les valeurs de x y z\n";
		self::$cpt++;
	}

	public function __destruct() {
		echo "L'objet Test2 est détruit\n";
	}
}

$t = new Test(1, 2, 3);
echo "Valeur de de Z : " . $t->getZ() . "\n";
echo "valeur de x :" . $t->x . "\n";
echo "Valeur de y :" . $t->getY() ."\n";
$t->showProp();


echo "\n\n";
foreach ($t as $k => $v)
	echo "$k => $v\n";
echo $t;
echo $t->instances();
echo Test::statiqueMethod();
$t->showConstante();
unset($t);

$s = new Test2();
$s->instances();
