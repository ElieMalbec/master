<?php

class AuthenticationManager{
    private $list_comptes;
    private $is_connected;
    private $is_admin_connected;

    public function __construct($list_comptes){
        $this->list_comptes = $list_comptes;
        $this->is_connected = false;
        $this->is_admin_connected = false;
    }


    public function connectUser($login, $password){
        foreach ($this->list_comptes as $key => $value){
            if ($value["login"] === $login  && (password_verify($_POST['password'], $b["password"]))){
                if ($value["status"] === "admin"){
                    $this->is_admin_connected = true;
                }
                $this->is_connected = true;
            }
        }
    }

    public function isUserConnected(){
        return $this->is_connected;
    }

    public function isAdminConnected(){
        return $this->is_admin_connected;
    }

    public function getUserName(){

    }

    public function disconnectUser(){
        $this->is_connected = false;
    }
}
