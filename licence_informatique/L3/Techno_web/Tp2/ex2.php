<?php

//$NBCELLULE = 100;

function build_world($taille, $proportion_noir){
    if ($proportion_noir * 100 > 100 || $proportion_noir * 100 < 0) throw new Exception("Coucou tu veux voir mon erreur ?");
    $arr = [];
    for ($i = 0; $i < $taille; $i++){
        if (rand(1,100) <= $proportion_noir * 100){
            $arr [] = true;
        }
        else {
            $arr [] = false;
        }
    }
    return $arr;
};

function print_world($world){
    foreach ($world as $cellule){
        if (!$cellule){
            echo " ";
        }
        else {
            echo "#";
        }
    }
    echo "\n";
};

function compute_next_state_rule110($left, $self, $right){
    if ((!$left && !$right && !$self) || ($left && $right && $self) || ($left && !$right && !$self)){
        return false;
    }
    else {
        return true;
    }
};

function compute_next_state_rule184($left, $self, $right){
    if (!$self) {
        return $left;
    }
    else {
        return $right;
    }
};

function next_generation($world, $func){
    $new_world = [];
    
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
};

function display_evolution($world, $nb_generations){
    $my_func = 'compute_next_state_rule110';
    //$my_func = 'compute_next_state_rule184';
    for ($i = 0; $i < $nb_generations; $i++){
        $world = next_generation($world, $my_func);
        print_world($world);
    }
};

function get_cell_at_index($world, $index){
    if ($index == 0){
        return compute_next_state_rule110(count($world) - 1, $world[$index], $world[$index+1]);
    }
    else if ($index == count($world) - 1){
        return compute_next_state_rule110($world[$index-1], $world[$index], $world[0]);
    }
};

/*$my_tab = next_generation($my_tab);
print_world($my_tab);

$my_tab = next_generation($my_tab);
print_world($my_tab);

$my_tab = next_generation($my_tab);
print_world($my_tab);
*/

function main(){ 
    if ($argc != 4){
        //throw new Exception ("Not enough args or too much args !");
        $my_tab = build_world(100, 0.5);
        print_world($my_tab);
        display_evolution($my_tab, 50);
    }
    else {
        $my_tab = build_world($argv[2], $argv[1]);
        print_world($my_tab);
        display_evolution($my_tab, $argv[3]);
    }
}

main();
