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


if(isset($_POST['SubmitButton'])){

if(!(isset( $_POST['titulo']) && isset($_POST['texto'])) ){
    echo "<h1> Entrada no válida </h1>";
    $value = $_SESSION['username'];
    header('../usuario.php?usuario=' . $value);
    exit;
}

  $titulo = processText($_POST['titulo']);
  $texto = processText($_POST['texto']);

  $fecha_public = date("Y-m-d");
  $autor = $_SESSION['username'];
  $autor_id = $_SESSION['user_id'];

  $tiene_media = strpos($texto, 'http://') !== false || strpos($texto, 'www.') !== false || strpos($texto, 'https://') !== false;

  if($tiene_media){
      $index = strrpos($texto, 'http');
      
      $length = $index;
      $aux_text = "";
      while (isset($texto[$length])) {
        $aux_text .= $texto[$length]; 
        $length++;
      }
      $result = explode(" ", $aux_text, 2);
      $media = $result[0];

      $texto = str_replace($media, "", $texto);
      $media = str_replace('watch?v=', 'embed/', $media);

      $sql  = "INSERT INTO `entradas` (user_id, username, titulo, texto, media_ent, fecha_public) VALUES ('$autor_id', '$autor', '$titulo', '$texto', '$media', '$fecha_public');";
  }else{
      $sql  = "INSERT INTO `entradas` (user_id, username, titulo, texto, fecha_public) VALUES ('$autor_id', '$autor', '$titulo', '$texto', '$fecha_public');";
  }

      $conn->query($sql);
  

      $value = $_SESSION['username'];
      header("Location: ../usuario.php?usuario=" . $value);

      unset($_POST['titulo']);
      unset($_POST['texto']); 
}else{
    echo "<h1> No publicada </h1>";
}