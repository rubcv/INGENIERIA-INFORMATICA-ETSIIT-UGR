<!DOCTYPE html>
<html>
   
        <?php
            $nombre = $_POST["nombre"];
            $apellido = $_POST["apellido"];
            $genero = $_POST["genero"]; 
            $rango = $_POST["rangoEdad"];
            $comentario = $_POST["comentarios"];
        
            echo  $nombre; 
            echo  $apellido;
            echo $genero; 
            echo $rango ;
            echo  $comentario;
        ?>
</html>