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
    <section> 
        <h1> Aliexpress </h1>

        <h3> Saludos, escribe tu nombre y selecciona la prenda a comprar: </h3>

        <?php
            
            if(!isset($_COOKIE['nombre']) && !isset($_COOKIE['prenda'])){

                if(isset($_COOKIE['fallo'])){
                    echo '<h4 id="error_msg"> <i> Error, revisa los campos </i> </h4>';
                }
                
            }


            
        ?>
            
        <form action="segundo.php" method="POST">
            Nombre: <input type="text" name="nombre"> <br> <br>
            <select name="prenda" size="3">
                <option value="camisa">Camisa</option>
                <option value="pantalon">Pantalón</option>
                <option value="falda">Falda</option>
            </select> <br> <br>
            <input type="submit" value="Enviar" id="enviar">
        </form>
    </section>
</body>
</html>