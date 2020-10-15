<?php

class View {
    private $title;
    private $content;

    function __construct(){
    }

    public function render(){
        include 'templates/squelette.php';
    }

    public function makeTestPage(){
        $this->title = 'random stuff';
        $this->content = 'random stuff yeah youpi yeah ouypi';
        $this->render();
    }

    public function makeAnimalPage($name, $species){
        $this->title = "Page sur " . $name;
        $this->content = $this->title . ' est un animal de l\'espèce ' . $species;
        $this->render();
    }

    public function makeHomepage(){
        $this->title = "Accueil";
        $this->content = "Bienvenue à Gattaca !";
        $this->render();
    }

}