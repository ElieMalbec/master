<?php http_response_code(404);

if ($_GET['mode'] === "texte") header("Content-Type: text/plain");

echo "Hello\n";
echo "<strong>\n";
echo "World!\n";

var_export(getallheaders());

echo "\n";
var_export($_GET);



interface EvolutionRule {
    public function computeNextStateCell($leftAlive, $selfAlive, $rightAlive);

}

class Rule110 implements EvolutionRule {
    public function computeNextStateCell($leftAlive, $selfAlive, $rightAlive){
        if ((!$leftAlive && !$rightAlive && !$selfAlive) || ($leftAlive && $rightAlive && $selfAlive) || ($leftAlive && !$rightAlive && !$selfAlive)){
            return false;
        }
        else {
            return true;
        }
    }
}


class Rule184 implements EvolutionRule {
    public function computeNextStateCell($leftAlive, $selfAlive, $rightAlive){
        if ((!$leftAlive && !$rightAlive && !$selfAlive) || (!$leftAlive && !$rightAlive && $selfAlive) || (!$leftAlive && $rightAlive && !$selfAlive) || ($leftAlive && !$rightAlive && $selfAlive)){
            return false;
        }
        else {
            return true;
        }
    }
}


class WorldState {
    private $cells;
    private $age;

    public function __construct($nbCells){
        $this->cells = array();
        for ($i = 0; $i < $nbCells; $i++){
            $this->cells [] = false;
        }
        $this->age = 0;
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
        echo "(" . $this->age . ")" ;
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

    public function get_cell_at_index($index, EvolutionRule $rule){
        if ($index == 0){
            return $rule->computeNextStateCell($this->isCellAliveAtPosition(count($this->cells) - 1), $this->isCellAliveAtPosition($this->cells[$index]), $this->isCellAliveAtPosition($this->cells[$index+1]));
        }
        else if ($index == count($this->cells) - 1){
            return $rule->computeNextStateCell($this->isCellAliveAtPosition($this->cells[$index-1]), $this->isCellAliveAtPosition($this->cells[$index]), $this->isCellAliveAtPosition($this->cells[0]));
        }
    }

    public function  next_generation(EvolutionRule $compute_next_state) : WorldState {
        $new_world = [] ; // dont use clone to be able to print the age
        //var_export($this->cells);
        for ($i = 0; $i < count($this->cells) ; $i++){
            if ($i == 0 || $i == count($this->cells) - 1){
                $new_world[$i] = $this->get_cell_at_index($i, $compute_next_state);
            }
            else {
                $new_world[$i] = $compute_next_state->computeNextStateCell($this->isCellAliveAtPosition($i-1), $this->isCellAliveAtPosition($i), $this->isCellAliveAtPosition($i+1));
            }
        }
        $this->age++;
        $this->cells = $new_world;
        return $this;
    }

    public function getAge(){
        return $this->age;
    }
}

class Simulator{
    private $worldState;
    private $evolutionRule;

    public function __construct($new_world_state, EvolutionRule $evolutionRule){
        $this->worldState = $new_world_state;
        $this->evolutionRule = $evolutionRule;
    }

    public function displayEvolution($nb_generations){
        $my_rule = $this->evolutionRule;
        //$my_func = 'compute_next_state_rule184';
        for ($i = 0; $i < $nb_generations; $i++){
            $this->worldState = $this->worldState->next_generation($my_rule);
            $this->worldState->__toString();
        }
    }

}

interface Displayer {
    public function displayWorld(WorldState $instance);
}

if ($argc != 4){
    echo "Not enough args or too much\n";
    //throw new Exception ("Not enough args or too much args !");
    /*$my_tab = build_world(100, 0.5);
    print_world($my_tab);
    display_evolution($my_tab, 50);*/
    $ratio = 0.5;
    $taille = 50;
    $generation = 50;
    $my_world = WorldState::buildRandomWorld($taille,$ratio); //work
    $s1 = new Simulator($my_world, new Rule184()); //work
    $s1 = $s1->displayEvolution($generation);
}
else {
    $ratio = $argv[1];
    $taille = $argv[2];
    $generation = $argv[3];
    $my_world = WorldState::buildRandomWorld($taille,$ratio); //work
    $s1 = new Simulator($my_world, new Rule184()); //work
    $s1 = $s1->displayEvolution($generation);
}
