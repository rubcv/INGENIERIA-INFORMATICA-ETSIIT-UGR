

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


    function guardarLogs($accion){
        
        $hora = date('H:i');
        $fecha = date('d-m-y');
        if(isset($_SESSION['nombre'])){

            $usuario = $_SESSION['nombre'];
            
            $autor = "\n" .'El usuario ' . $usuario;
        }else{
            $autor = "\n" . 'Se ';
        }

        $log = $autor . ' ha realizado la siguiente acción ' . "\n" .
        $accion . "\n\n" . 'El ' . $fecha . ' a las ' . $hora . "\n\n ||";

        $fp = fopen('database/logs.txt', 'a+');
        fwrite($fp, $log);

        fclose($fp);
    }


