<?php
 ob_start();
 session_start();

  include_once 'dbconexion.php';



function processText($text) {
    $text = strip_tags($text);
    $text = trim($text);
    $text = htmlspecialchars($text);
    return $text;
}

  if(isset($_POST['GuardarCambios'])){
      $user_name = $_SESSION['username'];


    if(isset($_POST['nombre'])){
        $nombre = processText($_POST['nombre']);

        if($nombre != ""){
            $sql = "UPDATE `usuarios` SET `nombre` = '$nombre' WHERE `username` = '$user_name';";
            $conn->query($sql);

            $_SESSION['nombre'] = $nombre;
        }
    }
    if(isset($_POST['apellidos'])){
        $apellidos = processText($_POST['apellidos']);
            
        if($apellidos != ""){
            $sql = "UPDATE `usuarios` SET `apellidos` = '$apellidos' WHERE `username` = '$user_name';";
            $conn->query($sql);

            $_SESSION['apellidos'] = $apellidos;
        }
    }
    if(isset($_POST['username'])){
        $username = processText($_POST['username']);
        
        if($username != ""){

            $sql = "UPDATE `usuarios` SET `username` = '$username' WHERE `username` = '$user_name';";
            $conn->query($sql);

            // Cambiamos tambien sus entradas escritas
            $sql = "UPDATE entradas SET username = '$username' WHERE username = '$user_name';";
            $conn->query($sql);

            $_SESSION['username'] = $username;
            $user_name = $username;
        }
    }
    if(isset($_POST['email'])){
        $email = processText($_POST['email']);
        
        if($email != ""){
            $sql = "UPDATE `usuarios` SET `email` = '$email' WHERE `username` = '$user_name';";
            $conn->query($sql);

            $_SESSION['email'] = $email;
        }
    }

  }
    
      $value = $_SESSION['username'];
     header("Location: ../info.php?usuario=" . $value);