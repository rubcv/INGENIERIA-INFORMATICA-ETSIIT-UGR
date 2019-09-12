<?php
 ob_start();
 session_start();

  include_once 'dbconexion.php';
  
        
        // $sql  = "SELECT DISTINCT entradas.id_ent, usuarios.foto_usuario, entradas.username, usuarios.username, entradas.titulo, entradas.texto, entradas.fecha_public FROM entradas, usuarios WHERE entradas.username = usuarios.username AND `id_ent` NOT IN (SELECT id_ent FROM entradas ORDER BY id_ent desc limit $limit) ORDER BY entradas.id_ent DESC LIMIT $consulta;";
        $sql  = "SELECT entradas.id_ent, usuarios.foto_usuario, entradas.username, usuarios.username, entradas.titulo, entradas.texto, entradas.fecha_public FROM entradas, usuarios WHERE entradas.username = usuarios.username ORDER BY entradas.id_ent DESC LIMIT 6;";
        try{
            $result = $conn->query($sql);
            $array = $result->fetchAll(PDO::FETCH_ASSOC); 
        }catch(Exception $e){
            echo "Entradas no cargadas";
        }
            
        if (strlen($array[0]['texto']) > 150){
            $array[0]['texto'] = substr($array[0]['texto'], 0, 147) . '...';
        }
        
        echo json_encode($array);

        