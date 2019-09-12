<?php

        require_once 'conexion.php';

        $email = $_POST['email'];
        $nombre = $_POST['nombre'];
        $apellidos = $_POST['apellidos'];
        $pass = $_POST['pass'];
        if(isset($_POST['admin'])){
            $admin = 'admin';
        }else{
            $admin = 'normal';
        }
        

        $error = false;

        $email = $mysqli->real_escape_string($email);
        $nombre =  $mysqli->real_escape_string($nombre); 
        $apellidos =  $mysqli->real_escape_string($apellidos); 
        $pass =  base64_encode($pass);
        $admin =  $mysqli->real_escape_string($admin); 

        if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
            $error = true;
        }

        if($error){
            header("Location: portal.php?error=true");
            exit();

        }else{
            
            $sql = "INSERT INTO `usuarios` (email, nombre, apellidos, clave_cifrada, tipo) VALUES ('$email', '$nombre', '$apellidos', '$pass', '$admin');";
            
            $mysqli->query($sql) or die($mysqli->error);

            header("Location: portal.php?error=false");      
            exit();      
        }



    