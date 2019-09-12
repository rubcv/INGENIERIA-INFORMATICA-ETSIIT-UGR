<?php
 ob_start();
 session_start();

  include_once 'dbconexion.php';
  
  
  var_dump($_POST);
  try{
    $actual = $_SESSION['username'];
    $amigo = $_POST['username'];

    $sql = "INSERT INTO amigos(actual, amigo) VALUES ('$actual', '$amigo');";
        $conn->query($sql);

  }catch(Exception $e){
      echo "<h1> No se ha podido agregar como amigo </h1>";
  }
    $location = "../info.php?usuario=" . "$amigo";
    header("Location: $location");
    