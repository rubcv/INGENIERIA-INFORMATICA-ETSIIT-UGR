
<?php

 ob_start();
session_start();

  include_once 'dbconexion.php';
  
  
     $value = $_SESSION['username'];

    $sql = "UPDATE `usuarios` SET `activo` = 0 WHERE `username` = '$value';";
    $conn->query($sql);

      unset($_SESSION['user_id']);
      unset($_SESSION['nombre']); 
      unset($_SESSION['apellidos']);
      unset($_SESSION['username']);
      unset($_SESSION['email']);
      unset($_SESSION['password']);
      unset($_SESSION['last_login']);
      unset($_SESSION['fecha_registro']);
      unset($_SESSION['foto_usuario']);
      unset($_SESSION['activo']);

    header("Location: ../index.php");
 