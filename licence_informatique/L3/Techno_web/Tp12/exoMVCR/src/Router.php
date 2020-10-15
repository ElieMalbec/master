<?php
include 'view/View.php';
include 'control/Controller.php';
class Router{

    public function main(){
        $view = new View();
        $controller = new Controller($view);
        if (isset($_GET["id"])){
            $controller->showInformation($_GET["id"]);
        }
        else {
            $view->makeHomepage();
        }
        
    }
}