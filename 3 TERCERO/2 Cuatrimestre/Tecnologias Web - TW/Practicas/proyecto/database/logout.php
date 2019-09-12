<?php

    require_once 'conexion.php';
    session_start();

    guardarLogs('Se ha desconectado');

    unset($_SESSION['nombre']);
    unset($_SESSION['apellidos']);
    unset($_SESSION['telefono']);
    unset($_SESSION['email']);
    unset($_SESSION['tipo']);

    $mysqli->close();

    header("Location: ../index.php");

?>