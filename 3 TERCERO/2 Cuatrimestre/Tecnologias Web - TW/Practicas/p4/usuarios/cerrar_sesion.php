<?php

    require_once 'portal.php';
    session_start();

    unset($_SESSION['email']);
    unset($_SESSION['pass']);

    $mysqli->close();

    header("Location: usuarios.php");

?>