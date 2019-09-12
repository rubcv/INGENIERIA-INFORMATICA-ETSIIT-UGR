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


try{  

  

  $texto_com = processText($_POST['texto']);

  $fecha_public = date("Y-m-d");
  $autor = $_SESSION['username'];
  $autor_id = $_SESSION['user_id'];
  $entrada_id = $_POST['titulo'];

  $sql  = "INSERT INTO `comentarios` (id_ent, user_id, username, texto_com, fecha_com) VALUES ('$entrada_id', '$autor_id', '$autor', '$texto_com', '$fecha_public');";
    $conn->query($sql);
  

      

      unset($_POST['texto']);
}catch(Exception $e){
    echo "<h1> Entrada no publicada </h1>";  
}
      header("Location: ../entrada.php?entrada=" . $entrada_id);