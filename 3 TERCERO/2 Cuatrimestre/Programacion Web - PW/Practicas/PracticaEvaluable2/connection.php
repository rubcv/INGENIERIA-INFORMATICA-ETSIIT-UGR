<?php

    $servername = "localhost";
    $username = "root";
    $password = "rubencav";


    try {

        // Create connection
        $conn = new mysqli($servername, $username, $password);
        echo "Connected succesfully\n";
    }catch(PDOException $e){
        die( "Connection failed: " . $e->getMessage());
        $conn->close(); 
    }
   

   
   // Create database
   $sql = "CREATE DATABASE $pruebas";

   try{
        mysqli_query($conn, $sql);
        echo "Database una creada\n";
   }catch(Exception $e){
       echo "Error creating: " . una . mysqli_error($conn);
   }

   // Añadir acceso a la database

//   $grant_access = "GRANT ALL ON menagerie.* TO 'root'@'127.0.0.1';";
//   if(!mysqli_query($conn, $sql)){
//       die("Error getting permissions in the database\n");
//   }

   // Seleccionar la database
   $sql = "use pruebas";

   if(!mysqli_query($conn, $sql)){
        echo "Error selecting una" . mysqli_query($conn);  
   }
//   GRANT ALL ON scanner.* TO your_user@'IP_ofServer_where_PHP_runs' IDENTIFIED BY 'PASSWORD';
//  GRANT ALL ON menagerie.* TO 'your_mysql_name'@'your_client_host';


   // Creando una tabla
   $dbtable = readline("Escribe el nombre de la tabla: \n");
   $sql = "CREATE TABLE $dbtable(
    id INT(3) unsigned primary key,
    name varchar(10) not null);";

    if(mysqli_query($conn, $sql)){
        echo "Tabla $dbtable creada\n";
    }else{
        echo "Error creando $dbtable " . $conn->error;
    }

    // Insertando en la tabla
    $sql = "INSERT INTO $dbtable
    values (1, 'Esequiel');";

    if (mysqli_query($conn, $sql)){
        echo "Datos insertados en $dbtable\n";
    }else{
        echo "Error insertando datos en una\n";
    }


    // Imprimiendo los datos de la tabla

    $sql = "SELECT * from $dbtable";
    
    $result =  mysqli_query($conn, $sql);
    if(!$result){
        echo "Error: \n" . mysqli_error($conn);
    }

    // Imprimir datos de cada fila
    while($row = mysqli_fetch_array($result)) {
        echo "ID: " . $row[0] . " - Name: " . $row['Esequiel'] . "\n";
    }

   // Eliminar database
   $sql = "DROP DATABASE una";
   if(mysqli_query($conn, $sql)){
        echo "Database una eliminada\n";
   }else{
        echo "Error eliminando la database: " . una . mysqli_error($conn);
   }






?>