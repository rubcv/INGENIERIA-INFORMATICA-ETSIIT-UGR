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

        if(isset($_POST['nombre']) && isset($_POST['prenda'])){
            
            if(preg_match('/\d/', $_POST['nombre']) || preg_match('/\d/', $_POST['prenda'])){
                
                setcookie('fallo','fallo'); // fallo
                header ("Location: cookies.php");
                exit;
            }else{
                $nombre = $_POST['nombre'];
                $prenda = $_POST['prenda'];

                setcookie('nombre', $nombre);
                setcookie('prenda', $prenda );
                setcookie('fallo','fallo', time() - 1); // borrar fallo
            }

        }else if(!isset($_COOKIE['fallo2']) && 
                        ((!isset($_POST['nombre']) || $_POST['nombre'] == "" || 
                        !isset($_POST['prenda']) || $_POST['prenda']  == ""))
                ){
            
            setcookie('fallo','fallo'); // fallo
            header("Location: cookies.php");
            exit;
       
        }
    ?>

    
    
    <section> 
        <h1> Aliexpress </h1>

        <h3> Saludos <?php echo $nombre  ?>,  rellena los siguientes datos antes de comprar <?php echo $prenda ?> : </h3>
        
        <?php
                if(isset($_COOKIE['fallo2'])){
                    echo '<h4 id="error_msg"> <i> Error, revisa los campos </i> </h4>';
                }

        ?>
        
        <form action="tercero.php" method="POST">
            Introduce la talla (entre 30 y 50) 
                    <input type="number" name="talla" min="30" max="50"><br><br>
            Selecciona el color: <br><br>
            <select name="color" size="3">
                <option value="rojo">Rojo</option>
                <option value="verde">Verde</option>
                <option value="azul">Azul</option>
            </select> <br> <br>
            <input type="submit" value="Continuar" id="enviar">
        </form>
    </section>
</body>
</html>