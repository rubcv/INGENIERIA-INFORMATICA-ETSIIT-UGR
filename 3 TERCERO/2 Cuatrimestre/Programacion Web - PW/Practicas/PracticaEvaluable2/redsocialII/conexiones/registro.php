<?php
 ob_start();
 session_start();

  include_once 'dbconexion.php';

  

if(isset($_POST['SubmitButton'])){


  // Limpiar la entrada para evitar sql injection

  $user_firstname = trim($_POST['user_firstname']);
  $user_firstname = strip_tags($user_firstname);
  $user_firstname = htmlspecialchars($user_firstname);


  $user_lastname = trim($_POST['user_lastname']);
  $user_lastname = strip_tags($user_lastname);
  $user_lastname = htmlspecialchars($user_lastname);

  $user_name = trim($_POST['user_name']);
  $user_name = strip_tags($user_name);
  $user_name = htmlspecialchars($user_name);

  $user_email = trim($_POST['user_email']);
  $user_email = strip_tags($user_email);
  $user_email = htmlspecialchars($user_email);

  $user_password = trim($_POST['user_password']);
  $user_password = strip_tags($user_password);
  $user_password = htmlspecialchars($user_password);


  // Encriptamos la contraseña
 // $user_password = hash('sha256', $user_password);

  $fecha_registro = date("Y-m-d");
  

  // Vemos que el usuario no exista ya
  $sql = "SELECT `email`, `username` FROM `usuarios` WHERE `email` = '$user_email' OR `username` = '$user_name';";
  //  echo "$sql";
  $result = $conn->query($sql);
  $array = $result->fetch(PDO::FETCH_ASSOC);
  $num_rows = $result->fetchColumn();

  
   if( sizeof($array) != 1){
     echo "<h1> El usuario ya existe <h1>";
     exit(1);
   }else{ 


    // Hacemos la consulta
    
    $sql = "INSERT INTO `usuarios` ( `nombre`, `apellidos`, `username`, `email`, `password`, `last_login`, `fecha_registro`) VALUES ( '$user_firstname', '$user_lastname', '$user_name',  '$user_email',  '$user_password', NULL, '$fecha_registro');";

    $conn->query($sql);
   
   }


  // Hacemos los unset correspondientes

  unset($_POST['user_firstname']);
  unset($_POST['user_lastname']);
  unset($_POST['user_name']);
  unset($_POST['user_email']);
  unset($_POST['user_password']);
  unset($user_firstname);
  unset($user_lastname);
  unset($user_name);
  unset($user_email);
  unset($user_password);

}
?>