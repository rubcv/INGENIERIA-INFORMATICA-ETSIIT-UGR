<?php

 
 //error_reporting( ~E_DEPRECATED & ~E_NOTICE ); // Que no aparezcan errores
 //error_reporting(E_ERROR | E_PARSE);
 
try {

    $DBHOST = 'localhost';
    $DBUSER = 'pw_76065313';
    $DBPASS = 'Xpw_76065313';
    $DBNAME = 'pw_76065313';


    $conn = new PDO("mysql:host=$DBHOST;dbname=$DBNAME", $DBUSER, $DBPASS);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
   

}catch(PDOException $e){
    echo "Conexion fallida " . $e->getMessage();
}



