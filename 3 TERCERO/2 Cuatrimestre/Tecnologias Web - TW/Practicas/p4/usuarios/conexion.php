

    <?php
    
        ini_set('display_errors', 1);
        ini_set('display_startup_errors', 1);
        error_reporting(E_ALL);
        
        $username = "rubencav1718";
        $password = "YgoDFKzv";

        $mysqli = new mysqli('localhost', $username, $password, $username);
        
        if ($mysqli->connect_errno) {
            printf("Falló la conexión: %s\n", $mysqli->connect_error);
            exit();
        }




