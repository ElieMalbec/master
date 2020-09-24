<?php

class WorldState {
    private $cells;

    public function __construct($nbCells){
        $this->cells = array();
        for ($i = 0; $i < $nbCells; $i++){
            $this->cells [] = false;
        }
    }
    public static function buildFixedWorld($nbcells){
        $tmp = new WorldState($nbcells);
        $tmp->cells [5] = true;
        $tmp->cells [25] = true;
        $tmp->cells [45] = true;
        $tmp->cells [90] = true;

        return $tmp;
    }

    function buildRandomWorld($taille, $ratioAlive){
        if ($ratioAlive * 100 > 100 || $ratioAlive * 100 < 0) throw new Exception("Coucou tu veux voir mon erreur ?");
        $tmp = new WorldState($taille);
        for ($i = 0; $i < $taille; $i++){
            if (rand(1,100) <= $ratioAlive * 100){
                $tmp->cells[$i] = true;
            }
            else {
                $tmp->cells[$i] = false;
            }
        }
        return $tmp;
    }

    public function isCellAliveAtPosition($position){
        $position = $position % count($this->cells);
        if ($position < 0 || $position > count($this->cells)){
            echo "\n-->ERROR, no cells at that position<--\n";
            return false;
        }
        return ($this->cells[$position] == true);
    }

    public function __toString(){
        foreach ($this->cells as $cellule){
            if (!$cellule){
                echo " ";
            }
            else {
                echo "#";
            }
        }
        echo "\n";
    }

    public function compute_next_state_rule110($left, $self, $right){
        if ((!$this->cells[$left] && !$this->cells[$right] && !$this->cells[$self]) || ($this->cells[$left] && $this->cells[$right] && $this->cells[$self]) || ($this->cells[$left] && !$this->cells[$right] && !$this->cells[$self])){
            return false;
        }
        else {
            return true;
        }
    }

    public function get_cell_at_index($index){
        if ($index == 0){
            return $this->compute_next_state_rule110(count($this->cells) - 1, $this->cells[$index], $this->cells[$index+1]);
        }
        else if ($index == count($this->cells) - 1){
            return $this->compute_next_state_rule110($this->cells[$index-1], $this->cells[$index], $this->cells[0]);
        }
    }

    public function next_generation($compute_next_state){
        $new_world = clone $this;
        $func = $compute_next_state;
        for ($i = 0; $i < count($new_world->cells) ; $i++){
            if ($i == 0 || $i == count($this->cells) - 1){
                $new_world->cells[$i] = $this->get_cell_at_index($i);
            }
            else {
                $new_world->cells[$i] = $this->$func($i-1, $i, $i+1);
            }
        }
        return $new_world;

        /*$new_world = [];
        
        for ($i = 0; $i < count($world) ; $i++){
            if ($i == 0){
                $new_world[] = get_cell_at_index($world, $i);
            }
            else if ($i == count($world) - 1){
                $new_world[] = get_cell_at_index($world, $i);
            }
            else {
                $new_world [] = $func($world[$i-1], $world[$i], $world[$i+1]);
            }
        }
        return $new_world;
        */
    }

    public function compute_next_state_rule184($left, $self, $right){
        if (!$this->cells[$self]) {
            return $this->cells[$left];
        }
        else {
            return $this->cells[$right];
        }
    }
}

class Simulator{
    private $worldState;

    public function __construct($new_world_state){
        $this->worldState = $new_world_state;
    }

    public function displayEvolution($nb_generations){
        //$my_func = 'compute_next_state_rule110';
        $my_func = 'compute_next_state_rule184';
        for ($i = 0; $i < $nb_generations; $i++){
            $this->worldState = $this->worldState->next_generation($my_func);
            $this->worldState->__toString();
        }
    }

}

//$test = new WorldState(100);
//var_export($test);

/*
$test2 = WorldState::buildFixedWorld(100);
var_export($test2);
echo "\n";
var_export($test2->isCellAliveAtPosition(5));
echo " ";
var_export($test2->isCellAliveAtPosition(15));
echo "\n";
//var_export($test2->isCellAliveAtPosition(105)); //offset

$test2->__toString();
var_export($test2->compute_next_state_rule110(1,2,3));
echo " ";
var_export($test2->compute_next_state_rule110(4,5,6));
echo " ";
var_export($test2->compute_next_state_rule110(90,91,92));
echo "\n";

$test3 = $test2->next_generation();
var_export($test3);

echo "\n---------SIMULATOR---------\n";
$s1 = new Simulator($test2);
var_export($s1);
$s1 = $s1->displayEvolution(50);

echo "\n---------Random World---------\n";
$test4 = WorldState::buildRandomWorld(100,0.5);
$test4->__toString();
$test4 = WorldState::buildRandomWorld(100,0.5);
$test4->__toString();
$test4 = WorldState::buildRandomWorld(100,0.5);
$test4->__toString();
*/

if ($argc != 4){
    echo "Not enough args or too much";
    //throw new Exception ("Not enough args or too much args !");
    /*$my_tab = build_world(100, 0.5);
    print_world($my_tab);
    display_evolution($my_tab, 50);*/
}
else {
    $ratio = $argv[1];
    $taille = $argv[2];
    $generation = $argv[3];
    $my_world = WorldState::buildRandomWorld($taille,$ratio);
    $s1 = new Simulator($my_world);
    $s1 = $s1->displayEvolution($generation);
}
