<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Aliexpress</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
  
</head>
<body>
  
    <?php

        function comprobarTalla($talla){
            return (is_numeric($talla) && (30 <= $talla ) && ($talla <= 50));
        }
        
        
        if(!isset($_COOKIE['nombre']) && !isset($_COOKIE['prenda'])){
            setcookie('fallo','fallo'); // fallo
            header("Location: cookies.php");
            exit;
        }else{
            $nombre = $_COOKIE['nombre'];
            $prenda = $_COOKIE['prenda'];
        }

        if(isset($_POST['talla']) && isset($_POST['color'])){
            
            if(!comprobarTalla($_POST['talla']) || preg_match('/\d/', $_POST['color'])){
                
                setcookie('fallo2','fallo2'); // fallo
                header ("Location: segundo.php");
                exit;
            }else{
                $talla = $_POST['talla'];
                $color = $_POST['color'];

                setcookie('talla', $talla);
                setcookie('color', $color );
                //setcookie('fallo','fallo', time() - 1, '/', 'localhost', false, true); // borrar fallo
                setcookie('fallo2','fallo2', time() - 1); // borrar fallo2
                
            }

        }else if(!isset($_POST['talla']) || $_POST['talla'] == "" || 
                !isset($_POST['color']) || $_POST['color']  == ""){
            
            setcookie('fallo2','fallo2'); // fallo2
            header("Location: segundo.php");
            exit;
    
        }
        
    ?>

    
    
    <section> 
        <h1> Aliexpress </h1>
            <form action="segundo.php" method="POST">
                <input type="hidden" name="nombre" value=" <?php echo $nombre ?> ">
                <input type="hidden" name="prenda" value=" <?php echo $prenda ?> ">
            </form>
         

        <h3> Saludos <?php echo $nombre  ?>, estos son los datos recibidos: </h3>
     
        <h4> Nombre: </h4> <p> <?php echo $nombre ?> <p>
        <h4> Prenda: </h4> <p> <?php echo $prenda ?> <p>
        <h4> Talla: </h4> <p> <?php echo $talla ?> <p>
        <h4> Color: </h4> <p> <?php echo $color ?> <p>
        
    </section>

    <?php
            // Borramos las cookies

            setcookie('nombre', $nombre, time() - 1);
            setcookie('prenda', $prenda, time() - 1 );
            setcookie('talla', $talla, time() - 1);
            setcookie('color', $color, time() - 1  );
            setcookie('fallo','fallo', time() - 1 ); // borrar fallo
            setcookie('fallo2','fallo2', time() - 1); // borrar fallo2

    ?>
</body>
</html>