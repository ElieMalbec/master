<?php

class Controller {
    private $view;
    private $animalsTab = array(
        'medor' => array('Médor', 'chien'),
        'felix' => array('Félix', 'chat'),
        'denver' => array('Denver', 'dinosaure'),
    );

    public function __construct(View $my_view){
        $this->view = $my_view;
    }

    public function showInformation($id) {
        if (key_exists($id, $this->animalsTab)){
            $this->view->makeAnimalPage($this->animalsTab[$id][0], $this->animalsTab[$id][1]);
        }
        else {
            $this->makeUnknownAnimalPage();
        }
    }
    
    public function makeUnknownAnimalPage(){
        echo "Animal inconnu";
    }
}