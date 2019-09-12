<?php
 ob_start();
 session_start();

  include_once 'dbconexion.php';
  
  if(isset($_POST['SessionStartClick'])){
    
  
  // Limpiar la entrada para evitar sql injection

  $user_name = trim($_POST['user_name']);
  $user_name = strip_tags($user_name);
  $user_name = htmlspecialchars($user_name);

  $user_password = trim($_POST['user_password']);
  $user_password = strip_tags($user_password);
  $user_password = htmlspecialchars($user_password);


  // Encriptamos la contraseña
  //$user_password = hash('sha256', $user_password);


  // Hacemos la consulta
  

  // Vemos que el usuario exista ya
  $sql = "SELECT * FROM `usuarios` WHERE `password` = '$user_password' AND `username` = '$user_name';";


  $result = $conn->query($sql);
  $array = $result->fetchAll(PDO::FETCH_ASSOC);
  
  
  if(sizeof($array) == 0){
     echo "<h1> El usuario no existe </h1>";
     exit(1);
  }else{
      
      
      //$session_array = array($array[0]['user_id'], $array[0]['nombre'], $array[0]['apellidos'], $array[0]['username'], $array[0]['email'], $array[0]['password'], $array[0]['last_login'], $array[0]['fecha_registro'], $array[0]['foto_usuario'], $array[0]['activo']);
      $_SESSION['user_id'] = $array[0]['user_id'];
      $_SESSION['nombre'] = $array[0]['nombre'];
      $_SESSION['apellidos'] = $array[0]['apellidos'];
      $_SESSION['username'] = $array[0]['username'];
      $_SESSION['email'] = $array[0]['email'];
      $_SESSION['password'] = $array[0]['password'];
      $_SESSION['last_login'] = $array[0]['last_login'];
      $_SESSION['fecha_registro'] = $array[0]['fecha_registro'];
      $_SESSION['foto_usuario'] = $array[0]['foto_usuario'];
      $_SESSION['activo'] = $array[0]['activo'];


      // Fecha de ultimo login
      $fecha_login = date("Y-m-d");

      $sql = "UPDATE `usuarios` SET `last_login` = '$fecha_login' WHERE `username` = '$user_name';";
      $conn->query($sql);

      // Tiene una sesión activa
      $sql = "UPDATE `usuarios` SET `activo` = 1 WHERE `username` = '$user_name';";
      $conn->query($sql);
      

      header('Location: portada.php?bienvenida=si');
  
  }


  

  // Hacemos los unset correspondientes

  unset($_POST['user_name']);
  unset($_POST['user_password']);
  unset($user_name);
  unset($user_password);

  }

