<?php

error_reporting(E_ALL);

$firstname = $_POST['firstname'];
$lastname = $_POST['lastname'];

echo "Your name: $firstname <br> Your last name: $lastname <br>"
/*

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

    $sql = "create database una";

   try{
        mysqli_query($conn, $sql);
        echo "Database una creada\n";
   }catch(Exception $e){
       echo "Error creating: " . una . mysqli_error($conn);
   }

   // Seleccionar la database
   $sql = "use pruebas";

   if(!mysqli_query($conn, $sql)){
        echo "Error selecting una" . mysqli_query($conn);  
   }

   $sql = "create table users(
       name varchar(20),
       surname varchar(20);";

    
    if(mysqli_query($conn, $sql)){
        echo "Tabla $dbtable creada\n";
    }else{
        echo "Error creando $dbtable " . $conn->error;
    }


    $sql = "insert into table users values ('$firstname', '$lastname');";

    if (mysqli_query($conn, $sql)){
        echo "Datos insertados en $dbtable\n";
    }else{
        echo "Error insertando datos en una\n";
    }
*/
?>