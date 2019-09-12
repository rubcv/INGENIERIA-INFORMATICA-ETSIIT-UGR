<?php
 ob_start();
 session_start();

  include_once 'dbconexion.php';
  

          $sql  = "SELECT username, foto_usuario FROM usuarios WHERE activo = 1;";
           $result = $conn->query($sql);
           $array = $result->fetchAll(PDO::FETCH_ASSOC);   

        echo json_encode($array);
  