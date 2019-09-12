<?php
 ob_start();
 session_start();

  include_once 'dbconexion.php';

  if(isset($_POST['submit'])){
      $user_name = $_SESSION['username'];
      
      $sql = "DELETE FROM usuarios WHERE username = '$user_name';";
      $conn->query($sql);

      $sql = "DELETE FROM entradas WHERE username = '$user_name';";
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

 
  }
    header("Location: ../index.php");